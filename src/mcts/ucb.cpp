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
#include "../fire.h"
#include "../pragma.h"
#include "../thread.h"
void monte_carlo::set_exploration_constant(const double c)
{
	ucb_exploration_constant_ = c;
}
double monte_carlo::exploration_constant() const
{
	return ucb_exploration_constant_;
}
double monte_carlo::ucb(mc_node node, const edge& edge) const
{
	const long father_visits = node->node_visits;
	assert(father_visits > 0);
	double result = 0.0;
	if (edge.visits < 1)result += edge.mean_action_value;
	else result += ucb_unexpanded_node_;
	const double c = ucb_use_father_visits_ ? exploration_constant() * sqrt(father_visits) : exploration_constant();
	const double losses = edge.visits - edge.action_value;
	const double visits = edge.visits;
	const double divisor = losses * ucb_losses_avoidance_ + visits * (1.0 - ucb_losses_avoidance_);
	result += c * edge.prior / (1 + divisor);
	result += ucb_log_term_factor_ * sqrt(log(father_visits) / (1 + visits));
	return result;
}
