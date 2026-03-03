#include "unit/add.hpp"
#include "unit/addi.hpp"
#include "unit/sl.hpp"
#include "unit/sli.hpp"
#include "unit/sr.hpp"
#include "unit/sri.hpp"
#include "unit/sub.hpp"

using TestFn = bool (*)();
using namespace Test;

// Tests defined
static constexpr std::array<TestFn, 36> add_tests = {
	&Unit::AddTester::i8_i8_test,	 &Unit::AddTester::i16_i16_test,   &Unit::AddTester::i32_i32_test,
	&Unit::AddTester::ui8_ui8_test,	 &Unit::AddTester::ui16_ui16_test, &Unit::AddTester::ui32_ui32_test,

	&Unit::AddTester::i8_i16_test,	 &Unit::AddTester::i8_i32_test,	   &Unit::AddTester::i8_ui8_test,
	&Unit::AddTester::i8_ui16_test,	 &Unit::AddTester::i8_ui32_test,

	&Unit::AddTester::i16_i8_test,	 &Unit::AddTester::i16_i32_test,   &Unit::AddTester::i16_ui8_test,
	&Unit::AddTester::i16_ui16_test, &Unit::AddTester::i16_ui32_test,

	&Unit::AddTester::i32_i8_test,	 &Unit::AddTester::i32_i16_test,   &Unit::AddTester::i32_ui8_test,
	&Unit::AddTester::i32_ui16_test, &Unit::AddTester::i32_ui32_test,

	&Unit::AddTester::ui8_i8_test,	 &Unit::AddTester::ui8_i16_test,   &Unit::AddTester::ui8_i32_test,
	&Unit::AddTester::ui8_ui16_test, &Unit::AddTester::ui8_ui32_test,

	&Unit::AddTester::ui16_i8_test,	 &Unit::AddTester::ui16_i16_test,  &Unit::AddTester::ui16_i32_test,
	&Unit::AddTester::ui16_ui8_test, &Unit::AddTester::ui16_ui32_test,

	&Unit::AddTester::ui32_i8_test,	 &Unit::AddTester::ui32_i16_test,  &Unit::AddTester::ui32_i32_test,
	&Unit::AddTester::ui32_ui8_test, &Unit::AddTester::ui32_ui16_test,
};

static constexpr std::array<std::string, 36> add_test_names = {
	"i8 + i8",	  "i16 + i16",	"i32 + i32",  "ui8 + ui8",	 "ui16 + ui16", "ui32 + ui32", "i8 + i16",	  "i8 + i32",
	"i8 + ui8",	  "i8 + ui16",	"i8 + ui32",  "i16 + i8",	 "i16 + i32",	"i16 + ui8",   "i16 + ui16",  "i16 + ui32",
	"i32 + i8",	  "i32 + i16",	"i32 + ui8",  "i32 + ui16",	 "i32 + ui32",	"ui8 + i8",	   "ui8 + i16",	  "ui8 + i32",
	"ui8 + ui16", "ui8 + ui32", "ui16 + i8",  "ui16 + i16",	 "ui16 + i32",	"ui16 + ui8",  "ui16 + ui32", "ui32 + i8",
	"ui32 + i16", "ui32 + i32", "ui32 + ui8", "ui32 + ui16",
};

static constexpr std::array<TestFn, 36> sub_tests = {
	&Unit::SubTester::i8_i8_test,	 &Unit::SubTester::i16_i16_test,   &Unit::SubTester::i32_i32_test,
	&Unit::SubTester::ui8_ui8_test,	 &Unit::SubTester::ui16_ui16_test, &Unit::SubTester::ui32_ui32_test,

	&Unit::SubTester::i8_i16_test,	 &Unit::SubTester::i8_i32_test,	   &Unit::SubTester::i8_ui8_test,
	&Unit::SubTester::i8_ui16_test,	 &Unit::SubTester::i8_ui32_test,

	&Unit::SubTester::i16_i8_test,	 &Unit::SubTester::i16_i32_test,   &Unit::SubTester::i16_ui8_test,
	&Unit::SubTester::i16_ui16_test, &Unit::SubTester::i16_ui32_test,

	&Unit::SubTester::i32_i8_test,	 &Unit::SubTester::i32_i16_test,   &Unit::SubTester::i32_ui8_test,
	&Unit::SubTester::i32_ui16_test, &Unit::SubTester::i32_ui32_test,

	&Unit::SubTester::ui8_i8_test,	 &Unit::SubTester::ui8_i16_test,   &Unit::SubTester::ui8_i32_test,
	&Unit::SubTester::ui8_ui16_test, &Unit::SubTester::ui8_ui32_test,

	&Unit::SubTester::ui16_i8_test,	 &Unit::SubTester::ui16_i16_test,  &Unit::SubTester::ui16_i32_test,
	&Unit::SubTester::ui16_ui8_test, &Unit::SubTester::ui16_ui32_test,

	&Unit::SubTester::ui32_i8_test,	 &Unit::SubTester::ui32_i16_test,  &Unit::SubTester::ui32_i32_test,
	&Unit::SubTester::ui32_ui8_test, &Unit::SubTester::ui32_ui16_test,
};

