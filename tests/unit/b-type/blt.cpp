#include "blt.hpp"

namespace Test::Unit {
	static constexpr uint32_t BLT_X5_X6_12 = 0x0062CC63;

	static bool blt_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
						 bool should_branch) {
		Simulator::CPU cpu;
		cpu.set_register(5, a_val, a_tag);
		cpu.set_register(6, b_val, b_tag);

		int pc_before = cpu.get_pc();
		cpu.execute_instruction(BLT_X5_X6_12);

		int pc_after;
		bool pc_modified = cpu.get_pc_modified();
		if (should_branch) {
			pc_after = cpu.get_pc();
			return pc_after == pc_before + 12 && pc_modified;
		}

		pc_after = cpu.get_pc() + 4;
		return pc_after == pc_before + 4 && !pc_modified;
	}

	bool BltTester::i8_i8_less_test() { return blt_test(-5, 2, Simulator::Tag::SB, Simulator::Tag::SB, true); }
	bool BltTester::i8_i8_not_less_test() { return blt_test(2, -5, Simulator::Tag::SB, Simulator::Tag::SB, false); }

	bool BltTester::i16_i16_less_test() { return blt_test(-500, 200, Simulator::Tag::SH, Simulator::Tag::SH, true); }
	bool BltTester::i16_i16_not_less_test() {
		return blt_test(200, -500, Simulator::Tag::SH, Simulator::Tag::SH, false);
	}

	bool BltTester::i32_i32_less_test() {
		return blt_test(-100000, 200000, Simulator::Tag::SW, Simulator::Tag::SW, true);
	}
	bool BltTester::i32_i32_not_less_test() {
		return blt_test(200000, -100000, Simulator::Tag::SW, Simulator::Tag::SW, false);
	}

	bool BltTester::ui8_ui8_less_test() { return blt_test(2, 5, Simulator::Tag::UB, Simulator::Tag::UB, true); }
	bool BltTester::ui8_ui8_not_less_test() {
		return blt_test(5, 2, Simulator::Tag::UB, Simulator::Tag::UB, false);
	}

	bool BltTester::ui16_ui16_less_test() { return blt_test(200, 500, Simulator::Tag::UH, Simulator::Tag::UH, true); }
	bool BltTester::ui16_ui16_not_less_test() {
		return blt_test(500, 200, Simulator::Tag::UH, Simulator::Tag::UH, false);
	}

	bool BltTester::ui32_ui32_less_test() {
		return blt_test(200000, 500000, Simulator::Tag::UW, Simulator::Tag::UW, true);
	}
	bool BltTester::ui32_ui32_not_less_test() {
		return blt_test(500000, 200000, Simulator::Tag::UW, Simulator::Tag::UW, false);
	}

	bool BltTester::i8_i16_less_test() { return blt_test(-5, 2, Simulator::Tag::SB, Simulator::Tag::SH, true); }
	bool BltTester::i8_i16_not_less_test() {
		return blt_test(5, -2, Simulator::Tag::SB, Simulator::Tag::SH, false);
	}
	bool BltTester::i8_i32_less_test() { return blt_test(-5, 2, Simulator::Tag::SB, Simulator::Tag::SW, true); }
	bool BltTester::i8_i32_not_less_test() {
		return blt_test(5, -2, Simulator::Tag::SB, Simulator::Tag::SW, false);
	}
	bool BltTester::i8_ui8_less_test() { return blt_test(-1, 1, Simulator::Tag::SB, Simulator::Tag::UB, true); }
	bool BltTester::i8_ui8_not_less_test() {
		return blt_test(7, 2, Simulator::Tag::SB, Simulator::Tag::UB, false);
	}
	bool BltTester::i8_ui16_less_test() { return blt_test(-1, 1, Simulator::Tag::SB, Simulator::Tag::UH, true); }
	bool BltTester::i8_ui16_not_less_test() {
		return blt_test(7, 2, Simulator::Tag::SB, Simulator::Tag::UH, false);
	}
	bool BltTester::i8_ui32_less_test() { return blt_test(-1, 1, Simulator::Tag::SB, Simulator::Tag::UW, true); }
	bool BltTester::i8_ui32_not_less_test() {
		return blt_test(7, 2, Simulator::Tag::SB, Simulator::Tag::UW, false);
	}

	bool BltTester::i16_i8_less_test() { return blt_test(-5, 2, Simulator::Tag::SH, Simulator::Tag::SB, true); }
	bool BltTester::i16_i8_not_less_test() {
		return blt_test(5, -2, Simulator::Tag::SH, Simulator::Tag::SB, false);
	}
	bool BltTester::i16_i32_less_test() { return blt_test(-5, 2, Simulator::Tag::SH, Simulator::Tag::SW, true); }
	bool BltTester::i16_i32_not_less_test() {
		return blt_test(5, -2, Simulator::Tag::SH, Simulator::Tag::SW, false);
	}
	bool BltTester::i16_ui8_less_test() { return blt_test(-1, 1, Simulator::Tag::SH, Simulator::Tag::UB, true); }
	bool BltTester::i16_ui8_not_less_test() {
		return blt_test(7, 2, Simulator::Tag::SH, Simulator::Tag::UB, false);
	}
	bool BltTester::i16_ui16_less_test() { return blt_test(-1, 1, Simulator::Tag::SH, Simulator::Tag::UH, true); }
	bool BltTester::i16_ui16_not_less_test() {
		return blt_test(7, 2, Simulator::Tag::SH, Simulator::Tag::UH, false);
	}
	bool BltTester::i16_ui32_less_test() { return blt_test(-1, 1, Simulator::Tag::SH, Simulator::Tag::UW, true); }
	bool BltTester::i16_ui32_not_less_test() {
		return blt_test(7, 2, Simulator::Tag::SH, Simulator::Tag::UW, false);
	}

	bool BltTester::i32_i8_less_test() { return blt_test(-5, 2, Simulator::Tag::SW, Simulator::Tag::SB, true); }
	bool BltTester::i32_i8_not_less_test() {
		return blt_test(5, -2, Simulator::Tag::SW, Simulator::Tag::SB, false);
	}
	bool BltTester::i32_i16_less_test() { return blt_test(-5, 2, Simulator::Tag::SW, Simulator::Tag::SH, true); }
	bool BltTester::i32_i16_not_less_test() {
		return blt_test(5, -2, Simulator::Tag::SW, Simulator::Tag::SH, false);
	}
	bool BltTester::i32_ui8_less_test() { return blt_test(-1, 1, Simulator::Tag::SW, Simulator::Tag::UB, true); }
	bool BltTester::i32_ui8_not_less_test() {
		return blt_test(7, 2, Simulator::Tag::SW, Simulator::Tag::UB, false);
	}
	bool BltTester::i32_ui16_less_test() { return blt_test(-1, 1, Simulator::Tag::SW, Simulator::Tag::UH, true); }
	bool BltTester::i32_ui16_not_less_test() {
		return blt_test(7, 2, Simulator::Tag::SW, Simulator::Tag::UH, false);
	}
	bool BltTester::i32_ui32_less_test() { return blt_test(-1, 1, Simulator::Tag::SW, Simulator::Tag::UW, true); }
	bool BltTester::i32_ui32_not_less_test() {
		return blt_test(7, 2, Simulator::Tag::SW, Simulator::Tag::UW, false);
	}

	bool BltTester::ui8_i8_less_test() { return blt_test(2, 5, Simulator::Tag::UB, Simulator::Tag::SB, true); }
	bool BltTester::ui8_i8_not_less_test() {
		return blt_test(7, -1, Simulator::Tag::UB, Simulator::Tag::SB, false);
	}
	bool BltTester::ui8_i16_less_test() { return blt_test(2, 5, Simulator::Tag::UB, Simulator::Tag::SH, true); }
	bool BltTester::ui8_i16_not_less_test() {
		return blt_test(7, -1, Simulator::Tag::UB, Simulator::Tag::SH, false);
	}
	bool BltTester::ui8_i32_less_test() { return blt_test(2, 5, Simulator::Tag::UB, Simulator::Tag::SW, true); }
	bool BltTester::ui8_i32_not_less_test() {
		return blt_test(7, -1, Simulator::Tag::UB, Simulator::Tag::SW, false);
	}
	bool BltTester::ui8_ui16_less_test() { return blt_test(2, 5, Simulator::Tag::UB, Simulator::Tag::UH, true); }
	bool BltTester::ui8_ui16_not_less_test() {
		return blt_test(5, 2, Simulator::Tag::UB, Simulator::Tag::UH, false);
	}
	bool BltTester::ui8_ui32_less_test() { return blt_test(2, 5, Simulator::Tag::UB, Simulator::Tag::UW, true); }
	bool BltTester::ui8_ui32_not_less_test() {
		return blt_test(5, 2, Simulator::Tag::UB, Simulator::Tag::UW, false);
	}

	bool BltTester::ui16_i8_less_test() { return blt_test(2, 5, Simulator::Tag::UH, Simulator::Tag::SB, true); }
	bool BltTester::ui16_i8_not_less_test() {
		return blt_test(7, -1, Simulator::Tag::UH, Simulator::Tag::SB, false);
	}
	bool BltTester::ui16_i16_less_test() { return blt_test(2, 5, Simulator::Tag::UH, Simulator::Tag::SH, true); }
	bool BltTester::ui16_i16_not_less_test() {
		return blt_test(7, -1, Simulator::Tag::UH, Simulator::Tag::SH, false);
	}
	bool BltTester::ui16_i32_less_test() { return blt_test(2, 5, Simulator::Tag::UH, Simulator::Tag::SW, true); }
	bool BltTester::ui16_i32_not_less_test() {
		return blt_test(7, -1, Simulator::Tag::UH, Simulator::Tag::SW, false);
	}
	bool BltTester::ui16_ui8_less_test() { return blt_test(2, 5, Simulator::Tag::UH, Simulator::Tag::UB, true); }
	bool BltTester::ui16_ui8_not_less_test() {
		return blt_test(5, 2, Simulator::Tag::UH, Simulator::Tag::UB, false);
	}
	bool BltTester::ui16_ui32_less_test() { return blt_test(2, 5, Simulator::Tag::UH, Simulator::Tag::UW, true); }
	bool BltTester::ui16_ui32_not_less_test() {
		return blt_test(5, 2, Simulator::Tag::UH, Simulator::Tag::UW, false);
	}

	bool BltTester::ui32_i8_less_test() { return blt_test(2, 5, Simulator::Tag::UW, Simulator::Tag::SB, true); }
	bool BltTester::ui32_i8_not_less_test() {
		return blt_test(7, -1, Simulator::Tag::UW, Simulator::Tag::SB, false);
	}
	bool BltTester::ui32_i16_less_test() { return blt_test(2, 5, Simulator::Tag::UW, Simulator::Tag::SH, true); }
	bool BltTester::ui32_i16_not_less_test() {
		return blt_test(7, -1, Simulator::Tag::UW, Simulator::Tag::SH, false);
	}
	bool BltTester::ui32_i32_less_test() { return blt_test(2, 5, Simulator::Tag::UW, Simulator::Tag::SW, true); }
	bool BltTester::ui32_i32_not_less_test() {
		return blt_test(7, -1, Simulator::Tag::UW, Simulator::Tag::SW, false);
	}
	bool BltTester::ui32_ui8_less_test() { return blt_test(2, 5, Simulator::Tag::UW, Simulator::Tag::UB, true); }
	bool BltTester::ui32_ui8_not_less_test() {
		return blt_test(5, 2, Simulator::Tag::UW, Simulator::Tag::UB, false);
	}
	bool BltTester::ui32_ui16_less_test() { return blt_test(2, 5, Simulator::Tag::UW, Simulator::Tag::UH, true); }
	bool BltTester::ui32_ui16_not_less_test() {
		return blt_test(5, 2, Simulator::Tag::UW, Simulator::Tag::UH, false);
	}
} // namespace Test::Unit
