#include "../include/instructions.hpp"

namespace Simulator {
	void handle_instruction(CPU &cpu, int instruction) {
		char opcode = instruction & 0x7F;

		switch (opcode) {
		case 0x33: {
			char rd = (instruction >> OPCODE_LEN) & 0x1F;
			char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			char rs1 =
				(instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			char rs2 = (instruction >>
						(OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN)) &
					   0x1F;

			r_instruction(cpu.registers, rd, func3, rs1, rs2);
		} break;
		default:
			break;
		};

		cpu.pc += 4;
	}

	void r_instruction(std::array<Register, REGISTERNUM> &registers,
					   const char rd, const char func3, const char rs1,
					   const char rs2) {
		switch (func3) {
		case 0x2: // SHIFT
			break;
		case 0x0: // ADD
		{
			unsigned char rs1_sign = get_tag_sign(registers[rs1].tag);
			unsigned char rs2_sign = get_tag_sign(registers[rs2].tag);
			unsigned char rs1_size = get_tag_size(registers[rs1].tag);
			unsigned char rs2_size = get_tag_size(registers[rs2].tag);

			Register res;
			if (rs1_size > rs2_size) {
				res = {registers[rs1].data + registers[rs2].data,
					   registers[rs1].tag};
			} else if (rs1_size == rs2_size && rs1_sign < rs2_sign) {
				res = {registers[rs1].data + registers[rs2].data,
					   registers[rs1].tag};
			} else {
				res = {registers[rs1].data + registers[rs2].data,
					   registers[rs2].tag};
			}

			registers[rd] = res;
		} break;
		case 0x1: // SUB
			break;
		default:
			break;
		}
	}
} // namespace Simulator
