#include "../include/cpu.hpp"

namespace Simulator {
    
	uint32_t bitwise_add(uint32_t a, uint32_t b) {
		while (b != 0) {
			uint32_t carry = (a & b) << 1;
			a = a ^ b;
			b = carry;
		}
		return a;
	}
}