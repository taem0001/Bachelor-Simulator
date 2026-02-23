#include "../include/cpu.hpp"
#include "../include/instructions.hpp"

void run_sim() {
	Simulator::CPU cpu;

	Simulator::execute_instruction(cpu, 0b0000000010000011000001010110011);	

	for (int i = 0; i < REGISTERNUM; i++) {
		std::cout << "x" << i << ": " << cpu.registers[i] << std::endl;
	}
}

int main() {
	run_sim();
	return 0;
}
