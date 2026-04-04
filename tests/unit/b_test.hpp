#ifndef B_TEST_HPP
#define B_TEST_HPP

#include "b-type/beq.hpp"
#include "b-type/bne.hpp"
#include "b-type/blt.hpp"
#include "b-type/bge.hpp"

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

	static const std::array<TestFn, 42> bne_tests = {
		&Unit::BneTester::i8_i8_equal_test,      &Unit::BneTester::i8_i8_not_equal_test,
		&Unit::BneTester::i16_i16_equal_test,    &Unit::BneTester::i16_i16_not_equal_test,
		&Unit::BneTester::i32_i32_equal_test,    &Unit::BneTester::i32_i32_not_equal_test,
		&Unit::BneTester::ui8_ui8_equal_test,    &Unit::BneTester::ui8_ui8_not_equal_test,
		&Unit::BneTester::ui16_ui16_equal_test,  &Unit::BneTester::ui16_ui16_not_equal_test,
		&Unit::BneTester::ui32_ui32_equal_test,  &Unit::BneTester::ui32_ui32_not_equal_test,

		&Unit::BneTester::i8_i16_not_equal_test,   &Unit::BneTester::i8_i32_not_equal_test,
		&Unit::BneTester::i8_ui8_not_equal_test,   &Unit::BneTester::i8_ui16_not_equal_test,
		&Unit::BneTester::i8_ui32_not_equal_test,

		&Unit::BneTester::i16_i8_not_equal_test,   &Unit::BneTester::i16_i32_not_equal_test,
		&Unit::BneTester::i16_ui8_not_equal_test,  &Unit::BneTester::i16_ui16_not_equal_test,
		&Unit::BneTester::i16_ui32_not_equal_test,

		&Unit::BneTester::i32_i8_not_equal_test,   &Unit::BneTester::i32_i16_not_equal_test,
		&Unit::BneTester::i32_ui8_not_equal_test,  &Unit::BneTester::i32_ui16_not_equal_test,
		&Unit::BneTester::i32_ui32_not_equal_test,

		&Unit::BneTester::ui8_i8_not_equal_test,   &Unit::BneTester::ui8_i16_not_equal_test,
		&Unit::BneTester::ui8_i32_not_equal_test,  &Unit::BneTester::ui8_ui16_not_equal_test,
		&Unit::BneTester::ui8_ui32_not_equal_test,

		&Unit::BneTester::ui16_i8_not_equal_test,  &Unit::BneTester::ui16_i16_not_equal_test,
		&Unit::BneTester::ui16_i32_not_equal_test, &Unit::BneTester::ui16_ui8_not_equal_test,
		&Unit::BneTester::ui16_ui32_not_equal_test,

		&Unit::BneTester::ui32_i8_not_equal_test,  &Unit::BneTester::ui32_i16_not_equal_test,
		&Unit::BneTester::ui32_i32_not_equal_test, &Unit::BneTester::ui32_ui8_not_equal_test,
		&Unit::BneTester::ui32_ui16_not_equal_test,
	};

	static const std::array<std::string, 42> bne_test_names = {
		"i8 != i8 (equal)",      "i8 != i8 (not equal)",
		"i16 != i16 (equal)",    "i16 != i16 (not equal)",
		"i32 != i32 (equal)",    "i32 != i32 (not equal)",
		"ui8 != ui8 (equal)",    "ui8 != ui8 (not equal)",
		"ui16 != ui16 (equal)",  "ui16 != ui16 (not equal)",
		"ui32 != ui32 (equal)",  "ui32 != ui32 (not equal)",

		"i8 != i16 (not equal)",   "i8 != i32 (not equal)",
		"i8 != ui8 (not equal)",   "i8 != ui16 (not equal)",
		"i8 != ui32 (not equal)",

		"i16 != i8 (not equal)",   "i16 != i32 (not equal)",
		"i16 != ui8 (not equal)",  "i16 != ui16 (not equal)",
		"i16 != ui32 (not equal)",

		"i32 != i8 (not equal)",   "i32 != i16 (not equal)",
		"i32 != ui8 (not equal)",  "i32 != ui16 (not equal)",
		"i32 != ui32 (not equal)",

		"ui8 != i8 (not equal)",   "ui8 != i16 (not equal)",
		"ui8 != i32 (not equal)",  "ui8 != ui16 (not equal)",
		"ui8 != ui32 (not equal)",

		"ui16 != i8 (not equal)",  "ui16 != i16 (not equal)",
		"ui16 != i32 (not equal)", "ui16 != ui8 (not equal)",
		"ui16 != ui32 (not equal)",

		"ui32 != i8 (not equal)",  "ui32 != i16 (not equal)",
		"ui32 != i32 (not equal)", "ui32 != ui8 (not equal)",
		"ui32 != ui16 (not equal)",
	};

	static const std::array<TestFn, 72> blt_tests = {
		&Unit::BltTester::i8_i8_less_test,      &Unit::BltTester::i8_i8_not_less_test,
		&Unit::BltTester::i16_i16_less_test,    &Unit::BltTester::i16_i16_not_less_test,
		&Unit::BltTester::i32_i32_less_test,    &Unit::BltTester::i32_i32_not_less_test,
		&Unit::BltTester::ui8_ui8_less_test,    &Unit::BltTester::ui8_ui8_not_less_test,
		&Unit::BltTester::ui16_ui16_less_test,  &Unit::BltTester::ui16_ui16_not_less_test,
		&Unit::BltTester::ui32_ui32_less_test,  &Unit::BltTester::ui32_ui32_not_less_test,

		&Unit::BltTester::i8_i16_less_test,   &Unit::BltTester::i8_i16_not_less_test,
		&Unit::BltTester::i8_i32_less_test,   &Unit::BltTester::i8_i32_not_less_test,
		&Unit::BltTester::i8_ui8_less_test,   &Unit::BltTester::i8_ui8_not_less_test,
		&Unit::BltTester::i8_ui16_less_test,  &Unit::BltTester::i8_ui16_not_less_test,
		&Unit::BltTester::i8_ui32_less_test,  &Unit::BltTester::i8_ui32_not_less_test,

		&Unit::BltTester::i16_i8_less_test,   &Unit::BltTester::i16_i8_not_less_test,
		&Unit::BltTester::i16_i32_less_test,  &Unit::BltTester::i16_i32_not_less_test,
		&Unit::BltTester::i16_ui8_less_test,  &Unit::BltTester::i16_ui8_not_less_test,
		&Unit::BltTester::i16_ui16_less_test, &Unit::BltTester::i16_ui16_not_less_test,
		&Unit::BltTester::i16_ui32_less_test, &Unit::BltTester::i16_ui32_not_less_test,

		&Unit::BltTester::i32_i8_less_test,   &Unit::BltTester::i32_i8_not_less_test,
		&Unit::BltTester::i32_i16_less_test,  &Unit::BltTester::i32_i16_not_less_test,
		&Unit::BltTester::i32_ui8_less_test,  &Unit::BltTester::i32_ui8_not_less_test,
		&Unit::BltTester::i32_ui16_less_test, &Unit::BltTester::i32_ui16_not_less_test,
		&Unit::BltTester::i32_ui32_less_test, &Unit::BltTester::i32_ui32_not_less_test,

		&Unit::BltTester::ui8_i8_less_test,   &Unit::BltTester::ui8_i8_not_less_test,
		&Unit::BltTester::ui8_i16_less_test,  &Unit::BltTester::ui8_i16_not_less_test,
		&Unit::BltTester::ui8_i32_less_test,  &Unit::BltTester::ui8_i32_not_less_test,
		&Unit::BltTester::ui8_ui16_less_test, &Unit::BltTester::ui8_ui16_not_less_test,
		&Unit::BltTester::ui8_ui32_less_test, &Unit::BltTester::ui8_ui32_not_less_test,

		&Unit::BltTester::ui16_i8_less_test,   &Unit::BltTester::ui16_i8_not_less_test,
		&Unit::BltTester::ui16_i16_less_test,  &Unit::BltTester::ui16_i16_not_less_test,
		&Unit::BltTester::ui16_i32_less_test,  &Unit::BltTester::ui16_i32_not_less_test,
		&Unit::BltTester::ui16_ui8_less_test,  &Unit::BltTester::ui16_ui8_not_less_test,
		&Unit::BltTester::ui16_ui32_less_test, &Unit::BltTester::ui16_ui32_not_less_test,

		&Unit::BltTester::ui32_i8_less_test,   &Unit::BltTester::ui32_i8_not_less_test,
		&Unit::BltTester::ui32_i16_less_test,  &Unit::BltTester::ui32_i16_not_less_test,
		&Unit::BltTester::ui32_i32_less_test,  &Unit::BltTester::ui32_i32_not_less_test,
		&Unit::BltTester::ui32_ui8_less_test,  &Unit::BltTester::ui32_ui8_not_less_test,
		&Unit::BltTester::ui32_ui16_less_test, &Unit::BltTester::ui32_ui16_not_less_test,
	};

	static const std::array<std::string, 72> blt_test_names = {
		"i8 < i8 (less)",      "i8 < i8 (not less)",
		"i16 < i16 (less)",    "i16 < i16 (not less)",
		"i32 < i32 (less)",    "i32 < i32 (not less)",
		"ui8 < ui8 (less)",    "ui8 < ui8 (not less)",
		"ui16 < ui16 (less)",  "ui16 < ui16 (not less)",
		"ui32 < ui32 (less)",  "ui32 < ui32 (not less)",

		"i8 < i16 (less)",   "i8 < i16 (not less)",
		"i8 < i32 (less)",   "i8 < i32 (not less)",
		"i8 < ui8 (less)",   "i8 < ui8 (not less)",
		"i8 < ui16 (less)",  "i8 < ui16 (not less)",
		"i8 < ui32 (less)",  "i8 < ui32 (not less)",

		"i16 < i8 (less)",   "i16 < i8 (not less)",
		"i16 < i32 (less)",  "i16 < i32 (not less)",
		"i16 < ui8 (less)",  "i16 < ui8 (not less)",
		"i16 < ui16 (less)", "i16 < ui16 (not less)",
		"i16 < ui32 (less)", "i16 < ui32 (not less)",

		"i32 < i8 (less)",   "i32 < i8 (not less)",
		"i32 < i16 (less)",  "i32 < i16 (not less)",
		"i32 < ui8 (less)",  "i32 < ui8 (not less)",
		"i32 < ui16 (less)", "i32 < ui16 (not less)",
		"i32 < ui32 (less)", "i32 < ui32 (not less)",

		"ui8 < i8 (less)",   "ui8 < i8 (not less)",
		"ui8 < i16 (less)",  "ui8 < i16 (not less)",
		"ui8 < i32 (less)",  "ui8 < i32 (not less)",
		"ui8 < ui16 (less)", "ui8 < ui16 (not less)",
		"ui8 < ui32 (less)", "ui8 < ui32 (not less)",

		"ui16 < i8 (less)",   "ui16 < i8 (not less)",
		"ui16 < i16 (less)",  "ui16 < i16 (not less)",
		"ui16 < i32 (less)",  "ui16 < i32 (not less)",
		"ui16 < ui8 (less)",  "ui16 < ui8 (not less)",
		"ui16 < ui32 (less)", "ui16 < ui32 (not less)",

		"ui32 < i8 (less)",   "ui32 < i8 (not less)",
		"ui32 < i16 (less)",  "ui32 < i16 (not less)",
		"ui32 < i32 (less)",  "ui32 < i32 (not less)",
		"ui32 < ui8 (less)",  "ui32 < ui8 (not less)",
		"ui32 < ui16 (less)", "ui32 < ui16 (not less)",
	};

	static const std::array<TestFn, 72> bge_tests = {
		&Unit::BgeTester::i8_i8_ge_test,      &Unit::BgeTester::i8_i8_less_test,
		&Unit::BgeTester::i16_i16_ge_test,    &Unit::BgeTester::i16_i16_less_test,
		&Unit::BgeTester::i32_i32_ge_test,    &Unit::BgeTester::i32_i32_less_test,
		&Unit::BgeTester::ui8_ui8_ge_test,    &Unit::BgeTester::ui8_ui8_less_test,
		&Unit::BgeTester::ui16_ui16_ge_test,  &Unit::BgeTester::ui16_ui16_less_test,
		&Unit::BgeTester::ui32_ui32_ge_test,  &Unit::BgeTester::ui32_ui32_less_test,

		&Unit::BgeTester::i8_i16_ge_test,   &Unit::BgeTester::i8_i16_less_test,
		&Unit::BgeTester::i8_i32_ge_test,   &Unit::BgeTester::i8_i32_less_test,
		&Unit::BgeTester::i8_ui8_ge_test,   &Unit::BgeTester::i8_ui8_less_test,
		&Unit::BgeTester::i8_ui16_ge_test,  &Unit::BgeTester::i8_ui16_less_test,
		&Unit::BgeTester::i8_ui32_ge_test,  &Unit::BgeTester::i8_ui32_less_test,

		&Unit::BgeTester::i16_i8_ge_test,   &Unit::BgeTester::i16_i8_less_test,
		&Unit::BgeTester::i16_i32_ge_test,  &Unit::BgeTester::i16_i32_less_test,
		&Unit::BgeTester::i16_ui8_ge_test,  &Unit::BgeTester::i16_ui8_less_test,
		&Unit::BgeTester::i16_ui16_ge_test, &Unit::BgeTester::i16_ui16_less_test,
		&Unit::BgeTester::i16_ui32_ge_test, &Unit::BgeTester::i16_ui32_less_test,

		&Unit::BgeTester::i32_i8_ge_test,   &Unit::BgeTester::i32_i8_less_test,
		&Unit::BgeTester::i32_i16_ge_test,  &Unit::BgeTester::i32_i16_less_test,
		&Unit::BgeTester::i32_ui8_ge_test,  &Unit::BgeTester::i32_ui8_less_test,
		&Unit::BgeTester::i32_ui16_ge_test, &Unit::BgeTester::i32_ui16_less_test,
		&Unit::BgeTester::i32_ui32_ge_test, &Unit::BgeTester::i32_ui32_less_test,

		&Unit::BgeTester::ui8_i8_ge_test,   &Unit::BgeTester::ui8_i8_less_test,
		&Unit::BgeTester::ui8_i16_ge_test,  &Unit::BgeTester::ui8_i16_less_test,
		&Unit::BgeTester::ui8_i32_ge_test,  &Unit::BgeTester::ui8_i32_less_test,
		&Unit::BgeTester::ui8_ui16_ge_test, &Unit::BgeTester::ui8_ui16_less_test,
		&Unit::BgeTester::ui8_ui32_ge_test, &Unit::BgeTester::ui8_ui32_less_test,

		&Unit::BgeTester::ui16_i8_ge_test,   &Unit::BgeTester::ui16_i8_less_test,
		&Unit::BgeTester::ui16_i16_ge_test,  &Unit::BgeTester::ui16_i16_less_test,
		&Unit::BgeTester::ui16_i32_ge_test,  &Unit::BgeTester::ui16_i32_less_test,
		&Unit::BgeTester::ui16_ui8_ge_test,  &Unit::BgeTester::ui16_ui8_less_test,
		&Unit::BgeTester::ui16_ui32_ge_test, &Unit::BgeTester::ui16_ui32_less_test,

		&Unit::BgeTester::ui32_i8_ge_test,   &Unit::BgeTester::ui32_i8_less_test,
		&Unit::BgeTester::ui32_i16_ge_test,  &Unit::BgeTester::ui32_i16_less_test,
		&Unit::BgeTester::ui32_i32_ge_test,  &Unit::BgeTester::ui32_i32_less_test,
		&Unit::BgeTester::ui32_ui8_ge_test,  &Unit::BgeTester::ui32_ui8_less_test,
		&Unit::BgeTester::ui32_ui16_ge_test, &Unit::BgeTester::ui32_ui16_less_test,
	};

	static const std::array<std::string, 72> bge_test_names = {
		"i8 >= i8 (ge)",      "i8 >= i8 (less)",
		"i16 >= i16 (ge)",    "i16 >= i16 (less)",
		"i32 >= i32 (ge)",    "i32 >= i32 (less)",
		"ui8 >= ui8 (ge)",    "ui8 >= ui8 (less)",
		"ui16 >= ui16 (ge)",  "ui16 >= ui16 (less)",
		"ui32 >= ui32 (ge)",  "ui32 >= ui32 (less)",

		"i8 >= i16 (ge)",   "i8 >= i16 (less)",
		"i8 >= i32 (ge)",   "i8 >= i32 (less)",
		"i8 >= ui8 (ge)",   "i8 >= ui8 (less)",
		"i8 >= ui16 (ge)",  "i8 >= ui16 (less)",
		"i8 >= ui32 (ge)",  "i8 >= ui32 (less)",

		"i16 >= i8 (ge)",   "i16 >= i8 (less)",
		"i16 >= i32 (ge)",  "i16 >= i32 (less)",
		"i16 >= ui8 (ge)",  "i16 >= ui8 (less)",
		"i16 >= ui16 (ge)", "i16 >= ui16 (less)",
		"i16 >= ui32 (ge)", "i16 >= ui32 (less)",

		"i32 >= i8 (ge)",   "i32 >= i8 (less)",
		"i32 >= i16 (ge)",  "i32 >= i16 (less)",
		"i32 >= ui8 (ge)",  "i32 >= ui8 (less)",
		"i32 >= ui16 (ge)", "i32 >= ui16 (less)",
		"i32 >= ui32 (ge)", "i32 >= ui32 (less)",

		"ui8 >= i8 (ge)",   "ui8 >= i8 (less)",
		"ui8 >= i16 (ge)",  "ui8 >= i16 (less)",
		"ui8 >= i32 (ge)",  "ui8 >= i32 (less)",
		"ui8 >= ui16 (ge)", "ui8 >= ui16 (less)",
		"ui8 >= ui32 (ge)", "ui8 >= ui32 (less)",

		"ui16 >= i8 (ge)",   "ui16 >= i8 (less)",
		"ui16 >= i16 (ge)",  "ui16 >= i16 (less)",
		"ui16 >= i32 (ge)",  "ui16 >= i32 (less)",
		"ui16 >= ui8 (ge)",  "ui16 >= ui8 (less)",
		"ui16 >= ui32 (ge)", "ui16 >= ui32 (less)",

		"ui32 >= i8 (ge)",   "ui32 >= i8 (less)",
		"ui32 >= i16 (ge)",  "ui32 >= i16 (less)",
		"ui32 >= i32 (ge)",  "ui32 >= i32 (less)",
		"ui32 >= ui8 (ge)",  "ui32 >= ui8 (less)",
		"ui32 >= ui16 (ge)", "ui32 >= ui16 (less)",
	};

	void beq_test(Stats &stats) {
		int i = 0;
		for (auto test : beq_tests) {
			bool ok = test();
			print_result(stats, "BEQ", beq_test_names[i], ok);
			i++;
		}
	}

	void bne_test(Stats &stats) {
		int i = 0;
		for (auto test : bne_tests) {
			bool ok = test();
			print_result(stats, "BNE", bne_test_names[i], ok);
			i++;
		}
	}

	void blt_test(Stats &stats) {
		int i = 0;
		for (auto test : blt_tests) {
			bool ok = test();
			print_result(stats, "BLT", blt_test_names[i], ok);
			i++;
		}
	}

	void bge_test(Stats &stats) {
		int i = 0;
		for (auto test : bge_tests) {
			bool ok = test();
			print_result(stats, "BGE", bge_test_names[i], ok);
			i++;
		}
	}

	void b_tests(Stats &stats) {
		beq_test(stats);
		bne_test(stats);
		blt_test(stats);
		bge_test(stats);
	}
}

#endif