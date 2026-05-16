#include "mul.hpp"

namespace Test::Unit {
    static constexpr uint32_t MUL_X7_X5_X6 = 0b00000010011000101000001110110011;

    static bool mul_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
                         uint32_t expected_val, Simulator::Tag expected_tag) {
        Simulator::CPU cpu;
        cpu.set_register(5, a_val, a_tag);
        cpu.set_register(6, b_val, b_tag);
        cpu.execute_instruction(MUL_X7_X5_X6);

        const auto registers = cpu.get_registers();

        const bool passed_data = registers[7].data == expected_val;
        const bool passed_tag = registers[7].tag == expected_tag;
        return passed_data && passed_tag;
    }

    bool MulTester::i8_i8_test() {
        int8_t a = 32;
        int8_t b = 45;
        return mul_test(a, b, Simulator::Tag::SB, Simulator::Tag::SB, 1440, Simulator::Tag::SW);
    }

    bool MulTester::i16_i16_test() {
        int16_t a = 23065;
        int16_t b = -1203;
        return mul_test(a, b, Simulator::Tag::SH, Simulator::Tag::SH, 0xFE589C85u, Simulator::Tag::SW);
    }

    bool MulTester::i32_i32_test() {
        int32_t a = 1000000000;
        int32_t b = -123456789;
        return mul_test(a, b, Simulator::Tag::SW, Simulator::Tag::SW, 0x5A8B6E00u, Simulator::Tag::SW);
    }

    bool MulTester::ui8_ui8_test() {
        uint8_t a = 200;
        uint8_t b = 55;
        return mul_test(a, b, Simulator::Tag::UB, Simulator::Tag::UB, 11000, Simulator::Tag::SW);
    }

    bool MulTester::ui16_ui16_test() {
        uint16_t a = 60000;
        uint16_t b = 1234;
        return mul_test(a, b, Simulator::Tag::UH, Simulator::Tag::UH, 74040000, Simulator::Tag::SW);
    }

    bool MulTester::ui32_ui32_test() {
        uint32_t a = 4000000000u;
        uint32_t b = 123456789u;
        return mul_test(a, b, Simulator::Tag::UW, Simulator::Tag::UW, 0x95D24800u, Simulator::Tag::UW);
    }

    bool MulTester::i8_i16_test() {
        int8_t a = -12;
        int16_t b = 3000;
        return mul_test(a, b, Simulator::Tag::SB, Simulator::Tag::SH, 0xFFFF7360u, Simulator::Tag::SW);
    }

    bool MulTester::i8_i32_test() {
        int8_t a = 100;
        int32_t b = -100000;
        return mul_test(a, b, Simulator::Tag::SB, Simulator::Tag::SW, 0xFF676980u, Simulator::Tag::SW);
    }

    bool MulTester::i8_ui8_test() {
        int8_t a = -1;
        uint8_t b = 200;
        return mul_test(a, b, Simulator::Tag::SB, Simulator::Tag::UB, 0xFFFFFF38u, Simulator::Tag::SW);
    }

    bool MulTester::i8_ui16_test() {
        int8_t a = 10;
        uint16_t b = 65000;
        return mul_test(a, b, Simulator::Tag::SB, Simulator::Tag::UH, 650000, Simulator::Tag::SW);
    }

    bool MulTester::i8_ui32_test() {
        int8_t a = 1;
        uint32_t b = 3000000000u;
        return mul_test(a, b, Simulator::Tag::SB, Simulator::Tag::UW, 3000000000u, Simulator::Tag::UW);
    }

    bool MulTester::i16_i8_test() {
        int16_t a = -1234;
        int8_t b = 12;
        return mul_test(a, b, Simulator::Tag::SH, Simulator::Tag::SB, 0xFFFFC628u, Simulator::Tag::SW);
    }

    bool MulTester::i16_i32_test() {
        int16_t a = 12345;
        int32_t b = 200000;
        return mul_test(a, b, Simulator::Tag::SH, Simulator::Tag::SW, 2469000000u, Simulator::Tag::SW);
    }

    bool MulTester::i16_ui8_test() {
        int16_t a = -10;
        uint8_t b = 250;
        return mul_test(a, b, Simulator::Tag::SH, Simulator::Tag::UB, 0xFFFFF63Cu, Simulator::Tag::SW);
    }

    bool MulTester::i16_ui16_test() {
        int16_t a = -200;
        uint16_t b = 65000;
        return mul_test(a, b, Simulator::Tag::SH, Simulator::Tag::UH, 0xFF39A2C0u, Simulator::Tag::SW);
    }

    bool MulTester::i16_ui32_test() {
        int16_t a = 7;
        uint32_t b = 4000000000u;
        return mul_test(a, b, Simulator::Tag::SH, Simulator::Tag::UW, 0x84EE1800u, Simulator::Tag::UW);
    }

    bool MulTester::i32_i8_test() {
        int32_t a = -100000;
        int8_t b = 1;
        return mul_test(a, b, Simulator::Tag::SW, Simulator::Tag::SB, 0xFFFE7960u, Simulator::Tag::SW);
    }

    bool MulTester::i32_i16_test() {
        int32_t a = 500000;
        int16_t b = -123;
        return mul_test(a, b, Simulator::Tag::SW, Simulator::Tag::SH, 0xFC5595A0u, Simulator::Tag::SW);
    }

    bool MulTester::i32_ui8_test() {
        int32_t a = -5;
        uint8_t b = 10;
        return mul_test(a, b, Simulator::Tag::SW, Simulator::Tag::UB, 0xFFFFFFCEu, Simulator::Tag::SW);
    }

    bool MulTester::i32_ui16_test() {
        int32_t a = -1000;
        uint16_t b = 60000;
        return mul_test(a, b, Simulator::Tag::SW, Simulator::Tag::UH, 0xFC6C7900u, Simulator::Tag::SW);
    }

    bool MulTester::i32_ui32_test() {
        int32_t a = -1;
        uint32_t b = 4000000000u;
        return mul_test(a, b, Simulator::Tag::SW, Simulator::Tag::UW, 0x1194D800u, Simulator::Tag::UW);
    }

    bool MulTester::ui8_i8_test() {
        uint8_t a = 200;
        int8_t b = -1;
        return mul_test(a, b, Simulator::Tag::UB, Simulator::Tag::SB, 0xFFFFFF38u, Simulator::Tag::SW);
    }

    bool MulTester::ui8_i16_test() {
        uint8_t a = 250;
        int16_t b = -1000;
        return mul_test(a, b, Simulator::Tag::UB, Simulator::Tag::SH, 0xFFFC2F70u, Simulator::Tag::SW);
    }

    bool MulTester::ui8_i32_test() {
        uint8_t a = 10;
        int32_t b = -100000;
        return mul_test(a, b, Simulator::Tag::UB, Simulator::Tag::SW, 0xFFF0BDC0u, Simulator::Tag::SW);
    }

    bool MulTester::ui8_ui16_test() {
        uint8_t a = 200;
        uint16_t b = 1000;
        return mul_test(a, b, Simulator::Tag::UB, Simulator::Tag::UH, 200000, Simulator::Tag::SW);
    }

    bool MulTester::ui8_ui32_test() {
        uint8_t a = 1;
        uint32_t b = 3000000000u;
        return mul_test(a, b, Simulator::Tag::UB, Simulator::Tag::UW, 3000000000u, Simulator::Tag::UW);
    }

    bool MulTester::ui16_i8_test() {
        uint16_t a = 65000;
        int8_t b = 10;
        return mul_test(a, b, Simulator::Tag::UH, Simulator::Tag::SB, 650000, Simulator::Tag::SW);
    }

    bool MulTester::ui16_i16_test() {
        uint16_t a = 60000;
        int16_t b = -200;
        return mul_test(a, b, Simulator::Tag::UH, Simulator::Tag::SH, 0xFF48E500u, Simulator::Tag::SW);
    }

    bool MulTester::ui16_i32_test() {
        uint16_t a = 65000;
        int32_t b = -1000;
        return mul_test(a, b, Simulator::Tag::UH, Simulator::Tag::SW, 0xFC202DC0u, Simulator::Tag::SW);
    }

    bool MulTester::ui16_ui8_test() {
        uint16_t a = 1000;
        uint8_t b = 200;
        return mul_test(a, b, Simulator::Tag::UH, Simulator::Tag::UB, 200000, Simulator::Tag::SW);
    }

    bool MulTester::ui16_ui32_test() {
        uint16_t a = 65000;
        uint32_t b = 3000000000u;
        return mul_test(a, b, Simulator::Tag::UH, Simulator::Tag::UW, 0xF9BB3000u, Simulator::Tag::UW);
    }

    bool MulTester::ui32_i8_test() {
        uint32_t a = 3000000000u;
        int8_t b = 1;
        return mul_test(a, b, Simulator::Tag::UW, Simulator::Tag::SB, 3000000000u, Simulator::Tag::UW);
    }

    bool MulTester::ui32_i16_test() {
        uint32_t a = 3000000000u;
        int16_t b = 7;
        return mul_test(a, b, Simulator::Tag::UW, Simulator::Tag::SH, 0xE3B29200u, Simulator::Tag::UW);
    }

    bool MulTester::ui32_i32_test() {
        uint32_t a = 3000000000u;
        int32_t b = -1;
        return mul_test(a, b, Simulator::Tag::UW, Simulator::Tag::SW, 0x4D2FA200u, Simulator::Tag::UW);
    }

    bool MulTester::ui32_ui8_test() {
        uint32_t a = 3000000000u;
        uint8_t b = 2;
        return mul_test(a, b, Simulator::Tag::UW, Simulator::Tag::UB, 0x65A0BC00u, Simulator::Tag::UW);
    }

    bool MulTester::ui32_ui16_test() {
        uint32_t a = 3000000000u;
        uint16_t b = 60000;
        return mul_test(a, b, Simulator::Tag::UW, Simulator::Tag::UH, 0x840F4000u, Simulator::Tag::UW);
    }
} // namespace Test::Unit