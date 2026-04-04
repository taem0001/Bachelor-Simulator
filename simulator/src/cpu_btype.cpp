#include "../include/cpu.hpp"

namespace Simulator {
    void CPU::b_instruction(const char imm4_1_11, const char func3, const char rs1, const char rs2,
                            const char imm12_10_5) {
        int imm =
            ((imm12_10_5 << 5) & 0x800) | ((imm4_1_11 & 0x1) << 11) | ((imm12_10_5 & 0x3F) << 5) | (imm4_1_11 >> 1);
        if (imm & 0x1000) {
            imm |= 0xFFFFe000;
        }

        switch (func3) {
            case 0x0: // beq
                if ((registers[rs1].data == registers[rs2].data) && (registers[rs1].tag == registers[rs2].tag)) {
                    pc += imm;
                }
                break;
            case 0x1: // BNE
                if ((registers[rs1].data != registers[rs2].data) || (registers[rs1].tag != registers[rs2].tag)) {
                    pc += imm;
                }
                break;
            default:
                break;
        }
    }
} // namespace Simulator