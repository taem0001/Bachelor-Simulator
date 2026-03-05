#ifndef TAG_HPP
#define TAG_HPP

#include "includes.hpp"

namespace Simulator {
	static constexpr uint8_t SIGN_MASK = 0b100;
	static constexpr uint8_t WIDTH_MASK = 0b011;

	enum class Tag : uint8_t { UB = 0b000, UH = 0b001, UW = 0b010, SB = 0b100, SH = 0b101, SW = 0b110 };
	std::ostream &operator<<(std::ostream &out, const Tag &tag);

	inline constexpr Tag make_tag(bool sign, uint8_t width) {
		const uint8_t sign_ = sign ? SIGN_MASK : 0;
		return static_cast<Tag>(sign_ | (width & WIDTH_MASK));
	}
	inline constexpr bool is_unsigned(const Tag &tag) { return (static_cast<uint8_t>(tag) & 0b100u) == 0; }
	inline constexpr int width_of(const Tag &tag) { return static_cast<uint8_t>(tag) & WIDTH_MASK; }
	inline constexpr uint8_t promote_width(uint8_t w) {
		return (w < TAG_WORD) ? static_cast<uint8_t>(w + 1) : static_cast<uint8_t>(TAG_WORD);
	}
} // namespace Simulator

#endif
