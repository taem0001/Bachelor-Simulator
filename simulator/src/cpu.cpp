#include "../include/cpu.hpp"

namespace Simulator {
	CPU::CPU() : program_size_bytes(0), pc(0), pc_modified(false), ebreak(false) {
		registers.fill({0, Tag::SW});

		// x1 / ra should hold return addresses, so use unsigned word tag.
		// registers[1] = {0, Tag::UW};

		// Initialize stack pointer (x2) to top of simulated memory.
		registers[2] = {MEMORY_SIZE_BYTES, Tag::UW};
	}

	// Getters/Setters
	std::array<Register, REGISTERNUM> &CPU::get_registers() { return registers; }

	const std::array<Register, REGISTERNUM> &CPU::get_registers() const { return registers; }
	const std::array<uint8_t, MEMORY_SIZE_BYTES> &CPU::get_memory() const { return memory; }

	void CPU::set_register(const char rd, const uint32_t data, const Tag &tag) { write_to_register(rd, {data, tag}); }

	void CPU::set_memory(uint32_t addr, uint32_t data, Tag tag) {
		memory[addr] = data & 0xFF;
		switch (tag) {
		case Tag::UH:
		case Tag::SH: {
			memory[addr + 1] = (data >> 8) & 0xFF;
		} break;
		case Tag::UW:
		case Tag::SW: {
			memory[addr + 1] = (data >> 8) & 0xFF;
			memory[addr + 2] = (data >> 16) & 0xFF;
			memory[addr + 3] = (data >> 24) & 0xFF;
		} break;
		default:
			break;
		}
	}

	void CPU::load_program(const std::string &path) {
		std::ifstream in_file(path, std::ios::binary | std::ios::ate);
		if (in_file) {
			program_size_bytes = static_cast<std::size_t>(in_file.tellg());
		} else {
			program_size_bytes = 0;
		}

		pc = 0;
		Simulator::load_program(path, memory, 0);
	}

	void CPU::print_registers() {
		int i = 0;
		for (const Register &reg : get_registers()) {
			std::cout << "x" << i++ << ":" << reg << std::endl;
		}
	}

	void CPU::run() {
		constexpr uint32_t INSTR_SIZE_BYTES = 4;

		while (pc >= 0 && (static_cast<std::size_t>(pc) + (INSTR_SIZE_BYTES - 1) < program_size_bytes)) {
			const uint32_t instr = static_cast<uint32_t>(memory[pc]) | (static_cast<uint32_t>(memory[pc + 1]) << 8) |
								   (static_cast<uint32_t>(memory[pc + 2]) << 16) |
								   (static_cast<uint32_t>(memory[pc + 3]) << 24);
			pc_modified = false;
			ebreak = false;
			// std::cerr << "Tryin to execute with pc: " << pc << std::endl;
			execute_instruction(instr);
			if (ebreak) break;
			if (!pc_modified) pc += INSTR_SIZE_BYTES;
		}

		print_registers();
	}

	void CPU::write_to_register(const char rd, const Register &r) {
		if (rd != 0) {
			registers[rd] = r;
		}
	}

	// Instruction functions
	void CPU::execute_instruction(const int instruction) {
		char opcode = instruction & 0x7F;

		switch (opcode) {
		case 0x03: { // l-type
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			const short imm = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN));

			l_instruction(rd, func3, rs1, imm);
		} break;
		case 0x67: { // i-type (jalr)
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			const short imm = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN));

			jalr_instruction(rd, func3, rs1, imm);
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
			const char func7 =
				(instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN + REG_ENC_LEN)) & 0x7F;

			r_instruction(rd, func3, rs1, rs2, func7);
		} break;
		case 0x23: { // s-type
			const char imm4_0 = (instruction >> OPCODE_LEN) & 0x1F;
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			const char rs2 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN)) & 0x1F;
			const char imm11_5 =
				(instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN + REG_ENC_LEN)) & 0x7F;

			s_instruction(imm4_0, func3, rs1, rs2, imm11_5);
		} break;
		case 0x7B: { // si-type
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;

			si_instruction(rd, func3);
		} break;
		case 0x63: { // b-type
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			const char rs2 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN)) & 0x1F;
			int imm = ((instruction >> 31) << 12) | (((instruction >> 7) & 0x1) << 11) |
					  (((instruction >> 25) & 0x3F) << 5) | (((instruction >> 8) & 0xF) << 1);

			b_instruction(func3, rs1, rs2, imm);
		} break;
		case 0x6F: { // j-type
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const int imm = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0xFFFFF;

			j_instruction(rd, imm);
		} break;
		case 0x73: { // x-type
			const int bits = instruction >> OPCODE_LEN;

			x_instruction(bits);
		} break;
		case 0x37: { // u-type (lui)
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const int imm = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0xFFFFF;

			lui_instruction(rd, imm);
		} break;
		case 0x17: { // u-type (auipc)
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const int imm = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0xFFFFF;

			auipc_instruction(rd, imm);
		} break;
		default:
			break;
		};
	}
} // namespace Simulator