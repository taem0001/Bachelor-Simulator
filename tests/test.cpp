#include "unit/i_test.hpp"
#include "unit/r_test.hpp"
#include "unit/si_test.hpp"

using namespace Test;

int main() {
	Stats stats;
	print_header();

	r_tests(stats);
	i_tests(stats);
	si_tests(stats);

	std::cout << std::endl << "Passed: " << stats.passed << "  Failed: " << stats.failed << std::endl;
	return stats.failed == 0 ? 0 : 1;
}