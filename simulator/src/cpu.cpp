#include "../include/cpu.hpp"

namespace Simulator {
	CPU::CPU() : pc(0) { registers.fill({0, Tag::SW}); }

	// Getters/Setters
	std::array<Register, REGISTERNUM> &CPU::get_registers() { return registers; }

	const std::array<Register, REGISTERNUM> &CPU::get_registers() const { return registers; }

	void CPU::set_register(const char rd, const uint32_t data, const Tag &tag) { write_to_register(rd, {data, tag}); }

	void CPU::write_to_register(const char rd, const Register &r) {
		if (rd != 0) {
			registers[rd] = r;
		}
	}

	// Instruction functions
	void CPU::execute_instruction(const int instruction) {
		char opcode = instruction & 0x7F;

		switch (opcode) {
		case 0x13: { // i-type
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			const short imm = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN));

			i_instruction(rd, func3, rs1, imm);
		} break;
		case 0x33: { // r-type
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			const char rs2 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN)) & 0x1F;
			const char func7 =
				(instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN + REG_ENC_LEN)) & 0x7F;

			r_instruction(rd, func3, rs1, rs2, func7);
		} break;
		case 0x7B: {
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const char func7 =
				(instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN + REG_ENC_LEN)) & 0x7F;

			si_instruction(rd, func7);
		} break;
		default:
			break;
		};

		pc += 4;
	}
} // namespace Simulator