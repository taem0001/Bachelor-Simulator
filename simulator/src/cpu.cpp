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
		case 0x13: {
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			const short imm = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN));

			i_instruction(rd, func3, rs1, imm);
		} break;
		case 0x33: {
			const char rd = (instruction >> OPCODE_LEN) & 0x1F;
			const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			const char rs2 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN)) & 0x1F;

			r_instruction(rd, func3, rs1, rs2);
		} break;
		default:
			break;
		};

		pc += 4;
	}

	// r-type instruction functions
	Tag _compute_arithmetic_tag(const Tag &t1, const Tag &t2) {
		const uint8_t w1 = width_of(t1);
		const uint8_t w2 = width_of(t2);
		uint8_t res_w;
		if (std::abs(w1 - w2) < 2) {
			res_w = promote_width((w1 < w2) ? w1 : w2);
		} else {
			res_w = promote_width((w1 < w2) ? w2 : w1);
		}

		const bool s1 = !is_unsigned(t1);
		const bool s2 = !is_unsigned(t2);

		bool res_signed = false;
		if (s1 && s2) {
			res_signed = true;
		} else if (!s1 && !s2) {
			res_signed = false;
		} else {
			const uint8_t unsigned_w = s1 ? w2 : w1;

			switch (unsigned_w) {
			case TAG_BYTE:
			case TAG_HALF:
				res_signed = res_w > unsigned_w;
				break;
			case TAG_WORD:
				res_signed = false;
				break;
			default:
				res_signed = false;
				break;
			}
		}

		return make_tag(res_signed, res_w);
	}

	uint32_t _bitwise_add(uint32_t a, uint32_t b) {
		while (b != 0) {
			uint32_t carry = (a & b) << 1;
			a = a ^ b;
			b = carry;
		}
		return a;
	}

	Register _add_instruction(const Register &rs1, const Register &rs2) {
		const Tag t1 = rs1.tag;
		const Tag t2 = rs2.tag;

		// Compute resulting tag
		const Tag res_tag = _compute_arithmetic_tag(t1, t2);

		// Compute addition
		uint32_t res_data = _bitwise_add(rs1.data, rs2.data);

		return {res_data, res_tag};
	}

	uint32_t _bitwise_sub(uint32_t a, uint32_t b) {
		uint32_t neg_b = _bitwise_add(~b, 1);
		return _bitwise_add(a, neg_b);
	}

	Register _sub_instruction(const Register &rs1, const Register &rs2) {
		const Tag t1 = rs1.tag;
		const Tag t2 = rs2.tag;

		// Compute resulting tag
		const Tag res_tag = _compute_arithmetic_tag(t1, t2);

		// Compute subtraction
		uint32_t res_data = _bitwise_sub(rs1.data, rs2.data);

		return {res_data, res_tag};
	}

	Register _shift_instruction(const Register &rs1, const Register &rs2) { return {0, Tag::SW}; }

	void CPU::r_instruction(const char rd, const char func3, const char rs1, const char rs2) {
		switch (func3) {
		case 0x2: // SHIFT
		{
			Register result = _shift_instruction(registers[rs2], registers[rs2]);
			write_to_register(rd, result);
		} break;
		case 0x0: // ADD
		{
			Register result = _add_instruction(registers[rs1], registers[rs2]);
			write_to_register(rd, result);
		} break;
		case 0x1: // SUB
		{
			Register result = _sub_instruction(registers[rs1], registers[rs2]);
			write_to_register(rd, result);
		} break;
		default:
			break;
		}
	}

	// i-type instruction functions
	Register _sli_instruction(const Register &rs1, const int8_t imm) {}

	Register _sri_instruction(const Register &rs1, const int8_t imm) {}

	void CPU::i_instruction(const char rd, const char func3, const char rs1, const short imm) {
		switch (func3) {
		case 0x1: // SLI
		{
			if (((imm >> 5) & 0x7F) != 0) break;
			Register result = _sli_instruction(registers[rs1], imm & 0x1F);
			write_to_register(rd, result);
		} break;
		case 0x5: // SRI
		{
			if (((imm >> 5) & 0x7F) != 0) break;
			Register result = _sri_instruction(registers[rs1], imm & 0x1F);
			write_to_register(rd, result);
		} break;
		default:
			break;
		}
	}
} // namespace Simulator