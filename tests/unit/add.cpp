#include "add.hpp"

namespace Test::Unit {
	bool AddTester::i8_i8_test() {
		Simulator::CPU cpu;
		cpu.set_register(5, static_cast<int8_t>(55), Simulator::TAG::SB);
		cpu.set_register(6, static_cast<int8_t>(10), Simulator::TAG::SB);
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
		cpu.set_register(5, static_cast<int16_t>(300), Simulator::TAG::SH);
		cpu.set_register(6, static_cast<int16_t>(340), Simulator::TAG::SH);
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
		cpu.set_register(5, static_cast<int32_t>(23590), Simulator::TAG::SW);
		cpu.set_register(6, static_cast<int32_t>(234222), Simulator::TAG::SW);
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
		cpu.set_register(5, static_cast<uint8_t>(101), Simulator::TAG::UB);
		cpu.set_register(6, static_cast<uint8_t>(45), Simulator::TAG::UB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 146;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui16_ui16_test() {
		Simulator::CPU cpu;
		cpu.set_register(5, static_cast<uint16_t>(2401), Simulator::TAG::UB);
		cpu.set_register(6, static_cast<uint16_t>(3455), Simulator::TAG::UB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 5856;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui32_ui32_test() {
		Simulator::CPU cpu;
		cpu.set_register(5, static_cast<uint16_t>(2334224), Simulator::TAG::UB);
		cpu.set_register(6, static_cast<uint16_t>(1043352), Simulator::TAG::UB);
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