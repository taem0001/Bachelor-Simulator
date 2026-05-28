#include "unit/b_test.hpp"
#include "unit/i_test.hpp"
#include "unit/j_test.hpp"
#include "unit/l_test.hpp"
#include "unit/r_test.hpp"
#include "unit/s_test.hpp"
#include "unit/si_test.hpp"
#include "unit/u_test.hpp"
#include "unit/x_test.hpp"

using namespace Test;

int main(int argc, char *argv[]) {
	Stats stats;
	print_header();
	const char arg1 = (argc <= 1) ? 'd' : argv[1][0];
	switch (arg1) {
	case 'b':
		b_tests(stats);
		break;
	case 'r':
		r_tests(stats);
		break;
	case 'i':
		i_tests(stats);
		break;
	case 's':
		if (argv[1][1] == 'i') {
			si_tests(stats);
		} else {
			s_tests(stats);
		}
		break;
	case 'l':
		l_tests(stats);
		break;
	case 'j':
		jal_test(stats);
		break;
	case 'x':
		x_tests(stats);
		break;
	case 'u':
		u_tests(stats);
		break;
	default:
		b_tests(stats);
		r_tests(stats);
		i_tests(stats);
		si_tests(stats);
		l_tests(stats);
		jal_test(stats);
		s_tests(stats);
		u_tests(stats);
		x_tests(stats);
	}

	std::cout << std::endl << "Passed: " << stats.passed << "  Failed: " << stats.failed << std::endl;
	return stats.failed == 0 ? 0 : 1;
}