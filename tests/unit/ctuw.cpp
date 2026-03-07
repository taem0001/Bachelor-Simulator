#include "ctuw.hpp"

namespace Test::Unit {
	static constexpr uint32_t CTUW_X9 = 0b00000100000000000000010011111011;

	static bool ctuw_test(Simulator::Tag a_tag, Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(9, 0, a_tag);
		cpu.execute_instruction(CTUW_X9);

		const auto registers = cpu.get_registers();

		const bool passed = registers[9].tag == expected_tag;
		return passed;
	}

	bool CtuwTester::i8_test() { return ctuw_test(Simulator::Tag::SB, Simulator::Tag::UW); }
	bool CtuwTester::i16_test() { return ctuw_test(Simulator::Tag::SH, Simulator::Tag::UW); }
	bool CtuwTester::i32_test() { return ctuw_test(Simulator::Tag::SW, Simulator::Tag::UW); }
	bool CtuwTester::ui8_test() { return ctuw_test(Simulator::Tag::UB, Simulator::Tag::UW); }
	bool CtuwTester::ui16_test() { return ctuw_test(Simulator::Tag::UH, Simulator::Tag::UW); }
	bool CtuwTester::ui32_test() { return ctuw_test(Simulator::Tag::UW, Simulator::Tag::UW); }
} // namespace Test::Unit