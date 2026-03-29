#include "unit/i_test.hpp"
#include "unit/r_test.hpp"
#include "unit/si_test.hpp"
#include "unit/l_test.hpp"
#include "unit/s_test.hpp"

using namespace Test;

int main(int argc, char* argv[]) {
	Stats stats;
	print_header();
	const char arg1 = (argc <= 1) ? 'd' : argv[1][0];
	switch(arg1) {
		case 'r': 
			r_tests(stats);
			break;
		case 'i':
			i_tests(stats);
			break;
		case 's': 
			if(argv[1][1] == 'i') {
				si_tests(stats);
			} else {
				s_test(stats);
			}
			break;
		case 'l':
			l_test(stats);
			break;
		default:
			r_tests(stats);
			i_tests(stats);
			si_tests(stats);
			l_test(stats);
			s_test(stats);
	}

	std::cout << std::endl << "Passed: " << stats.passed << "  Failed: " << stats.failed << std::endl;
	return stats.failed == 0 ? 0 : 1;
}