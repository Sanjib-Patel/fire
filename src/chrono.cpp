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
#include "chrono.h"
#include "fire.h"
#include "uci.h"
// init the vars and structures needed for time manager
// including class c_time_manager private member vars optimal_time_ & maximum_time_
void timecontrol::init(const search_param& limit, const side me, const int ply)
{
	start_time_ = now();
	optimal_time_ = maximum_time_ = limit.time[me];
	const auto maxmoves = limit.moves_to_go ? std::min(limit.moves_to_go, moves_horizon_) : moves_horizon_;
	const auto move_importance = calc_move_importance(ply) * move_importance_factor_;
	double other_moves_importance = 0;
	auto available = static_cast<int64_t>(limit.time[me]) - static_cast<int64_t>(uci_move_overhead);
	for (auto n = 1; n <= maxmoves; n++)
	{
		const auto ratio1 = move_importance / (move_importance + other_moves_importance);
		int64_t t1 = std::llround(static_cast<double>(available) * ratio1);
		auto ratio2 = max_ratio_ * move_importance / (max_ratio_ * move_importance + other_moves_importance);
		auto ratio3 = (move_importance + steal_ratio_ * other_moves_importance) / (move_importance + other_moves_importance);
		int64_t t2 = std::llround(static_cast<double>(available) * std::min(ratio2, ratio3));
		optimal_time_ = std::min(t1, optimal_time_);
		maximum_time_ = std::min(t2, maximum_time_);
		other_moves_importance += calc_move_importance(ply + 2 * n);
		available += static_cast<int64_t>(limit.inc[me]) - static_cast<int64_t>(uci_move_overhead);
	}
	optimal_time_ = std::max(optimal_time_, uci_minimum_time);
	maximum_time_ = std::max(maximum_time_, uci_minimum_time);
	if (uci_ponder)
	{
		// add time if ponder = 'on"
		optimal_time_ += optimal_time_ * 3 / 10;
		optimal_time_ = std::min(optimal_time_, maximum_time_);
	}
}
void timecontrol::adjustment_after_ponder_hit()
{
	// move faster in proportion to time elapsed if there's a ponder hit
	const auto new_max_time = maximum_time_ + elapsed();
	optimal_time_ = optimal_time_ * new_max_time / maximum_time_;
}
double timecontrol::calc_move_importance(const int ply) const
{
	auto factor = 1.0;
	if (ply > ply_min_ && ply < ply_max_)
		factor = factor_base_ - ply_factor_ * (static_cast<double>(ply) - static_cast<double>(base_moves_)) * (static_cast<double>(ply) - static_cast<double>(base_moves_));
	return factor * pow(1 + exp((ply - x_shift_) / x_scale_), -skew_);
}
int64_t timecontrol::elapsed() const { return now() - start_time_; }
timecontrol time_control;
