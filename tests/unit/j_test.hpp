#ifndef J_TEST_HPP
#define J_TEST_HPP

#include "j-type/jal.hpp"

namespace Test {
	using TestFn = bool (*)();

	static const std::array<TestFn, 6> jal_tests = {&Unit::JalTester::i8_test,   &Unit::JalTester::i16_test,
											   &Unit::JalTester::i32_test,  &Unit::JalTester::ui8_test,
											   &Unit::JalTester::ui16_test, &Unit::JalTester::ui32_test};

	static const std::array<std::string, 6> jal_test_names = {"i8 jal",  "i16 jal",  "i32 jal",
											   "ui8 jal", "ui16 jal", "ui32 jal"};

	void jal_test(Stats &stats) {
		int i = 0;
		for (auto test : jal_tests) {
			bool ok = test();
			print_result(stats, "JAL", jal_test_names[i], ok);
			i++;
		}
	}

}

#endif