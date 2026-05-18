#include "../include/cpu.hpp"

namespace Simulator {

	// i-type instruction functions
	Register _sli_instruction(const Register &rs1, const int8_t imm) {
		const uint8_t shamt = static_cast<uint8_t>(imm) & 0x1F;
		const uint32_t res_data = rs1.data << shamt;

		return {res_data, rs1.tag};
	}

	Register _sri_instruction(const Register &rs1, const int8_t imm) {
		const uint8_t shamt = static_cast<uint8_t>(imm) & 0x1F;
		uint32_t res_data;

		// Casting is needed to arithemtically shift right
		switch (rs1.tag) {
		case Tag::SB:
		case Tag::SH:
		case Tag::SW: {
			int32_t temp_data = static_cast<int32_t>(rs1.data);
			temp_data >>= shamt;
			res_data = static_cast<uint32_t>(temp_data);
		} break;
		default:
			res_data = rs1.data >> shamt;
			break;
		}

		return {res_data, rs1.tag};
	}

	Register _addi_instruction(const Register &rs1, const int32_t imm) {
		const uint32_t imm_cast = static_cast<uint32_t>(imm);
		const uint32_t res_data = _bitwise_add(rs1.data, imm_cast);
		const Tag res_tag = (rs1.tag == Tag::UW) ? Tag::UW : Tag::SW;

		return {res_data, res_tag};
	}

	Register _slti_instruction(const Register &rs1, const int32_t imm12) {
		uint32_t res_data;
		if (is_unsigned(rs1.tag)) {
			res_data = imm12 < 0 ? 0 : 1;
			if (res_data) {
				res_data = (rs1.data < static_cast<uint32_t>(imm12) ? 1 : 0);
			}
		} else {
			const int32_t rs1_cast = static_cast<int32_t>(rs1.data);
			res_data = (rs1_cast < imm12 ? 1 : 0);
		}
		return {res_data, Tag::SW};
	}

	Register _xori_instruction(Register &rs1, uint32_t imm12) {
		uint32_t res_data = (rs1.data ^ imm12);
		Tag res_tag = rs1.tag == Tag::UW ? Tag::UW : Tag::SW;
		return {res_data, res_tag};
	}

	Register _ori_instruction(Register &rs1, uint32_t imm12) {
		uint32_t res_data = (rs1.data | imm12);
		Tag res_tag = rs1.tag == Tag::UW ? Tag::UW : Tag::SW;
		return {res_data, res_tag};
	}

	Register _andi_instruction(Register &rs1, uint32_t imm12) {
		uint32_t res_data = (rs1.data & imm12);
		Tag res_tag = rs1.tag == Tag::UW ? Tag::UW : Tag::SW;
		return {res_data, res_tag};
	}

	void CPU::i_instruction(const char rd, const char func3, const char rs1, const short imm) {
		int32_t imm12 = imm & 0xFFF;
		if (imm12 & 0x800) imm12 |= ~0xFFF;
		switch (func3) {
		case 0x0: // ADDI
		{
			Register result = _addi_instruction(registers[rs1], imm12);
			write_to_register(rd, result);
		} break;
		case 0x2: // SLTI
		{
			Register result = _slti_instruction(registers[rs1], imm12);
			write_to_register(rd, result);
		} break;
		case 0x4: // XORI
		{
			Register result = _xori_instruction(registers[rs1], imm12);
			write_to_register(rd, result);
		} break;
		case 0x6: // ORI
		{
			Register result = _ori_instruction(registers[rs1], imm12);
			write_to_register(rd, result);
		} break;
		case 0x7: // ANDI
		{
			Register result = _andi_instruction(registers[rs1], imm12);
			write_to_register(rd, result);
		} break;
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

	void CPU::jalr_instruction(const char rd, const char func3, const char rs1, const short imm) {
		if (func3 != 0x0) return;

		int32_t imm12 = static_cast<int32_t>(imm) & 0xFFF;
		if (imm12 & 0x800) imm12 |= ~0xFFF;

		const uint32_t val = _bitwise_add(static_cast<uint32_t>(pc), 4u);
		pc = static_cast<int>((registers[rs1].data + static_cast<uint32_t>(imm12)) & ~1u);
		pc_modified = true;

		Register res = {.data = val, .tag = registers[rd].tag};
		write_to_register(rd, res);
	}
} // namespace Simulator