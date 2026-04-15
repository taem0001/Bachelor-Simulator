#include "../include/cpu.hpp"

namespace Simulator {
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

	void CPU::b_instruction(const char imm4_1_11, const char func3, const char rs1, const char rs2,
							const char imm12_10_5) {
		int imm =
			((imm12_10_5 << 5) & 0x800) | ((imm4_1_11 & 0x1) << 11) | ((imm12_10_5 & 0x3F) << 5) | (imm4_1_11 >> 1);
		if (imm & 0x1000) {
			imm |= 0xffffe000;
		}

		switch (func3) {
		case 0x0: // beq
			if ((registers[rs1].data == registers[rs2].data) && (registers[rs1].tag == registers[rs2].tag)) {
				pc += imm;
				pc_modified = true;
			}
			break;
		case 0x1: // bne
			if ((registers[rs1].data != registers[rs2].data) || (registers[rs1].tag != registers[rs2].tag)) {
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