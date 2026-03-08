#include "ctsh.hpp"

namespace Test::Unit {
    static constexpr uint32_t CTSH_X9 = 0b00001010000000000000010011111011;

    static bool ctsh_test(Simulator::Tag a_tag, Simulator::Tag expected_tag) {
        Simulator::CPU cpu;
        cpu.set_register(9, 0, a_tag);
        cpu.execute_instruction(CTSH_X9);

        const auto registers = cpu.get_registers();

        const bool passed = registers[9].tag == expected_tag;
        return passed;
    }

    bool CtshTester::i8_test() { return ctsh_test(Simulator::Tag::SB, Simulator::Tag::SH); }
    bool CtshTester::i16_test() { return ctsh_test(Simulator::Tag::SH, Simulator::Tag::SH); }
    bool CtshTester::i32_test() { return ctsh_test(Simulator::Tag::SW, Simulator::Tag::SH); }
    bool CtshTester::ui8_test() { return ctsh_test(Simulator::Tag::UB, Simulator::Tag::SH); }
    bool CtshTester::ui16_test() { return ctsh_test(Simulator::Tag::UH, Simulator::Tag::SH); }
    bool CtshTester::ui32_test() { return ctsh_test(Simulator::Tag::UW, Simulator::Tag::SH); }
} // namespace Test::Unit