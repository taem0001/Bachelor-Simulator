#include "add.hpp"

namespace Test::Unit {
    static constexpr uint32_t ADD_X7_X5_X6 = 0b00000000011000101000001110110011;

    static bool add_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
                         uint32_t expected_val, Simulator::Tag expected_tag) {
        Simulator::CPU cpu;
        cpu.set_register(5, a_val, a_tag);
        cpu.set_register(6, b_val, b_tag);
        cpu.execute_instruction(ADD_X7_X5_X6);

        const auto registers = cpu.get_registers();

        const bool passed_data = registers[7].data == expected_val;
        const bool passed_tag = registers[7].tag == expected_tag;
        return passed_data && passed_tag;
    }

    bool AddTester::i8_i8_test() {
        int8_t a = 32;
        int8_t b = 45;
        return add_test(a, b, Simulator::Tag::SB, Simulator::Tag::SB, 77, Simulator::Tag::SH);
    }
    bool AddTester::i16_i16_test() {
        int16_t a = 23065;
        int16_t b = -1203;
        return add_test(a, b, Simulator::Tag::SH, Simulator::Tag::SH, 21862, Simulator::Tag::SW);
    }
    bool AddTester::i32_i32_test() {
        int32_t a = 1000000000;
        int32_t b = -123456789;
        return add_test(a, b, Simulator::Tag::SW, Simulator::Tag::SW, 876543211, Simulator::Tag::SW);
    }
    bool AddTester::ui8_ui8_test() {
        uint8_t a = 200;
        uint8_t b = 55;
        return add_test(a, b, Simulator::Tag::UB, Simulator::Tag::UB, 255, Simulator::Tag::UH);
    }
    bool AddTester::ui16_ui16_test() {
        uint16_t a = 60000;
        uint16_t b = 1234;
        return add_test(a, b, Simulator::Tag::UH, Simulator::Tag::UH, 61234, Simulator::Tag::UW);
    }
    bool AddTester::ui32_ui32_test() {
        uint32_t a = 4000000000;
        uint32_t b = 123456789;
        return add_test(a, b, Simulator::Tag::UW, Simulator::Tag::UW, 4123456789, Simulator::Tag::UW);
    }
    bool AddTester::i8_i16_test() {
        int8_t a = -12;
        int16_t b = 3000;
        return add_test(a, b, Simulator::Tag::SB, Simulator::Tag::SH, 2988, Simulator::Tag::SH);
    }
    bool AddTester::i8_i32_test() {
        int8_t a = 100;
        int32_t b = -100000;
        return add_test(a, b, Simulator::Tag::SB, Simulator::Tag::SW, -99900, Simulator::Tag::SW);
    }
    bool AddTester::i8_ui8_test() {
        int8_t a = -1;
        uint8_t b = 200;
        return add_test(a, b, Simulator::Tag::SB, Simulator::Tag::UB, 199, Simulator::Tag::SH);
    }
    bool AddTester::i8_ui16_test() {
        int8_t a = 10;
        uint16_t b = 65000;
        return add_test(a, b, Simulator::Tag::SB, Simulator::Tag::UH, 65010, Simulator::Tag::UH);
    }
    bool AddTester::i8_ui32_test() {
        int8_t a = 1;
        uint32_t b = 3000000000;
        return add_test(a, b, Simulator::Tag::SB, Simulator::Tag::UW, 3000000001, Simulator::Tag::UW);
    }
    bool AddTester::i16_i8_test() {
        int16_t a = -1234;
        int8_t b = 12;
        return add_test(a, b, Simulator::Tag::SH, Simulator::Tag::SB, -1222, Simulator::Tag::SH);
    }
    bool AddTester::i16_i32_test() {
        int16_t a = 12345;
        int32_t b = 200000;
        return add_test(a, b, Simulator::Tag::SH, Simulator::Tag::SW, 212345, Simulator::Tag::SW);
    }
    bool AddTester::i16_ui8_test() {
        int16_t a = -10;
        uint8_t b = 250;
        return add_test(a, b, Simulator::Tag::SH, Simulator::Tag::UB, 240, Simulator::Tag::SH);
    }
    bool AddTester::i16_ui16_test() {
        int16_t a = -200;
        uint16_t b = 65000;
        return add_test(a, b, Simulator::Tag::SH, Simulator::Tag::UH, 64800, Simulator::Tag::SW);
    }
    bool AddTester::i16_ui32_test() {
        int16_t a = 7;
        uint32_t b = 4000000000;
        return add_test(a, b, Simulator::Tag::SH, Simulator::Tag::UW, 4000000007, Simulator::Tag::UW);
    }
    bool AddTester::i32_i8_test() {
        int32_t a = -100000;
        int8_t b = 1;
        return add_test(a, b, Simulator::Tag::SW, Simulator::Tag::SB, -99999, Simulator::Tag::SW);
    }
    bool AddTester::i32_i16_test() {
        int32_t a = 500000;
        int16_t b = -123;
        return add_test(a, b, Simulator::Tag::SW, Simulator::Tag::SH, 499877, Simulator::Tag::SW);
    }
    bool AddTester::i32_ui8_test() {
        int32_t a = -5;
        uint8_t b = 10;
        return add_test(a, b, Simulator::Tag::SW, Simulator::Tag::UB, 5, Simulator::Tag::SW);
    }
    bool AddTester::i32_ui16_test() {
        int32_t a = -1000;
        uint16_t b = 60000;
        return add_test(a, b, Simulator::Tag::SW, Simulator::Tag::UH, 59000, Simulator::Tag::SW);
    }
    bool AddTester::i32_ui32_test() {
        int32_t a = -1;
        uint32_t b = 4000000000;
        return add_test(a, b, Simulator::Tag::SW, Simulator::Tag::UW, 3999999999, Simulator::Tag::UW);
    }
    bool AddTester::ui8_i8_test() {
        uint8_t a = 200;
        int8_t b = -1;
        return add_test(a, b, Simulator::Tag::UB, Simulator::Tag::SB, 199, Simulator::Tag::SH);
    }
    bool AddTester::ui8_i16_test() {
        uint8_t a = 250;
        int16_t b = -1000;
        return add_test(a, b, Simulator::Tag::UB, Simulator::Tag::SH, -750, Simulator::Tag::SH);
    }
    bool AddTester::ui8_i32_test() {
        uint8_t a = 10;
        int32_t b = -100000;
        return add_test(a, b, Simulator::Tag::UB, Simulator::Tag::SW, -99990, Simulator::Tag::SW);
    }
    bool AddTester::ui8_ui16_test() {
        uint8_t a = 200;
        uint16_t b = 1000;
        return add_test(a, b, Simulator::Tag::UB, Simulator::Tag::UH, 1200, Simulator::Tag::UH);
    }
    bool AddTester::ui8_ui32_test() {
        uint8_t a = 1;
        uint32_t b = 3000000000;
        return add_test(a, b, Simulator::Tag::UB, Simulator::Tag::UW, 3000000001, Simulator::Tag::UW);
    }
    bool AddTester::ui16_i8_test() {
        uint16_t a = 65000;
        int8_t b = 10;
        return add_test(a, b, Simulator::Tag::UH, Simulator::Tag::SB, 65010, Simulator::Tag::UH);
    }
    bool AddTester::ui16_i16_test() {
        uint16_t a = 60000;
        int16_t b = -200;
        return add_test(a, b, Simulator::Tag::UH, Simulator::Tag::SH, 59800, Simulator::Tag::SW);
    }
    bool AddTester::ui16_i32_test() {
        uint16_t a = 65000;
        int32_t b = -1000;
        return add_test(a, b, Simulator::Tag::UH, Simulator::Tag::SW, 64000, Simulator::Tag::SW);
    }
    bool AddTester::ui16_ui8_test() {
        uint16_t a = 1000;
        uint8_t b = 200;
        return add_test(a, b, Simulator::Tag::UH, Simulator::Tag::UB, 1200, Simulator::Tag::UH);
    }
    bool AddTester::ui16_ui32_test() {
        uint16_t a = 65000;
        uint32_t b = 3000000000;
        return add_test(a, b, Simulator::Tag::UH, Simulator::Tag::UW, 3000065000, Simulator::Tag::UW);
    }
    bool AddTester::ui32_i8_test() {
        uint32_t a = 3000000000;
        int8_t b = 1;
        return add_test(a, b, Simulator::Tag::UW, Simulator::Tag::SB, 3000000001, Simulator::Tag::UW);
    }
    bool AddTester::ui32_i16_test() {
        uint32_t a = 3000000000;
        int16_t b = 7;
        return add_test(a, b, Simulator::Tag::UW, Simulator::Tag::SH, 3000000007, Simulator::Tag::UW);
    }
    bool AddTester::ui32_i32_test() {
        uint32_t a = 3000000000;
        int32_t b = -1;
        return add_test(a, b, Simulator::Tag::UW, Simulator::Tag::SW, 2999999999, Simulator::Tag::UW);
    }
    bool AddTester::ui32_ui8_test() {
        uint32_t a = 3000000000;
        uint8_t b = 2;
        return add_test(a, b, Simulator::Tag::UW, Simulator::Tag::UB, 3000000002, Simulator::Tag::UW);
    }
    bool AddTester::ui32_ui16_test() {
        uint32_t a = 3000000000;
        uint16_t b = 60000;
        return add_test(a, b, Simulator::Tag::UW, Simulator::Tag::UH, 3000060000, Simulator::Tag::UW);
    }
} // namespace Test::Unit