#include "sri.hpp"

namespace Test::Unit {
	static constexpr uint32_t SRI_X30_X3_6 = 0b00000000011000011101111100010011;

	template <typename A, typename ExpectedT>
	static bool sri_test(A a, Simulator::TAG tag_a, ExpectedT expected_val, Simulator::TAG expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(3, a, tag_a);
		cpu.execute_instruction(SRI_X30_X3_6);

		const auto registers = cpu.get_registers();

		const bool passed_data = std::holds_alternative<ExpectedT>(registers[30].data) &&
								 std::get<ExpectedT>(registers[30].data) == expected_val;
		const bool passed_tag = registers[30].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool SriTester::i8_test() {
        return sri_test<int8_t, int8_t>(-128, Simulator::TAG::SB, -2, Simulator::TAG::SB);
    }

	bool SriTester::i16_test() {
        return sri_test<int16_t, int16_t>(28917, Simulator::TAG::SH, 451, Simulator::TAG::SH);
    }

    bool SriTester::i32_test() {
        return sri_test<int32_t, int32_t>(-233577552, Simulator::TAG::SW, -3649650, Simulator::TAG::SW);
    }

    bool SriTester::ui8_test() {
        return sri_test<uint8_t, uint8_t>(192, Simulator::TAG::UB, 3, Simulator::TAG::UB);
    }

    bool SriTester::ui16_test() {
        return sri_test<uint16_t, uint16_t>(50947, Simulator::TAG::UH, 796, Simulator::TAG::UH);
    }

    bool SriTester::ui32_test() {
        return sri_test<uint32_t, uint32_t>(4078699292, Simulator::TAG::UW, 63729676, Simulator::TAG::UW);
    }
} // namespace Test::Unit