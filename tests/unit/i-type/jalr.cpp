#include "jalr.hpp"

namespace Test::Unit {
	static constexpr uint32_t JALR_X9_X24 = (24u << 15) | (9u << 7) | 0x67u;

	static bool jalr_test(uint32_t rs1_val, Simulator::Tag rs1_tag, Simulator::Tag rd_initial_tag, int32_t imm,
						  uint32_t expected_pc, uint32_t expected_rd_data, Simulator::Tag expected_rd_tag) {
		Simulator::CPU cpu;
		const uint32_t imm12 = static_cast<uint32_t>(imm) & 0xFFF;
		const uint32_t instr = (imm12 << 20) | JALR_X9_X24;

		cpu.set_register(24, rs1_val, rs1_tag);
		cpu.set_register(9, 0, rd_initial_tag);
		cpu.execute_instruction(instr);

		const auto registers = cpu.get_registers();
		const bool passed_pc = cpu.get_pc() == static_cast<int>(expected_pc);
		const bool passed_pc_modified = cpu.get_pc_modified();
		const bool passed_data = registers[9].data == expected_rd_data;
		const bool passed_tag = registers[9].tag == expected_rd_tag;
		return passed_pc && passed_pc_modified && passed_data && passed_tag;
	}

	bool JalrTester::i8_test() {
		return jalr_test(100, Simulator::Tag::SB, Simulator::Tag::SB, 12, 112, 4, Simulator::Tag::SB);
	}
	bool JalrTester::i16_test() {
		return jalr_test(1024, Simulator::Tag::SH, Simulator::Tag::SH, -8, 1016, 4, Simulator::Tag::SH);
	}
	bool JalrTester::i32_test() {
		return jalr_test(400000, Simulator::Tag::SW, Simulator::Tag::SW, 16, 400016, 4, Simulator::Tag::SW);
	}
	bool JalrTester::ui8_test() {
		return jalr_test(41, Simulator::Tag::UB, Simulator::Tag::UB, 4, 44, 4, Simulator::Tag::UB);
	}
	bool JalrTester::ui16_test() {
		return jalr_test(60000, Simulator::Tag::UH, Simulator::Tag::UH, -20, 59980, 4, Simulator::Tag::UH);
	}
	bool JalrTester::ui32_test() {
		return jalr_test(3000000000u, Simulator::Tag::UW, Simulator::Tag::UW, 64, 3000000064u, 4, Simulator::Tag::UW);
	}
} // namespace Test::Unit
