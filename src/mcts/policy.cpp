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
#include <cassert>
#include <unordered_map>
#include "mcts.h"
#include "node.h"
#include "../pragma.h"
#include "../thread.h"
mc_node monte_carlo::tree_policy()
{
	assert(is_root(current_node()));
	descent_cnt_++;
	if (number_of_sons(root_) == 0)
		return root_;
	while (current_node()->node_visits > 0)
	{
		if (is_terminal(current_node()))
			return current_node();
		edges_[ply_] = best_child(current_node(), stat_ucb);
		const uint32_t m = edges_[ply_]->move;
		edge* edge = edges_[ply_];
		current_node()->lock.acquire();
		current_node()->node_visits++;
		edge->visits = edge->visits + 1.0;
		edge->mean_action_value = edge->action_value / edge->visits;
		current_node()->lock.release();
		assert(is_ok(m));
		assert(pos_.legal_move(m));
		do_move(m);
		nodes_[ply_] = get_node(pos_);
	}
	assert(current_node()->node_visits == 0);
	return current_node();
}
reward monte_carlo::playout_policy(mc_node node)
{
	playout_cnt_++;
	assert(current_node() == node);
	if (is_terminal(node))
		return evaluate_terminal();
	assert(current_node()->node_visits == 0);
	generate_moves();
	assert(current_node()->node_visits >= 1);
	if (number_of_sons(node) == 0)
		return evaluate_terminal();
	assert(current_node()->number_of_sons > 0);
	return get_list_of_children(current_node())[0].prior;
}
void monte_carlo::backup(reward r)
{
	assert(ply_ >= 1);
	while (!is_root(current_node()))
	{
		constexpr double weight = 1.0;
		undo_move();
		r = 1.0 - r;
		edge* edge = edges_[ply_];
		current_node()->lock.acquire();
		edge->visits = edge->visits - 1.0;
		edge->visits = edge->visits + weight;
		edge->action_value = edge->action_value + weight * r;
		edge->mean_action_value = edge->action_value / edge->visits;
		assert(edge->mean_action_value >= 0.0);
		assert(edge->mean_action_value <= 1.0);
		const double minimax = best_child(current_node(), stat_mean)->mean_action_value;
		r = r * (1.0 - backup_minimax_) + minimax * backup_minimax_;
		current_node()->lock.release();
		assert(stack_[ply_].current_move == edge->move);
	}
	assert(is_root(current_node()));
}
