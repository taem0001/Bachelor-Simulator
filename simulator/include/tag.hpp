#ifndef TAG_HPP
#define TAG_HPP

#include "includes.hpp"

namespace Simulator {
	enum class Tag : uint8_t { UB = 0b000, UH = 0b001, UW = 0b010, SB = 0b100, SH = 0b101, SW = 0b110 };
	std::ostream &operator<<(std::ostream &out, const Tag &tag);
	static bool is_unsigned(Tag &tag);
	static int tag_bits(Tag &tag);
} // namespace Simulator

#endif
