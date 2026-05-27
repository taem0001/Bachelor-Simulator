#include "../include/cpu.hpp"

namespace Simulator {
    static constexpr Tag load_tag_from_func3(const char func3) {
        switch (func3) {
        case 0x0: return Tag::SB;
        case 0x1: return Tag::SH;
        case 0x2: return Tag::SW;
        case 0x4: return Tag::UB;
        case 0x5: return Tag::UH;
        case 0x6: return Tag::UW;
        default: return Tag::SW;
        }
    }


    void CPU::l_instruction(const char rd, const char func3, const char rs1, const short imm) {
        int32_t imm12 = imm & 0xFFF;
		if (imm12 & 0x800) imm12 |= ~0xFFF;

        int64_t addr64 = static_cast<int64_t>(registers[rs1].data) + imm12;
        if (addr64 < 0 || addr64 >= MEMORY_SIZE_BYTES) {
            std::cerr << "ERROR: Load instruction out of bounds" << std::endl;
            std::cerr << "  Base address (rs" << static_cast<int>(rs1) << "): 0x" << std::hex << registers[rs1].data << std::endl;
            std::cerr << "  Offset (imm): " << std::dec << imm12 << std::endl;
            std::cerr << "  Computed address: 0x" << std::hex << addr64 << std::endl;
            std::cerr << "  Memory size: 0x" << MEMORY_SIZE_BYTES << std::endl;
            std::exit(1);
        }
        uint32_t addr = static_cast<uint32_t>(addr64);

        switch(func3) {
            case 0x0: { //LB
                uint32_t result = memory[addr];
                if(result & 0x80) result |= ~0xFF;
                write_to_register(rd, {result, load_tag_from_func3(func3)});
            } break;
            case 0x1: { // LH
                if (addr + 1 >= MEMORY_SIZE_BYTES) {
                    std::cerr << "ERROR: Load halfword instruction out of bounds at address 0x" << std::hex << addr << std::endl;
                    std::exit(1);
                }
                uint32_t result = memory[addr] | (memory[addr + 1] << 8);
                if(result & 0x8000) result |= ~0xFFFF;
                write_to_register(rd, {result, load_tag_from_func3(func3)});
            } break;
            case 0x2: { // LW
                if (addr + 3 >= MEMORY_SIZE_BYTES) {
                    std::cerr << "ERROR: Load word instruction out of bounds at address 0x" << std::hex << addr << std::endl;
                    std::exit(1);
                }
                uint32_t result = memory[addr]
                                | (memory[addr + 1] << 8)
                                | (memory[addr + 2] << 16)
                                | (memory[addr + 3] << 24);
                write_to_register(rd, {result, load_tag_from_func3(func3)});
            } break;
            case 0x4: { // LBU
                uint32_t result = memory[addr];
                write_to_register(rd, {result, load_tag_from_func3(func3)});
            } break;
            case 0x5: { // LHU
                if (addr + 1 >= MEMORY_SIZE_BYTES) {
                    std::cerr << "ERROR: Load halfword unsigned instruction out of bounds at address 0x" << std::hex << addr << std::endl;
                    std::exit(1);
                }
                uint32_t result = memory[addr] | (memory[addr + 1] << 8);
                write_to_register(rd, {result, load_tag_from_func3(func3)});
            } break;
            case 0x6: { // LWU
                std::cout << "Inside LWU\n";
                if (addr + 3 >= MEMORY_SIZE_BYTES) {
                    std::cerr << "ERROR: Load word unsigned instruction out of bounds at address 0x" << std::hex << addr << std::endl;
                    std::exit(1);
                }
                uint32_t result = memory[addr]
                                | (memory[addr + 1] << 8)
                                | (memory[addr + 2] << 16)
                                | (memory[addr + 3] << 24);
                write_to_register(rd, {result, load_tag_from_func3(func3)});
            } break;
            case 0x7: {
                if(addr + 4 >= MEMORY_SIZE_BYTES) {
                    std::cerr << "ERROR: Load TAG instruction out of bounds at address 0x" << std::hex << addr << std::endl;
                    std::exit(1);
                }
                uint32_t result = memory[addr]
                                | (memory[addr + 1] << 8)
                                | (memory[addr + 2] << 16)
                                | (memory[addr + 3] << 24);
                uint8_t raw_tag = memory[addr + 4] & 0b111;
                Tag tag = static_cast<Tag>(raw_tag);
                write_to_register(rd, {result, tag});
            } break;
            default:
                break;
        }
    }
}