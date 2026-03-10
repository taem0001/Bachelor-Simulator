#include "../include/file.hpp"

namespace Simulator {
	std::vector<uint8_t> get_program(const std::string &file_path) {
		std::ifstream in_file(file_path, std::ios::binary);

		if (!in_file) {
            std::cerr << "\x1b[31m[ERROR]\x1b[0m Could not locate file." << std::endl;
			exit(1);
		}
		std::vector<uint8_t> res;

		char byte;
		while (in_file.read(&byte, 1)) {
			uint8_t u = static_cast<uint8_t>(byte);
			res.push_back(u);
		}
		in_file.close();

		return res;
	}
} // namespace Simulator