#ifndef BNE_HPP
#define BNE_HPP

#include "../../../simulator/include/cpu.hpp"
#include "../../../simulator/include/includes.hpp"
#include "../../test_utils.hpp"

namespace Test::Unit {
	struct BneTester {
			// Equal tests
			static bool i8_i8_equal_test();
			static bool i16_i16_equal_test();
			static bool i32_i32_equal_test();
			static bool ui8_ui8_equal_test();
			static bool ui16_ui16_equal_test();
			static bool ui32_ui32_equal_test();

			// Not equal tests
			static bool i8_i8_not_equal_test();
			static bool i16_i16_not_equal_test();
			static bool i32_i32_not_equal_test();
			static bool ui8_ui8_not_equal_test();
			static bool ui16_ui16_not_equal_test();
			static bool ui32_ui32_not_equal_test();

			static bool i8_i16_not_equal_test();
			static bool i8_i32_not_equal_test();
			static bool i8_ui8_not_equal_test();
			static bool i8_ui16_not_equal_test();
			static bool i8_ui32_not_equal_test();

			static bool i16_i8_not_equal_test();
			static bool i16_i32_not_equal_test();
			static bool i16_ui8_not_equal_test();
			static bool i16_ui16_not_equal_test();
			static bool i16_ui32_not_equal_test();

			static bool i32_i8_not_equal_test();
			static bool i32_i16_not_equal_test();
			static bool i32_ui8_not_equal_test();
			static bool i32_ui16_not_equal_test();
			static bool i32_ui32_not_equal_test();

			static bool ui8_i8_not_equal_test();
			static bool ui8_i16_not_equal_test();
			static bool ui8_i32_not_equal_test();
			static bool ui8_ui16_not_equal_test();
			static bool ui8_ui32_not_equal_test();

			static bool ui16_i8_not_equal_test();
			static bool ui16_i16_not_equal_test();
			static bool ui16_i32_not_equal_test();
			static bool ui16_ui8_not_equal_test();
			static bool ui16_ui32_not_equal_test();

			static bool ui32_i8_not_equal_test();
			static bool ui32_i16_not_equal_test();
			static bool ui32_i32_not_equal_test();
			static bool ui32_ui8_not_equal_test();
			static bool ui32_ui16_not_equal_test();
	};
} // namespace Test::Unit

#endif
