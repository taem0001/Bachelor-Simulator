#ifndef I_TEST_HPP
#define I_TEST_HPP

#include "i-type/addi.hpp"
#include "i-type/sli.hpp"
#include "i-type/sri.hpp"
#include "i-type/slti.hpp"
#include "i-type/xori.hpp"
#include "i-type/ori.hpp"
#include "i-type/andi.hpp"

namespace Test {
	using TestFn = bool (*)();

	static const std::array<TestFn, 6> sli_tests = {&Unit::SliTester::i8_test,	 &Unit::SliTester::i16_test,
														&Unit::SliTester::i32_test,	 &Unit::SliTester::ui8_test,
														&Unit::SliTester::ui16_test, &Unit::SliTester::ui32_test};

	static const std::array<std::string, 6> sli_test_names = {"i8 << imm",	"i16 << imm",  "i32 << imm",
																  "ui8 << imm", "ui16 << imm", "ui32 << imm"};

	static const std::array<TestFn, 6> sri_tests = {&Unit::SriTester::i8_test,	 &Unit::SriTester::i16_test,
														&Unit::SriTester::i32_test,	 &Unit::SriTester::ui8_test,
														&Unit::SriTester::ui16_test, &Unit::SriTester::ui32_test};

	static const std::array<std::string, 6> sri_test_names = {"i8 >> imm",	"i16 >> imm",  "i32 >> imm",
																  "ui8 >> imm", "ui16 >> imm", "ui32 >> imm"};

	static const std::array<TestFn, 6> addi_tests = {&Unit::AddiTester::i8_test,   &Unit::AddiTester::i16_test,
														 &Unit::AddiTester::i32_test,  &Unit::AddiTester::ui8_test,
														 &Unit::AddiTester::ui16_test, &Unit::AddiTester::ui32_test};

	static const std::array<std::string, 6> addi_test_names = {"i8 + imm",	"i16 + imm",  "i32 + imm",
																   "ui8 + imm", "ui16 + imm", "ui32 + imm"};

	static const std::array<TestFn, 6> slti_tests = {&Unit::SltiTester::i8_test,   &Unit::SltiTester::i16_test,
														 &Unit::SltiTester::i32_test,  &Unit::SltiTester::ui8_test,
														 &Unit::SltiTester::ui16_test, &Unit::SltiTester::ui32_test};

	static const std::array<std::string, 6> slti_test_names = {"i8 < imm",	"i16 < imm",  "i32 < imm",
																   "ui8 < imm", "ui16 < imm", "ui32 < imm"};

	static const std::array<TestFn, 6> xori_tests = {&Unit::XoriTester::i8_test,   &Unit::XoriTester::i16_test,
														 &Unit::XoriTester::i32_test,  &Unit::XoriTester::ui8_test,
														 &Unit::XoriTester::ui16_test, &Unit::XoriTester::ui32_test};

	static const std::array<std::string, 6> xori_test_names = {"i8 ^ imm",	"i16 ^ imm",  "i32 ^ imm",
																   "ui8 ^ imm", "ui16 ^ imm", "ui32 ^ imm"};

	static const std::array<TestFn, 6> ori_tests = {&Unit::OriTester::i8_test,   &Unit::OriTester::i16_test,
														 &Unit::OriTester::i32_test,  &Unit::OriTester::ui8_test,
														 &Unit::OriTester::ui16_test, &Unit::OriTester::ui32_test};

	static const std::array<std::string, 6> ori_test_names = {"i8 | imm",	"i16 | imm",  "i32 | imm",
																   "ui8 | imm", "ui16 | imm", "ui32 | imm"};

	static const std::array<TestFn, 6> andi_tests = {&Unit::AndiTester::i8_test,   &Unit::AndiTester::i16_test,
														 &Unit::AndiTester::i32_test,  &Unit::AndiTester::ui8_test,
														 &Unit::AndiTester::ui16_test, &Unit::AndiTester::ui32_test};

	static const std::array<std::string, 6> andi_test_names = {"i8 & imm",	"i16 & imm",  "i32 & imm",
																   "ui8 & imm", "ui16 & imm", "ui32 & imm"};

	void sli_test(Stats &stats) {
		int i = 0;
		for (auto test : sli_tests) {
			bool ok = test();
			print_result(stats, "SLI", sli_test_names[i], ok);
			i++;
		}
	}

	void sri_test(Stats &stats) {
		int i = 0;
		for (auto test : sri_tests) {
			bool ok = test();
			print_result(stats, "SRI", sri_test_names[i], ok);
			i++;
		}
	}

	void addi_test(Stats &stats) {
		int i = 0;
		for (auto test : addi_tests) {
			bool ok = test();
			print_result(stats, "ADDI", addi_test_names[i], ok);
			i++;
		}
	}

	void slti_test(Stats &stats) {
		int i = 0;
		for (auto test : slti_tests) {
			bool ok = test();
			print_result(stats, "SLTI", slti_test_names[i], ok);
			i++;
		}
	}

	void xori_test(Stats &stats) {
		int i = 0;
		for (auto test : xori_tests) {
			bool ok = test();
			print_result(stats, "XORI", xori_test_names[i], ok);
			i++;
		}
	}

	void ori_test(Stats &stats) {
		int i = 0;
		for (auto test : ori_tests) {
			bool ok = test();
			print_result(stats, "ORI", ori_test_names[i], ok);
			i++;
		}
	}

	void andi_test(Stats &stats) {
		int i = 0;
		for (auto test : andi_tests) {
			bool ok = test();
			print_result(stats, "ANDI", andi_test_names[i], ok);
			i++;
		}
	}

	void i_tests(Stats &stats) {
		sli_test(stats);
		sri_test(stats);
		addi_test(stats);
		slti_test(stats);
		xori_test(stats);
		ori_test(stats);
		andi_test(stats);
	}
} // namespace Test

#endif