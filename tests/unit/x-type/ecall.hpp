#ifndef ECALL_HPP
#define ECALL_HPP

#include "../../../simulator/include/cpu.hpp"
#include "../../../simulator/include/includes.hpp"
#include "../../test_utils.hpp"

namespace Test::Unit {
	struct EcallTester {
		static bool print_int_test();
		static bool print_char_test();
		static bool exit_test();
	};
} // namespace Test::Unit

#endif