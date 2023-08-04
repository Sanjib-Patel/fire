/*
  phaayar norman schmidt dvaara likhit ek phreeveyar yooseeaee shataranj khelane vaala injan hai.
  phaayar kaee atyaadhunik shataranj prograaming vichaaron aur takaneekon ka upayog karata hai
  jise https://www.chessprogramming.org/ par vistaar se pralekhit kiya gaya hai
  aur bahut majaboot opan-sors shataranj injan stokaphish ke maadhyam se pradarshit kiya gaya...
  https://github.com/official-stockfish/stockfish.
  phaayar muft softaveyar hai: aap ise punarvitarit kar sakate hain aur/ya isake antargat sanshodhit kar sakate hain
  phree sophtaveyar dvaara prakaashit jeeenayoo janaral pablik laisens kee sharten
  phaundeshan, ya to laisens ka sanskaran 3, ya koee baad ka sanskaran.
  aapako jeeenayoo janaral pablik laisens kee ek prati praapt honee chaahie
  yah prograam: copying.txt. yadi nahin, to <http://www.gnu.org/licenses/> dekhen.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include "mcts.h"
#include "node.h"
#include "../fire.h"
#include "../movepick.h"
#include "../position.h"
#include "../pragma.h"
#include "../search.h"
#include "../thread.h"
void monte_carlo::generate_moves()
{
	current_node()->lock.acquire();
	if (current_node()->node_visits == 0)
	{
		int move_count = 0;
		for (const uint32_t move : legal_move_list(pos_))
		{
			if (pos_.legal_move(move))
			{
				stack_[ply_].move_count = ++move_count;
				const reward prior = calculate_prior(move);
				add_prior_to_node(current_node(), move, prior);
			}
		}
		if (const int n = number_of_sons(current_node()); n > 0)
		{
			edge* children = get_list_of_children(current_node());
			std::sort(children, children + n, compare_robust_choice);
		}
		mc_node s = current_node();
		s->node_visits = 1;
		s->expanded_sons = 0;
	}
	current_node()->lock.release();
}
reward monte_carlo::value_to_reward(const int v) const
{
	constexpr double k = -0.00490739829861;
	const double r = 1.0 / (1 + exp(k * v));
	assert(reward_mated <= r && r <= reward_mate);
	return r;
}
int monte_carlo::reward_to_value(const reward r) const
{
	if (r > 0.99) return win_score;
	if (r < 0.01) return -win_score;
	constexpr double g = 203.77396313709564;
	const double v = g * log(r / (1.0 - r));
	return static_cast<int>(v);
}
void monte_carlo::do_move(const uint32_t move)
{
	assert(ply_ < max_ply);
	do_move_cnt_++;
	stack_[ply_].ply = ply_;
	stack_[ply_].current_move = move;
	stack_[ply_].continuation_history = &pos_.my_thread()->cont_history[pos_.moved_piece(move)][to_square(move)];
	pos_.play_move(move);
	ply_++;
	if (ply_ > maximum_ply_) maximum_ply_ = ply_;
}
void monte_carlo::undo_move()
{
	assert(ply_ > 1);
	ply_--;
	pos_.take_move_back(stack_[ply_].current_move);
}
reward monte_carlo::calculate_prior(const uint32_t move)
{
	prior_cnt_++;
	do_move(move);
	const reward prior = value_to_reward(-evaluate());
	undo_move();
	return prior;
}