static constexpr std::array<std::string, 36> sub_test_names = {
	"i8 - i8",	  "i16 - i16",	"i32 - i32",  "ui8 - ui8",	 "ui16 - ui16", "ui32 - ui32", "i8 - i16",	  "i8 - i32",
	"i8 - ui8",	  "i8 - ui16",	"i8 - ui32",  "i16 - i8",	 "i16 - i32",	"i16 - ui8",   "i16 - ui16",  "i16 - ui32",
	"i32 - i8",	  "i32 - i16",	"i32 - ui8",  "i32 - ui16",	 "i32 - ui32",	"ui8 - i8",	   "ui8 - i16",	  "ui8 - i32",
	"ui8 - ui16", "ui8 - ui32", "ui16 - i8",  "ui16 - i16",	 "ui16 - i32",	"ui16 - ui8",  "ui16 - ui32", "ui32 - i8",
	"ui32 - i16", "ui32 - i32", "ui32 - ui8", "ui32 - ui16",
};

static constexpr std::array<TestFn, 36> sl_tests = {
	&Unit::SlTester::i8_i8_test,	&Unit::SlTester::i16_i16_test,	 &Unit::SlTester::i32_i32_test,
	&Unit::SlTester::ui8_ui8_test,	&Unit::SlTester::ui16_ui16_test, &Unit::SlTester::ui32_ui32_test,

	&Unit::SlTester::i8_i16_test,	&Unit::SlTester::i8_i32_test,	 &Unit::SlTester::i8_ui8_test,
	&Unit::SlTester::i8_ui16_test,	&Unit::SlTester::i8_ui32_test,

	&Unit::SlTester::i16_i8_test,	&Unit::SlTester::i16_i32_test,	 &Unit::SlTester::i16_ui8_test,
	&Unit::SlTester::i16_ui16_test, &Unit::SlTester::i16_ui32_test,

	&Unit::SlTester::i32_i8_test,	&Unit::SlTester::i32_i16_test,	 &Unit::SlTester::i32_ui8_test,
	&Unit::SlTester::i32_ui16_test, &Unit::SlTester::i32_ui32_test,

	&Unit::SlTester::ui8_i8_test,	&Unit::SlTester::ui8_i16_test,	 &Unit::SlTester::ui8_i32_test,
	&Unit::SlTester::ui8_ui16_test, &Unit::SlTester::ui8_ui32_test,

	&Unit::SlTester::ui16_i8_test,	&Unit::SlTester::ui16_i16_test,	 &Unit::SlTester::ui16_i32_test,
	&Unit::SlTester::ui16_ui8_test, &Unit::SlTester::ui16_ui32_test,

	&Unit::SlTester::ui32_i8_test,	&Unit::SlTester::ui32_i16_test,	 &Unit::SlTester::ui32_i32_test,
	&Unit::SlTester::ui32_ui8_test, &Unit::SlTester::ui32_ui16_test,
};

static constexpr std::array<std::string, 36> sl_test_names = {
	"i8 << i8",		"i16 << i16",  "i32 << i32",  "ui8 << ui8",	 "ui16 << ui16", "ui32 << ui32",
	"i8 << i16",	"i8 << i32",   "i8 << ui8",	  "i8 << ui16",	 "i8 << ui32",	 "i16 << i8",
	"i16 << i32",	"i16 << ui8",  "i16 << ui16", "i16 << ui32", "i32 << i8",	 "i32 << i16",
	"i32 << ui8",	"i32 << ui16", "i32 << ui32", "ui8 << i8",	 "ui8 << i16",	 "ui8 << i32",
	"ui8 << ui16",	"ui8 << ui32", "ui16 << i8",  "ui16 << i16", "ui16 << i32",	 "ui16 << ui8",
	"ui16 << ui32", "ui32 << i8",  "ui32 << i16", "ui32 << i32", "ui32 << ui8",	 "ui32 << ui16",
};

