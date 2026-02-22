#ifndef CPU_HPP
#define CPU_HPP

#include "includes.hpp"
#include "util.hpp"

namespace Simulator {
	struct Register {
			int data;
			TAG tag;

			friend std::ostream &operator<<(std::ostream &out, const Register &r) noexcept {
				return out << "("  << r.data << "; " << r.tag << ")";
			}
	};

	struct CPU {
			std::array<Register, REGISTERNUM> registers;
			int pc;

			CPU() : pc(0) {
				for (int i = 0; i < REGISTERNUM; i++) {
					registers[i] = {0, TAG::SW};
					if (i == 3) {
						registers[i] = {2, TAG::UW};
					}
					if (i == 4) {
						registers[i] = {3, TAG::SW};
					}
				}
			}
	};
} // namespace Simulator

#endif
