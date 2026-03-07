#include "ctub.hpp"

namespace Test::Unit {
	static constexpr uint32_t CTUB_X9 = 0b00000000000000000000010011111011;

	static bool ctub_test(Simulator::Tag a_tag, Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(9, 0, a_tag);
		cpu.execute_instruction(CTUB_X9);

		const auto registers = cpu.get_registers();

		const bool passed = registers[9].tag == expected_tag;
		return passed;
	}

	bool CtubTester::i8_test() { return ctub_test(Simulator::Tag::SB, Simulator::Tag::UB); }
	bool CtubTester::i16_test() { return ctub_test(Simulator::Tag::SH, Simulator::Tag::UB); }
	bool CtubTester::i32_test() { return ctub_test(Simulator::Tag::SW, Simulator::Tag::UB); }
	bool CtubTester::ui8_test() { return ctub_test(Simulator::Tag::UB, Simulator::Tag::UB); }
	bool CtubTester::ui16_test() { return ctub_test(Simulator::Tag::UH, Simulator::Tag::UB); }
	bool CtubTester::ui32_test() { return ctub_test(Simulator::Tag::UW, Simulator::Tag::UB); }
} // namespace Test::Unit