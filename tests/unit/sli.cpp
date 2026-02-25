#include "sli.hpp"

namespace Test::Unit {
	static constexpr uint32_t SLI_X20_X26_7 = 0b00000000011111010001101000010011;

	template <typename A, typename ExpectedT>
	static bool sli_test(A a, Simulator::TAG tag_a, ExpectedT expected_val, Simulator::TAG expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(26, a, tag_a);
		cpu.execute_instruction(SLI_X20_X26_7);

		const auto registers = cpu.get_registers();

		const bool passed_data = std::holds_alternative<ExpectedT>(registers[20].data) &&
								 std::get<ExpectedT>(registers[20].data) == expected_val;
        const bool passed_tag = registers[20].tag == expected_tag;
        return passed_data && passed_tag;
	}

	bool SliTester::i8_test() {
        return sli_test<int8_t, int8_t>(1, Simulator::TAG::SB, -128, Simulator::TAG::SB);
    }

    bool SliTester::i16_test() {
		return sli_test<int16_t, int16_t>(11372, Simulator::TAG::SH, 13824, Simulator::TAG::SH);
	}

    bool SliTester::i32_test() {
		return sli_test<int32_t, int32_t>(0b00010000111110101011001100000000, Simulator::TAG::SW, 0b01111101010110011000000000000000, Simulator::TAG::SW);
	}

    bool SliTester::ui8_test() {
		return sli_test<uint8_t, uint8_t>(1, Simulator::TAG::UB, 128, Simulator::TAG::UB);
	}

    bool SliTester::ui16_test() {
		return sli_test<uint16_t, uint16_t>(35968, Simulator::TAG::UH, 16384, Simulator::TAG::UH);
	}

    bool SliTester::ui32_test() {
		return sli_test<uint32_t, uint32_t>(0b00100011001000000000010000000000, Simulator::TAG::UW, 0b10010000000000100000000000000000, Simulator::TAG::UW);
	}
} // namespace Test::Unit