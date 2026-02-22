#include "../include/util.hpp"

namespace Simulator {
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
} // namespace Simulator