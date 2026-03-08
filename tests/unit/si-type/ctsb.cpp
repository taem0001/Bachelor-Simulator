#include "ctsb.hpp"

namespace Test::Unit {
    static constexpr uint32_t CTSB_X9 = 0b00001000000000000000010011111011;

    static bool ctsb_test(Simulator::Tag a_tag, Simulator::Tag expected_tag) {
        Simulator::CPU cpu;
        cpu.set_register(9, 0, a_tag);
        cpu.execute_instruction(CTSB_X9);

        const auto registers = cpu.get_registers();

        const bool passed = registers[9].tag == expected_tag;
        return passed;
    }

    bool CtsbTester::i8_test() { return ctsb_test(Simulator::Tag::SB, Simulator::Tag::SB); }
    bool CtsbTester::i16_test() { return ctsb_test(Simulator::Tag::SH, Simulator::Tag::SB); }
    bool CtsbTester::i32_test() { return ctsb_test(Simulator::Tag::SW, Simulator::Tag::SB); }
    bool CtsbTester::ui8_test() { return ctsb_test(Simulator::Tag::UB, Simulator::Tag::SB); }
    bool CtsbTester::ui16_test() { return ctsb_test(Simulator::Tag::UH, Simulator::Tag::SB); }
    bool CtsbTester::ui32_test() { return ctsb_test(Simulator::Tag::UW, Simulator::Tag::SB); }
}