#include "../include/cpu.hpp"

namespace Simulator {
	// si-type instructions
	Register _cast_to_another_tag(const Register &r, const Tag &tag) {
		uint32_t res_data = 0;
		switch (tag) {
		case Tag::UB:
			res_data = r.data & 0xFFu; // zero-extend byte
			break;
		case Tag::SB:
			// take low 8 bits and sign-extend to 32
			res_data = static_cast<uint32_t>(static_cast<int32_t>(static_cast<int8_t>(r.data & 0xFFu)));
			break;
		case Tag::UH:
			res_data = r.data & 0xFFFFu; // zero-extend half
			break;
		case Tag::SH:
			// take low 16 bits and sign-extend to 32
			res_data = static_cast<uint32_t>(static_cast<int32_t>(static_cast<int16_t>(r.data & 0xFFFFu)));
			break;
		case Tag::UW:
			// target is unsigned 32: zero-extend from narrower sources
			switch (r.tag) {
			case Tag::UB: res_data = r.data & 0xFFu; break;
			case Tag::UH: res_data = r.data & 0xFFFFu; break;
			default: res_data = r.data; break;
			}
			break;
		case Tag::SW:
			// target is signed 32: sign-extend when source is a signed narrower type,
			// otherwise keep/zero-extend the raw bits
			switch (r.tag) {
			case Tag::SB:
				res_data = static_cast<uint32_t>(static_cast<int32_t>(static_cast<int8_t>(r.data & 0xFFu)));
				break;
			case Tag::SH:
				res_data = static_cast<uint32_t>(static_cast<int32_t>(static_cast<int16_t>(r.data & 0xFFFFu)));
				break;
			default:
				res_data = r.data; // already 32-bit or should be zero-extended
				break;
			}
			break;
		default:
			res_data = r.data;
			break;
		}

		const Tag res_tag = tag;

		return {res_data, res_tag};
	}

	void CPU::si_instruction(const char rd, const char func3) {
		switch (func3) {
		case 0x0: // CTUB
		{
			Register result = _cast_to_another_tag(registers[rd], Tag::UB);
			write_to_register(rd, result);
		} break;
		case 0x1: // CTUH
		{
			Register result = _cast_to_another_tag(registers[rd], Tag::UH);
			write_to_register(rd, result);
		} break;
		case 0x2: // CTUW
		{
			Register result = _cast_to_another_tag(registers[rd], Tag::UW);
			write_to_register(rd, result);
		} break;
		case 0x4: // CTSB
		{
			Register result = _cast_to_another_tag(registers[rd], Tag::SB);
			write_to_register(rd, result);
		} break;
		case 0x5: // CTSH
		{
			Register result = _cast_to_another_tag(registers[rd], Tag::SH);
			write_to_register(rd, result);
		} break;
		case 0x6: // CTSW
		{
			Register result = _cast_to_another_tag(registers[rd], Tag::SW);
			write_to_register(rd, result);
		} break;
		default:
			break;
		}
	}
} // namespace Simulator