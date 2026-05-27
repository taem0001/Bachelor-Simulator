#include "../include/cpu.hpp"

namespace Simulator {


    void _st(Tag tag, uint32_t addr, uint32_t value, std::array<uint8_t, MEMORY_SIZE_BYTES> &memory) {
        switch(tag) {
            case Tag::UB: 
            case Tag::SB: {
                memory[addr] = static_cast<uint8_t> (value);
            } break;
            case Tag::UH:
            case Tag::SH: {
                if(addr + 1 >= MEMORY_SIZE_BYTES) {
                    std::cerr << "ERROR: Store halfword instruction out of bounds at address 0x" << std::hex << addr << std::endl;
                    std::exit(1);
                }
                memory[addr] = static_cast<uint8_t> (value);
                memory[addr+1] = static_cast<uint8_t> (value >> 8);
            } break;
            case Tag::UW:
            case Tag::SW: {
                if(addr + 3 >= MEMORY_SIZE_BYTES) {
                    std::cerr << "ERROR: Store word instruction out of bounds at address 0x" << std::hex << addr << std::endl;
                    std::exit(1);
                }
                memory[addr] = static_cast<uint8_t> (value);
                memory[addr+1] = static_cast<uint8_t> (value >> 8);
                memory[addr+2] = static_cast<uint8_t> (value >> 16);
                memory[addr+3] = static_cast<uint8_t> (value >> 24);
            }
        }
    }

    void CPU::s_instruction(const char imm4_0, const char func3, const char rs1, const char rs2, const char imm11_5) {
        int32_t imm = (static_cast<int32_t>(imm11_5 & 0x7F) << 5)
                |  static_cast<int32_t>(imm4_0 & 0x1F);
        if (imm & 0x800) imm |= ~0xFFF;

        int temp_addr = static_cast<int>(registers[rs1].data) + imm;
        if (temp_addr < 0 || temp_addr >= MEMORY_SIZE_BYTES) {
            std::cerr << "ERROR: Store instruction out of bounds" << std::endl;
            std::cerr << "  Base address (rs" << static_cast<int>(rs1) << "): 0x" << std::hex << registers[rs1].data << std::endl;
            std::cerr << "  Offset (imm): " << std::dec << imm << std::endl;
            std::cerr << "  Computed address: 0x" << std::hex << temp_addr << std::endl;
            std::cerr << "  Memory size: 0x" << MEMORY_SIZE_BYTES << std::endl;
            std::exit(1);
        }
        uint32_t addr = static_cast<uint32_t>(temp_addr);

        uint32_t value = registers[rs2].data;
        Tag tag = registers[rs2].tag;

        switch(func3) {
            case 0b000: {
                _st(tag, addr, value, memory);
            } break;
            case 0b111: {
                memory[addr] = static_cast<uint8_t> (value);
                memory[addr+1] = static_cast<uint8_t> (value >> 8);
                memory[addr+2] = static_cast<uint8_t> (value >> 16);
                memory[addr+3] = static_cast<uint8_t> (value >> 24);
                memory[addr+4] = static_cast<uint8_t> (tag);
            }
        }
    }
}
