#ifndef FILE_HPP
#define FILE_HPP

#include "includes.hpp"

namespace Simulator {
	std::vector<uint8_t> load_program(const std::string &file_path, std::vector<uint8_t> &program,
									  const std::size_t program_size, std::size_t start_addr = 0);
}

#endif