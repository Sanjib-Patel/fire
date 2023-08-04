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
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#include <sys/mman.h>
#endif

#include <cinttypes>
#ifdef _WIN32
using FD = HANDLE;
#define FD_ERR INVALID_HANDLE_VALUE
using map_t = HANDLE;
#else /* Unix */
typedef int FD;
#define FD_ERR -1
typedef size_t map_t;
#endif

FD open_file(const char* name);
void close_file(FD fd);
size_t file_size(FD fd);
const void* map_file(FD fd, map_t* map);
void unmap_file(const void* data, map_t map);
inline uint32_t readu_le_u32(const void* p)
{
	const auto* q = static_cast<const uint8_t*>(p);
	return q[0] | (q[1] << 8) | (q[2] << 16) | (q[3] << 24);
}
inline uint16_t readu_le_u16(const void* p)
{
	const auto* q = static_cast<const uint8_t*>(p);
	return static_cast<uint16_t>(q[0] | (q[1] << 8));
}
template <typename T1, typename T2, typename T3>constexpr auto clamp(T1 a, T2 b, T3 c) { return ((a) < (b) ? (b) : (a) > (c) ? (c) : (a)); }
