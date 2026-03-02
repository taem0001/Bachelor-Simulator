#include "unit/add.hpp"
#include "unit/sub.hpp"

using TestFn = bool (*)();
using namespace Test;

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

static constexpr std::array<TestFn, 36> sub_tests =
	{
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

static constexpr std::array<std::string, 36>
	sub_test_names = {
		"i8 - i8",	   "i16 - i16",	 "i32 - i32",  "ui8 - ui8",	 "ui16 - ui16", "ui32 - ui32",
		"i8 - i16",	   "i8 - i32",	 "i8 - ui8",   "i8 - ui16",	 "i8 - ui32",	"i16 - i8",
		"i16 - i32",   "i16 - ui8",	 "i16 - ui16", "i16 - ui32", "i32 - i8",	"i32 - i16",
		"i32 - ui8",   "i32 - ui16", "i32 - ui32", "ui8 - i8",	 "ui8 - i16",	"ui8 - i32",
		"ui8 - ui16",  "ui8 - ui32", "ui16 - i8",  "ui16 - i16", "ui16 - i32",	"ui16 - ui8",
		"ui16 - ui32", "ui32 - i8",	 "ui32 - i16", "ui32 - i32", "ui32 - ui8",	"ui32 - ui16",
};

void add_test(Test::Stats &stats) {
	int i = 0;
	for (auto test : add_tests) {
		bool ok = test();
		print_result(stats, "ADD", add_test_names[i], ok);
		i++;
	}
}

void sub_test(Test::Stats &stats) {
    int i = 0;
    for (auto test : sub_tests) {
        bool ok = test();
        print_result(stats, "SUB", sub_test_names[i], ok);
        i++;
    }
}

void r_tests(Test::Stats &stats) {
	add_test(stats);
	sub_test(stats);
}

void i_tests(Test::Stats &stats) {}

int main() {
	Test::Stats stats;
	Test::print_header();

	r_tests(stats);
	i_tests(stats);

	std::cout << std::endl << "Passed: " << stats.passed << "  Failed: " << stats.failed << std::endl;

	return stats.failed == 0 ? 0 : 1;
}