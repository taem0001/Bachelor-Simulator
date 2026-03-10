#ifndef SI_TEST_HPP
#define SI_TEST_HPP

#include "si-type/ctsb.hpp"
#include "si-type/ctsh.hpp"
#include "si-type/ctsw.hpp"
#include "si-type/ctub.hpp"
#include "si-type/ctuh.hpp"
#include "si-type/ctuw.hpp"

namespace Test {
    using TestFn = bool (*)();

    static const std::array<TestFn, 6> ctub_tests = {&Unit::CtubTester::i8_test,   &Unit::CtubTester::i16_test,
                                                         &Unit::CtubTester::i32_test,  &Unit::CtubTester::ui8_test,
                                                         &Unit::CtubTester::ui16_test, &Unit::CtubTester::ui32_test};

    static const std::array<std::string, 6> ctub_test_names = {"i8 -> ui8",	 "i16 -> ui8",	"i32 -> ui8",
                                                                   "ui8 -> ui8", "ui16 -> ui8", "ui32 -> ui8"};

    static const std::array<TestFn, 6> ctuh_tests = {&Unit::CtuhTester::i8_test,   &Unit::CtuhTester::i16_test,
                                                         &Unit::CtuhTester::i32_test,  &Unit::CtuhTester::ui8_test,
                                                         &Unit::CtuhTester::ui16_test, &Unit::CtuhTester::ui32_test};

    static const std::array<std::string, 6> ctuh_test_names = {"i8 -> ui16",  "i16 -> ui16",  "i32 -> ui16",
                                                                   "ui8 -> ui16", "ui16 -> ui16", "ui32 -> ui16"};

    static const std::array<TestFn, 6> ctuw_tests = {&Unit::CtuwTester::i8_test,   &Unit::CtuwTester::i16_test,
                                                         &Unit::CtuwTester::i32_test,  &Unit::CtuwTester::ui8_test,
                                                         &Unit::CtuwTester::ui16_test, &Unit::CtuwTester::ui32_test};

    static const std::array<std::string, 6> ctuw_test_names = {"i8 -> ui32",  "i16 -> ui32",  "i32 -> ui32",
                                                                   "ui8 -> ui32", "ui16 -> ui32", "ui32 -> ui32"};

    static const std::array<TestFn, 6> ctsb_tests = {&Unit::CtsbTester::i8_test,   &Unit::CtsbTester::i16_test,
                                                         &Unit::CtsbTester::i32_test,  &Unit::CtsbTester::ui8_test,
                                                         &Unit::CtsbTester::ui16_test, &Unit::CtsbTester::ui32_test};

    static const std::array<std::string, 6> ctsb_test_names = {"i8 -> i8",	"i16 -> i8",  "i32 -> i8",
                                                                   "ui8 -> i8", "ui16 -> i8", "ui32 -> i8"};

    static const std::array<TestFn, 6> ctsh_tests = {&Unit::CtshTester::i8_test,   &Unit::CtshTester::i16_test,
                                                         &Unit::CtshTester::i32_test,  &Unit::CtshTester::ui8_test,
                                                         &Unit::CtshTester::ui16_test, &Unit::CtshTester::ui32_test};

    static const std::array<std::string, 6> ctsh_test_names = {"i8 -> i16",	 "i16 -> i16",	"i32 -> i16",
                                                                   "ui8 -> i16", "ui16 -> i16", "ui32 -> i16"};

    static const std::array<TestFn, 6> ctsw_tests = {&Unit::CtswTester::i8_test,   &Unit::CtswTester::i16_test,
                                                         &Unit::CtswTester::i32_test,  &Unit::CtswTester::ui8_test,
                                                         &Unit::CtswTester::ui16_test, &Unit::CtswTester::ui32_test};

    static const std::array<std::string, 6> ctsw_test_names = {"i8 -> i32",	 "i16 -> i32",	"i32 -> i32",
                                                                   "ui8 -> i32", "ui16 -> i32", "ui32 -> i32"};

    void ctub_test(Stats &stats) {
        int i = 0;
        for (auto test : ctub_tests) {
            bool ok = test();
            print_result(stats, "CTUB", ctub_test_names[i], ok);
            i++;
        }
    }

    void ctuh_test(Stats &stats) {
        int i = 0;
        for (auto test : ctuh_tests) {
            bool ok = test();
            print_result(stats, "CTUH", ctuh_test_names[i], ok);
            i++;
        }
    }

    void ctuw_test(Stats &stats) {
        int i = 0;
        for (auto test : ctuw_tests) {
            bool ok = test();
            print_result(stats, "CTUW", ctuw_test_names[i], ok);
            i++;
        }
    }

    void ctsb_test(Stats &stats) {
        int i = 0;
        for (auto test : ctsb_tests) {
            bool ok = test();
            print_result(stats, "CTSB", ctsb_test_names[i], ok);
            i++;
        }
    }

    void ctsh_test(Stats &stats) {
        int i = 0;
        for (auto test : ctsh_tests) {
            bool ok = test();
            print_result(stats, "CTSH", ctsh_test_names[i], ok);
            i++;
        }
    }

    void ctsw_test(Stats &stats) {
        int i = 0;
        for (auto test : ctsw_tests) {
            bool ok = test();
            print_result(stats, "CTSW", ctsw_test_names[i], ok);
            i++;
        }
    }

    void si_tests(Stats &stats) {
        ctub_test(stats);
        ctuh_test(stats);
        ctuw_test(stats);
        ctsb_test(stats);
        ctsh_test(stats);
        ctsw_test(stats);
    }
} // namespace Test

#endif