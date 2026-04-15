#include "auipc.hpp"

namespace Test::Unit {
	static constexpr uint32_t AUIPC_X9 = (9u << 7) | 0x17u;

	static uint32_t encode_jal_imm(int32_t offset) {
		const uint32_t imm = static_cast<uint32_t>(offset);
		return ((imm & 0x100000u) << 11) | ((imm & 0xFF000u)) | ((imm & 0x800u) << 9) | ((imm & 0x7FEu) << 20);
	}

	static bool auipc_test(uint32_t rd_initial_data, Simulator::Tag rd_initial_tag, int32_t pc_offset, uint32_t imm20,
						   uint32_t expected_data, Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		const uint32_t jal_x0 = encode_jal_imm(pc_offset) | 0x6Fu;
		const uint32_t auipc_x9 = (imm20 << 12) | AUIPC_X9;

		cpu.execute_instruction(jal_x0);
		cpu.set_register(9, rd_initial_data, rd_initial_tag);
		cpu.execute_instruction(auipc_x9);

		const auto registers = cpu.get_registers();
		const bool passed_data = registers[9].data == expected_data;
		const bool passed_tag = registers[9].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool AuipcTester::i8_test() {
		return auipc_test(0, Simulator::Tag::SB, 12, 0x00001u, 0x0000100Cu, Simulator::Tag::SB);
	}
	bool AuipcTester::i16_test() {
		return auipc_test(1, Simulator::Tag::SH, 16, 0x00123u, 0x00123010u, Simulator::Tag::SH);
	}
	bool AuipcTester::i32_test() {
		return auipc_test(2, Simulator::Tag::SW, 20, 0x12345u, 0x12345014u, Simulator::Tag::SW);
	}
	bool AuipcTester::ui8_test() {
		return auipc_test(3, Simulator::Tag::UB, 24, 0x00FF0u, 0x00FF0018u, Simulator::Tag::UB);
	}
	bool AuipcTester::ui16_test() {
		return auipc_test(4, Simulator::Tag::UH, 28, 0x54321u, 0x5432101Cu, Simulator::Tag::UH);
	}
	bool AuipcTester::ui32_test() {
		return auipc_test(5, Simulator::Tag::UW, 32, 0xABCDEu, 0xABCDE020u, Simulator::Tag::UW);
	}
} // namespace Test::Unit