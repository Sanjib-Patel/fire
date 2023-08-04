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
#include <unordered_map>
#include "node.h"
#include "mcts.h"
#include "../evaluate.h"
#include "../position.h"
#include "../pragma.h"
#include "../search.h"
#include "../thread.h"
mcts_hash_table mcts;
uint32_t monte_carlo::search()
{
	int depth = 0;
	create_root();
	search::running = true;
	thread_pool.root_position->copy_position(thread_pool.root_position, nullptr, nullptr);
	const auto me = thread_pool.root_position->on_move();
	time_control.init(search::param, me, thread_pool.root_position->game_ply());
	search::previous_info_time = 0;
	while (computational_budget())
	{
		mc_node node = tree_policy();
		const reward n_reward = playout_policy(node);
		backup(n_reward);
		if (should_output_result())
		{
			depth++;
			print_pv(depth);
		}
	}
	depth++;
	print_pv(depth);
	print_children = true;
	return best_child(root_, stat_visits)->move;
}
bool monte_carlo::computational_budget() const
{
	assert(is_root(current_node()));
	if (pos_.my_thread() == thread_pool.main())	static_cast<mainthread*>(pos_.my_thread())->check_time();
	return (descent_cnt_ < max_descents_) && !search::signals.stop_analyzing.load(std::memory_order_relaxed);
}
void mainthread::check_time()
{
	constexpr int time_denominator = 60;
	if (--calls_cnt > 0) return;
	calls_cnt = search::param.nodes ? std::min(1024, static_cast<int>(search::param.nodes / 1024)) : 1024;
	static time_point last_info_time = now();
	const time_point elapsed = time_control.elapsed();
	if (const time_point tick = search::param.start_time + elapsed; tick - last_info_time >= 1000) { last_info_time = tick; }
	if (search::param.ponder) return;
	if (constexpr int time_numerator = 10; (search::param.use_time_calculating() && (elapsed > time_control.maximum() * time_numerator / time_denominator
		|| search::signals.stop_if_ponder_hit))
		|| (search::param.move_time && elapsed >= search::param.move_time)
		|| (search::param.nodes && thread_pool.visited_nodes() >= search::param.nodes))
		search::signals.stop_analyzing = true;
}
int monte_carlo::evaluate() const { const int score = evaluate::eval(pos_); return score; }
