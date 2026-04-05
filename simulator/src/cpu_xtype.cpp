#include "../include/cpu.hpp"

namespace Simulator {
    void _ecall_instruction() {

    }

    void CPU::x_instruction(const int bits) {
        switch (bits)
        {
        case 0x0: // ecall
            _ecall_instruction();
            break;
        case 0x2000: // ebreak
            ebreak = true;
            break;
        default:
            break;
        }
    }
}