#include "../include/cpu.hpp"


namespace Simulator {
    Tag _compute_arithmetic_tag(const Tag &t1, const Tag &t2) {
		if (t1 == Tag::UW || t2 == Tag::UW) {
			return Tag::UW;
		}
		return Tag::SW;
	}

	uint32_t _bitwise_add(uint32_t a, uint32_t b) {
		while (b != 0) {
			uint32_t carry = (a & b) << 1;
			a = a ^ b;
			b = carry;
		}
		return a;
	}
}