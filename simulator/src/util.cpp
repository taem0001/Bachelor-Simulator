#include "../include/util.hpp"

namespace Simulator {
	// Data
	std::ostream &operator<<(std::ostream &out, const Data &data) {
		std::visit(
			overloaded{
				[&](int8_t value) { out << static_cast<int>(value); },
				[&](uint8_t value) { out << static_cast<unsigned int>(value); },
				[&](int16_t value) { out << value; },
				[&](uint16_t value) { out << value; },
				[&](int32_t value) { out << value; },
				[&](uint32_t value) { out << value; }},
			data);
		return out;
	}

	// Tag
	std::ostream &operator<<(std::ostream &out, TAG tag) {
		switch (tag) {
		case TAG::UB:
			return out << "UB";
		case TAG::UH:
			return out << "UH";
		case TAG::UW:
			return out << "UW";
		case TAG::SB:
			return out << "SB";
		case TAG::SH:
			return out << "SH";
		case TAG::SW:
			return out << "SW";
		default:
			break;
		}
	}

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
} // namespace Simulator