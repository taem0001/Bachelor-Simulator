#include "add.hpp"

namespace Test::Unit {
	static constexpr uint32_t ADD_X7_X5_X6 = 0b00000000011000101000001110110011;

	template <typename A, typename B, typename ExpectedT>
	static bool add_test(A a, B b, Simulator::TAG tag_a, Simulator::TAG tag_b, ExpectedT expected_val,
						 Simulator::TAG expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(5, a, tag_a);
		cpu.set_register(6, b, tag_b);
		cpu.execute_instruction(ADD_X7_X5_X6);

		const auto registers = cpu.get_registers();

		const bool passed_data = std::holds_alternative<ExpectedT>(registers[7].data) &&
								 std::get<ExpectedT>(registers[7].data) == expected_val;
		const bool passed_tag = registers[7].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool AddTester::i8_i8_test() {
		return add_test<int8_t, int8_t, int>(55, 10, Simulator::TAG::SB, Simulator::TAG::SB, 65, Simulator::TAG::SW);
	}

	bool AddTester::i16_i16_test() {
		return add_test<int16_t, int16_t, int>(300, 340, Simulator::TAG::SH, Simulator::TAG::SH, 640,
											   Simulator::TAG::SW);
	}

	bool AddTester::i32_i32_test() {
		return add_test<int32_t, int32_t, int>(23590, 234222, Simulator::TAG::SW, Simulator::TAG::SW, 257812,
											   Simulator::TAG::SW);
	}

	bool AddTester::ui8_ui8_test() {
		return add_test<uint8_t, uint8_t, int>(101, 45, Simulator::TAG::UB, Simulator::TAG::UB, 146,
											   Simulator::TAG::SW);
	}

	bool AddTester::ui16_ui16_test() {
		return add_test<uint16_t, uint16_t, int>(2401, 3455, Simulator::TAG::UB, Simulator::TAG::UB, 5856,
												 Simulator::TAG::SW);
	}

	bool AddTester::ui32_ui32_test() {
		return add_test<uint32_t, uint32_t, unsigned int>(2334224u, 1043352u, Simulator::TAG::UB, Simulator::TAG::UB,
														  3377576u, Simulator::TAG::UW);
	}

	bool AddTester::i8_i16_test() {
		return add_test<int8_t, int16_t, int>(55, 340, Simulator::TAG::SB, Simulator::TAG::SH, 395, Simulator::TAG::SW);
	}

	bool AddTester::i8_i32_test() {
		return add_test<int8_t, int32_t, int>(10, 234222, Simulator::TAG::SB, Simulator::TAG::SW, 234232,
											  Simulator::TAG::SW);
	}

	bool AddTester::i8_ui8_test() {
		return add_test<int8_t, uint8_t, int>(55, 45, Simulator::TAG::SB, Simulator::TAG::UB, 100, Simulator::TAG::SW);
	}

	bool AddTester::i8_ui16_test() {
		return add_test<int8_t, uint16_t, int>(55, 2401, Simulator::TAG::SB, Simulator::TAG::UH, 2456,
											   Simulator::TAG::SW);
	}

	bool AddTester::i8_ui32_test() {
		return add_test<int8_t, uint32_t, unsigned int>(10, 1043352u, Simulator::TAG::SB, Simulator::TAG::UW, 1043362u,
														Simulator::TAG::UW);
	}

	bool AddTester::i16_i8_test() {
		return add_test<int16_t, int8_t, int>(300, 10, Simulator::TAG::SH, Simulator::TAG::SB, 310, Simulator::TAG::SW);
	}

	bool AddTester::i16_i32_test() {
		return add_test<int16_t, int32_t, int>(340, 23590, Simulator::TAG::SH, Simulator::TAG::SW, 23930,
											   Simulator::TAG::SW);
	}

	bool AddTester::i16_ui8_test() {
		return add_test<int16_t, uint8_t, int>(300, 45, Simulator::TAG::SH, Simulator::TAG::UB, 345,
											   Simulator::TAG::SW);
	}

	bool AddTester::i16_ui16_test() {
		return add_test<int16_t, uint16_t, int>(300, 2401, Simulator::TAG::SH, Simulator::TAG::UH, 2701,
												Simulator::TAG::SW);
	}

	bool AddTester::i16_ui32_test() {
		return add_test<int16_t, uint32_t, unsigned int>(340, 1043352u, Simulator::TAG::SH, Simulator::TAG::UW,
														 1043692u, Simulator::TAG::UW);
	}

	bool AddTester::i32_i8_test() {
		return add_test<int32_t, int8_t, int>(23590, 10, Simulator::TAG::SW, Simulator::TAG::SB, 23600,
											  Simulator::TAG::SW);
	}

	bool AddTester::i32_i16_test() {
		return add_test<int32_t, int16_t, int>(234222, 340, Simulator::TAG::SW, Simulator::TAG::SH, 234562,
											   Simulator::TAG::SW);
	}

	bool AddTester::i32_ui8_test() {
		return add_test<int32_t, uint8_t, int>(23590, 45, Simulator::TAG::SW, Simulator::TAG::UB, 23635,
											   Simulator::TAG::SW);
	}

	bool AddTester::i32_ui16_test() {
		return add_test<int32_t, uint16_t, int>(23590, 2401, Simulator::TAG::SW, Simulator::TAG::UH, 25991,
												Simulator::TAG::SW);
	}

	bool AddTester::i32_ui32_test() {
		return add_test<int32_t, uint32_t, unsigned int>(23590, 1043352u, Simulator::TAG::SW, Simulator::TAG::UW,
														 1066942u, Simulator::TAG::UW);
	}

	bool AddTester::ui8_i8_test() {
		return add_test<uint8_t, int8_t, int>(101, 10, Simulator::TAG::UB, Simulator::TAG::SB, 111, Simulator::TAG::SW);
	}

	bool AddTester::ui8_i16_test() {
		return add_test<uint8_t, int16_t, int>(101, 300, Simulator::TAG::UB, Simulator::TAG::SH, 401,
											   Simulator::TAG::SW);
	}

	bool AddTester::ui8_i32_test() {
		return add_test<uint8_t, int32_t, int>(45, 23590, Simulator::TAG::UB, Simulator::TAG::SW, 23635,
											   Simulator::TAG::SW);
	}

	bool AddTester::ui8_ui16_test() {
		return add_test<uint8_t, uint16_t, int>(45, 2401, Simulator::TAG::UB, Simulator::TAG::UH, 2446,
												Simulator::TAG::SW);
	}

	bool AddTester::ui8_ui32_test() {
		return add_test<uint8_t, uint32_t, unsigned int>(45, 1043352u, Simulator::TAG::UB, Simulator::TAG::UW, 1043397u,
														 Simulator::TAG::UW);
	}

	bool AddTester::ui16_i8_test() {
		return add_test<uint16_t, int8_t, int>(2401, 10, Simulator::TAG::UH, Simulator::TAG::SB, 2411,
											   Simulator::TAG::SW);
	}

	bool AddTester::ui16_i16_test() {
		return add_test<uint16_t, int16_t, int>(3455, 300, Simulator::TAG::UH, Simulator::TAG::SH, 3755,
												Simulator::TAG::SW);
	}

	bool AddTester::ui16_i32_test() {
		return add_test<uint16_t, int32_t, int>(2401, 23590, Simulator::TAG::UH, Simulator::TAG::SW, 25991,
												Simulator::TAG::SW);
	}

	bool AddTester::ui16_ui8_test() {
		return add_test<uint16_t, uint8_t, int>(2401, 45, Simulator::TAG::UH, Simulator::TAG::UB, 2446,
												Simulator::TAG::SW);
	}

	bool AddTester::ui16_ui32_test() {
		return add_test<uint16_t, uint32_t, unsigned int>(3455, 1043352u, Simulator::TAG::UH, Simulator::TAG::UW,
														  1046807u, Simulator::TAG::UW);
	}

	bool AddTester::ui32_i8_test() {
		return add_test<uint32_t, int8_t, unsigned int>(1043352u, 10, Simulator::TAG::UW, Simulator::TAG::SB, 1043362u,
														Simulator::TAG::UW);
	}

	bool AddTester::ui32_i16_test() {
		return add_test<uint32_t, int16_t, unsigned int>(1043352u, 340, Simulator::TAG::UW, Simulator::TAG::SH,
														 1043692u, Simulator::TAG::UW);
	}

	bool AddTester::ui32_i32_test() {
		return add_test<uint32_t, int32_t, unsigned int>(1043352u, 23590, Simulator::TAG::UW, Simulator::TAG::SW,
														 1066942u, Simulator::TAG::UW);
	}

	bool AddTester::ui32_ui8_test() {
		return add_test<uint32_t, uint8_t, unsigned int>(1043352u, 45, Simulator::TAG::UW, Simulator::TAG::UB, 1043397u,
														 Simulator::TAG::UW);
	}

	bool AddTester::ui32_ui16_test() {
		return add_test<uint32_t, uint16_t, unsigned int>(1043352u, 3455, Simulator::TAG::UW, Simulator::TAG::UH,
														  1046807u, Simulator::TAG::UW);
	}
} // namespace Test::Unit