#include "lui.hpp"

namespace Test::Unit {
	static constexpr uint32_t LUI_X9 = (9u << 7) | 0x37u;

	static bool lui_test(uint32_t rd_initial_data, Simulator::Tag rd_initial_tag, uint32_t imm20,
						 uint32_t expected_data, Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		const uint32_t instr = (imm20 << 12) | LUI_X9;

		cpu.set_register(9, rd_initial_data, rd_initial_tag);
		cpu.execute_instruction(instr);

		const auto registers = cpu.get_registers();
		const bool passed_data = registers[9].data == expected_data;
		const bool passed_tag = registers[9].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool LuiTester::i8_test() { return lui_test(0, Simulator::Tag::SB, 0x00001u, 0x00001000u, Simulator::Tag::SB); }
	bool LuiTester::i16_test() { return lui_test(1, Simulator::Tag::SH, 0x00123u, 0x00123000u, Simulator::Tag::SH); }
	bool LuiTester::i32_test() { return lui_test(2, Simulator::Tag::SW, 0x12345u, 0x12345000u, Simulator::Tag::SW); }
	bool LuiTester::ui8_test() { return lui_test(3, Simulator::Tag::UB, 0x00FF0u, 0x00FF0000u, Simulator::Tag::UB); }
	bool LuiTester::ui16_test() { return lui_test(4, Simulator::Tag::UH, 0x54321u, 0x54321000u, Simulator::Tag::UH); }
	bool LuiTester::ui32_test() { return lui_test(5, Simulator::Tag::UW, 0xABCDEu, 0xABCDE000u, Simulator::Tag::UW); }
} // namespace Test::Unit