#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include "../../simulator/include/includes.hpp"

namespace Test {
	struct Stats {
			int passed = 0;
			int failed = 0;
	};

	inline const std::string MAGENTA = "\x1b[35m";
	inline const std::string GREEN = "\x1b[32m";
	inline const std::string RED = "\x1b[31m";
	inline const std::string RESET = "\x1b[0m";

	inline void print_header() {
		std::cout << MAGENTA << std::left << std::setw(16) << "INSTRUCTION" << RESET << MAGENTA << std::setw(16)
				  << "OPERATION" << RESET << MAGENTA << "RESULT" << RESET << std::endl;
	}

	inline void print_result(Stats &s, const std::string &instr, const std::string &variant, bool ok) {
		std::cout << std::left << std::setw(16) << instr;
		std::cout << std::setw(16) << variant;
		std::cout << (ok ? (std::string(GREEN) + "PASSED" + RESET) : (std::string(RED) + "FAILED" + RESET))
				  << std::endl;
		ok ? ++s.passed : ++s.failed;
	}
} // namespace Test

#endif