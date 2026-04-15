#ifndef U_TEST_HPP
#define U_TEST_HPP

#include "u-type/auipc.hpp"
#include "u-type/lui.hpp"

namespace Test {
	using TestFn = bool (*)();

	static const std::array<TestFn, 6> lui_tests = {&Unit::LuiTester::i8_test,   &Unit::LuiTester::i16_test,
													   &Unit::LuiTester::i32_test,  &Unit::LuiTester::ui8_test,
													   &Unit::LuiTester::ui16_test, &Unit::LuiTester::ui32_test};

	static const std::array<std::string, 6> lui_test_names = {"i8 lui",  "i16 lui",  "i32 lui",
														  "ui8 lui", "ui16 lui", "ui32 lui"};

	static const std::array<TestFn, 6> auipc_tests = {&Unit::AuipcTester::i8_test,   &Unit::AuipcTester::i16_test,
														 &Unit::AuipcTester::i32_test,  &Unit::AuipcTester::ui8_test,
														 &Unit::AuipcTester::ui16_test, &Unit::AuipcTester::ui32_test};

	static const std::array<std::string, 6> auipc_test_names = {"i8 auipc",  "i16 auipc",  "i32 auipc",
															"ui8 auipc", "ui16 auipc", "ui32 auipc"};

	void lui_test(Stats &stats) {
		int i = 0;
		for (auto test : lui_tests) {
			bool ok = test();
			print_result(stats, "LUI", lui_test_names[i], ok);
			i++;
		}
	}

	void auipc_test(Stats &stats) {
		int i = 0;
		for (auto test : auipc_tests) {
			bool ok = test();
			print_result(stats, "AUIPC", auipc_test_names[i], ok);
			i++;
		}
	}

	void u_tests(Stats &stats) {
		lui_test(stats);
		auipc_test(stats);
	}
} // namespace Test

#endif