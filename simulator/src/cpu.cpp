#include "../include/cpu.hpp"

namespace Simulator {
	CPU::CPU() : pc(0) { registers.fill({0, Tag::SW}); }

	// Getters/Setters
	std::array<Register, REGISTERNUM> &CPU::get_registers() { return registers; }

	const std::array<Register, REGISTERNUM> &CPU::get_registers() const { return registers; }
	const std::array<uint8_t, MEMORY_SIZE_BYTES> &CPU::get_memory() const { return memory; }

	void CPU::set_register(const char rd, const uint32_t data, const Tag &tag) { write_to_register(rd, {data, tag}); }

	void CPU::set_memory(uint32_t addr, uint32_t data, Tag tag) {
		memory[addr] = data & 0xFF;
		switch (tag)
		{
		case Tag::UH:
		case Tag::SH: {
			memory[addr + 1] = (data >> 8);
		} break;
		case Tag::UW:
		case Tag::SW: {
			memory[addr + 1] = (data >> 8);
			memory[addr + 2] = (data >> 16);
			memory[addr + 3] = (data >> 24);
		} break;
		default:
			break;
		}
	}

	void CPU::load_program(const std::string &path) {
		Simulator::load_program(path, memory, 0);
	}

	void CPU::print_registers() {
		for (const Register& reg : get_registers()) {
			std::cout << reg << '\n';
		}
	}

	void CPU::run() {
		while(pc+3 < MEMORY_SIZE_BYTES) {
			uint32_t instr = memory[pc]
				| (memory[pc + 1] << 8)
				| (memory[pc + 2] << 16)
				| (memory[pc + 3] << 24);
			
			if(instr == 0) {
				print_registers();
				return;
			}
			execute_instruction(instr);

			pc += 4;
		}
	}

	void CPU::write_to_register(const char rd, const Register &r) {
		if (rd != 0) {
			registers[rd] = r;
		}
	}

	// Instruction functions
	void CPU::execute_instruction(const int instruction) {
		//std::cout << std::bitset<32>(instruction) << '\n';

		char opcode = instruction & 0x7F;

		switch (opcode) {
		case 0x03: { // l-type
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			const short imm = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN));

			l_instruction(rd, func3, rs1, imm);
		} break;
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
			const char func7 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN + REG_ENC_LEN)) & 0x7F;

			r_instruction(rd, func3, rs1, rs2, func7);
		} break;
		case 0x23: { // s-type
			const char imm4_0 = (instruction >> OPCODE_LEN) & 0x1F;
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			const char rs2 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN)) & 0x1F;
			const char imm11_5 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN + REG_ENC_LEN)) & 0x7F;

			s_instruction(imm4_0, func3, rs1, rs2, imm11_5);
		}
		case 0x7B: {
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const char func7 =
				(instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN + REG_ENC_LEN)) & 0x7F;

			si_instruction(rd, func7);
		} break;
		default:
			break;
		};
	}
} // namespace Simulator