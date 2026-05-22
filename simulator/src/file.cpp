#include "../include/file.hpp"

namespace Simulator {
	void load_program(const std::string &file_path, std::array<uint8_t, MEMORY_SIZE_BYTES> &memory, std::size_t start_addr) {
		std::ifstream in_file(file_path, std::ios::binary);

		if (!in_file) {
			std::cerr << "\x1b[31m[ERROR]\x1b[0m Could not locate file." << std::endl;
			std::exit(1);
		}

		char byte;
		std::size_t addr = start_addr;

		while (in_file.read(&byte, 1)) {
			if (addr >= MEMORY_SIZE_BYTES) {
				std::cerr << "\x1b[31m[ERROR]\x1b[0m Program does not fit in memory." << std::endl;
				std::exit(1);
			}

			memory[addr++] = static_cast<uint8_t>(byte);
		}
	}
} // namespace Simulator