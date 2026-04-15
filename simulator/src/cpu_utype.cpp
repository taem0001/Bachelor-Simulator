#include "../include/cpu.hpp"

namespace Simulator {
	void CPU::lui_instruction(const char rd, const int imm) {
		uint32_t val = imm << 12;
		Tag res_tag = registers[rd].tag;
		Register res = {.data = val, .tag = res_tag};
		write_to_register(rd, res);
	}

	void CPU::auipc_instruction(const char rd, const int imm) {
		uint32_t val = pc + (imm << 12);
		Tag res_tag = registers[rd].tag;
		Register res = {.data = val, .tag = res_tag};
		write_to_register(rd, res);
	}
} // namespace Simulator