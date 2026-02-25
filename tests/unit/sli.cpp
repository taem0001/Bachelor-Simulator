#include "sli.hpp"

namespace Test::Unit {
	static constexpr uint32_t SLI_X20_X26_11 = 0b00000000101111010001101000010011;

	template <typename A, typename ExpectedT>
	static bool sli_test(A a, Simulator::TAG tag_a, ExpectedT expected_val, Simulator::TAG expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(26, a, tag_a);
		cpu.execute_instruction(SLI_X20_X26_11);

		const auto registers = cpu.get_registers();

		const bool passed_data = std::holds_alternative<ExpectedT>(registers[20].data) &&
								 std::get<ExpectedT>(registers[20].data) == expected_val;
        const bool passed_tag = registers[20].tag == expected_tag;
        return passed_data && passed_tag;
	}

	bool SliTester::i8_test() {
        return sli_test<int8_t, int8_t>(3, Simulator::TAG::SB, 0, Simulator::TAG::SB);
    }
} // namespace Test::Unit