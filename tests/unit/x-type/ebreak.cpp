#include "ebreak.hpp"

namespace Test::Unit {
	static constexpr uint32_t EBREAK = 0x00100073;

	bool EbreakTester::test() {
		Simulator::CPU cpu;

		bool before = cpu.get_ebreak();
		cpu.execute_instruction(EBREAK);
		bool after = cpu.get_ebreak();

		return !before && after;
	}
} // namespace Test::Unit