#include "../include/cpu.hpp"

namespace Simulator {
	static uint32_t normalized_value(const Register &reg) {
		switch (width_of(reg.tag)) {
		case 0x0: {
			const uint32_t value = reg.data & 0xFFu;
			if (is_unsigned(reg.tag)) return value;
			return (value & 0x80u) ? (value | 0xFFFFFF00u) : value;
		}
		case 0x1: {
			const uint32_t value = reg.data & 0xFFFFu;
			if (is_unsigned(reg.tag)) return value;
			return (value & 0x8000u) ? (value | 0xFFFF0000u) : value;
		}
		default:
			return reg.data;
		}
	}

	int _blt_instruction(const Register &rs1, const Register &rs2, const int imm, bool &modified) {
		const bool rs1_unsigned = is_unsigned(rs1.tag);
		const bool rs2_unsigned = is_unsigned(rs2.tag);

		if (rs1_unsigned && rs2_unsigned) {
			if (rs1.data < rs2.data) {
				modified = true;
				return imm;
			}
			return 0;
		}

		if (!rs1_unsigned && !rs2_unsigned) {
			int32_t rs1_signed = static_cast<int32_t>(rs1.data);
			int32_t rs2_signed = static_cast<int32_t>(rs2.data);
			if (rs1_signed < rs2_signed) {
				modified = true;
				return imm;
			}
			return 0;
		}

		if (rs1_unsigned && !rs2_unsigned) {
			int32_t rs2_signed = static_cast<int32_t>(rs2.data);
			if (rs2_signed < 0) return 0;
			if (rs1.data < static_cast<uint32_t>(rs2_signed)) {
				modified = true;
				return imm;
			}
			return 0;
		}

		int32_t rs1_signed = static_cast<int32_t>(rs1.data);
		if (rs1_signed < 0) {
			modified = true;
			return imm;
		}
		if (static_cast<uint32_t>(rs1_signed) < rs2.data) {
			modified = true;
			return imm;
		}
		return 0;
	}

	int _bge_instruction(const Register &rs1, const Register &rs2, const int imm, bool &modified) {
		const bool rs1_unsigned = is_unsigned(rs1.tag);
		const bool rs2_unsgined = is_unsigned(rs2.tag);

		if (rs1_unsigned && rs2_unsgined) {
			if (rs1.data >= rs2.data) {
				modified = true;
				return imm;
			}
			return 0;
		}

		if (!rs1_unsigned && !rs2_unsgined) {
			int32_t rs1_signed = static_cast<int32_t>(rs1.data);
			int32_t rs2_signed = static_cast<int32_t>(rs2.data);
			if (rs1_signed >= rs2_signed) {
				modified = true;
				return imm;
			}
			return 0;
		}

		if (rs1_unsigned && !rs2_unsgined) {
			int32_t rs2_signed = static_cast<int32_t>(rs2.data);
			if (rs2_signed < 0) {
				modified = true;
				return imm;
			}
			if (rs1.data >= static_cast<uint32_t>(rs2_signed)) {
				modified = true;
				return imm;
			}
			return 0;
		}

		int32_t rs1_signed = static_cast<int32_t>(rs1.data);
		if (rs1_signed < 0) return 0;
		if (static_cast<uint32_t>(rs1_signed) >= rs2.data) {
			modified = true;
			return imm;
		}
		return 0;
	}

	void CPU::b_instruction(const char func3, const char rs1, const char rs2, int imm) {
		if (imm & 0x1000) {
			imm |= 0xffffe000;
		}

		switch (func3) {
		case 0x0: // beq
			if (normalized_value(registers[rs1]) == normalized_value(registers[rs2])) {
				pc += imm;
				pc_modified = true;
			}
			break;
		case 0x1: // bne
			if (normalized_value(registers[rs1]) != normalized_value(registers[rs2])) {
				pc += imm;
				pc_modified = true;
			}
			break;
		case 0x4: // blt
			pc += _blt_instruction(registers[rs1], registers[rs2], imm, pc_modified);
			break;
		case 0x5: // bge
			pc += _bge_instruction(registers[rs1], registers[rs2], imm, pc_modified);
			break;
		default:
			break;
		}
	}
} // namespace Simulator