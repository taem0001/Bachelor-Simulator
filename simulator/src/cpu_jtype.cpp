#include "../include/cpu.hpp"

namespace Simulator {
	void CPU::j_instruction(const char rd, const int imm) {
		int real_imm = ((imm & 0x80000) << 1) | ((imm & 0xFF) << 12) | ((imm & 0x100) << 3) |
					   (((imm >> 9) & 0x3FF) << 1);
		if (real_imm & 0x100000) real_imm |= 0xffe00000;

		int val = pc + 4;
		pc += real_imm;
		pc_modified = true;

		Register res = {.data = static_cast<uint32_t>(val), .tag = registers[rd].tag};
		write_to_register(rd, res);
    }
} // namespace Simulator