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
// these macros specify basic arithmetic operations: + (addition), - (subtraction), *(multiplication), ++ (post-increment) on enumerated rank values
inline side operator+(const side c1, const side c2) { return static_cast<side>(static_cast<int>(c1) + static_cast<int>(c2)); }
inline side operator-(const side c1, const side c2) { return static_cast<side>(static_cast<int>(c1) - static_cast<int>(c2)); }
inline side operator*(const int i, const side c) { return static_cast<side>(i * static_cast<int>(c)); }
inline side& operator++(side& c) { return c = static_cast<side>(static_cast<int>(c) + 1); }
