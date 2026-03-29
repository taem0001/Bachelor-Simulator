#include "s.hpp"

namespace Test::Unit {
    static constexpr uint32_t S_2_30_X9 = 0b00000000011100101000001010100011;

    static bool s_test(uint32_t a_data, Simulator::Tag a_tag,
                    uint32_t b_data, Simulator::Tag b_tag,
                    uint32_t expected_memory, uint8_t imm11_5,
                    uint32_t expected_result) {
        Simulator::CPU cpu;
        cpu.set_register(0b00101, a_data, a_tag);
        cpu.set_register(0b00111, b_data, b_tag);

        cpu.execute_instruction(S_2_30_X9 | (static_cast<uint32_t>(imm11_5) << 25));

        const auto& mem = cpu.get_memory();

        int32_t imm = 0b00101 | ((imm11_5 & 0x7F) << 5);
        if (imm & 0x800) {
            imm |= ~0xFFF;
        }

        int64_t addr = static_cast<int64_t>(a_data) + imm;

        size_t width = 1;
        switch (b_tag) {
            case Simulator::Tag::UB:
            case Simulator::Tag::SB: 
            {
                width = 1;
                expected_result = static_cast<uint8_t> (expected_result);
            } break;
            case Simulator::Tag::UH:
            case Simulator::Tag::SH:
            {
                width = 2;
                expected_result = static_cast<uint16_t> (expected_result); 
            } break;
            case Simulator::Tag::UW:
            case Simulator::Tag::SW: width = 4; break;
        }

        if (addr < 0 || addr + width > MEMORY_SIZE_BYTES) {
            return expected_result == 0;
        }

        int32_t result = mem[addr];
        if (width >= 2) result |= (mem[addr + 1] << 8);
        if (width >= 4) {
            result |= (mem[addr + 2] << 16);
            result |= (mem[addr + 3] << 24);
        }
        return static_cast<uint32_t>(addr) == expected_memory
            && result == expected_result;
    }
    //uint32_t a_data, Simulator::Tag a_tag, uint32_t b_data, Simulator::Tag b_tag, uint32_t expected_memory, uint8_t imm11_5, uint32_t expected_result
    bool STester::i8_test() { return s_test(-8, Simulator::Tag::SB, 20, Simulator::Tag::SB, 45, 0b0000001, 0); }
    bool STester::i16_test() { return s_test(51, Simulator::Tag::SH, -1000, Simulator::Tag::SH, 88, 0b0000001, -1000); }
    bool STester::i32_test() { return s_test(91, Simulator::Tag::SW, -10000, Simulator::Tag::SW, 96, 0, -10000); }
    bool STester::ui8_test() { return s_test(4, Simulator::Tag::UB, 30, Simulator::Tag::UB, 41, 0b0000001, 30); }
    bool STester::ui16_test() { return s_test(42, Simulator::Tag::UH, 1000, Simulator::Tag::UH, 47, 0b1001000, 0); }
    bool STester::ui32_test() { return s_test(123, Simulator::Tag::UW, 10000, Simulator::Tag::UW, 64, 0b1111110, 10000); }
}