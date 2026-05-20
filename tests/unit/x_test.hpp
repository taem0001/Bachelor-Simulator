#ifndef X_TEST_HPP
#define X_TEST_HPP

#include "x-type/ebreak.hpp"

namespace Test {
	using TestFn = bool (*)();

	static const std::array<TestFn, 1> ebreak_tests = {&Unit::EbreakTester::test};
	static const std::array<std::string, 1> ebreak_test_names = {"ebreak"};

	void ebreak_test(Stats &stats) {
		int i = 0;
		for (auto test : ebreak_tests) {
			bool ok = test();
			print_result(stats, "EBREAK", ebreak_test_names[i], ok);
			i++;
		}
	}

	void x_tests(Stats &stats) {
		ebreak_test(stats);
	}
} // namespace Test

#endif