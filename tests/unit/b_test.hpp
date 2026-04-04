#ifndef B_TEST_HPP
#define B_TEST_HPP

#include "b-type/beq.hpp"

namespace Test {
	using TestFn = bool (*)();

	static const std::array<TestFn, 42> beq_tests = {
		&Unit::BeqTester::i8_i8_equal_test,      &Unit::BeqTester::i8_i8_not_equal_test,
		&Unit::BeqTester::i16_i16_equal_test,    &Unit::BeqTester::i16_i16_not_equal_test,
		&Unit::BeqTester::i32_i32_equal_test,    &Unit::BeqTester::i32_i32_not_equal_test,
		&Unit::BeqTester::ui8_ui8_equal_test,    &Unit::BeqTester::ui8_ui8_not_equal_test,
		&Unit::BeqTester::ui16_ui16_equal_test,  &Unit::BeqTester::ui16_ui16_not_equal_test,
		&Unit::BeqTester::ui32_ui32_equal_test,  &Unit::BeqTester::ui32_ui32_not_equal_test,

		&Unit::BeqTester::i8_i16_not_equal_test,   &Unit::BeqTester::i8_i32_not_equal_test,
		&Unit::BeqTester::i8_ui8_not_equal_test,   &Unit::BeqTester::i8_ui16_not_equal_test,
		&Unit::BeqTester::i8_ui32_not_equal_test,

		&Unit::BeqTester::i16_i8_not_equal_test,   &Unit::BeqTester::i16_i32_not_equal_test,
		&Unit::BeqTester::i16_ui8_not_equal_test,  &Unit::BeqTester::i16_ui16_not_equal_test,
		&Unit::BeqTester::i16_ui32_not_equal_test,

		&Unit::BeqTester::i32_i8_not_equal_test,   &Unit::BeqTester::i32_i16_not_equal_test,
		&Unit::BeqTester::i32_ui8_not_equal_test,  &Unit::BeqTester::i32_ui16_not_equal_test,
		&Unit::BeqTester::i32_ui32_not_equal_test,

		&Unit::BeqTester::ui8_i8_not_equal_test,   &Unit::BeqTester::ui8_i16_not_equal_test,
		&Unit::BeqTester::ui8_i32_not_equal_test,  &Unit::BeqTester::ui8_ui16_not_equal_test,
		&Unit::BeqTester::ui8_ui32_not_equal_test,

		&Unit::BeqTester::ui16_i8_not_equal_test,  &Unit::BeqTester::ui16_i16_not_equal_test,
		&Unit::BeqTester::ui16_i32_not_equal_test, &Unit::BeqTester::ui16_ui8_not_equal_test,
		&Unit::BeqTester::ui16_ui32_not_equal_test,

		&Unit::BeqTester::ui32_i8_not_equal_test,  &Unit::BeqTester::ui32_i16_not_equal_test,
		&Unit::BeqTester::ui32_i32_not_equal_test, &Unit::BeqTester::ui32_ui8_not_equal_test,
		&Unit::BeqTester::ui32_ui16_not_equal_test,
	};

	static const std::array<std::string, 42> beq_test_names = {
		"i8 == i8 (equal)",      "i8 == i8 (not equal)",
		"i16 == i16 (equal)",    "i16 == i16 (not equal)",
		"i32 == i32 (equal)",    "i32 == i32 (not equal)",
		"ui8 == ui8 (equal)",    "ui8 == ui8 (not equal)",
		"ui16 == ui16 (equal)",  "ui16 == ui16 (not equal)",
		"ui32 == ui32 (equal)",  "ui32 == ui32 (not equal)",

		"i8 == i16 (not equal)",   "i8 == i32 (not equal)",
		"i8 == ui8 (not equal)",   "i8 == ui16 (not equal)",
		"i8 == ui32 (not equal)",

		"i16 == i8 (not equal)",   "i16 == i32 (not equal)",
		"i16 == ui8 (not equal)",  "i16 == ui16 (not equal)",
		"i16 == ui32 (not equal)",

		"i32 == i8 (not equal)",   "i32 == i16 (not equal)",
		"i32 == ui8 (not equal)",  "i32 == ui16 (not equal)",
		"i32 == ui32 (not equal)",

		"ui8 == i8 (not equal)",   "ui8 == i16 (not equal)",
		"ui8 == i32 (not equal)",  "ui8 == ui16 (not equal)",
		"ui8 == ui32 (not equal)",

		"ui16 == i8 (not equal)",  "ui16 == i16 (not equal)",
		"ui16 == i32 (not equal)", "ui16 == ui8 (not equal)",
		"ui16 == ui32 (not equal)",

		"ui32 == i8 (not equal)",  "ui32 == i16 (not equal)",
		"ui32 == i32 (not equal)", "ui32 == ui8 (not equal)",
		"ui32 == ui16 (not equal)",
	};

	void beq_test(Stats &stats) {
		int i = 0;
		for (auto test : beq_tests) {
			bool ok = test();
			print_result(stats, "BEQ", beq_test_names[i], ok);
			i++;
		}
	}

	void b_tests(Stats &stats) { beq_test(stats); }
}

#endif