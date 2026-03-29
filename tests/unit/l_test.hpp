#ifndef L_TEST_HPP
#define L_TEST_HPP

#include "l-type/l.hpp"

namespace Test {
    using TestFn = bool (*)();

    static const std::array<TestFn, 6> l_tests = {&Unit::LTester::i8_test,   &Unit::LTester::i16_test,
                                                         &Unit::LTester::i32_test,  &Unit::LTester::ui8_test,
                                                         &Unit::LTester::ui16_test, &Unit::LTester::ui32_test};

    static const std::array<std::string, 6> l_test_names = {"LB",	 "LH",	"LW",
                                                                   "LBU", "LHU", "LWU"};


    void l_test(Stats &stats) {
        int i = 0;
        for (auto test : l_tests) {
            bool ok = test();
            print_result(stats, "L", l_test_names[i], ok);
            i++;
        }
    }
} // namespace Test

#endif