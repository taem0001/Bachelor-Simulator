#include "unit/add.hpp"

void r_tests(Test::Stats &stats) {
	{
		bool ok = Test::Unit::AddTester::i8_i8_test();
		Test::print_result(stats, "ADD", "(i8 + i8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i16_i16_test();
		Test::print_result(stats, "ADD", "(i16 + i16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i32_i32_test();
		Test::print_result(stats, "ADD", "(i32 + i32)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui8_ui8_test();
		Test::print_result(stats, "ADD", "(ui8 + ui8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui16_ui16_test();
		Test::print_result(stats, "ADD", "(ui16 + ui16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui32_ui32_test();
		Test::print_result(stats, "ADD", "(ui32 + ui32)", ok);
	}
}

int main() {
	Test::Stats stats;
	Test::print_header();

	r_tests(stats);

	std::cout << std::endl
			  << "Passed: " << stats.passed << "  Failed: " << stats.failed
			  << std::endl;

	return stats.failed == 0 ? 0 : 1;
}