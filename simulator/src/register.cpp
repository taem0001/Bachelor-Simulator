#include "../include/register.hpp"

namespace Simulator {
    void Register::mask_by_tag() {
		switch (tag) {
		case Tag::UB:
			data &= 0x000000FFu;
            break;
		case Tag::UH:
			data &= 0x0000FFFFu;
            break;
		case Tag::UW:
		case Tag::SW:
			break;
		case Tag::SB:
			data &= 0x000000FFu;
			if (data & 0x80u) data |= 0xFFFFFF00u;
            break;
		case Tag::SH:
			data &= 0x0000FFFFu;
			if (data & 0x8000u) data |= 0xFFFF0000u;
            break;
		default:
			break;
		}
	}
}