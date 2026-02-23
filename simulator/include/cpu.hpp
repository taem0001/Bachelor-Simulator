#ifndef CPU_HPP
#define CPU_HPP

#include "includes.hpp"
#include "util.hpp"

namespace Simulator {
	struct Register {
			Data data;
			TAG tag;

			friend std::ostream &operator<<(std::ostream &out,
											const Register &r) noexcept {
				return out << "(" << r.data << "; " << r.tag << ")";
			}
	};

	struct CPU {
			std::array<Register, REGISTERNUM> registers;
			int pc;

			CPU() : pc(0) {
				for (int i = 0; i < REGISTERNUM; i++) {
					registers[i] = {0, TAG::SW};
				}
				registers[3] = {static_cast<uint32_t>(3), TAG::UW};
				registers[4] = {1, TAG::SW};
			}
	};
} // namespace Simulator

#endif
