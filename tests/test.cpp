#include "unit/i_test.hpp"
#include "unit/r_test.hpp"
#include "unit/si_test.hpp"

using namespace Test;

int main(int argc, char* argv[]) {
	Stats stats;
	print_header();

	switch(argv[1][0]) {
		case 'r': 
			r_tests(stats);
			break;
		case 'i':
			i_tests(stats);
			break;
		case 's': 
			if(argv[1][1] == 'i') si_tests(stats);
			break;
		default:
			r_tests(stats);
			i_tests(stats);
			si_tests(stats);
	}

	std::cout << std::endl << "Passed: " << stats.passed << "  Failed: " << stats.failed << std::endl;
	return stats.failed == 0 ? 0 : 1;
}