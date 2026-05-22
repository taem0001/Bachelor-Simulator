#include "jal.hpp"

namespace Test::Unit {
	static constexpr uint32_t JAL_X9 = (9u << 7) | 0x6Fu;

	static uint32_t encode_jal_imm(int32_t offset) {
		const uint32_t imm = static_cast<uint32_t>(offset);
		return ((imm & 0x100000u) << 11) | ((imm & 0xFF000u)) | ((imm & 0x800u) << 9) | ((imm & 0x7FEu) << 20);
	}

	static bool jal_test(uint32_t rd_initial_data, Simulator::Tag rd_initial_tag, int32_t offset,
						 uint32_t expected_pc, uint32_t expected_rd_data, Simulator::Tag expected_rd_tag) {
		Simulator::CPU cpu;
		const uint32_t instr = encode_jal_imm(offset) | JAL_X9;

		cpu.set_register(9, rd_initial_data, rd_initial_tag);
		cpu.execute_instruction(instr);

		const auto registers = cpu.get_registers();
		const bool passed_pc = cpu.get_pc() == static_cast<int>(expected_pc);
		const bool passed_pc_modified = cpu.get_pc_modified();
		const bool passed_data = registers[9].data == expected_rd_data;
		const bool passed_tag = registers[9].tag == expected_rd_tag;
		return passed_pc && passed_pc_modified && passed_data && passed_tag;
	}

	bool JalTester::i8_test() { return jal_test(0, Simulator::Tag::SB, 12, 12, 4, Simulator::Tag::SW); }
	bool JalTester::i16_test() { return jal_test(1, Simulator::Tag::SH, 256, 256, 4, Simulator::Tag::SW); }
	bool JalTester::i32_test() { return jal_test(2, Simulator::Tag::SW, 1024, 1024, 4, Simulator::Tag::SW); }
	bool JalTester::ui8_test() { return jal_test(3, Simulator::Tag::UB, 40, 40, 4, Simulator::Tag::SW); }
	bool JalTester::ui16_test() { return jal_test(4, Simulator::Tag::UH, 60000, 60000, 4, Simulator::Tag::SW); }
	bool JalTester::ui32_test() { return jal_test(5, Simulator::Tag::UW, 500000, 500000, 4, Simulator::Tag::SW); }
} // namespace Test::Unit
