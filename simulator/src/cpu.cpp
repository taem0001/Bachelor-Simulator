#include "../include/cpu.hpp"

namespace Simulator {
	CPU::CPU() : pc(0) { registers.fill({0, TAG::SW}); }

	void CPU::execute_instruction(int instruction) {
		char opcode = instruction & 0x7F;

		switch (opcode) {
		case 0x33: {
			char rd = (instruction >> OPCODE_LEN) & 0x1F;
			char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
			char rs1 =
				(instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
			char rs2 = (instruction >>
						(OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN)) &
					   0x1F;

			r_instruction(rd, func3, rs1, rs2);
		} break;
		default:
			break;
		};

		pc += 4;
	}

	void _add_instruction(Register &rd, Register &rs1, Register &rs2) {
		const auto add_visitor = overloaded{
			[](auto a, auto b)
				requires(std::is_integral_v<std::decay_t<decltype(a)>> &&
						 std::is_integral_v<std::decay_t<decltype(b)>>)
			{
				using A = std::decay_t<decltype(a)>;
				using B = std::decay_t<decltype(b)>;
				using R = std::common_type_t<A, B>;
				return Data{static_cast<R>(a) + static_cast<R>(b)};
			}};

		const auto tag_visitor = overloaded{
			[](int8_t) { return TAG::SB; },	  [](int16_t) { return TAG::SH; },
			[](int32_t) { return TAG::SW; },  [](uint8_t) { return TAG::UB; },
			[](uint16_t) { return TAG::UH; }, [](uint32_t) { return TAG::UW; },
		};

		const Data add_result = std::visit(add_visitor, rs1.data, rs2.data);
		const TAG tag_result = std::visit(tag_visitor, add_result);

		rd = {add_result, tag_result};
	}

	void CPU::r_instruction(const char rd, const char func3, const char rs1,
							const char rs2) {
		switch (func3) {
		case 0x2: // SHIFT
			break;
		case 0x0: // ADD
			_add_instruction(registers[rd], registers[rs1], registers[rs2]);
			break;
		case 0x1: // SUB
			break;
		default:
			break;
		}
	}
} // namespace Simulator