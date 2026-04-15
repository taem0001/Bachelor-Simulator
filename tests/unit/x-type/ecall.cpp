#include "ecall.hpp"

#include <sstream>

namespace Test::Unit {
	static constexpr uint32_t ECALL = 0x00000073;

	bool EcallTester::print_int_test() {
		Simulator::CPU cpu;
		cpu.set_register(17, 1, Simulator::Tag::UW);
		cpu.set_register(10, 42, Simulator::Tag::UW);

		std::ostringstream output;
		auto *const original = std::cout.rdbuf(output.rdbuf());
		cpu.execute_instruction(ECALL);
		std::cout.rdbuf(original);

		return !cpu.get_ebreak() && output.str() == "42";
	}

	bool EcallTester::exit_test() {
		Simulator::CPU cpu;
		cpu.set_register(17, 93, Simulator::Tag::UW);
		cpu.set_register(10, 7, Simulator::Tag::UW);

		cpu.execute_instruction(ECALL);

		return cpu.get_ebreak();
	}
} // namespace Test::Unit