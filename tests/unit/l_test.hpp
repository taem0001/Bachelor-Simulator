#ifndef L_TEST_HPP
#define L_TEST_HPP

#include "l-type/l.hpp"
#include "l-type/ltag.hpp"

namespace Test {
	using TestFn = bool (*)();

	static const std::array<TestFn, 6> load_tests = {&Unit::LTester::i8_test,	 &Unit::LTester::i16_test,
												  &Unit::LTester::i32_test,	 &Unit::LTester::ui8_test,
												  &Unit::LTester::ui16_test, &Unit::LTester::ui32_test};

	static const std::array<std::string, 6> l_test_names = {"LB", "LH", "LW", "LBU", "LHU", "LWU"};

	static const std::array<TestFn, 6> ltag_tests = {&Unit::LtagTester::i8_test,   &Unit::LtagTester::i16_test,
													 &Unit::LtagTester::i32_test,  &Unit::LtagTester::ui8_test,
													 &Unit::LtagTester::ui16_test, &Unit::LtagTester::ui32_test};

	static const std::array<std::string, 6> ltag_test_names = {"LTB", "LTH", "LTW", "LTBU", "LTHU", "LTWU"};

	void l_test(Stats &stats) {
		int i = 0;
		for (auto test : load_tests) {
			bool ok = test();
			print_result(stats, "L", l_test_names[i], ok);
			i++;
		}
	}

	void ltag_test(Stats &stats) {
		int i = 0;
		for (auto test : ltag_tests) {
			bool ok = test();
			print_result(stats, "LT", ltag_test_names[i], ok);
			i++;
		}
	}

	void l_tests(Stats &stats) {
		l_test(stats);
		ltag_test(stats);
	}
} // namespace Test

#endif