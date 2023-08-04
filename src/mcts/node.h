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
#include "mcts.h"
#include "../position.h"
#include "../pragma.h"
constexpr reward reward_none = 0.0;
constexpr reward reward_mated = 0.0;
constexpr reward reward_draw = 0.5;
constexpr reward reward_mate = 1.0;
mc_node get_node(const position& pos);
inline edge edge_none = { 0, 0, reward_none, reward_none, reward_none };
inline uint32_t move_of(mc_node node) { return node->last_move(); }
inline edge* get_list_of_children(mc_node node) { return node->children_list(); }
inline int number_of_sons(mc_node node) { return node->number_of_sons; }
