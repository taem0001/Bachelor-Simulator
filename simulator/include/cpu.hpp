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

	class CPU {
		public:
			CPU();
			void execute_instruction(int instruction);

			std::array<Register, REGISTERNUM> &get_registers() const;

		private:
			std::array<Register, REGISTERNUM> registers;
			int pc;

			void r_instruction(const char rd, const char func3, const char rs1,
							   const char rs2);
	};
} // namespace Simulator

#endif
