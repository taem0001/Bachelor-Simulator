#include "sr.hpp"

namespace Test::Unit {
    static constexpr uint32_t SR_X15_X18_X29 = 0b01000001110110010101011110110011;

    static bool sr_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
                        uint32_t expected_val, Simulator::Tag expected_tag) {
        Simulator::CPU cpu;
        cpu.set_register(18, a_val, a_tag);
        cpu.set_register(29, b_val, b_tag);
        cpu.execute_instruction(SR_X15_X18_X29);

        const auto registers = cpu.get_registers();

        const bool passed_data = registers[15].data == expected_val;
        const bool passed_tag = registers[15].tag == expected_tag;
        return passed_data && passed_tag;
    }

    bool SrTester::i8_i8_test() {
        int8_t a = static_cast<int8_t>(0xC9);
        int8_t b = static_cast<int8_t>(0x05);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::SB, 0xFFFFFFFEu, Simulator::Tag::SB);
    }
    bool SrTester::i16_i16_test() {
        int16_t a = static_cast<int16_t>(0xD3B2);
        int16_t b = static_cast<int16_t>(0x0005);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::SH, 0xFFFFFE9Du, Simulator::Tag::SH);
    }
    bool SrTester::i32_i32_test() {
        int32_t a = static_cast<int32_t>(0xD3B2D3B2u);
        int32_t b = static_cast<int32_t>(5);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::SW, 0xFE9D969Du, Simulator::Tag::SW);
    }
    bool SrTester::ui8_ui8_test() {
        uint8_t a = static_cast<uint8_t>(0x8B);
        uint8_t b = static_cast<uint8_t>(0x05);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::UB, 0x00000004u, Simulator::Tag::UB);
    }
    bool SrTester::ui16_ui16_test() {
        uint16_t a = static_cast<uint16_t>(0xC2BA);
        uint16_t b = static_cast<uint16_t>(0x0005);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::UH, 0x00000615u, Simulator::Tag::UH);
    }
    bool SrTester::ui32_ui32_test() {
        uint32_t a = 0xD3B2D3B2u;
        uint32_t b = 5u;

        uint32_t in_a = a;
        uint32_t shamt = b;

        return sr_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::UW, 0x069D969Du, Simulator::Tag::UW);
    }

    bool SrTester::i8_i16_test() {
        int8_t a = static_cast<int8_t>(0xC9);
        int16_t b = static_cast<int16_t>(0x0005);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::SH, 0xFFFFFFFEu, Simulator::Tag::SB);
    }
    bool SrTester::i8_i32_test() {
        int8_t a = static_cast<int8_t>(0xC9);
        int32_t b = static_cast<int32_t>(5);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::SW, 0xFFFFFFFEu, Simulator::Tag::SB);
    }
    bool SrTester::i8_ui8_test() {
        int8_t a = static_cast<int8_t>(0xC9);
        uint8_t b = static_cast<uint8_t>(0x05);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::UB, 0xFFFFFFFEu, Simulator::Tag::SB);
    }
    bool SrTester::i8_ui16_test() {
        int8_t a = static_cast<int8_t>(0xC9);
        uint16_t b = static_cast<uint16_t>(0x0005);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::UH, 0xFFFFFFFEu, Simulator::Tag::SB);
    }
    bool SrTester::i8_ui32_test() {
        int8_t a = static_cast<int8_t>(0xC9);
        uint32_t b = 5u;

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = b;

        return sr_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::UW, 0xFFFFFFFEu, Simulator::Tag::SB);
    }

    bool SrTester::i16_i8_test() {
        int16_t a = static_cast<int16_t>(0xD3B2);
        int8_t b = static_cast<int8_t>(0x05);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::SB, 0xFFFFFE9Du, Simulator::Tag::SH);
    }
    bool SrTester::i16_i32_test() {
        int16_t a = static_cast<int16_t>(0xD3B2);
        int32_t b = static_cast<int32_t>(5);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::SW, 0xFFFFFE9Du, Simulator::Tag::SH);
    }
    bool SrTester::i16_ui8_test() {
        int16_t a = static_cast<int16_t>(0xD3B2);
        uint8_t b = static_cast<uint8_t>(0x05);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::UB, 0xFFFFFE9Du, Simulator::Tag::SH);
    }
    bool SrTester::i16_ui16_test() {
        int16_t a = static_cast<int16_t>(0xD3B2);
        uint16_t b = static_cast<uint16_t>(0x0005);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::UH, 0xFFFFFE9Du, Simulator::Tag::SH);
    }
    bool SrTester::i16_ui32_test() {
        int16_t a = static_cast<int16_t>(0xD3B2);
        uint32_t b = 5u;

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = b;

        return sr_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::UW, 0xFFFFFE9Du, Simulator::Tag::SH);
    }

    bool SrTester::i32_i8_test() {
        int32_t a = static_cast<int32_t>(0xD3B2D3B2u);
        int8_t b = static_cast<int8_t>(0x05);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::SB, 0xFE9D969Du, Simulator::Tag::SW);
    }
    bool SrTester::i32_i16_test() {
        int32_t a = static_cast<int32_t>(0xD3B2D3B2u);
        int16_t b = static_cast<int16_t>(0x0005);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::SH, 0xFE9D969Du, Simulator::Tag::SW);
    }
    bool SrTester::i32_ui8_test() {
        int32_t a = static_cast<int32_t>(0xD3B2D3B2u);
        uint8_t b = static_cast<uint8_t>(0x05);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::UB, 0xFE9D969Du, Simulator::Tag::SW);
    }
    bool SrTester::i32_ui16_test() {
        int32_t a = static_cast<int32_t>(0xD3B2D3B2u);
        uint16_t b = static_cast<uint16_t>(0x0005);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::UH, 0xFE9D969Du, Simulator::Tag::SW);
    }
    bool SrTester::i32_ui32_test() {
        int32_t a = static_cast<int32_t>(0xD3B2D3B2u);
        uint32_t b = 5u;

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = b;

        return sr_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::UW, 0xFE9D969Du, Simulator::Tag::SW);
    }

    bool SrTester::ui8_i8_test() {
        uint8_t a = static_cast<uint8_t>(0x8B);
        int8_t b = static_cast<int8_t>(0x05);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::SB, 0x00000004u, Simulator::Tag::UB);
    }
    bool SrTester::ui8_i16_test() {
        uint8_t a = static_cast<uint8_t>(0x8B);
        int16_t b = static_cast<int16_t>(0x0005);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::SH, 0x00000004u, Simulator::Tag::UB);
    }
    bool SrTester::ui8_i32_test() {
        uint8_t a = static_cast<uint8_t>(0x8B);
        int32_t b = static_cast<int32_t>(5);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::SW, 0x00000004u, Simulator::Tag::UB);
    }
    bool SrTester::ui8_ui16_test() {
        uint8_t a = static_cast<uint8_t>(0x8B);
        uint16_t b = static_cast<uint16_t>(0x0005);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::UH, 0x00000004u, Simulator::Tag::UB);
    }
    bool SrTester::ui8_ui32_test() {
        uint8_t a = static_cast<uint8_t>(0x8B);
        uint32_t b = 5u;

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = b;

        return sr_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::UW, 0x00000004u, Simulator::Tag::UB);
    }

    bool SrTester::ui16_i8_test() {
        uint16_t a = static_cast<uint16_t>(0xC2BA);
        int8_t b = static_cast<int8_t>(0x05);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::SB, 0x00000615u, Simulator::Tag::UH);
    }
    bool SrTester::ui16_i16_test() {
        uint16_t a = static_cast<uint16_t>(0xC2BA);
        int16_t b = static_cast<int16_t>(0x0005);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::SH, 0x00000615u, Simulator::Tag::UH);
    }
    bool SrTester::ui16_i32_test() {
        uint16_t a = static_cast<uint16_t>(0xC2BA);
        int32_t b = static_cast<int32_t>(5);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::SW, 0x00000615u, Simulator::Tag::UH);
    }
    bool SrTester::ui16_ui8_test() {
        uint16_t a = static_cast<uint16_t>(0xC2BA);
        uint8_t b = static_cast<uint8_t>(0x05);

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::UB, 0x00000615u, Simulator::Tag::UH);
    }
    bool SrTester::ui16_ui32_test() {
        uint16_t a = static_cast<uint16_t>(0xC2BA);
        uint32_t b = 5u;

        uint32_t in_a = static_cast<uint32_t>(a);
        uint32_t shamt = b;

        return sr_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::UW, 0x00000615u, Simulator::Tag::UH);
    }

    bool SrTester::ui32_i8_test() {
        uint32_t a = 0xD3B2D3B2u;
        int8_t b = static_cast<int8_t>(0x05);

        uint32_t in_a = a;
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::SB, 0x069D969Du, Simulator::Tag::UW);
    }
    bool SrTester::ui32_i16_test() {
        uint32_t a = 0xD3B2D3B2u;
        int16_t b = static_cast<int16_t>(0x0005);

        uint32_t in_a = a;
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::SH, 0x069D969Du, Simulator::Tag::UW);
    }
    bool SrTester::ui32_i32_test() {
        uint32_t a = 0xD3B2D3B2u;
        int32_t b = static_cast<int32_t>(5);

        uint32_t in_a = a;
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::SW, 0x069D969Du, Simulator::Tag::UW);
    }
    bool SrTester::ui32_ui8_test() {
        uint32_t a = 0xD3B2D3B2u;
        uint8_t b = static_cast<uint8_t>(0x05);

        uint32_t in_a = a;
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::UB, 0x069D969Du, Simulator::Tag::UW);
    }
    bool SrTester::ui32_ui16_test() {
        uint32_t a = 0xD3B2D3B2u;
        uint16_t b = static_cast<uint16_t>(0x0005);

        uint32_t in_a = a;
        uint32_t shamt = static_cast<uint32_t>(b);

        return sr_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::UH, 0x069D969Du, Simulator::Tag::UW);
    }
} // namespace Test::Unit