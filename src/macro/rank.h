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
// these macros specify basic arithmetic operations: + (addition), - (subtraction), ++ (post-increment) and -- (post-decrement) on enumerated rank values
inline rank operator+(const rank r1, const rank r2) { return static_cast<rank>(static_cast<int>(r1) + static_cast<int>(r2)); }
inline rank operator-(const rank r1, const rank r2) { return static_cast<rank>(static_cast<int>(r1) - static_cast<int>(r2)); }
inline rank& operator++(rank& r) { return r = static_cast<rank>(static_cast<int>(r) + 1); }
inline rank& operator--(rank& r) { return r = static_cast<rank>(static_cast<int>(r) - 1); }
