#ifndef UTIL_HPP
#define UTIL_HPP

#include "includes.hpp"

namespace Simulator {
	enum class TAG : unsigned char {
		UB = 0b000,
		UH = 0b001,
		UW = 0b010,
		SB = 0b100,
		SH = 0b101,
		SW = 0b110
	};

	std::ostream &operator<<(std::ostream &out, TAG tag);

	static inline unsigned char get_tag_sign(const TAG &tag) {
		switch (tag) {
		case TAG::UB:
		case TAG::UH:
		case TAG::UW:
			return 0;
		case TAG::SB:
		case TAG::SH:
		case TAG::SW:
			return 1;
		};
	}

	static inline unsigned char get_tag_size(const TAG &tag) {
		switch (tag) {
		case TAG::UB:
		case TAG::SB:
			return 0b00;
		case TAG::UH:
		case TAG::SH:
			return 0b01;
		case TAG::UW:
		case TAG::SW:
			return 0b10;
		};
	}

	static inline TAG get_tag(unsigned char sign, unsigned char size) {
		return (TAG)((sign << 2) | (size & 0x3));
	}
} // namespace Simulator

#endif
