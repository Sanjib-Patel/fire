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
#include "../fire.h"
// these macros specify basic arithmetic operations on enumerated score values
inline score operator+(const score s1, const score s2) { return static_cast<score>(static_cast<int>(s1) + static_cast<int>(s2)); }
inline score operator-(const score s1, const score s2) { return static_cast<score>(static_cast<int>(s1) - static_cast<int>(s2)); }
inline score operator*(const int i, const score s) { return static_cast<score>(i * static_cast<int>(s)); }
inline score operator*(const score s, const int i) { return static_cast<score>(static_cast<int>(s) * i); }
inline score& operator+=(score& s1, const score s2) { return s1 = s1 + s2; }
inline score& operator-=(score& s1, const score s2) { return s1 = s1 - s2; }
