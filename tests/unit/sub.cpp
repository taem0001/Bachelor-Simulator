#include "sub.hpp"

namespace Test::Unit {
	static constexpr uint32_t SUB_X9_X4_X15 = 0b00000000111100100001010010110011;

	template <typename A, typename B, typename ExpectedT>
	static bool sub_test(A a, B b, Simulator::TAG tag_a, Simulator::TAG tag_b, ExpectedT expected_val,
						 Simulator::TAG expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(4, a, tag_a);
		cpu.set_register(15, b, tag_b);
		cpu.execute_instruction(SUB_X9_X4_X15);

		const auto registers = cpu.get_registers();

		const bool passed_data = std::holds_alternative<ExpectedT>(registers[9].data) &&
								 std::get<ExpectedT>(registers[9].data) == expected_val;
		const bool passed_tag = registers[9].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool SubTester::i8_i8_test() {
		return sub_test<int8_t, int8_t, int>(55, 10, Simulator::TAG::SB, Simulator::TAG::SB, 45, Simulator::TAG::SW);
	}

	bool SubTester::i16_i16_test() {
		return sub_test<int16_t, int16_t, int>(300, 340, Simulator::TAG::SH, Simulator::TAG::SH, -40,
											   Simulator::TAG::SW);
	}

	bool SubTester::i32_i32_test() {
		return sub_test<int32_t, int32_t, int>(23590, 234222, Simulator::TAG::SW, Simulator::TAG::SW, -210632,
											   Simulator::TAG::SW);
	}

	bool SubTester::ui8_ui8_test() {
		return sub_test<uint8_t, uint8_t, int>(101, 45, Simulator::TAG::UB, Simulator::TAG::UB, 56, Simulator::TAG::SW);
	}

	bool SubTester::ui16_ui16_test() {
		return sub_test<uint16_t, uint16_t, int>(2401, 3455, Simulator::TAG::UH, Simulator::TAG::UH, -1054,
												 Simulator::TAG::SW);
	}

	bool SubTester::ui32_ui32_test() {
		return sub_test<uint32_t, uint32_t, unsigned int>(2334224u, 1043352u, Simulator::TAG::UW, Simulator::TAG::UW,
														  1290872u, Simulator::TAG::UW);
	}

	bool SubTester::i8_i16_test() {
		return sub_test<int8_t, int16_t, int>(55, 340, Simulator::TAG::SB, Simulator::TAG::SH, -285,
											  Simulator::TAG::SW);
	}

	bool SubTester::i8_i32_test() {
		return sub_test<int8_t, int32_t, int>(10, 234222, Simulator::TAG::SB, Simulator::TAG::SW, -234212,
											  Simulator::TAG::SW);
	}

	bool SubTester::i8_ui8_test() {
		return sub_test<int8_t, uint8_t, int>(55, 45, Simulator::TAG::SB, Simulator::TAG::UB, 10, Simulator::TAG::SW);
	}

	bool SubTester::i8_ui16_test() {
		return sub_test<int8_t, uint16_t, int>(55, 2401, Simulator::TAG::SB, Simulator::TAG::UH, -2346,
											   Simulator::TAG::SW);
	}

	bool SubTester::i8_ui32_test() {
		return sub_test<int8_t, uint32_t, unsigned int>(10, 1043352u, Simulator::TAG::SB, Simulator::TAG::UW,
														4293923954u, Simulator::TAG::UW);
	}

	bool SubTester::i16_i8_test() {
		return sub_test<int16_t, int8_t, int>(300, 10, Simulator::TAG::SH, Simulator::TAG::SB, 290, Simulator::TAG::SW);
	}

	bool SubTester::i16_i32_test() {
		return sub_test<int16_t, int32_t, int>(340, 23590, Simulator::TAG::SH, Simulator::TAG::SW, -23250,
											   Simulator::TAG::SW);
	}

	bool SubTester::i16_ui8_test() {
		return sub_test<int16_t, uint8_t, int>(300, 45, Simulator::TAG::SH, Simulator::TAG::UB, 255,
											   Simulator::TAG::SW);
	}

	bool SubTester::i16_ui16_test() {
		return sub_test<int16_t, uint16_t, int>(300, 2401, Simulator::TAG::SH, Simulator::TAG::UH, -2101,
												Simulator::TAG::SW);
	}

	bool SubTester::i16_ui32_test() {
		return sub_test<int16_t, uint32_t, unsigned int>(340, 1043352u, Simulator::TAG::SH, Simulator::TAG::UW,
														 4293924284u, Simulator::TAG::UW);
	}

	bool SubTester::i32_i8_test() {
		return sub_test<int32_t, int8_t, int>(23590, 10, Simulator::TAG::SW, Simulator::TAG::SB, 23580,
											  Simulator::TAG::SW);
	}

	bool SubTester::i32_i16_test() {
		return sub_test<int32_t, int16_t, int>(234222, 340, Simulator::TAG::SW, Simulator::TAG::SH, 233882,
											   Simulator::TAG::SW);
	}

	bool SubTester::i32_ui8_test() {
		return sub_test<int32_t, uint8_t, int>(23590, 45, Simulator::TAG::SW, Simulator::TAG::UB, 23545,
											   Simulator::TAG::SW);
	}

	bool SubTester::i32_ui16_test() {
		return sub_test<int32_t, uint16_t, int>(23590, 2401, Simulator::TAG::SW, Simulator::TAG::UH, 21189,
												Simulator::TAG::SW);
	}

	bool SubTester::i32_ui32_test() {
		return sub_test<int32_t, uint32_t, unsigned int>(23590, 1043352u, Simulator::TAG::SW, Simulator::TAG::UW,
														 4293947534u, Simulator::TAG::UW);
	}

	bool SubTester::ui8_i8_test() {
		return sub_test<uint8_t, int8_t, int>(101, 10, Simulator::TAG::UB, Simulator::TAG::SB, 91, Simulator::TAG::SW);
	}

	bool SubTester::ui8_i16_test() {
		return sub_test<uint8_t, int16_t, int>(101, 300, Simulator::TAG::UB, Simulator::TAG::SH, -199,
											   Simulator::TAG::SW);
	}

	bool SubTester::ui8_i32_test() {
		return sub_test<uint8_t, int32_t, int>(45, 23590, Simulator::TAG::UB, Simulator::TAG::SW, -23545,
											   Simulator::TAG::SW);
	}

	bool SubTester::ui8_ui16_test() {
		return sub_test<uint8_t, uint16_t, int>(45, 2401, Simulator::TAG::UB, Simulator::TAG::UH, -2356,
												Simulator::TAG::SW);
	}

	bool SubTester::ui8_ui32_test() {
		return sub_test<uint8_t, uint32_t, unsigned int>(45, 1043352u, Simulator::TAG::UB, Simulator::TAG::UW,
														 4293923989u, Simulator::TAG::UW);
	}

	bool SubTester::ui16_i8_test() {
		return sub_test<uint16_t, int8_t, int>(2401, 10, Simulator::TAG::UH, Simulator::TAG::SB, 2391,
											   Simulator::TAG::SW);
	}

	bool SubTester::ui16_i16_test() {
		return sub_test<uint16_t, int16_t, int>(3455, 300, Simulator::TAG::UH, Simulator::TAG::SH, 3155,
												Simulator::TAG::SW);
	}

	bool SubTester::ui16_i32_test() {
		return sub_test<uint16_t, int32_t, int>(2401, 23590, Simulator::TAG::UH, Simulator::TAG::SW, -21189,
												Simulator::TAG::SW);
	}

	bool SubTester::ui16_ui8_test() {
		return sub_test<uint16_t, uint8_t, int>(2401, 45, Simulator::TAG::UH, Simulator::TAG::UB, 2356,
												Simulator::TAG::SW);
	}

	bool SubTester::ui16_ui32_test() {
		return sub_test<uint16_t, uint32_t, unsigned int>(3455, 1043352u, Simulator::TAG::UH, Simulator::TAG::UW,
														  4293927399u, Simulator::TAG::UW);
	}

	bool SubTester::ui32_i8_test() {
		return sub_test<uint32_t, int8_t, unsigned int>(1043352u, 10, Simulator::TAG::UW, Simulator::TAG::SB, 1043342u,
														Simulator::TAG::UW);
	}

	bool SubTester::ui32_i16_test() {
		return sub_test<uint32_t, int16_t, unsigned int>(1043352u, 340, Simulator::TAG::UW, Simulator::TAG::SH,
														 1043012u, Simulator::TAG::UW);
	}

	bool SubTester::ui32_i32_test() {
		return sub_test<uint32_t, int32_t, unsigned int>(1043352u, 23590, Simulator::TAG::UW, Simulator::TAG::SW,
														 1019762u, Simulator::TAG::UW);
	}

	bool SubTester::ui32_ui8_test() {
		return sub_test<uint32_t, uint8_t, unsigned int>(1043352u, 45, Simulator::TAG::UW, Simulator::TAG::UB, 1043307u,
														 Simulator::TAG::UW);
	}

	bool SubTester::ui32_ui16_test() {
		return sub_test<uint32_t, uint16_t, unsigned int>(1043352u, 3455, Simulator::TAG::UW, Simulator::TAG::UH,
														  1039897u, Simulator::TAG::UW);
	}
} // namespace Test::Unit