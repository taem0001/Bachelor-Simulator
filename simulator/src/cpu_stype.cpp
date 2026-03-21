#include "../include/cpu.hpp"

namespace Simulator {

    void CPU::s_instruction(const char imm4_0, const char func3, const char rs1, const char rs2, const char imm11_5) {
        int32_t imm = (static_cast<int32_t>(imm11_5 & 0x7F) << 5)
                |  static_cast<int32_t>(imm4_0 & 0x1F);

        // sign-extend 12-bit immediate
        if (imm & 0x800) {
            imm |= ~0xFFF;
        }

        uint32_t addr = registers[rs1].data + imm;
        uint32_t value = registers[rs2].data;
        Tag tag = registers[rs2].tag;

        switch(tag) {
            case Tag::UB: 
            case Tag::SB: {
                memory[addr] = static_cast<uint8_t> (value);
            } break;
            case Tag::UH:
            case Tag::SH: {
                if(addr + 1 >= MEMORY_SIZE_BYTES) return;
                memory[addr] = static_cast<uint8_t> (value);
                memory[addr+1] = static_cast<uint8_t> (value >> 8);
            } break;
            case Tag::UW:
            case Tag::SW: {
                if(addr + 3 >= MEMORY_SIZE_BYTES) return;
                memory[addr] = static_cast<uint8_t> (value);
                memory[addr+1] = static_cast<uint8_t> (value >> 8);
                memory[addr+2] = static_cast<uint8_t> (value >> 16);
                memory[addr+3] = static_cast<uint8_t> (value >> 24);
            }
        }
    }
}