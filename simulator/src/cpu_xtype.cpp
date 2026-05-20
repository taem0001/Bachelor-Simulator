#include "../include/cpu.hpp"

namespace Simulator {
	void CPU::x_instruction(const int bits) {
		switch (bits) {
		case 0x2000: // ebreak
			ebreak = true;
			break;
		default:
			break;
		}
	}
} // namespace Simulator