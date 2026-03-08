#include "ctsw.hpp"

namespace Test::Unit {
    static constexpr uint32_t CTSW_X9 = 0b00001100000000000000010011111011;

    static bool ctsw_test(Simulator::Tag a_tag, Simulator::Tag expected_tag) {
        Simulator::CPU cpu;
        cpu.set_register(9, 0, a_tag);
        cpu.execute_instruction(CTSW_X9);

        const auto registers = cpu.get_registers();

        const bool passed = registers[9].tag == expected_tag;
        return passed;
    }

    bool CtswTester::i8_test() { return ctsw_test(Simulator::Tag::SB, Simulator::Tag::SW); }
    bool CtswTester::i16_test() { return ctsw_test(Simulator::Tag::SH, Simulator::Tag::SW); }
    bool CtswTester::i32_test() { return ctsw_test(Simulator::Tag::SW, Simulator::Tag::SW); }
    bool CtswTester::ui8_test() { return ctsw_test(Simulator::Tag::UB, Simulator::Tag::SW); }
    bool CtswTester::ui16_test() { return ctsw_test(Simulator::Tag::UH, Simulator::Tag::SW); }
    bool CtswTester::ui32_test() { return ctsw_test(Simulator::Tag::UW, Simulator::Tag::SW); }
} // namespace Test::Unit