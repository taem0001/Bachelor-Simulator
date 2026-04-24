#include "../include/cpu.hpp"

namespace Simulator {
	void CPU::lui_instruction(const char rd, const int imm) {
		uint32_t val = imm << 12;
		Tag res_tag = registers[rd].tag;
		Register res = {.data = val, .tag = res_tag};
		write_to_register(rd, res);
	}

	void CPU::auipc_instruction(const char rd, const int imm) {
		uint32_t val = _bitwise_add(static_cast<uint32_t>(pc), static_cast<uint32_t>(imm << 12));
		Tag res_tag = registers[rd].tag;
		Register res = {.data = val, .tag = res_tag};
		write_to_register(rd, res);
	}
} // namespace Simulator