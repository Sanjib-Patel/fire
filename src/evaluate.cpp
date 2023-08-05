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
#include "evaluate.h"
#include "endgame.h"
#include "fire.h"
#include "nnue/nnue.h"
#include "pragma.h"
	namespace evaluate {
	/*
	* tukada kod hain
	* wking=1, wquaiain=2, wrook=3, wbishop= 4, wknight= 5, wpawn= 6,
	* beeking=7, beekveen=8, brook=9, beebeeshop=10, beekenait=11, beepeeeen=12,
	*
	* varg hain
	* e1=0, bee1=1 ... echa8=63
	*
	* inaput praaroop:
	* tukada [0] saphed raaja hai, varg [0] usaka sthaan hai
	* tukada [1] kaala raaja hai, varg [1] isaka sthaan hai
	* ..
	* tukada[x], varg[x] kisee bhee kram mein ho sakata hai
	* ..
	* tukada[n+1] saranee ke ant ko darshaane ke lie 0 par set hai
	*
	* ritarn
	* anumaanit senteepons mein sthaanaantarit karane ke lie paksh ke saapeksh skor
	*/
	// uparokt enenayoo vinirdeshon ke anusaar aavashyakataanusaar tukade aur varg saaranee banaata hai
	int eval_nnue(const position& pos)
	{
		int pieces[33]{};
		int squares[33]{};
		int index = 2;
		for (uint8_t i = 0; i < 64; i++)
		{
			if (pos.piece_on_square(static_cast<square>(i)) == 1) { pieces[0] = 1; squares[0] = i; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 9) { pieces[1] = 7; squares[1] = i; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 2) { pieces[index] = 6; squares[index] = i; index++; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 3) { pieces[index] = 5; squares[index] = i; index++; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 4) { pieces[index] = 4; squares[index] = i; index++; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 5) { pieces[index] = 3; squares[index] = i; index++; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 6) { pieces[index] = 2; squares[index] = i; index++; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 10) { pieces[index] = 12; squares[index] = i; index++; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 11) { pieces[index] = 11; squares[index] = i; index++; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 12) { pieces[index] = 10; squares[index] = i; index++; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 13) { pieces[index] = 9; squares[index] = i; index++; }
			else if (pos.piece_on_square(static_cast<square>(i)) == 14) { pieces[index] = 8; squares[index] = i; index++; }
		}
		const int nnue_score = nnue_evaluate(pos.on_move(), pieces, squares);
		return nnue_score;
	}
	int eval(const position& pos)
	{
		const int nnue_score = eval_nnue(pos);
		return nnue_score;
	}
	int eval_after_null_move(const int eval)
	{
		const auto result = -eval + 2 * value_tempo;
		return result;
	}
}
