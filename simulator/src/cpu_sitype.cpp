#include "../include/cpu.hpp"

namespace Simulator {
    // si-type instructions
	Register _cast_to_another_tag(const Register &r, const Tag &tag) {
		const uint32_t res_data = r.data;
		const Tag res_tag = tag;

		return {res_data, res_tag};
	}

	void CPU::si_instruction(const char rd, const char func7) {
		switch (func7) {
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
}