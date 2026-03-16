#include "ori.hpp"

namespace Test::Unit {
	static constexpr uint32_t ORI_X9_24 = 0b11000110010010010011;

	static bool ori_test(uint32_t a_val, Simulator::Tag a_tag, int32_t imm, uint32_t expected_val,
						  Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		const uint32_t imm12 = static_cast<uint32_t>(imm) & 0xFFF;
		const uint32_t instr = (imm12 << 20) | ORI_X9_24;

		cpu.set_register(24, a_val, a_tag);
		cpu.execute_instruction(instr);

		const auto registers = cpu.get_registers();

		const bool passed_data = registers[9].data == expected_val;
		const bool passed_tag = registers[9].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool OriTester::i8_test() {
		int8_t a = -110;
		return ori_test(a, Simulator::Tag::SB, 100, -10, Simulator::Tag::SB);
	}
	bool OriTester::i16_test() {
		int16_t a = 5000;
		return ori_test(a, Simulator::Tag::SH, -500, -116, Simulator::Tag::SH);
	}
	bool OriTester::i32_test() {
		int32_t a = 100000;
		return ori_test(a, Simulator::Tag::SW, 1000, 100328, Simulator::Tag::SW);
	}
	bool OriTester::ui8_test() {
		uint8_t a = 40;
		return ori_test(a, Simulator::Tag::UB, 100, 108, Simulator::Tag::UB);
	}
	bool OriTester::ui16_test() {
		uint16_t a = 40000;
		return ori_test(a, Simulator::Tag::UH, -400, 65136, Simulator::Tag::UH);
	}
	bool OriTester::ui32_test() {
		uint32_t a = 25005433;
		return ori_test(a, Simulator::Tag::UW, 1200, 25005561, Simulator::Tag::UW);
	}
} // namespace Test::Unit