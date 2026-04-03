#include "../include/cpu.hpp"

namespace Simulator {


    void CPU::l_instruction(const char rd, const char func3, const char rs1, const short imm) {
        int32_t imm12 = imm & 0xFFF;
		if (imm12 & 0x800) imm12 |= ~0xFFF;

        int64_t addr64 = static_cast<int64_t>(registers[rs1].data) + imm12;
        if (addr64 < 0 || addr64 >= MEMORY_SIZE_BYTES) return;
        uint32_t addr = static_cast<uint32_t>(addr64);

        switch(func3) {
            case 0x0: { //LB
                uint32_t result = memory[addr];
                if(result & 0x80) result |= ~0xFF;
                write_to_register(rd, {result, Tag::SB});
            } break;
            case 0x1: { // LH
                if (addr + 1 >= MEMORY_SIZE_BYTES) return;
                uint32_t result = memory[addr] | (memory[addr + 1] << 8);
                if(result & 0x8000) result |= ~0xFFFF;
                write_to_register(rd, {result, Tag::SH});
            } break;
            case 0x2: { // LW
                if (addr + 3 >= MEMORY_SIZE_BYTES) return;
                uint32_t result = memory[addr]
                                | (memory[addr + 1] << 8)
                                | (memory[addr + 2] << 16)
                                | (memory[addr + 3] << 24);
                write_to_register(rd, {result, Tag::SW});
            } break;
            case 0x4: { // LBU
                uint32_t result = memory[addr];
                write_to_register(rd, {result, Tag::UB});
            } break;
            case 0x5: { // LHU
                if (addr + 1 >= MEMORY_SIZE_BYTES) return;
                uint32_t result = memory[addr] | (memory[addr + 1] << 8);
                write_to_register(rd, {result, Tag::UH});
            } break;
            case 0x7: { // LWU
                if (addr + 3 >= MEMORY_SIZE_BYTES) return;
                uint32_t result = memory[addr]
                                | (memory[addr + 1] << 8)
                                | (memory[addr + 2] << 16)
                                | (memory[addr + 3] << 24);
                write_to_register(rd, {result, Tag::UW});
            } break;
            default:
                break;
        }
    }
}