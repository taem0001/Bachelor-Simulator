#include "sub.hpp"

namespace Test::Unit {
	static constexpr uint32_t SUB_X30_X17_X25 = 0b00000001100110001001111100110011;

	static bool sub_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
						 uint32_t expected_val, Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(17, a_val, a_tag);
		cpu.set_register(25, b_val, b_tag);
		cpu.execute_instruction(SUB_X30_X17_X25);

		const auto registers = cpu.get_registers();

		const bool passed_data = registers[30].data == expected_val;
		const bool passed_tag = registers[30].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool SubTester::i8_i8_test() {
		int8_t a = 45;
		int8_t b = 32;
		return sub_test(a, b, Simulator::Tag::SB, Simulator::Tag::SB, 13, Simulator::Tag::SH);
	}
	bool SubTester::i16_i16_test() {
		int16_t a = 23065;
		int16_t b = -1203;
		return sub_test(a, b, Simulator::Tag::SH, Simulator::Tag::SH, 24268, Simulator::Tag::SW);
	}
	bool SubTester::i32_i32_test() {
		int32_t a = 1000000000;
		int32_t b = -123456789;
		return sub_test(a, b, Simulator::Tag::SW, Simulator::Tag::SW, 1123456789, Simulator::Tag::SW);
	}
	bool SubTester::ui8_ui8_test() {
		uint8_t a = 200;
		uint8_t b = 55;
		return sub_test(a, b, Simulator::Tag::UB, Simulator::Tag::UB, 145, Simulator::Tag::UH);
	}
	bool SubTester::ui16_ui16_test() {
		uint16_t a = 60000;
		uint16_t b = 1234;
		return sub_test(a, b, Simulator::Tag::UH, Simulator::Tag::UH, 58766, Simulator::Tag::UW);
	}
	bool SubTester::ui32_ui32_test() {
		uint32_t a = 4000000000;
		uint32_t b = 123456789;
		return sub_test(a, b, Simulator::Tag::UW, Simulator::Tag::UW, 3876543211u, Simulator::Tag::UW);
	}
	bool SubTester::i8_i16_test() {
		int8_t a = -12;
		int16_t b = 3000;
		return sub_test(a, b, Simulator::Tag::SB, Simulator::Tag::SH, -3012, Simulator::Tag::SH);
	}
	bool SubTester::i8_i32_test() {
		int8_t a = 100;
		int32_t b = -100000;
		return sub_test(a, b, Simulator::Tag::SB, Simulator::Tag::SW, 100100, Simulator::Tag::SW);
	}
	bool SubTester::i8_ui8_test() {
		int8_t a = -1;
		uint8_t b = 200;
		return sub_test(a, b, Simulator::Tag::SB, Simulator::Tag::UB, -201, Simulator::Tag::SH);
	}
	bool SubTester::i8_ui16_test() {
		int8_t a = 10;
		uint16_t b = 65000;
		return sub_test(a, b, Simulator::Tag::SB, Simulator::Tag::UH, -64990, Simulator::Tag::UH);
	}
	bool SubTester::i8_ui32_test() {
		int8_t a = 1;
		uint32_t b = 3000000000;
		return sub_test(a, b, Simulator::Tag::SB, Simulator::Tag::UW, 1294967297u, Simulator::Tag::UW);
	}
	bool SubTester::i16_i8_test() {
		int16_t a = -1234;
		int8_t b = 12;
		return sub_test(a, b, Simulator::Tag::SH, Simulator::Tag::SB, -1246, Simulator::Tag::SH);
	}
	bool SubTester::i16_i32_test() {
		int16_t a = 12345;
		int32_t b = 200000;
		return sub_test(a, b, Simulator::Tag::SH, Simulator::Tag::SW, -187655, Simulator::Tag::SW);
	}
	bool SubTester::i16_ui8_test() {
		int16_t a = -10;
		uint8_t b = 250;
		return sub_test(a, b, Simulator::Tag::SH, Simulator::Tag::UB, -260, Simulator::Tag::SH);
	}
	bool SubTester::i16_ui16_test() {
		int16_t a = -200;
		uint16_t b = 65000;
		return sub_test(a, b, Simulator::Tag::SH, Simulator::Tag::UH, -65200, Simulator::Tag::SW);
	}
	bool SubTester::i16_ui32_test() {
		int16_t a = 7;
		uint32_t b = 4000000000;
		return sub_test(a, b, Simulator::Tag::SH, Simulator::Tag::UW, 294967303u, Simulator::Tag::UW);
	}
	bool SubTester::i32_i8_test() {
		int32_t a = -100000;
		int8_t b = 1;
		return sub_test(a, b, Simulator::Tag::SW, Simulator::Tag::SB, -100001, Simulator::Tag::SW);
	}
	bool SubTester::i32_i16_test() {
		int32_t a = 500000;
		int16_t b = -123;
		return sub_test(a, b, Simulator::Tag::SW, Simulator::Tag::SH, 500123, Simulator::Tag::SW);
	}
	bool SubTester::i32_ui8_test() {
		int32_t a = -5;
		uint8_t b = 10;
		return sub_test(a, b, Simulator::Tag::SW, Simulator::Tag::UB, -15, Simulator::Tag::SW);
	}
	bool SubTester::i32_ui16_test() {
		int32_t a = -1000;
		uint16_t b = 60000;
		return sub_test(a, b, Simulator::Tag::SW, Simulator::Tag::UH, -61000, Simulator::Tag::SW);
	}
	bool SubTester::i32_ui32_test() {
		int32_t a = -1;
		uint32_t b = 4000000000;
		return sub_test(a, b, Simulator::Tag::SW, Simulator::Tag::UW, 294967295u, Simulator::Tag::UW);
	}
	bool SubTester::ui8_i8_test() {
		uint8_t a = 200;
		int8_t b = -1;
		return sub_test(a, b, Simulator::Tag::UB, Simulator::Tag::SB, 201, Simulator::Tag::SH);
	}
	bool SubTester::ui8_i16_test() {
		uint8_t a = 250;
		int16_t b = -1000;
		return sub_test(a, b, Simulator::Tag::UB, Simulator::Tag::SH, 1250, Simulator::Tag::SH);
	}
	bool SubTester::ui8_i32_test() {
		uint8_t a = 10;
		int32_t b = -100000;
		return sub_test(a, b, Simulator::Tag::UB, Simulator::Tag::SW, 100010, Simulator::Tag::SW);
	}
	bool SubTester::ui8_ui16_test() {
		uint8_t a = 200;
		uint16_t b = 100;
		return sub_test(a, b, Simulator::Tag::UB, Simulator::Tag::UH, 100, Simulator::Tag::UH);
	}
	bool SubTester::ui8_ui32_test() {
		uint8_t a = 1;
		uint32_t b = 3000000000;
		return sub_test(a, b, Simulator::Tag::UB, Simulator::Tag::UW, 1294967297u, Simulator::Tag::UW);
	}
	bool SubTester::ui16_i8_test() {
		uint16_t a = 65000;
		int8_t b = 10;
		return sub_test(a, b, Simulator::Tag::UH, Simulator::Tag::SB, 64990, Simulator::Tag::UH);
	}
	bool SubTester::ui16_i16_test() {
		uint16_t a = 60000;
		int16_t b = -200;
		return sub_test(a, b, Simulator::Tag::UH, Simulator::Tag::SH, 60200, Simulator::Tag::SW);
	}
	bool SubTester::ui16_i32_test() {
		uint16_t a = 65000;
		int32_t b = -1000;
		return sub_test(a, b, Simulator::Tag::UH, Simulator::Tag::SW, 66000, Simulator::Tag::SW);
	}
	bool SubTester::ui16_ui8_test() {
		uint16_t a = 1000;
		uint8_t b = 200;
		return sub_test(a, b, Simulator::Tag::UH, Simulator::Tag::UB, 800, Simulator::Tag::UH);
	}
	bool SubTester::ui16_ui32_test() {
		uint16_t a = 65000;
		uint32_t b = 3000000000;
		return sub_test(a, b, Simulator::Tag::UH, Simulator::Tag::UW, 1295032296u, Simulator::Tag::UW);
	}
	bool SubTester::ui32_i8_test() {
		uint32_t a = 3000000000;
		int8_t b = 1;
		return sub_test(a, b, Simulator::Tag::UW, Simulator::Tag::SB, 2999999999u, Simulator::Tag::UW);
	}
	bool SubTester::ui32_i16_test() {
		uint32_t a = 3000000000;
		int16_t b = 7;
		return sub_test(a, b, Simulator::Tag::UW, Simulator::Tag::SH, 2999999993u, Simulator::Tag::UW);
	}
	bool SubTester::ui32_i32_test() {
		uint32_t a = 3000000000;
		int32_t b = -1;
		return sub_test(a, b, Simulator::Tag::UW, Simulator::Tag::SW, 3000000001u, Simulator::Tag::UW);
	}
	bool SubTester::ui32_ui8_test() {
		uint32_t a = 3000000000;
		uint8_t b = 2;
		return sub_test(a, b, Simulator::Tag::UW, Simulator::Tag::UB, 2999999998u, Simulator::Tag::UW);
	}
	bool SubTester::ui32_ui16_test() {
		uint32_t a = 3000000000;
		uint16_t b = 60000;
		return sub_test(a, b, Simulator::Tag::UW, Simulator::Tag::UH, 2999940000u, Simulator::Tag::UW);
	}
} // namespace Test::Unit