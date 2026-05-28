#ifndef S_TEST_HPP
#define S_TEST_HPP

#include "s-type/s.hpp"
#include "s-type/stag.hpp"

namespace Test {
	using TestFn = bool (*)();

	static const std::array<TestFn, 6> st_tests = {&Unit::STester::i8_test,	  &Unit::STester::i16_test,
												   &Unit::STester::i32_test,  &Unit::STester::ui8_test,
												   &Unit::STester::ui16_test, &Unit::STester::ui32_test};

	static const std::array<std::string, 6> s_test_names = {"ST i8",  "ST i16",	 "ST i32",
															"ST ui8", "ST ui16", "ST ui32"};

	static const std::array<TestFn, 6> stag_tests = {&Unit::StagTester::i8_test,   &Unit::StagTester::i16_test,
													 &Unit::StagTester::i32_test,  &Unit::StagTester::ui8_test,
													 &Unit::StagTester::ui16_test, &Unit::StagTester::ui32_test};

	static const std::array<std::string, 6> stag_test_names = {"STAG i8",  "STAG i16",	"STAG i32",
															   "STAG ui8", "STAG ui16", "STAG ui32"};
	void st_test(Stats &stats) {
		int i = 0;
		for (auto test : st_tests) {
			bool ok = test();
			print_result(stats, "S", s_test_names[i], ok);
			i++;
		}
	}

	void stag_test(Stats &stats) {
		int i = 0;
		for (auto test : stag_tests) {
			bool ok = test();
			print_result(stats, "S", stag_test_names[i], ok);
			i++;
		}
	}

	void s_tests(Stats &stats) {
		st_test(stats);
		stag_test(stats);
	}
} // namespace Test

#endif