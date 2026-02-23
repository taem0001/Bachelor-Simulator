#ifndef UTIL_HPP
#define UTIL_HPP

#include "includes.hpp"

namespace Simulator {
	template <class... Ts> struct overloaded : Ts... {
			using Ts::operator()...;
	};
	template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

	// Data
	using Data = std::variant<int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t>;
	std::ostream &operator<<(std::ostream &out, const Data &data);

	// Tag
	enum class TAG : unsigned char {
		UB = 0b000,
		UH = 0b001,
		UW = 0b010,
		SB = 0b100,
		SH = 0b101,
		SW = 0b110
	};
	std::ostream &operator<<(std::ostream &out, TAG tag);
	static inline unsigned char get_tag_sign(const TAG &tag);
	static inline unsigned char get_tag_size(const TAG &tag);
} // namespace Simulator

#endif
