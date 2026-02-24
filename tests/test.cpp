#include "unit/add.hpp"

void add_test(Test::Stats &stats) {
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
	{
		bool ok = Test::Unit::AddTester::i8_i16_test();
		Test::print_result(stats, "ADD", "(i8 + i16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i8_i32_test();
		Test::print_result(stats, "ADD", "(i8 + i32)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i8_ui8_test();
		Test::print_result(stats, "ADD", "(i8 + ui8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i8_ui16_test();
		Test::print_result(stats, "ADD", "(i8 + ui16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i8_ui32_test();
		Test::print_result(stats, "ADD", "(i8 + ui32)", ok);
	}

	{
		bool ok = Test::Unit::AddTester::i16_i8_test();
		Test::print_result(stats, "ADD", "(i16 + i8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i16_i32_test();
		Test::print_result(stats, "ADD", "(i16 + i32)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i16_ui8_test();
		Test::print_result(stats, "ADD", "(i16 + ui8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i16_ui16_test();
		Test::print_result(stats, "ADD", "(i16 + ui16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i16_ui32_test();
		Test::print_result(stats, "ADD", "(i16 + ui32)", ok);
	}

	{
		bool ok = Test::Unit::AddTester::i32_i8_test();
		Test::print_result(stats, "ADD", "(i32 + i8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i32_i16_test();
		Test::print_result(stats, "ADD", "(i32 + i16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i32_ui8_test();
		Test::print_result(stats, "ADD", "(i32 + ui8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i32_ui16_test();
		Test::print_result(stats, "ADD", "(i32 + ui16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::i32_ui32_test();
		Test::print_result(stats, "ADD", "(i32 + ui32)", ok);
	}

	{
		bool ok = Test::Unit::AddTester::ui8_i8_test();
		Test::print_result(stats, "ADD", "(ui8 + i8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui8_i16_test();
		Test::print_result(stats, "ADD", "(ui8 + i16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui8_i32_test();
		Test::print_result(stats, "ADD", "(ui8 + i32)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui8_ui16_test();
		Test::print_result(stats, "ADD", "(ui8 + ui16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui8_ui32_test();
		Test::print_result(stats, "ADD", "(ui8 + ui32)", ok);
	}

	{
		bool ok = Test::Unit::AddTester::ui16_i8_test();
		Test::print_result(stats, "ADD", "(ui16 + i8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui16_i16_test();
		Test::print_result(stats, "ADD", "(ui16 + i16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui16_i32_test();
		Test::print_result(stats, "ADD", "(ui16 + i32)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui16_ui8_test();
		Test::print_result(stats, "ADD", "(ui16 + ui8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui16_ui32_test();
		Test::print_result(stats, "ADD", "(ui16 + ui32)", ok);
	}

	{
		bool ok = Test::Unit::AddTester::ui32_i8_test();
		Test::print_result(stats, "ADD", "(ui32 + i8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui32_i16_test();
		Test::print_result(stats, "ADD", "(ui32 + i16)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui32_i32_test();
		Test::print_result(stats, "ADD", "(ui32 + i32)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui32_ui8_test();
		Test::print_result(stats, "ADD", "(ui32 + ui8)", ok);
	}
	{
		bool ok = Test::Unit::AddTester::ui32_ui16_test();
		Test::print_result(stats, "ADD", "(ui32 + ui16)", ok);
	}
}

void r_tests(Test::Stats &stats) {
	add_test(stats);
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