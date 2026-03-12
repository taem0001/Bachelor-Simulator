#include "../include/register.hpp"

namespace Simulator {
    void Register::mask_by_tag() {
		switch (tag) {
		case Tag::UB:
		case Tag::SB:
			data & 0x000000FFu;
            break;
		case Tag::UH:
		case Tag::SH:
			data & 0x0000FFFFu;
            break;
		case Tag::UW:
		case Tag::SW:
			data & 0xFFFFFFFFu;
            break;
		default:
			break;
		}
	}
}