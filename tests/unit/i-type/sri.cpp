#include "sri.hpp"

namespace Test::Unit {
    static constexpr uint32_t SRI_X15_X3_10 = 0b00000000101000011101011110010011;

    static bool sri_test(uint32_t a_val, Simulator::Tag a_tag, uint32_t expected_val, Simulator::Tag expected_tag) {
        Simulator::CPU cpu;
        cpu.set_register(3, a_val, a_tag);
        cpu.execute_instruction(SRI_X15_X3_10);

        const auto registers = cpu.get_registers();

        const bool passed_data = registers[15].data == expected_val;
        const bool passed_tag = registers[15].tag == expected_tag;
        return passed_data && passed_tag;
    }

    bool SriTester::i8_test() {
        int8_t a = static_cast<int8_t>(0b11001001);
        return sri_test(static_cast<uint32_t>(a), Simulator::Tag::SB, 0xFFFFFFFFu, Simulator::Tag::SB);
    }
    bool SriTester::i16_test() {
        int16_t a = static_cast<int16_t>(0b1101001110110010);
        return sri_test(static_cast<uint32_t>(a), Simulator::Tag::SH, 0xFFFFFFF4u, Simulator::Tag::SH);
    }
    bool SriTester::i32_test() {
        int32_t a = static_cast<int32_t>(0xD3B2D3B2u);
        return sri_test(static_cast<uint32_t>(a), Simulator::Tag::SW, 0xFFF4ECB4u, Simulator::Tag::SW);
    }
    bool SriTester::ui8_test() {
        uint8_t a = static_cast<uint8_t>(0b10001011);
        return sri_test(static_cast<uint32_t>(a), Simulator::Tag::UB, 0x00000000u, Simulator::Tag::UB);
    }
    bool SriTester::ui16_test() {
        uint16_t a = static_cast<uint16_t>(0b1100001010111010);
        return sri_test(static_cast<uint32_t>(a), Simulator::Tag::UH, 0x00000030u, Simulator::Tag::UH);
    }
    bool SriTester::ui32_test() {
        uint32_t a = 0xD3B2D3B2u;
        return sri_test(a, Simulator::Tag::UW, 0x0034ECB4u, Simulator::Tag::UW);
    }
}