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
#if defined(_MSC_VER)
#include <bit>
#endif
#include "fire.h"
// the C/C++ AVX intrinsic functions for x86 processors are in the header "immintrin.h".
// the corresponding Intel® AVX2 instruction is PEXT (Parallel Bits Extract)
#ifdef USE_PEXT
#include <immintrin.h>
inline uint64_t pext(const uint64_t occupied, const uint64_t mask) { return _pext_u64(occupied, mask); }
#endif
#if defined(_MSC_VER)
inline int popcnt(const uint64_t bb) { return std::popcount(bb); }
inline square lsb(const uint64_t bb) { return static_cast<square>(std::countr_zero(bb)); }
inline square msb(const uint64_t bb) { unsigned long idx; _BitScanReverse64(&idx, bb); return static_cast<square>(idx); }
inline void prefetch(void* address) { _mm_prefetch(static_cast<char*>(address), _MM_HINT_T0); }
#define CACHE_ALIGN __declspec(align(64))
#elif defined(__GNUC__)
inline int popcnt(uint64_t bb) { return __builtin_popcountll(bb); }
inline square lsb(uint64_t bb) { return static_cast<square>(__builtin_ctzll(bb)); }
inline square msb(uint64_t bb) { return static_cast<square>(63 ^ __builtin_clzll(bb)); }
inline void prefetch(void* address) { __builtin_prefetch(address); }
#define CACHE_ALIGN __attribute__ ((aligned(64)))
#endif