static constexpr std::array<TestFn, 36> sr_tests = {
	&Unit::SrTester::i8_i8_test,	&Unit::SrTester::i16_i16_test,	 &Unit::SrTester::i32_i32_test,
	&Unit::SrTester::ui8_ui8_test,	&Unit::SrTester::ui16_ui16_test, &Unit::SrTester::ui32_ui32_test,

	&Unit::SrTester::i8_i16_test,	&Unit::SrTester::i8_i32_test,	 &Unit::SrTester::i8_ui8_test,
	&Unit::SrTester::i8_ui16_test,	&Unit::SrTester::i8_ui32_test,

	&Unit::SrTester::i16_i8_test,	&Unit::SrTester::i16_i32_test,	 &Unit::SrTester::i16_ui8_test,
	&Unit::SrTester::i16_ui16_test, &Unit::SrTester::i16_ui32_test,

	&Unit::SrTester::i32_i8_test,	&Unit::SrTester::i32_i16_test,	 &Unit::SrTester::i32_ui8_test,
	&Unit::SrTester::i32_ui16_test, &Unit::SrTester::i32_ui32_test,

	&Unit::SrTester::ui8_i8_test,	&Unit::SrTester::ui8_i16_test,	 &Unit::SrTester::ui8_i32_test,
	&Unit::SrTester::ui8_ui16_test, &Unit::SrTester::ui8_ui32_test,

	&Unit::SrTester::ui16_i8_test,	&Unit::SrTester::ui16_i16_test,	 &Unit::SrTester::ui16_i32_test,
	&Unit::SrTester::ui16_ui8_test, &Unit::SrTester::ui16_ui32_test,

	&Unit::SrTester::ui32_i8_test,	&Unit::SrTester::ui32_i16_test,	 &Unit::SrTester::ui32_i32_test,
	&Unit::SrTester::ui32_ui8_test, &Unit::SrTester::ui32_ui16_test,
};

static constexpr std::array<std::string, 36> sr_test_names = {
	"i8 >> i8",		"i16 >> i16",  "i32 >> i32",  "ui8 >> ui8",	 "ui16 >> ui16", "ui32 >> ui32",
	"i8 >> i16",	"i8 >> i32",   "i8 >> ui8",	  "i8 >> ui16",	 "i8 >> ui32",	 "i16 >> i8",
	"i16 >> i32",	"i16 >> ui8",  "i16 >> ui16", "i16 >> ui32", "i32 >> i8",	 "i32 >> i16",
	"i32 >> ui8",	"i32 >> ui16", "i32 >> ui32", "ui8 >> i8",	 "ui8 >> i16",	 "ui8 >> i32",
	"ui8 >> ui16",	"ui8 >> ui32", "ui16 >> i8",  "ui16 >> i16", "ui16 >> i32",	 "ui16 >> ui8",
	"ui16 >> ui32", "ui32 >> i8",  "ui32 >> i16", "ui32 >> i32", "ui32 >> ui8",	 "ui32 >> ui16",
};

static constexpr std::array<TestFn, 6> sli_tests = {&Unit::SliTester::i8_test,	 &Unit::SliTester::i16_test,
													&Unit::SliTester::i32_test,	 &Unit::SliTester::ui8_test,
													&Unit::SliTester::ui16_test, &Unit::SliTester::ui32_test};

static constexpr std::array<std::string, 6> sli_test_names = {"i8 << imm",	"i16 << imm",  "i32 << imm",
															  "ui8 << imm", "ui16 << imm", "ui32 << imm"};

static constexpr std::array<TestFn, 6> sri_tests = {&Unit::SriTester::i8_test,	 &Unit::SriTester::i16_test,
													&Unit::SriTester::i32_test,	 &Unit::SriTester::ui8_test,
													&Unit::SriTester::ui16_test, &Unit::SriTester::ui32_test};

static constexpr std::array<std::string, 6> sri_test_names = {"i8 >> imm",	"i16 >> imm",  "i32 >> imm",
															  "ui8 >> imm", "ui16 >> imm", "ui32 >> imm"};

static constexpr std::array<TestFn, 6> addi_tests = {&Unit::AddiTester::i8_test,   &Unit::AddiTester::i16_test,
													 &Unit::AddiTester::i32_test,  &Unit::AddiTester::ui8_test,
													 &Unit::AddiTester::ui16_test, &Unit::AddiTester::ui32_test};

static constexpr std::array<std::string, 6> addi_test_names = {"i8 + imm",	"i16 + imm",  "i32 + imm",
															   "ui8 + imm", "ui16 + imm", "ui32 + imm"};

// Call tests
void add_test(Stats &stats) {
	int i = 0;
	for (auto test : add_tests) {
		bool ok = test();
		print_result(stats, "ADD", add_test_names[i], ok);
		i++;
	}
}

void sub_test(Stats &stats) {
	int i = 0;
	for (auto test : sub_tests) {
		bool ok = test();
		print_result(stats, "SUB", sub_test_names[i], ok);
		i++;
	}
}

void sl_test(Stats &stats) {
	int i = 0;
	for (auto test : sl_tests) {
		bool ok = test();
		print_result(stats, "SL", sl_test_names[i], ok);
		i++;
	}
}

void sr_test(Stats &stats) {
	int i = 0;
	for (auto test : sr_tests) {
		bool ok = test();
		print_result(stats, "SR", sr_test_names[i], ok);
		i++;
	}
}

void r_tests(Stats &stats) {
	add_test(stats);
	sub_test(stats);
	sl_test(stats);
	sr_test(stats);
}

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

void i_tests(Stats &stats) {
	sli_test(stats);
	sri_test(stats);
    addi_test(stats);
}

int main() {
	Stats stats;
	print_header();

	r_tests(stats);
	i_tests(stats);

	std::cout << std::endl << "Passed: " << stats.passed << "  Failed: " << stats.failed << std::endl;

	return stats.failed == 0 ? 0 : 1;
}