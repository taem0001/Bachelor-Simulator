#include "../include/cpu.hpp"

namespace Simulator {
	void CPU::lui_instruction(const char rd, const int imm) {
		uint32_t val = imm << 12;
		Register res = {.data = val, .tag = Tag::SW};
		write_to_register(rd, res);
	}

	void CPU::auipc_instruction(const char rd, const int imm) {
		uint32_t val = _bitwise_add(static_cast<uint32_t>(pc), static_cast<uint32_t>(imm << 12));
		Register res = {.data = val, .tag = Tag::SW};
		write_to_register(rd, res);
	}
} // namespace Simulator