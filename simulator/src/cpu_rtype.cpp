#include "../include/cpu.hpp"
#include "cpu_shared.cpp"



namespace Simulator {

	// r-type instruction functions
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
		if(is_unsigned(rs1.tag) && is_unsigned(rs2.tag)) {
			res_data = rs1.data < rs2.data ? 1 : 0;
		} else if(!is_unsigned(rs1.tag) && is_unsigned(rs2.tag)) {
			res_data = static_cast<int32_t> (rs1.data) < rs2.data ? 1 : 0;
		} else if(is_unsigned(rs1.tag) && !is_unsigned(rs2.tag)) {
			res_data = rs1.data < static_cast<int32_t> (rs2.data) ? 1 : 0;
		} else if(!is_unsigned(rs1.tag) && !is_unsigned(rs2.tag)) {
			res_data = static_cast<int32_t> (rs1.data) < static_cast<int32_t> (rs2.data) ? 1 : 0;
		}
		return {res_data, Tag::UB};
	}

    void CPU::r_instruction(const char rd, const char func3, const char rs1, const char rs2, const char func7) {
		switch (func3) {
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
		case 0x2: //SLT
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
			const uint32_t res_data = (registers[rs1].data ^ registers[rs2].data);
			Tag largest_tag = width_of(registers[rs1].tag) < width_of(registers[rs2].tag) ? registers[rs1].tag : registers[rs2].tag; 
			Register result = {res_data, largest_tag};
			result.mask_by_tag();
			write_to_register(rd, result);
		} break;
		case 0x6: // OR
		{
			const uint32_t res_data = (registers[rs1].data | registers[rs2].data);
			Tag largest_tag = width_of(registers[rs1].tag) < width_of(registers[rs2].tag) ? registers[rs1].tag : registers[rs2].tag; 
			Register result = {res_data, largest_tag};
			result.mask_by_tag();
			write_to_register(rd, result);
		} break;
		case 0x7: // AND
		{
			const uint32_t res_data = (registers[rs1].data & registers[rs2].data);
			Tag largest_tag = width_of(registers[rs1].tag) < width_of(registers[rs2].tag) ? registers[rs1].tag : registers[rs2].tag; 
			Register result = {res_data, largest_tag};
			result.mask_by_tag();
			write_to_register(rd, result);
		} break;
		default:
			break;
		}
	}
}