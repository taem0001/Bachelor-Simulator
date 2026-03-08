#ifndef CTSW_HPP
#define CTSW_HPP

#include "../../../simulator/include/cpu.hpp"
#include "../../../simulator/include/includes.hpp"
#include "../../test_utils.hpp"

namespace Test::Unit {
    struct CtswTester {
            static bool i8_test();
            static bool i16_test();
            static bool i32_test();
            static bool ui8_test();
            static bool ui16_test();
            static bool ui32_test();
    };
} // namespace Test::Unit

#endif