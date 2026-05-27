#include "l.hpp"

namespace Test::Unit {
    static constexpr uint32_t L_2_30_X9 = 0b00000000001001110000010010000011;

    static bool l_test(uint8_t func3_mask, Simulator::Tag a_tag, uint32_t test_memory, Simulator::Tag expected_tag, uint32_t expected_data) {
        Simulator::CPU cpu;
        uint32_t instruction = L_2_30_X9 | (func3_mask << 12);
        cpu.set_memory(0b100000u, test_memory, a_tag);
        cpu.set_register(0b01110u, 0b11110u, Simulator::Tag::UH);
        cpu.execute_instruction(instruction);

        const auto registers = cpu.get_registers();

        const bool passed = (registers[9].tag == expected_tag) && (registers[9].data == expected_data);
        return passed;
    }

    bool LTester::i8_test() { return l_test(0b000 ,Simulator::Tag::SB, -30, Simulator::Tag::SB, -30); }
    bool LTester::i16_test() { return l_test(0b001, Simulator::Tag::SH, -1000, Simulator::Tag::SH, -1000); }
    bool LTester::i32_test() { return l_test(0b010, Simulator::Tag::SW, -10000, Simulator::Tag::SW, -10000); }
    bool LTester::ui8_test() { return l_test(0b100, Simulator::Tag::UB, 30, Simulator::Tag::UB, 30); }
    bool LTester::ui16_test() { return l_test(0b101, Simulator::Tag::UH, 1000, Simulator::Tag::UH, 1000); }
    bool LTester::ui32_test() { return l_test(0b110, Simulator::Tag::UW, 10000, Simulator::Tag::UW, 10000); }
}