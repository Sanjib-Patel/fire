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
#include "tbprobe.h"
#include "../search.h"
#include "../util/util.h"

// syzygy initialization and probe functions
namespace egtb {
	int max_pieces_wdl = 0;
	int max_pieces_dtz = 0;
	int max_pieces_dtm = 0;
	egtb_probe egtb_probe_wdl = nullptr;
	egtb_probe egtb_probe_dtm = nullptr;
	egtb_probe egtb_probe_dtz = nullptr;
	bool use_rule50;
	static bool syzygy_in_use = false;
	static std::string current_syzygy_path;
	//probe distance-to-zero
	int tb_probe_dtz(position& pos)
	{
		auto success = 0;
		const auto val = syzygy_probe_dtz(pos, &success);
		if (success == 0) return no_score;
		pos.increase_tb_hits();
		const auto move50 = pos.fifty_move_counter();
		if (val > 0 && (!use_rule50 || move50 + val <= 100)) return std::max(longest_mate_score - (pos.info()->ply + val), egtb_win_score + score_1);
		if (val < 0 && (!use_rule50 || move50 - val <= 100)) return std::min(-longest_mate_score + (pos.info()->ply - val), -egtb_win_score - score_1);
		return draw_score;
	}
	// probe win-loss-draw
	int tb_probe_wdl(position& pos)
	{
		auto success = 0;
		const auto val = syzygy_probe_wdl(pos, &success);
		if (success == 0) return no_score;
		pos.increase_tb_hits();
		const auto draw_value = use_rule50 ? 1 : 0;
		if (val > draw_value) return longest_mate_score - pos.info()->ply;
		if (val < -draw_value) return -longest_mate_score + pos.info()->ply;
		return draw_value;
	}
	void syzygy_init(const std::string& path)
	{
		const auto path_specified = !path.empty() && path != "<empty>";
		if (path_specified)
		{
			if (path != current_syzygy_path) { syzygy_path_init(path); current_syzygy_path = path; }
			max_pieces_wdl = max_pieces_dtz = tb_max_men;
			if (max_pieces_wdl) {
				syzygy_in_use = true; egtb_probe_wdl = &tb_probe_wdl; egtb_probe_dtz = &tb_probe_dtz;
				acout() << "info string Found " << tb_num_piece + tb_num_pawn << " tablebases" << std::endl; return;
			}
		}
		if (path_specified || syzygy_in_use) { syzygy_in_use = false; max_pieces_wdl = max_pieces_dtz = 0; egtb_probe_wdl = nullptr; egtb_probe_dtz = nullptr; }
	}
}