#include "add.hpp"

namespace Test::Unit {
	bool AddTester::i8_i8_test() {
		Simulator::CPU cpu;
		int8_t a = 55;
		int8_t b = 10;
		cpu.set_register(5, a, Simulator::TAG::SB);
		cpu.set_register(6, b, Simulator::TAG::SB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const auto registers = cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 65;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i16_i16_test() {
		Simulator::CPU cpu;
		int16_t a = 300;
		int16_t b = 340;
		cpu.set_register(5, a, Simulator::TAG::SH);
		cpu.set_register(6, b, Simulator::TAG::SH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 640;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i32_i32_test() {
		Simulator::CPU cpu;
		int32_t a = 23590;
		int32_t b = 234222;
		cpu.set_register(5, a, Simulator::TAG::SW);
		cpu.set_register(6, b, Simulator::TAG::SW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 257812;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui8_ui8_test() {
		Simulator::CPU cpu;
		uint8_t a = 101;
		uint8_t b = 45;
		cpu.set_register(5, a, Simulator::TAG::UB);
		cpu.set_register(6, b, Simulator::TAG::UB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 146;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui16_ui16_test() {
		Simulator::CPU cpu;
		uint16_t a = 2401;
		uint16_t b = 3455;
		cpu.set_register(5, a, Simulator::TAG::UB);
		cpu.set_register(6, b, Simulator::TAG::UB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 5856;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui32_ui32_test() {
		Simulator::CPU cpu;
		uint32_t a = 2334224;
		uint32_t b = 1043352;
		cpu.set_register(5, a, Simulator::TAG::UB);
		cpu.set_register(6, b, Simulator::TAG::UB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 3377576;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}
} // namespace Test::Unit