#ifndef SRI_HPP
#define SRI_HPP

#include "../../../simulator/include/cpu.hpp"
#include "../../../simulator/include/includes.hpp"
#include "../../test_utils.hpp"

namespace Test::Unit {
	struct SriTester {
			static bool i8_test();
			static bool i16_test();
			static bool i32_test();
			static bool ui8_test();
			static bool ui16_test();
			static bool ui32_test();
	};
} // namespace Test::Unit

#endif