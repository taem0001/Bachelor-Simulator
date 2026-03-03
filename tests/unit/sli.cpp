#include "sli.hpp"

namespace Test::Unit {
	static constexpr uint32_t SLI_X5_X7_5 = 0b00000000010100111001001010010011;

	static bool sli_test(uint32_t a_val, Simulator::Tag a_tag, uint32_t expected_val, Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(7, a_val, a_tag);
		cpu.execute_instruction(SLI_X5_X7_5);

		const auto registers = cpu.get_registers();

		const bool passed_data = registers[5].data == expected_val;
		const bool passed_tag = registers[5].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool SliTester::i8_test() {
		int8_t a = static_cast<int8_t>(0b11001001);
		uint32_t in = static_cast<uint32_t>(static_cast<uint8_t>(a));
		return sli_test(in, Simulator::Tag::SB, 0b1100100100000, Simulator::Tag::SB);
	}
	bool SliTester::i16_test() {
		int16_t a = static_cast<int16_t>(0b1101001110110010);
		uint32_t in = static_cast<uint32_t>(static_cast<uint16_t>(a));
		return sli_test(in, Simulator::Tag::SH, 0b110100111011001000000, Simulator::Tag::SH);
	}
	bool SliTester::i32_test() {
		int32_t a = static_cast<int32_t>(0xD3B2D3B2u);
		return sli_test(static_cast<uint32_t>(a), Simulator::Tag::SW, 0x765A7640u, Simulator::Tag::SW);
	}
	bool SliTester::ui8_test() {
		uint8_t a = 0b10001011;
		return sli_test(a, Simulator::Tag::UB, 0b1000101100000, Simulator::Tag::UB);
	}
	bool SliTester::ui16_test() {
		uint16_t a = 0b1100001010111010;
		return sli_test(a, Simulator::Tag::UH, 0b110000101011101000000, Simulator::Tag::UH);
	}
	bool SliTester::ui32_test() {
		uint32_t a = 0b11010011101100101101001110110010;
		return sli_test(a, Simulator::Tag::UW, 0x765A7640u, Simulator::Tag::UW);
	}
} // namespace Test::Unit