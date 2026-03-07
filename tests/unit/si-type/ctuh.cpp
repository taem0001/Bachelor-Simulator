#include "ctuh.hpp"

namespace Test::Unit {
	static constexpr uint32_t CTUH_X9 = 0b00000010000000000000010011111011;

	static bool ctuh_test(Simulator::Tag a_tag, Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(9, 0, a_tag);
		cpu.execute_instruction(CTUH_X9);

		const auto registers = cpu.get_registers();

		const bool passed = registers[9].tag == expected_tag;
		return passed;
	}

	bool CtuhTester::i8_test() { return ctuh_test(Simulator::Tag::SB, Simulator::Tag::UH); }
	bool CtuhTester::i16_test() { return ctuh_test(Simulator::Tag::SH, Simulator::Tag::UH); }
	bool CtuhTester::i32_test() { return ctuh_test(Simulator::Tag::SW, Simulator::Tag::UH); }
	bool CtuhTester::ui8_test() { return ctuh_test(Simulator::Tag::UB, Simulator::Tag::UH); }
	bool CtuhTester::ui16_test() { return ctuh_test(Simulator::Tag::UH, Simulator::Tag::UH); }
	bool CtuhTester::ui32_test() { return ctuh_test(Simulator::Tag::UW, Simulator::Tag::UH); }
} // namespace Test::Unit