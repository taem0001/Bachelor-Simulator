#include "bge.hpp"

namespace Test::Unit {
	static constexpr uint32_t BGE_X5_X6_12 = 0x0062DC63;

	static bool bge_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
						 bool should_branch) {
		Simulator::CPU cpu;
		cpu.set_register(5, a_val, a_tag);
		cpu.set_register(6, b_val, b_tag);

		int pc_before = cpu.get_pc();
		cpu.execute_instruction(BGE_X5_X6_12);

		int pc_after;
		bool pc_modified = cpu.get_pc_modified();
		if (should_branch) {
			pc_after = cpu.get_pc();
			return pc_after == pc_before + 12 && pc_modified;
		}

		pc_after = cpu.get_pc() + 4;
		return pc_after == pc_before + 4 && !pc_modified;
	}

	bool BgeTester::i8_i8_ge_test() { return bge_test(2, -5, Simulator::Tag::SB, Simulator::Tag::SB, true); }
	bool BgeTester::i8_i8_less_test() { return bge_test(-5, 2, Simulator::Tag::SB, Simulator::Tag::SB, false); }

	bool BgeTester::i16_i16_ge_test() { return bge_test(200, -500, Simulator::Tag::SH, Simulator::Tag::SH, true); }
	bool BgeTester::i16_i16_less_test() {
		return bge_test(-500, 200, Simulator::Tag::SH, Simulator::Tag::SH, false);
	}

	bool BgeTester::i32_i32_ge_test() {
		return bge_test(200000, -100000, Simulator::Tag::SW, Simulator::Tag::SW, true);
	}
	bool BgeTester::i32_i32_less_test() {
		return bge_test(-100000, 200000, Simulator::Tag::SW, Simulator::Tag::SW, false);
	}

	bool BgeTester::ui8_ui8_ge_test() { return bge_test(5, 2, Simulator::Tag::UB, Simulator::Tag::UB, true); }
	bool BgeTester::ui8_ui8_less_test() {
		return bge_test(2, 5, Simulator::Tag::UB, Simulator::Tag::UB, false);
	}

	bool BgeTester::ui16_ui16_ge_test() { return bge_test(500, 200, Simulator::Tag::UH, Simulator::Tag::UH, true); }
	bool BgeTester::ui16_ui16_less_test() {
		return bge_test(200, 500, Simulator::Tag::UH, Simulator::Tag::UH, false);
	}

	bool BgeTester::ui32_ui32_ge_test() {
		return bge_test(500000, 200000, Simulator::Tag::UW, Simulator::Tag::UW, true);
	}
	bool BgeTester::ui32_ui32_less_test() {
		return bge_test(200000, 500000, Simulator::Tag::UW, Simulator::Tag::UW, false);
	}

	bool BgeTester::i8_i16_ge_test() { return bge_test(2, -5, Simulator::Tag::SB, Simulator::Tag::SH, true); }
	bool BgeTester::i8_i16_less_test() {
		return bge_test(-5, 2, Simulator::Tag::SB, Simulator::Tag::SH, false);
	}
	bool BgeTester::i8_i32_ge_test() { return bge_test(2, -5, Simulator::Tag::SB, Simulator::Tag::SW, true); }
	bool BgeTester::i8_i32_less_test() {
		return bge_test(-5, 2, Simulator::Tag::SB, Simulator::Tag::SW, false);
	}
	bool BgeTester::i8_ui8_ge_test() { return bge_test(7, 2, Simulator::Tag::SB, Simulator::Tag::UB, true); }
	bool BgeTester::i8_ui8_less_test() {
		return bge_test(1, 7, Simulator::Tag::SB, Simulator::Tag::UB, false);
	}
	bool BgeTester::i8_ui16_ge_test() { return bge_test(7, 2, Simulator::Tag::SB, Simulator::Tag::UH, true); }
	bool BgeTester::i8_ui16_less_test() {
		return bge_test(1, 7, Simulator::Tag::SB, Simulator::Tag::UH, false);
	}
	bool BgeTester::i8_ui32_ge_test() { return bge_test(7, 2, Simulator::Tag::SB, Simulator::Tag::UW, true); }
	bool BgeTester::i8_ui32_less_test() {
		return bge_test(1, 7, Simulator::Tag::SB, Simulator::Tag::UW, false);
	}

	bool BgeTester::i16_i8_ge_test() { return bge_test(2, -5, Simulator::Tag::SH, Simulator::Tag::SB, true); }
	bool BgeTester::i16_i8_less_test() {
		return bge_test(-5, 2, Simulator::Tag::SH, Simulator::Tag::SB, false);
	}
	bool BgeTester::i16_i32_ge_test() { return bge_test(2, -5, Simulator::Tag::SH, Simulator::Tag::SW, true); }
	bool BgeTester::i16_i32_less_test() {
		return bge_test(-5, 2, Simulator::Tag::SH, Simulator::Tag::SW, false);
	}
	bool BgeTester::i16_ui8_ge_test() { return bge_test(7, 2, Simulator::Tag::SH, Simulator::Tag::UB, true); }
	bool BgeTester::i16_ui8_less_test() {
		return bge_test(1, 7, Simulator::Tag::SH, Simulator::Tag::UB, false);
	}
	bool BgeTester::i16_ui16_ge_test() { return bge_test(7, 2, Simulator::Tag::SH, Simulator::Tag::UH, true); }
	bool BgeTester::i16_ui16_less_test() {
		return bge_test(1, 7, Simulator::Tag::SH, Simulator::Tag::UH, false);
	}
	bool BgeTester::i16_ui32_ge_test() { return bge_test(7, 2, Simulator::Tag::SH, Simulator::Tag::UW, true); }
	bool BgeTester::i16_ui32_less_test() {
		return bge_test(1, 7, Simulator::Tag::SH, Simulator::Tag::UW, false);
	}

	bool BgeTester::i32_i8_ge_test() { return bge_test(2, -5, Simulator::Tag::SW, Simulator::Tag::SB, true); }
	bool BgeTester::i32_i8_less_test() {
		return bge_test(-5, 2, Simulator::Tag::SW, Simulator::Tag::SB, false);
	}
	bool BgeTester::i32_i16_ge_test() { return bge_test(2, -5, Simulator::Tag::SW, Simulator::Tag::SH, true); }
	bool BgeTester::i32_i16_less_test() {
		return bge_test(-5, 2, Simulator::Tag::SW, Simulator::Tag::SH, false);
	}
	bool BgeTester::i32_ui8_ge_test() { return bge_test(7, 2, Simulator::Tag::SW, Simulator::Tag::UB, true); }
	bool BgeTester::i32_ui8_less_test() {
		return bge_test(1, 7, Simulator::Tag::SW, Simulator::Tag::UB, false);
	}
	bool BgeTester::i32_ui16_ge_test() { return bge_test(7, 2, Simulator::Tag::SW, Simulator::Tag::UH, true); }
	bool BgeTester::i32_ui16_less_test() {
		return bge_test(1, 7, Simulator::Tag::SW, Simulator::Tag::UH, false);
	}
	bool BgeTester::i32_ui32_ge_test() { return bge_test(7, 2, Simulator::Tag::SW, Simulator::Tag::UW, true); }
	bool BgeTester::i32_ui32_less_test() {
		return bge_test(1, 7, Simulator::Tag::SW, Simulator::Tag::UW, false);
	}

	bool BgeTester::ui8_i8_ge_test() { return bge_test(7, -1, Simulator::Tag::UB, Simulator::Tag::SB, true); }
	bool BgeTester::ui8_i8_less_test() {
		return bge_test(2, 5, Simulator::Tag::UB, Simulator::Tag::SB, false);
	}
	bool BgeTester::ui8_i16_ge_test() { return bge_test(7, -1, Simulator::Tag::UB, Simulator::Tag::SH, true); }
	bool BgeTester::ui8_i16_less_test() {
		return bge_test(2, 5, Simulator::Tag::UB, Simulator::Tag::SH, false);
	}
	bool BgeTester::ui8_i32_ge_test() { return bge_test(7, -1, Simulator::Tag::UB, Simulator::Tag::SW, true); }
	bool BgeTester::ui8_i32_less_test() {
		return bge_test(2, 5, Simulator::Tag::UB, Simulator::Tag::SW, false);
	}
	bool BgeTester::ui8_ui16_ge_test() { return bge_test(5, 2, Simulator::Tag::UB, Simulator::Tag::UH, true); }
	bool BgeTester::ui8_ui16_less_test() {
		return bge_test(2, 5, Simulator::Tag::UB, Simulator::Tag::UH, false);
	}
	bool BgeTester::ui8_ui32_ge_test() { return bge_test(5, 2, Simulator::Tag::UB, Simulator::Tag::UW, true); }
	bool BgeTester::ui8_ui32_less_test() {
		return bge_test(2, 5, Simulator::Tag::UB, Simulator::Tag::UW, false);
	}

	bool BgeTester::ui16_i8_ge_test() { return bge_test(7, -1, Simulator::Tag::UH, Simulator::Tag::SB, true); }
	bool BgeTester::ui16_i8_less_test() {
		return bge_test(2, 5, Simulator::Tag::UH, Simulator::Tag::SB, false);
	}
	bool BgeTester::ui16_i16_ge_test() { return bge_test(7, -1, Simulator::Tag::UH, Simulator::Tag::SH, true); }
	bool BgeTester::ui16_i16_less_test() {
		return bge_test(2, 5, Simulator::Tag::UH, Simulator::Tag::SH, false);
	}
	bool BgeTester::ui16_i32_ge_test() { return bge_test(7, -1, Simulator::Tag::UH, Simulator::Tag::SW, true); }
	bool BgeTester::ui16_i32_less_test() {
		return bge_test(2, 5, Simulator::Tag::UH, Simulator::Tag::SW, false);
	}
	bool BgeTester::ui16_ui8_ge_test() { return bge_test(5, 2, Simulator::Tag::UH, Simulator::Tag::UB, true); }
	bool BgeTester::ui16_ui8_less_test() {
		return bge_test(2, 5, Simulator::Tag::UH, Simulator::Tag::UB, false);
	}
	bool BgeTester::ui16_ui32_ge_test() { return bge_test(5, 2, Simulator::Tag::UH, Simulator::Tag::UW, true); }
	bool BgeTester::ui16_ui32_less_test() {
		return bge_test(2, 5, Simulator::Tag::UH, Simulator::Tag::UW, false);
	}

	bool BgeTester::ui32_i8_ge_test() { return bge_test(7, -1, Simulator::Tag::UW, Simulator::Tag::SB, true); }
	bool BgeTester::ui32_i8_less_test() {
		return bge_test(2, 5, Simulator::Tag::UW, Simulator::Tag::SB, false);
	}
	bool BgeTester::ui32_i16_ge_test() { return bge_test(7, -1, Simulator::Tag::UW, Simulator::Tag::SH, true); }
	bool BgeTester::ui32_i16_less_test() {
		return bge_test(2, 5, Simulator::Tag::UW, Simulator::Tag::SH, false);
	}
	bool BgeTester::ui32_i32_ge_test() { return bge_test(7, -1, Simulator::Tag::UW, Simulator::Tag::SW, true); }
	bool BgeTester::ui32_i32_less_test() {
		return bge_test(2, 5, Simulator::Tag::UW, Simulator::Tag::SW, false);
	}
	bool BgeTester::ui32_ui8_ge_test() { return bge_test(5, 2, Simulator::Tag::UW, Simulator::Tag::UB, true); }
	bool BgeTester::ui32_ui8_less_test() {
		return bge_test(2, 5, Simulator::Tag::UW, Simulator::Tag::UB, false);
	}
	bool BgeTester::ui32_ui16_ge_test() { return bge_test(5, 2, Simulator::Tag::UW, Simulator::Tag::UH, true); }
	bool BgeTester::ui32_ui16_less_test() {
		return bge_test(2, 5, Simulator::Tag::UW, Simulator::Tag::UH, false);
	}
} // namespace Test::Unit
