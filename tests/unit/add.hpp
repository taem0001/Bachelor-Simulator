#ifndef ADD_HPP
#define ADD_HPP

#include "../../simulator/include/cpu.hpp"
#include "../../simulator/include/includes.hpp"
#include "../test_utils.hpp"

namespace Test::Unit {
	struct AddTester {
			static bool i8_i8_test();
			static bool i16_i16_test();
			static bool i32_i32_test();
			static bool ui8_ui8_test();
			static bool ui16_ui16_test();
			static bool ui32_ui32_test();
	};
} // namespace Test::Unit

#endif