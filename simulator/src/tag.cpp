#include "../include/tag.hpp"

namespace Simulator {
	std::ostream &operator<<(std::ostream &out, const Tag &tag) {
		switch (tag) {
		case Tag::UB:
			return out << "UB";
		case Tag::UH:
			return out << "UH";
		case Tag::UW:
			return out << "UW";
		case Tag::SB:
			return out << "SB";
		case Tag::SH:
			return out << "SH";
		case Tag::SW:
			return out << "SW";
		default:
			break;
		}
		return out << "";
	}
} // namespace Simulator