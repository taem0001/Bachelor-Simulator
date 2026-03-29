#ifndef s_TEST_HPP
#define s_TEST_HPP

#include "s-type/s.hpp"

namespace Test {
    using TestFn = bool (*)();

    static const std::array<TestFn, 6> s_tests = {&Unit::STester::i8_test,   &Unit::STester::i16_test,
                                                         &Unit::STester::i32_test,  &Unit::STester::ui8_test,
                                                         &Unit::STester::ui16_test, &Unit::STester::ui32_test};

    static const std::array<std::string, 6> s_test_names = {"S",	 "S",	"S",
                                                                   "S", "S", "S"};


    void s_test(Stats &stats) {
        int i = 0;
        for (auto test : s_tests) {
            bool ok = test();
            print_result(stats, "S", s_test_names[i], ok);
            i++;
        }
    }
} // namespace Test

#endif