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
#pragma once
#include "position.h"
// UCI option default values
inline std::string startpos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
inline int uci_hash = 64;
inline int uci_threads = 1;
inline int uci_multipv = 1;
inline int uci_contempt = 0;
inline bool uci_mcts = false;
inline bool uci_ponder = false;
inline bool uci_chess960 = false;
inline bool uci_syzygy_50_move_rule = false;
inline int uci_syzygy_probe_depth = 1;
inline int uci_syzygy_probe_limit = 6;
inline std::string uci_syzygy_path;
inline std::string uci_nnue_evalfile = "05152023-045758.bin";
inline std::string engine_mode = "nnue";
inline bool bench_active = false;
// function declarations
int init(int hash_size);
void new_game();
void uci_loop(int argc, char* argv[]);
void set_position(position& pos, std::istringstream& is);
void set_option(std::istringstream& is);
void go(position& pos, std::istringstream& is);
void bench(int depth);
std::string trim(const std::string& str, const std::string& whitespace = " \t");
std::string sq(square sq);
std::string print_pv(const position& pos, int alpha, int beta, int active_pv, int active_move);
