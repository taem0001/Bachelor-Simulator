#include "slti.hpp"

namespace Test::Unit {
	static constexpr uint32_t SLTI_X9_X24 = 0b11000010010010010011;

	static bool slti_test(uint32_t a_val, Simulator::Tag a_tag, int32_t imm, uint32_t expected_val,
						  Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		const uint32_t imm12 = static_cast<uint32_t>(imm) & 0xFFF;
		const uint32_t instr = (imm12 << 20) | SLTI_X9_X24;

		cpu.set_register(24, a_val, a_tag);
		cpu.execute_instruction(instr);

		const auto registers = cpu.get_registers();

		const bool passed_data = registers[9].data == expected_val;
		const bool passed_tag = registers[9].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool SltiTester::i8_test() {
		int8_t a = -110;
		return slti_test(a, Simulator::Tag::SB, 100, 1, Simulator::Tag::UB);
	}
	bool SltiTester::i16_test() {
		int16_t a = 5000;
		return slti_test(a, Simulator::Tag::SH, -500, 0, Simulator::Tag::UB);
	}
	bool SltiTester::i32_test() {
		int32_t a = 100000;
		return slti_test(a, Simulator::Tag::SW, 1000, 0, Simulator::Tag::UB);
	}
	bool SltiTester::ui8_test() {
		uint8_t a = 40;
		return slti_test(a, Simulator::Tag::UB, 100, 1, Simulator::Tag::UB);
	}
	bool SltiTester::ui16_test() {
		uint16_t a = 40000;
		return slti_test(a, Simulator::Tag::UH, -400, 0, Simulator::Tag::UB);
	}
	bool SltiTester::ui32_test() {
		uint32_t a = 25005433;
		return slti_test(a, Simulator::Tag::UW, 1200, 0, Simulator::Tag::UB);
	}
} // namespace Test::Unit