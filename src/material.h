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
#include "endgame.h"
#include "fire.h"
#include "position.h"
namespace material {
	// material hash data structure
	struct mat_hash_entry
	{
		[[nodiscard]] int get_game_phase() const { return game_phase; }
		[[nodiscard]] bool has_value_function() const { return value_function_index >= 0; }
		[[nodiscard]] int value_from_function(const position& pos) const;
		[[nodiscard]] sfactor scale_factor_from_function(const position& pos, side color) const;
		uint64_t key64;
		int value_function_index;
		int scale_function_index[num_sides];
		int value;
		sfactor conversion;
		uint8_t factor[num_sides];
		uint8_t game_phase;
		bool conversion_is_estimated;
	};
	static_assert(sizeof(mat_hash_entry) == 32, "Material Entry size incorrect");
	template <class Entry, int Size>
	struct material_hash_table
	{
		Entry* operator[](const uint64_t key)
		{
			static_assert(sizeof(Entry) == 32 || sizeof(Entry) == 128, "Wrong size");
			return reinterpret_cast<Entry*>(reinterpret_cast<char*>(mat_hash_mem_) + (static_cast<uint32_t>(key) & (Size - 1) * sizeof(Entry)));
		}
	private:
		CACHE_ALIGN Entry mat_hash_mem_[Size];
	};
	// default material hash size = 16 MB;
	constexpr int material_hash_size = 16384;
	using material_hash = material_hash_table<mat_hash_entry, material_hash_size>;
	mat_hash_entry* probe(const position& pos);
}
