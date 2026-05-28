#include "ltag.hpp"

namespace Test::Unit {
	static constexpr uint32_t LTAG_x8_12_x20 = 0b110010100111010000000011;

	static bool ltag_test(Simulator::Tag tag, uint32_t test_mem, Simulator::Tag expected_tag, uint32_t expected_mem) {
		Simulator::CPU cpu;
		cpu.set_memory(64, test_mem, Simulator::Tag::SW);
		cpu.set_memory(68, static_cast<uint32_t>(tag), Simulator::Tag::UB);
		cpu.set_register(20, 52, Simulator::Tag::SW);
		cpu.execute_instruction(LTAG_x8_12_x20);

		const auto registers = cpu.get_registers();
		const bool passed = registers[8].data == expected_mem && registers[8].tag == expected_tag;
		return passed;
	}

	bool LtagTester::i8_test() { return ltag_test(Simulator::Tag::SB, 120, Simulator::Tag::SB, 120); }
	bool LtagTester::i16_test() {
		return ltag_test(Simulator::Tag::SH, static_cast<uint32_t>(-1000), Simulator::Tag::SH,
						 static_cast<uint32_t>(-1000));
	}
	bool LtagTester::i32_test() {
		return ltag_test(Simulator::Tag::SW, static_cast<uint32_t>(-10000), Simulator::Tag::SW,
						 static_cast<uint32_t>(-10000));
	}
	bool LtagTester::ui8_test() { return ltag_test(Simulator::Tag::UB, 30, Simulator::Tag::UB, 30); }
	bool LtagTester::ui16_test() { return ltag_test(Simulator::Tag::UH, 1000, Simulator::Tag::UH, 1000); }
	bool LtagTester::ui32_test() { return ltag_test(Simulator::Tag::UW, 10000, Simulator::Tag::UW, 10000); }
} // namespace Test::Unit