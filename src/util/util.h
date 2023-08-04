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
#include <ostream>
#include <iostream>
#include <mutex>
#include <random>
#include "../position.h"
inline constexpr auto program = "Fire 9";
inline std::string version;
inline constexpr auto author = "N. Schmidt";
inline constexpr auto platform = "x64";
static std::mutex mutex_cout;
// asynchronous output w/ mutex
struct acout
{
	std::unique_lock<std::mutex> lk;
	acout() : lk(std::unique_lock(mutex_cout)) {	}
	template <typename T> acout& operator<<(const T& t) { std::cout << t; return *this; }
	acout& operator<<(std::ostream& (*fp)(std::ostream&)) { std::cout << fp; return *this; }
};
namespace util {
	const std::string piece_to_char(" KPNBRQ  kpnbrq");
	std::string engine_info();
	std::string build_date();
	std::string engine_author();
	std::string core_info();
	std::string compiler_info();
	std::string move_to_string(uint32_t move, const position& pos);
	uint32_t move_from_string(const position& pos, std::string& str);
	class random
	{
		uint64_t s_;
		static uint64_t rand64() { std::random_device rd; std::mt19937_64 gen(rd()); std::uniform_int_distribution<uint64_t> dis; return dis(gen); }
	public:
		explicit random(const uint64_t seed) : s_(seed) { assert(seed); }
		template <typename T>
		static T rand() { return T(rand64()); }
	};
}
std::ostream& operator<<(std::ostream& os, const position& pos);
