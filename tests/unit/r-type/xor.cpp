#include "xor.hpp"

namespace Test::Unit {
    static constexpr uint32_t XOR_X7_X5_X6 = 0b00000000011000101100001110110011;

    static bool xor_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
                         uint32_t expected_val, Simulator::Tag expected_tag) {
        Simulator::CPU cpu;
        cpu.set_register(5, a_val, a_tag);
        cpu.set_register(6, b_val, b_tag);
        cpu.execute_instruction(XOR_X7_X5_X6);

        const auto registers = cpu.get_registers();

        const bool passed_data = registers[7].data == expected_val;
        const bool passed_tag = registers[7].tag == expected_tag;
        return passed_data && passed_tag;
    }

    bool XorTester::i8_i8_test() {
        int8_t a = 32;
        int8_t b = 45;
        return xor_test(a, b, Simulator::Tag::SB, Simulator::Tag::SB, 13, Simulator::Tag::SW);
    }
    bool XorTester::i16_i16_test() {
        int16_t a = 23065;
        int16_t b = -1203;
        return xor_test(a, b, Simulator::Tag::SH, Simulator::Tag::SH, 4294943060, Simulator::Tag::SW);
    }
    bool XorTester::i32_i32_test() {
        int32_t a = 1000000000;
        int32_t b = -123456789;
        return xor_test(a, b, Simulator::Tag::SW, Simulator::Tag::SW, 3275684075, Simulator::Tag::SW);
    }
    bool XorTester::ui8_ui8_test() {
        uint8_t a = 200;
        uint8_t b = 55;
        return xor_test(a, b, Simulator::Tag::UB, Simulator::Tag::UB, 255, Simulator::Tag::SW);
    }
    bool XorTester::ui16_ui16_test() {
        uint16_t a = 60000;
        uint16_t b = 1234;
        return xor_test(a, b, Simulator::Tag::UH, Simulator::Tag::UH, 61106, Simulator::Tag::SW);
    }
    bool XorTester::ui32_ui32_test() {
        uint32_t a = 4000000000;
        uint32_t b = 123456789;
        return xor_test(a, b, Simulator::Tag::UW, Simulator::Tag::UW, 3912295701, Simulator::Tag::UW);
    }
    bool XorTester::i8_i16_test() {
        int8_t a = -12;
        int16_t b = 3000;
        return xor_test(a, b, Simulator::Tag::SB, Simulator::Tag::SH, 4294964300, Simulator::Tag::SW);
    }
    bool XorTester::i8_i32_test() {
        int8_t a = 100;
        int32_t b = -100000;
        return xor_test(a, b, Simulator::Tag::SB, Simulator::Tag::SW, 4294867204, Simulator::Tag::SW);
    }
    bool XorTester::i8_ui8_test() {
        int8_t a = -1;
        uint8_t b = 200;
        return xor_test(a, b, Simulator::Tag::SB, Simulator::Tag::UB, 4294967095, Simulator::Tag::SW);
    }
    bool XorTester::i8_ui16_test() {
        int8_t a = 10;
        uint16_t b = 65000;
        return xor_test(a, b, Simulator::Tag::SB, Simulator::Tag::UH, 64994, Simulator::Tag::SW);
    }
    bool XorTester::i8_ui32_test() {
        int8_t a = 1;
        uint32_t b = 3000000000;
        return xor_test(a, b, Simulator::Tag::SB, Simulator::Tag::UW, 3000000001, Simulator::Tag::UW);
    }
    bool XorTester::i16_i8_test() {
        int16_t a = -1234;
        int8_t b = 12;
        return xor_test(a, b, Simulator::Tag::SH, Simulator::Tag::SB, 4294966050, Simulator::Tag::SW);
    }
    bool XorTester::i16_i32_test() {
        int16_t a = 12345;
        int32_t b = 200000;
        return xor_test(a, b, Simulator::Tag::SH, Simulator::Tag::SW, 212345, Simulator::Tag::SW);
    }
    bool XorTester::i16_ui8_test() {
        int16_t a = -10;
        uint8_t b = 250;
        return xor_test(a, b, Simulator::Tag::SH, Simulator::Tag::UB, 4294967052, Simulator::Tag::SW);
    }
    bool XorTester::i16_ui16_test() {
        int16_t a = -200;
        uint16_t b = 65000;
        return xor_test(a, b, Simulator::Tag::SH, Simulator::Tag::UH, 4294902480, Simulator::Tag::SW);
    }
    bool XorTester::i16_ui32_test() {
        int16_t a = 7;
        uint32_t b = 4000000000;
        return xor_test(a, b, Simulator::Tag::SH, Simulator::Tag::UW, 4000000007, Simulator::Tag::UW);
    }
    bool XorTester::i32_i8_test() {
        int32_t a = -100000;
        int8_t b = 1;
        return xor_test(a, b, Simulator::Tag::SW, Simulator::Tag::SB, 4294867297, Simulator::Tag::SW);
    }
    bool XorTester::i32_i16_test() {
        int32_t a = 500000;
        int16_t b = -123;
        return xor_test(a, b, Simulator::Tag::SW, Simulator::Tag::SH, 4294467237, Simulator::Tag::SW);
    }
    bool XorTester::i32_ui8_test() {
        int32_t a = -5;
        uint8_t b = 10;
        return xor_test(a, b, Simulator::Tag::SW, Simulator::Tag::UB, 4294967281, Simulator::Tag::SW);
    }
    bool XorTester::i32_ui16_test() {
        int32_t a = -1000;
        uint16_t b = 60000;
        return xor_test(a, b, Simulator::Tag::SW, Simulator::Tag::UH, 4294907512, Simulator::Tag::SW);
    }
    bool XorTester::i32_ui32_test() {
        int32_t a = -1;
        uint32_t b = 4000000000;
        return xor_test(a, b, Simulator::Tag::SW, Simulator::Tag::UW, 294967295, Simulator::Tag::UW);
    }
    bool XorTester::ui8_i8_test() {
        uint8_t a = 200;
        int8_t b = -1;
        return xor_test(a, b, Simulator::Tag::UB, Simulator::Tag::SB, 4294967095, Simulator::Tag::SW);
    }
    bool XorTester::ui8_i16_test() {
        uint8_t a = 250;
        int16_t b = -1000;
        return xor_test(a, b, Simulator::Tag::UB, Simulator::Tag::SH, 4294966498, Simulator::Tag::SW);
    }
    bool XorTester::ui8_i32_test() {
        uint8_t a = 10;
        int32_t b = -100000;
        return xor_test(a, b, Simulator::Tag::UB, Simulator::Tag::SW, 4294867306, Simulator::Tag::SW);
    }
    bool XorTester::ui8_ui16_test() {
        uint8_t a = 200;
        uint16_t b = 1000;
        return xor_test(a, b, Simulator::Tag::UB, Simulator::Tag::UH, 800, Simulator::Tag::SW);
    }
    bool XorTester::ui8_ui32_test() {
        uint8_t a = 1;
        uint32_t b = 3000000000;
        return xor_test(a, b, Simulator::Tag::UB, Simulator::Tag::UW, 3000000001, Simulator::Tag::UW);
    }
    bool XorTester::ui16_i8_test() {
        uint16_t a = 65000;
        int8_t b = 10;
        return xor_test(a, b, Simulator::Tag::UH, Simulator::Tag::SB, 64994, Simulator::Tag::SW);
    }
    bool XorTester::ui16_i16_test() {
        uint16_t a = 60000;
        int16_t b = -200;
        return xor_test(a, b, Simulator::Tag::UH, Simulator::Tag::SH, 4294907224, Simulator::Tag::SW);
    }
    bool XorTester::ui16_i32_test() {
        uint16_t a = 65000;
        int32_t b = -1000;
        return xor_test(a, b, Simulator::Tag::UH, Simulator::Tag::SW, 4294902256, Simulator::Tag::SW);
    }
    bool XorTester::ui16_ui8_test() {
        uint16_t a = 1000;
        uint8_t b = 200;
        return xor_test(a, b, Simulator::Tag::UH, Simulator::Tag::UB, 800, Simulator::Tag::SW);
    }
    bool XorTester::ui16_ui32_test() {
        uint16_t a = 65000;
        uint32_t b = 3000000000;
        return xor_test(a, b, Simulator::Tag::UH, Simulator::Tag::UW, 3000017896, Simulator::Tag::UW);
    }
    bool XorTester::ui32_i8_test() {
        uint32_t a = 3000000000;
        int8_t b = 1;
        return xor_test(a, b, Simulator::Tag::UW, Simulator::Tag::SB, 3000000001, Simulator::Tag::UW);
    }
    bool XorTester::ui32_i16_test() {
        uint32_t a = 3000000000;
        int16_t b = 7;
        return xor_test(a, b, Simulator::Tag::UW, Simulator::Tag::SH, 3000000007, Simulator::Tag::UW);
    }
    bool XorTester::ui32_i32_test() {
        uint32_t a = 3000000000;
        int32_t b = -1;
        return xor_test(a, b, Simulator::Tag::UW, Simulator::Tag::SW, 1294967295, Simulator::Tag::UW);
    }
    bool XorTester::ui32_ui8_test() {
        uint32_t a = 3000000000;
        uint8_t b = 2;
        return xor_test(a, b, Simulator::Tag::UW, Simulator::Tag::UB, 3000000002, Simulator::Tag::UW);
    }
    bool XorTester::ui32_ui16_test() {
        uint32_t a = 3000000000;
        uint16_t b = 60000;
        return xor_test(a, b, Simulator::Tag::UW, Simulator::Tag::UH, 3000022112, Simulator::Tag::UW);
    }
} // namespace Test::Unit