#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include "cpu.hpp"
#include "includes.hpp"
#include "util.hpp"

namespace Simulator {
	void execute_instruction(CPU &cpu, int instruction);
	void r_instruction(std::array<Register, REGISTERNUM> &registers,
					   const char rd, const char func3, const char rs1,
					   const char rs2);
	;
} // namespace Simulator

#endif
