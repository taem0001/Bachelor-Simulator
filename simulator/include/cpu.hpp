#ifndef CPU_HPP
#define CPU_HPP

#include "includes.hpp"
#include "tag.hpp"
#include "register.hpp"

namespace Simulator {
	class CPU {
		public:
			CPU();
			void execute_instruction(const int instruction);

			std::array<Register, REGISTERNUM> &get_registers();
			const std::array<Register, REGISTERNUM> &get_registers() const;

			// TODO: THIS FUNCTION IS ONLY FOR TESTING PURPOSES; REMOVE LATER
			void set_register(const char rd, const uint32_t data, const Tag &tag);

		private:
			std::array<Register, REGISTERNUM> registers;
			int pc;

			void write_to_register(const char rd, const Register &r);

			void r_instruction(const char rd, const char func3, const char rs1, const char rs2, const char func7);
			void i_instruction(const char rd, const char func3, const char rs1, const short imm);
			void si_instruction(const char rd, const char func7);
	};
} // namespace Simulator

#endif
