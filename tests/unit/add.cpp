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

	bool AddTester::i8_i16_test() {
		Simulator::CPU cpu;
		int8_t a = 55;
		int16_t b = 340;
		cpu.set_register(5, a, Simulator::TAG::SB);
		cpu.set_register(6, b, Simulator::TAG::SH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 395;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i8_i32_test() {
		Simulator::CPU cpu;
		int8_t a = 10;
		int32_t b = 234222;
		cpu.set_register(5, a, Simulator::TAG::SB);
		cpu.set_register(6, b, Simulator::TAG::SW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 234232;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i8_ui8_test() {
		Simulator::CPU cpu;
		int8_t a = 55;
		uint8_t b = 45;
		cpu.set_register(5, a, Simulator::TAG::SB);
		cpu.set_register(6, b, Simulator::TAG::UB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 100;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i8_ui16_test() {
		Simulator::CPU cpu;
		int8_t a = 55;
		uint16_t b = 2401;
		cpu.set_register(5, a, Simulator::TAG::SB);
		cpu.set_register(6, b, Simulator::TAG::UH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 2456;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i8_ui32_test() {
		Simulator::CPU cpu;
		int8_t a = 10;
		uint32_t b = 1043352;
		cpu.set_register(5, a, Simulator::TAG::SB);
		cpu.set_register(6, b, Simulator::TAG::UW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 1043362;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::i16_i8_test() {
		Simulator::CPU cpu;
		int16_t a = 300;
		int8_t b = 10;
		cpu.set_register(5, a, Simulator::TAG::SH);
		cpu.set_register(6, b, Simulator::TAG::SB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 310;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i16_i32_test() {
		Simulator::CPU cpu;
		int16_t a = 340;
		int32_t b = 23590;
		cpu.set_register(5, a, Simulator::TAG::SH);
		cpu.set_register(6, b, Simulator::TAG::SW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 23930;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i16_ui8_test() {
		Simulator::CPU cpu;
		int16_t a = 300;
		uint8_t b = 45;
		cpu.set_register(5, a, Simulator::TAG::SH);
		cpu.set_register(6, b, Simulator::TAG::UB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 345;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i16_ui16_test() {
		Simulator::CPU cpu;
		int16_t a = 300;
		uint16_t b = 2401;
		cpu.set_register(5, a, Simulator::TAG::SH);
		cpu.set_register(6, b, Simulator::TAG::UH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 2701;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i16_ui32_test() {
		Simulator::CPU cpu;
		int16_t a = 340;
		uint32_t b = 1043352;
		cpu.set_register(5, a, Simulator::TAG::SH);
		cpu.set_register(6, b, Simulator::TAG::UW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 1043692;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::i32_i8_test() {
		Simulator::CPU cpu;
		int32_t a = 23590;
		int8_t b = 10;
		cpu.set_register(5, a, Simulator::TAG::SW);
		cpu.set_register(6, b, Simulator::TAG::SB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 23600;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i32_i16_test() {
		Simulator::CPU cpu;
		int32_t a = 234222;
		int16_t b = 340;
		cpu.set_register(5, a, Simulator::TAG::SW);
		cpu.set_register(6, b, Simulator::TAG::SH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 234562;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i32_ui8_test() {
		Simulator::CPU cpu;
		int32_t a = 23590;
		uint8_t b = 45;
		cpu.set_register(5, a, Simulator::TAG::SW);
		cpu.set_register(6, b, Simulator::TAG::UB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 23635;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i32_ui16_test() {
		Simulator::CPU cpu;
		int32_t a = 23590;
		uint16_t b = 2401;
		cpu.set_register(5, a, Simulator::TAG::SW);
		cpu.set_register(6, b, Simulator::TAG::UH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 25991;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::i32_ui32_test() {
		Simulator::CPU cpu;
		int32_t a = 23590;
		uint32_t b = 1043352;
		cpu.set_register(5, a, Simulator::TAG::SW);
		cpu.set_register(6, b, Simulator::TAG::UW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 1066942;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui8_i8_test() {
		Simulator::CPU cpu;
		uint8_t a = 101;
		int8_t b = 10;
		cpu.set_register(5, a, Simulator::TAG::UB);
		cpu.set_register(6, b, Simulator::TAG::SB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 111;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui8_i16_test() {
		Simulator::CPU cpu;
		uint8_t a = 101;
		int16_t b = 300;
		cpu.set_register(5, a, Simulator::TAG::UB);
		cpu.set_register(6, b, Simulator::TAG::SH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 401;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui8_i32_test() {
		Simulator::CPU cpu;
		uint8_t a = 45;
		int32_t b = 23590;
		cpu.set_register(5, a, Simulator::TAG::UB);
		cpu.set_register(6, b, Simulator::TAG::SW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 23635;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui8_ui16_test() {
		Simulator::CPU cpu;
		uint8_t a = 45;
		uint16_t b = 2401;
		cpu.set_register(5, a, Simulator::TAG::UB);
		cpu.set_register(6, b, Simulator::TAG::UH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 2446;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui8_ui32_test() {
		Simulator::CPU cpu;
		uint8_t a = 45;
		uint32_t b = 1043352;
		cpu.set_register(5, a, Simulator::TAG::UB);
		cpu.set_register(6, b, Simulator::TAG::UW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 1043397;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui16_i8_test() {
		Simulator::CPU cpu;
		uint16_t a = 2401;
		int8_t b = 10;
		cpu.set_register(5, a, Simulator::TAG::UH);
		cpu.set_register(6, b, Simulator::TAG::SB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 2411;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui16_i16_test() {
		Simulator::CPU cpu;
		uint16_t a = 3455;
		int16_t b = 300;
		cpu.set_register(5, a, Simulator::TAG::UH);
		cpu.set_register(6, b, Simulator::TAG::SH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 3755;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui16_i32_test() {
		Simulator::CPU cpu;
		uint16_t a = 2401;
		int32_t b = 23590;
		cpu.set_register(5, a, Simulator::TAG::UH);
		cpu.set_register(6, b, Simulator::TAG::SW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 25991;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui16_ui8_test() {
		Simulator::CPU cpu;
		uint16_t a = 2401;
		uint8_t b = 45;
		cpu.set_register(5, a, Simulator::TAG::UH);
		cpu.set_register(6, b, Simulator::TAG::UB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<int>(registers[7].data) &&
			std::get<int>(registers[7].data) == 2446;
		const bool passed_tag = registers[7].tag == Simulator::TAG::SW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui16_ui32_test() {
		Simulator::CPU cpu;
		uint16_t a = 3455;
		uint32_t b = 1043352;
		cpu.set_register(5, a, Simulator::TAG::UH);
		cpu.set_register(6, b, Simulator::TAG::UW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 1046807;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui32_i8_test() {
		Simulator::CPU cpu;
		uint32_t a = 1043352;
		int8_t b = 10;
		cpu.set_register(5, a, Simulator::TAG::UW);
		cpu.set_register(6, b, Simulator::TAG::SB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 1043362;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui32_i16_test() {
		Simulator::CPU cpu;
		uint32_t a = 1043352;
		int16_t b = 340;
		cpu.set_register(5, a, Simulator::TAG::UW);
		cpu.set_register(6, b, Simulator::TAG::SH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 1043692;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui32_i32_test() {
		Simulator::CPU cpu;
		uint32_t a = 1043352;
		int32_t b = 23590;
		cpu.set_register(5, a, Simulator::TAG::UW);
		cpu.set_register(6, b, Simulator::TAG::SW);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 1066942;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui32_ui8_test() {
		Simulator::CPU cpu;
		uint32_t a = 1043352;
		uint8_t b = 45;
		cpu.set_register(5, a, Simulator::TAG::UW);
		cpu.set_register(6, b, Simulator::TAG::UB);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 1043397;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}

	bool AddTester::ui32_ui16_test() {
		Simulator::CPU cpu;
		uint32_t a = 1043352;
		uint16_t b = 3455;
		cpu.set_register(5, a, Simulator::TAG::UW);
		cpu.set_register(6, b, Simulator::TAG::UH);
		cpu.execute_instruction(0b00000000011000101000001110110011);

		const std::array<Simulator::Register, REGISTERNUM> registers =
			cpu.get_registers();

		const bool passed_data =
			std::holds_alternative<unsigned int>(registers[7].data) &&
			std::get<unsigned int>(registers[7].data) == 1046807;
		const bool passed_tag = registers[7].tag == Simulator::TAG::UW;
		return passed_data && passed_tag;
	}
} // namespace Test::Unit