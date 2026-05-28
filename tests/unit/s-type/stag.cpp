#include "stag.hpp"

namespace Test::Unit {
	static constexpr uint32_t STAG_X7_32_X3 = 0b10011100011111000000100011;

	static bool stag_test(uint32_t a_data, Simulator::Tag a_tag, uint32_t b_data, Simulator::Tag b_tag,
						  uint32_t expected_memory) {
		int addr = static_cast<int64_t>(a_data) + 32;
		// stag writes 5 bytes (4 for value, 1 for tag)
		if (addr < 0 || addr + 5 > MEMORY_SIZE_BYTES) {
			return false;
		}

		Simulator::CPU cpu;
		// rs1 = x3 (base), rs2 = x7 (source) per instruction encoding
		cpu.set_register(3, a_data, a_tag);
		cpu.set_register(7, b_data, b_tag);

		cpu.execute_instruction(STAG_X7_32_X3);

		const auto &mem = cpu.get_memory();

		uint32_t stored_value = mem[static_cast<uint32_t>(addr)];
		stored_value |= (mem[static_cast<uint32_t>(addr) + 1] << 8);
		stored_value |= (mem[static_cast<uint32_t>(addr) + 2] << 16);
		stored_value |= (mem[static_cast<uint32_t>(addr) + 3] << 24);

		uint8_t stored_tag = mem[static_cast<uint32_t>(addr) + 4];
		return static_cast<uint32_t>(addr) == expected_memory && stored_tag == static_cast<uint8_t>(b_tag) &&
			   stored_value == static_cast<uint32_t>(b_data);
	}

	bool StagTester::i8_test() { return stag_test(-8, Simulator::Tag::SB, 20, Simulator::Tag::SB, 24); }
	bool StagTester::i16_test() { return stag_test(51, Simulator::Tag::SH, -1000, Simulator::Tag::SH, 83); }
	bool StagTester::i32_test() { return stag_test(91, Simulator::Tag::SW, -10000, Simulator::Tag::SW, 123); }
	bool StagTester::ui8_test() { return stag_test(4, Simulator::Tag::UB, 30, Simulator::Tag::UB, 36); }
	bool StagTester::ui16_test() { return stag_test(42, Simulator::Tag::UH, 1000, Simulator::Tag::UH, 74); }
	bool StagTester::ui32_test() { return stag_test(123, Simulator::Tag::UW, 10000, Simulator::Tag::UW, 155); }
} // namespace Test::Unit