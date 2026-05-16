#include "../include/cpu.hpp"

namespace Simulator {

	// r-type instruction functions
	Register _add_instruction(const Register &rs1, const Register &rs2) {
		const Tag t1 = rs1.tag;
		const Tag t2 = rs2.tag;

		// Compute resulting tag
		const Tag res_tag = (t1 == Tag::UW || t2 == Tag::UW) ? Tag::UW : Tag::SW;

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
		const Tag res_tag = (t1 == Tag::UW || t2 == Tag::UW) ? Tag::UW : Tag::SW;

		// Compute subtraction
		uint32_t res_data = _bitwise_sub(rs1.data, rs2.data);

		return {res_data, res_tag};
	}

	Register _sl_instruction(const Register &rs1, const Register &rs2) {
		const uint8_t shamt = static_cast<uint8_t>(rs2.data) & 0x1F;
		const uint32_t res_data = rs1.data << shamt;

		return {res_data, rs1.tag};
	}

	Register _sr_instruction(const Register &rs1, const Register &rs2) {
		const uint8_t shamt = static_cast<uint8_t>(rs2.data) & 0x1F;
		uint32_t res_data;

		// Casting is needed to shift arithmetically right
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

	Register _slt_instruction(Register &rs1, Register &rs2) {
		uint32_t res_data;
		const bool rs1_unsigned = is_unsigned(rs1.tag);
		const bool rs2_unsigned = is_unsigned(rs2.tag);

		if (rs1_unsigned && rs2_unsigned) {
			res_data = rs1.data < rs2.data;
		} else if (!rs1_unsigned && rs2_unsigned) {
			res_data = static_cast<int32_t>(rs1.data) < 0 || rs1.data < rs2.data;
		} else if (rs1_unsigned && !rs2_unsigned) {
			res_data = static_cast<int32_t>(rs2.data) >= 0 && rs1.data < static_cast<uint32_t>(rs2.data);
		} else {
			res_data = static_cast<int32_t>(rs1.data) < static_cast<int32_t>(rs2.data);
		}

		return {res_data, Tag::UB};
	}

	Register _xor_instruction(Register &rs1, Register &rs2) {
		const uint32_t res_data = (rs1.data ^ rs2.data);
		Tag res_tag = (rs1.tag == Tag::UW || rs2.tag == Tag::UW) ? Tag::UW : Tag::SW;
		Register result = {res_data, res_tag};
		return result;
	}

	Register _or_instruction(Register &rs1, Register &rs2) {
		const uint32_t res_data = (rs1.data | rs2.data);
		Tag res_tag = (rs1.tag == Tag::UW || rs2.tag == Tag::UW) ? Tag::UW : Tag::SW;
		Register result = {res_data, res_tag};
		return result;
	}

	Register _and_instruction(Register &rs1, Register &rs2) {
		const uint32_t res_data = (rs1.data & rs2.data);
		Tag res_tag = (rs1.tag == Tag::UW || rs2.tag == Tag::UW) ? Tag::UW : Tag::SW;
		Register result = {res_data, res_tag};
		return result;
	}

	static bool _promotes_to_unsigned(const Register &reg) {
		return width_of(reg.tag) == TAG_WORD && is_unsigned(reg.tag);
	}

	static int32_t _promoted_signed_value(const Register &reg) {
		switch (width_of(reg.tag)) {
		case TAG_BYTE: {
			const uint32_t value = reg.data & 0xFFu;
			if (is_unsigned(reg.tag)) return static_cast<int32_t>(value);
			return (value & 0x80u) ? static_cast<int32_t>(value | 0xFFFFFF00u) : static_cast<int32_t>(value);
		}
		case TAG_HALF: {
			const uint32_t value = reg.data & 0xFFFFu;
			if (is_unsigned(reg.tag)) return static_cast<int32_t>(value);
			return (value & 0x8000u) ? static_cast<int32_t>(value | 0xFFFF0000u) : static_cast<int32_t>(value);
		}
		default:
			return static_cast<int32_t>(reg.data);
		}
	}

	static uint32_t _promoted_unsigned_value(const Register &reg) {
		switch (width_of(reg.tag)) {
		case TAG_BYTE:
			return static_cast<uint32_t>(_promoted_signed_value(reg));
		case TAG_HALF:
			return static_cast<uint32_t>(_promoted_signed_value(reg));
		default:
			return reg.data;
		}
	}

	Register _div_instruction(const Register &rs1, const Register &rs2) {
		const bool is_result_unsigned = _promotes_to_unsigned(rs1) || _promotes_to_unsigned(rs2);
		const Tag res_tag = is_result_unsigned ? Tag::UW : Tag::SW;

		if (rs2.data == 0) {
			return {0xFFFFFFFFu, res_tag};
		}

		if (is_result_unsigned) {
			const uint32_t dividend = _promoted_unsigned_value(rs1);
			const uint32_t divisor = _promoted_unsigned_value(rs2);
			return {dividend / divisor, res_tag};
		}

		const int32_t dividend = _promoted_signed_value(rs1);
		const int32_t divisor = _promoted_signed_value(rs2);
		if (dividend == static_cast<int32_t>(0x80000000u) && divisor == -1) {
			return {static_cast<uint32_t>(dividend), res_tag};
		}
		return {static_cast<uint32_t>(dividend / divisor), res_tag};
	}

	Register _rem_instruction(const Register &rs1, const Register &rs2) {
		const bool is_result_unsigned = _promotes_to_unsigned(rs1) || _promotes_to_unsigned(rs2);
		const Tag res_tag = is_result_unsigned ? Tag::UW : Tag::SW;

		if (rs2.data == 0) {
			return {_promoted_unsigned_value(rs1), res_tag};
		}

		if (is_result_unsigned) {
			const uint32_t dividend = _promoted_unsigned_value(rs1);
			const uint32_t divisor = _promoted_unsigned_value(rs2);
			return {dividend % divisor, res_tag};
		}

		const int32_t dividend = _promoted_signed_value(rs1);
		const int32_t divisor = _promoted_signed_value(rs2);
		if (dividend == static_cast<int32_t>(0x80000000u) && divisor == -1) {
			return {0u, res_tag};
		}
		return {static_cast<uint32_t>(dividend % divisor), res_tag};
	}

	Register _mul_instruction(Register &rs1, Register &rs2) {
		const uint32_t res_data = (rs1.data * rs2.data);
		Tag res_tag = (rs1.tag == Tag::UW || rs2.tag == Tag::UW) ? Tag::UW : Tag::SW;
		Register result = {res_data, res_tag};
		return result;
	}

	Register _mulh_instruction(Register &rs1, Register &rs2) {
		uint64_t data;
		if(!is_unsigned(rs1.tag) || !is_unsigned(rs2.tag)) {
			if(is_unsigned(rs1.tag)) {
				data = ((int64_t) rs1.data * (int64_t)(int32_t)rs2.data);
			} else if(is_unsigned(rs2.tag)) {
				data = ((int64_t)(int32_t)rs1.data * (int64_t) rs2.data);
			} else {
				data = ((int64_t)(int32_t)rs1.data * (int64_t)(int32_t)rs2.data);
			}
		} else {
			data = ((uint64_t) rs1.data * (uint64_t) rs2.data);
		}
		const uint32_t res_data = (data >> 32);
		Tag res_tag = (rs1.tag == Tag::UW || rs2.tag == Tag::UW) ? Tag::UW : Tag::SW;
		Register result = {res_data, res_tag};
		return result;
	}

    void CPU::r_instruction(const char rd, const char func3, const char rs1, const char rs2, const char func7) {
		switch (func3) {
		case 0x0: // ADD
		{
			Register result;
			if(func7 == 0b0000001) {
				result = _mul_instruction(registers[rs1], registers[rs2]);
			} else {
				result = _add_instruction(registers[rs1], registers[rs2]);
			}
			write_to_register(rd, result);
		} break;
		case 0x1: // SUB
		{
			Register result;
			if(func7 == 0b0000001) {
				result = _mulh_instruction(registers[rs1], registers[rs2]);
			} else {
				result = _sub_instruction(registers[rs1], registers[rs2]);
			}
			write_to_register(rd, result);
		} break;
		case 0x2: // SLT
		{
			Register result = _slt_instruction(registers[rs1], registers[rs2]);
			write_to_register(rd, result);
		} break;
		case 0x5: // SL or SR
		{
			if (func7 == 0b0100000) { // SR
				Register result = _sr_instruction(registers[rs1], registers[rs2]);
				write_to_register(rd, result);
			}
			if (func7 == 0) { // SL
				Register result = _sl_instruction(registers[rs1], registers[rs2]);
				write_to_register(rd, result);
			}
		} break;
		case 0x4: // XOR
		{
			if (func7 == 0x1) {
				Register result = _div_instruction(registers[rs1], registers[rs2]);
				write_to_register(rd, result);
			} else {
				Register result = _xor_instruction(registers[rs1], registers[rs2]);
				write_to_register(rd, result);
			}
		} break;
		case 0x6: // OR
		{
			if (func7 == 0x1) {
				Register result = _rem_instruction(registers[rs1], registers[rs2]);
				write_to_register(rd, result);
			} else {
				Register result = _or_instruction(registers[rs1], registers[rs2]);
				write_to_register(rd, result);
			}
		} break;
		case 0x7: // AND
		{
			Register result = _and_instruction(registers[rs1], registers[rs2]);
			write_to_register(rd, result);
		} break;
		default:
			break;
		}
	}
} // namespace Simulator