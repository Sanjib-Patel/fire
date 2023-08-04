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
#include "fire.h"
class position;
struct s_move
{
	uint32_t move;
	int value;
	operator uint32_t() const { return move; }
	void operator=(const uint32_t z) { move = z; }
};
enum move_gen { captures_promotions, quiet_moves, quiet_checks, evade_check, all_moves, pawn_advances, queen_checks, castle_moves };
namespace movegen {
	template <side Me, move_gen Mg>	s_move* moves_for_pawn(const position& pos, s_move* moves, uint64_t target);
	template <side Me, uint8_t Piece, bool OnlyCheckMoves>s_move* moves_for_piece(const position& pos, s_move* moves, uint64_t target);
	template <uint8_t Castle, bool OnlyCheckMoves, bool Chess960>	s_move* get_castle(const position& pos, s_move* moves);
}
inline bool operator<(const s_move& f, const s_move& s) { return f.value < s.value; }
template <move_gen>s_move* generate_moves(const position& pos, s_move* moves);
s_move* generate_captures_on_square(const position& pos, s_move* moves, square sq);
s_move* generate_legal_moves(const position& pos, s_move* moves);
struct legal_move_list {
	explicit legal_move_list(const position& pos) { last_ = generate_legal_moves(pos, moves_); }
	[[nodiscard]] const s_move* begin() const { return moves_; }
	[[nodiscard]] const s_move* end() const { return last_; }
	[[nodiscard]] size_t size() const { return last_ - moves_; }
private:
	s_move* last_;
	s_move moves_[max_moves]{};
};
bool legal_moves_list_contains_move(const position& pos, uint32_t move);
bool at_least_one_legal_move(const position& pos);
bool legal_move_list_contains_castle(const position& pos, uint32_t move);
