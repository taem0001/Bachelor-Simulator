#include "rem.hpp"

namespace Test::Unit {
	static constexpr uint32_t REM_X7_X5_X6 = 0b00000010011000101110001110110011;

	static bool rem_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
						 uint32_t expected_val, Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(5, a_val, a_tag);
		cpu.set_register(6, b_val, b_tag);
		cpu.execute_instruction(REM_X7_X5_X6);

		const auto registers = cpu.get_registers();

		const bool passed_data = registers[7].data == expected_val;
		const bool passed_tag = registers[7].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool RemTester::i8_i8_test() {
		return rem_test(static_cast<int8_t>(-84), static_cast<int8_t>(7), Simulator::Tag::SB, Simulator::Tag::SB, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::i16_i16_test() {
		return rem_test(static_cast<int16_t>(3000), static_cast<int16_t>(-12), Simulator::Tag::SH, Simulator::Tag::SH, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::i32_i32_test() {
		return rem_test(static_cast<int32_t>(-1000000000), static_cast<int32_t>(125000000), Simulator::Tag::SW,
						Simulator::Tag::SW, 0, Simulator::Tag::SW);
	}
	bool RemTester::ui8_ui8_test() {
		return rem_test(static_cast<uint8_t>(200), static_cast<uint8_t>(4), Simulator::Tag::UB, Simulator::Tag::UB, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::ui16_ui16_test() {
		return rem_test(static_cast<uint16_t>(60000), static_cast<uint16_t>(300), Simulator::Tag::UH,
						Simulator::Tag::UH, 0, Simulator::Tag::SW);
	}
	bool RemTester::ui32_ui32_test() {
		return rem_test(static_cast<uint32_t>(4000000000u), static_cast<uint32_t>(2u), Simulator::Tag::UW,
						Simulator::Tag::UW, 0u, Simulator::Tag::UW);
	}

	bool RemTester::i8_i16_test() {
		return rem_test(static_cast<int8_t>(-84), static_cast<int16_t>(12), Simulator::Tag::SB, Simulator::Tag::SH, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::i8_i32_test() {
		return rem_test(static_cast<int8_t>(100), static_cast<int32_t>(-5), Simulator::Tag::SB, Simulator::Tag::SW, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::i8_ui8_test() {
		return rem_test(static_cast<int8_t>(-1), static_cast<uint8_t>(200), Simulator::Tag::SB, Simulator::Tag::UB,
						static_cast<uint32_t>(-1), Simulator::Tag::SW);
	}
	bool RemTester::i8_ui16_test() {
		return rem_test(static_cast<int8_t>(-1), static_cast<uint16_t>(10), Simulator::Tag::SB, Simulator::Tag::UH,
						static_cast<uint32_t>(-1), Simulator::Tag::SW);
	}
	bool RemTester::i8_ui32_test() {
		return rem_test(static_cast<int8_t>(-1), static_cast<uint32_t>(3u), Simulator::Tag::SB, Simulator::Tag::UW, 0,
						Simulator::Tag::UW);
	}

	bool RemTester::i16_i8_test() {
		return rem_test(static_cast<int16_t>(3000), static_cast<int8_t>(-12), Simulator::Tag::SH, Simulator::Tag::SB, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::i16_i32_test() {
		return rem_test(static_cast<int16_t>(-6000), static_cast<int32_t>(30), Simulator::Tag::SH, Simulator::Tag::SW, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::i16_ui8_test() {
		return rem_test(static_cast<int16_t>(-1), static_cast<uint8_t>(250), Simulator::Tag::SH, Simulator::Tag::UB,
						static_cast<uint32_t>(-1), Simulator::Tag::SW);
	}
	bool RemTester::i16_ui16_test() {
		return rem_test(static_cast<int16_t>(-200), static_cast<uint16_t>(65000), Simulator::Tag::SH,
						Simulator::Tag::UH, static_cast<uint32_t>(-200), Simulator::Tag::SW);
	}
	bool RemTester::i16_ui32_test() {
		return rem_test(static_cast<int16_t>(-1), static_cast<uint32_t>(3u), Simulator::Tag::SH, Simulator::Tag::UW, 0,
						Simulator::Tag::UW);
	}

	bool RemTester::i32_i8_test() {
		return rem_test(static_cast<int32_t>(-1000000000), static_cast<int8_t>(8), Simulator::Tag::SW,
						Simulator::Tag::SB, 0, Simulator::Tag::SW);
	}
	bool RemTester::i32_i16_test() {
		return rem_test(static_cast<int32_t>(500000), static_cast<int16_t>(-100), Simulator::Tag::SW,
						Simulator::Tag::SH, 0, Simulator::Tag::SW);
	}
	bool RemTester::i32_ui8_test() {
		return rem_test(static_cast<int32_t>(-1), static_cast<uint8_t>(10), Simulator::Tag::SW, Simulator::Tag::UB,
						static_cast<uint32_t>(-1), Simulator::Tag::SW);
	}
	bool RemTester::i32_ui16_test() {
		return rem_test(static_cast<int32_t>(-1), static_cast<uint16_t>(60000), Simulator::Tag::SW, Simulator::Tag::UH,
						static_cast<uint32_t>(-1), Simulator::Tag::SW);
	}
	bool RemTester::i32_ui32_test() {
		return rem_test(static_cast<int32_t>(-1), static_cast<uint32_t>(3u), Simulator::Tag::SW, Simulator::Tag::UW, 0,
						Simulator::Tag::UW);
	}

	bool RemTester::ui8_i8_test() {
		return rem_test(static_cast<uint8_t>(200), static_cast<int8_t>(-4), Simulator::Tag::UB, Simulator::Tag::SB, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::ui8_i16_test() {
		return rem_test(static_cast<uint8_t>(250), static_cast<int16_t>(5), Simulator::Tag::UB, Simulator::Tag::SH, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::ui8_i32_test() {
		return rem_test(static_cast<uint8_t>(10), static_cast<int32_t>(-2), Simulator::Tag::UB, Simulator::Tag::SW, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::ui8_ui16_test() {
		return rem_test(static_cast<uint8_t>(200), static_cast<uint16_t>(10), Simulator::Tag::UB, Simulator::Tag::UH, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::ui8_ui32_test() {
		return rem_test(static_cast<uint8_t>(1), static_cast<uint32_t>(3u), Simulator::Tag::UB, Simulator::Tag::UW, 1,
						Simulator::Tag::UW);
	}

	bool RemTester::ui16_i8_test() {
		return rem_test(static_cast<uint16_t>(65000), static_cast<int8_t>(10), Simulator::Tag::UH, Simulator::Tag::SB, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::ui16_i16_test() {
		return rem_test(static_cast<uint16_t>(60000), static_cast<int16_t>(-200), Simulator::Tag::UH,
						Simulator::Tag::SH, 0, Simulator::Tag::SW);
	}
	bool RemTester::ui16_i32_test() {
		return rem_test(static_cast<uint16_t>(65000), static_cast<int32_t>(-1000), Simulator::Tag::UH,
						Simulator::Tag::SW, 0, Simulator::Tag::SW);
	}
	bool RemTester::ui16_ui8_test() {
		return rem_test(static_cast<uint16_t>(1000), static_cast<uint8_t>(10), Simulator::Tag::UH, Simulator::Tag::UB, 0,
						Simulator::Tag::SW);
	}
	bool RemTester::ui16_ui32_test() {
		return rem_test(static_cast<uint16_t>(1), static_cast<uint32_t>(3u), Simulator::Tag::UH, Simulator::Tag::UW, 1,
						Simulator::Tag::UW);
	}

	bool RemTester::ui32_i8_test() {
		return rem_test(static_cast<uint32_t>(3u), static_cast<int8_t>(-1), Simulator::Tag::UW, Simulator::Tag::SB, 3,
						Simulator::Tag::UW);
	}
	bool RemTester::ui32_i16_test() {
		return rem_test(static_cast<uint32_t>(3u), static_cast<int16_t>(-1), Simulator::Tag::UW, Simulator::Tag::SH, 3,
						Simulator::Tag::UW);
	}
	bool RemTester::ui32_i32_test() {
		return rem_test(static_cast<uint32_t>(3u), static_cast<int32_t>(-1), Simulator::Tag::UW, Simulator::Tag::SW, 3,
						Simulator::Tag::UW);
	}
	bool RemTester::ui32_ui8_test() {
		return rem_test(static_cast<uint32_t>(3u), static_cast<uint8_t>(2), Simulator::Tag::UW, Simulator::Tag::UB, 1,
						Simulator::Tag::UW);
	}
	bool RemTester::ui32_ui16_test() {
		return rem_test(static_cast<uint32_t>(3u), static_cast<uint16_t>(2), Simulator::Tag::UW, Simulator::Tag::UH, 1,
						Simulator::Tag::UW);
	}
} // namespace Test::Unit