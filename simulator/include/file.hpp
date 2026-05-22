#ifndef FILE_HPP
#define FILE_HPP

#include "includes.hpp"

namespace Simulator {
	void load_program(const std::string &file_path, std::array<uint8_t, MEMORY_SIZE_BYTES> &memory, std::size_t start_addr = 0);
}

#endif