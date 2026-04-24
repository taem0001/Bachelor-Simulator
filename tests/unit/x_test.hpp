#ifndef X_TEST_HPP
#define X_TEST_HPP

#include "x-type/ebreak.hpp"
#include "x-type/ecall.hpp"

namespace Test {
	using TestFn = bool (*)();

	static const std::array<TestFn, 3> ecall_tests = {
		&Unit::EcallTester::print_int_test, &Unit::EcallTester::print_char_test, &Unit::EcallTester::exit_test};

	static const std::array<std::string, 3> ecall_test_names = {"print integer", "print character", "exit"};

	static const std::array<TestFn, 1> ebreak_tests = {&Unit::EbreakTester::test};

	static const std::array<std::string, 1> ebreak_test_names = {"ebreak"};

	void ecall_test(Stats &stats) {
		int i = 0;
		for (auto test : ecall_tests) {
			bool ok = test();
			print_result(stats, "ECALL", ecall_test_names[i], ok);
			i++;
		}
	}

	void ebreak_test(Stats &stats) {
		int i = 0;
		for (auto test : ebreak_tests) {
			bool ok = test();
			print_result(stats, "EBREAK", ebreak_test_names[i], ok);
			i++;
		}
	}

	void x_tests(Stats &stats) {
		ecall_test(stats);
		ebreak_test(stats);
	}
} // namespace Test

#endif