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
// disable specific compiler warnings
#pragma once
#ifdef _MSC_VER
#pragma warning(disable: 4127) // conditional expression is constant
#pragma warning(disable: 4146) // unary minus operator applied to unsigned type
#pragma warning(disable: 4189) // local variable is initialized but not referenced
#pragma warning(disable: 4706) // assignment within conditional expression
#else
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#endif
#ifdef __INTEL_COMPILER
#pragma warning(disable: 1491) // definition from the enclosing scope function is used.
#pragma warning(disable: 26812) // The enum type '' is unscoped. Prefer 'enum class' over 'enum'
#pragma warning(disable: 26451) // Arithmetic overflow: Using operator '<<' on a 4 byte value and then casting the result to a 8 byte value.
#endif
