#include "bne.hpp"

namespace Test::Unit {
	static constexpr uint32_t BNE_X5_X6_12 = 0x00629663;

	static bool bne_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
						 bool should_branch) {
		Simulator::CPU cpu;
		cpu.set_register(5, a_val, a_tag);
		cpu.set_register(6, b_val, b_tag);

		int pc_before = cpu.get_pc();
		cpu.execute_instruction(BNE_X5_X6_12);

		int pc_after;
        bool pc_modified = cpu.get_pc_modified();
		if (should_branch) {
            pc_after = cpu.get_pc();
			return pc_after == pc_before + 12 && pc_modified;
		} else {
            pc_after = cpu.get_pc() + 4;
			return pc_after == pc_before + 4 && !pc_modified;
		}
	}

	bool BneTester::i8_i8_equal_test() { return bne_test(32, 32, Simulator::Tag::SB, Simulator::Tag::SB, false); }
	bool BneTester::i8_i8_not_equal_test() { return bne_test(32, 45, Simulator::Tag::SB, Simulator::Tag::SB, true); }

	bool BneTester::i16_i16_equal_test() {
		return bne_test(23065, 23065, Simulator::Tag::SH, Simulator::Tag::SH, false);
	}
	bool BneTester::i16_i16_not_equal_test() {
		return bne_test(23065, -1203, Simulator::Tag::SH, Simulator::Tag::SH, true);
	}

	bool BneTester::i32_i32_equal_test() {
		return bne_test(1000000000, 1000000000, Simulator::Tag::SW, Simulator::Tag::SW, false);
	}
	bool BneTester::i32_i32_not_equal_test() {
		return bne_test(1000000000, -123456789, Simulator::Tag::SW, Simulator::Tag::SW, true);
	}

	bool BneTester::ui8_ui8_equal_test() { return bne_test(200, 200, Simulator::Tag::UB, Simulator::Tag::UB, false); }
	bool BneTester::ui8_ui8_not_equal_test() {
		return bne_test(200, 55, Simulator::Tag::UB, Simulator::Tag::UB, true);
	}

	bool BneTester::ui16_ui16_equal_test() {
		return bne_test(60000, 60000, Simulator::Tag::UH, Simulator::Tag::UH, false);
	}
	bool BneTester::ui16_ui16_not_equal_test() {
		return bne_test(60000, 1234, Simulator::Tag::UH, Simulator::Tag::UH, true);
	}

	bool BneTester::ui32_ui32_equal_test() {
		return bne_test(4000000000, 4000000000, Simulator::Tag::UW, Simulator::Tag::UW, false);
	}
	bool BneTester::ui32_ui32_not_equal_test() {
		return bne_test(4000000000, 123456789, Simulator::Tag::UW, Simulator::Tag::UW, true);
	}
	bool BneTester::i8_i16_not_equal_test() {
		return bne_test(-12, 3000, Simulator::Tag::SB, Simulator::Tag::SH, true);
	}
	bool BneTester::i8_i32_not_equal_test() {
		return bne_test(100, -100000, Simulator::Tag::SB, Simulator::Tag::SW, true);
	}
	bool BneTester::i8_ui8_not_equal_test() { return bne_test(-1, 200, Simulator::Tag::SB, Simulator::Tag::UB, true); }
	bool BneTester::i8_ui16_not_equal_test() {
		return bne_test(10, 65000, Simulator::Tag::SB, Simulator::Tag::UH, true);
	}
	bool BneTester::i8_ui32_not_equal_test() {
		return bne_test(1, 3000000000, Simulator::Tag::SB, Simulator::Tag::UW, true);
	}
	bool BneTester::i16_i8_not_equal_test() {
		return bne_test(-1234, 12, Simulator::Tag::SH, Simulator::Tag::SB, true);
	}
	bool BneTester::i16_i32_not_equal_test() {
		return bne_test(12345, 200000, Simulator::Tag::SH, Simulator::Tag::SW, true);
	}
	bool BneTester::i16_ui8_not_equal_test() {
		return bne_test(-10, 250, Simulator::Tag::SH, Simulator::Tag::UB, true);
	}
	bool BneTester::i16_ui16_not_equal_test() {
		return bne_test(-200, 65000, Simulator::Tag::SH, Simulator::Tag::UH, true);
	}
	bool BneTester::i16_ui32_not_equal_test() {
		return bne_test(7, 4000000000, Simulator::Tag::SH, Simulator::Tag::UW, true);
	}
	bool BneTester::i32_i8_not_equal_test() {
		return bne_test(-100000, 1, Simulator::Tag::SW, Simulator::Tag::SB, true);
	}
	bool BneTester::i32_i16_not_equal_test() {
		return bne_test(500000, -123, Simulator::Tag::SW, Simulator::Tag::SH, true);
	}
	bool BneTester::i32_ui8_not_equal_test() { return bne_test(-5, 10, Simulator::Tag::SW, Simulator::Tag::UB, true); }
	bool BneTester::i32_ui16_not_equal_test() {
		return bne_test(-1000, 60000, Simulator::Tag::SW, Simulator::Tag::UH, true);
	}
	bool BneTester::i32_ui32_not_equal_test() {
		return bne_test(-1, 4000000000, Simulator::Tag::SW, Simulator::Tag::UW, true);
	}
	bool BneTester::ui8_i8_not_equal_test() { return bne_test(200, -1, Simulator::Tag::UB, Simulator::Tag::SB, true); }
	bool BneTester::ui8_i16_not_equal_test() {
		return bne_test(250, -1000, Simulator::Tag::UB, Simulator::Tag::SH, true);
	}
	bool BneTester::ui8_i32_not_equal_test() {
		return bne_test(10, -100000, Simulator::Tag::UB, Simulator::Tag::SW, true);
	}
	bool BneTester::ui8_ui16_not_equal_test() {
		return bne_test(200, 1000, Simulator::Tag::UB, Simulator::Tag::UH, true);
	}
	bool BneTester::ui8_ui32_not_equal_test() {
		return bne_test(1, 3000000000, Simulator::Tag::UB, Simulator::Tag::UW, true);
	}
	bool BneTester::ui16_i8_not_equal_test() {
		return bne_test(65000, 10, Simulator::Tag::UH, Simulator::Tag::SB, true);
	}
	bool BneTester::ui16_i16_not_equal_test() {
		return bne_test(60000, -200, Simulator::Tag::UH, Simulator::Tag::SH, true);
	}
	bool BneTester::ui16_i32_not_equal_test() {
		return bne_test(65000, -1000, Simulator::Tag::UH, Simulator::Tag::SW, true);
	}
	bool BneTester::ui16_ui8_not_equal_test() {
		return bne_test(1000, 200, Simulator::Tag::UH, Simulator::Tag::UB, true);
	}
	bool BneTester::ui16_ui32_not_equal_test() {
		return bne_test(65000, 3000000000, Simulator::Tag::UH, Simulator::Tag::UW, true);
	}
	bool BneTester::ui32_i8_not_equal_test() {
		return bne_test(3000000000, 1, Simulator::Tag::UW, Simulator::Tag::SB, true);
	}
	bool BneTester::ui32_i16_not_equal_test() {
		return bne_test(3000000000, 7, Simulator::Tag::UW, Simulator::Tag::SH, true);
	}
	bool BneTester::ui32_i32_not_equal_test() {
		return bne_test(3000000000, -1, Simulator::Tag::UW, Simulator::Tag::SW, true);
	}
	bool BneTester::ui32_ui8_not_equal_test() {
		return bne_test(3000000000, 2, Simulator::Tag::UW, Simulator::Tag::UB, true);
	}
	bool BneTester::ui32_ui16_not_equal_test() {
		return bne_test(3000000000, 60000, Simulator::Tag::UW, Simulator::Tag::UH, true);
	}
} // namespace Test::Unit
