#include "../include/cpu.hpp"

namespace Simulator {
	void CPU::ecall_instruction() {
		const int code = static_cast<int>(registers[17].data);

		switch (code) {
		case 1: {
			const int value = static_cast<int>(registers[10].data);
			std::cout << value;
		} break;
		case 4: {
			int address = static_cast<int>(registers[10].data);
			char c;
			while ((c = static_cast<char>(memory[address])) != '\0') {
				std::cout << c;
				address++;
			}
		} break;
		case 11: {
			const char value = static_cast<char>(registers[10].data);
			std::cout << value;
		} break;
		case 93: {
			ebreak = true;
		} break;
		default:
			break;
		}
	}

	void CPU::x_instruction(const int bits) {
		switch (bits) {
		case 0x0: // ecall
			ecall_instruction();
			break;
		case 0x2000: // ebreak
			ebreak = true;
			break;
		default:
			break;
		}
	}
} // namespace Simulator