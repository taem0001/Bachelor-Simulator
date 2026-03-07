#ifndef SL_HPP
#define SL_HPP

#include "../../../simulator/include/cpu.hpp"
#include "../../../simulator/include/includes.hpp"
#include "../../test_utils.hpp"

namespace Test::Unit {
	struct SlTester {
			static bool i8_i8_test();
			static bool i16_i16_test();
			static bool i32_i32_test();
			static bool ui8_ui8_test();
			static bool ui16_ui16_test();
			static bool ui32_ui32_test();

			static bool i8_i16_test();
			static bool i8_i32_test();
			static bool i8_ui8_test();
			static bool i8_ui16_test();
			static bool i8_ui32_test();

			static bool i16_i8_test();
			static bool i16_i32_test();
			static bool i16_ui8_test();
			static bool i16_ui16_test();
			static bool i16_ui32_test();

			static bool i32_i8_test();
			static bool i32_i16_test();
			static bool i32_ui8_test();
			static bool i32_ui16_test();
			static bool i32_ui32_test();

			static bool ui8_i8_test();
			static bool ui8_i16_test();
			static bool ui8_i32_test();
			static bool ui8_ui16_test();
			static bool ui8_ui32_test();

			static bool ui16_i8_test();
			static bool ui16_i16_test();
			static bool ui16_i32_test();
			static bool ui16_ui8_test();
			static bool ui16_ui32_test();

			static bool ui32_i8_test();
			static bool ui32_i16_test();
			static bool ui32_i32_test();
			static bool ui32_ui8_test();
			static bool ui32_ui16_test();
	};
} // namespace Test::Unit

#endif