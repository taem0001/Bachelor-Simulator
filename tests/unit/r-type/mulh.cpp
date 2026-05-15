#include "mulh.hpp"

namespace Test::Unit {
	static constexpr uint32_t MULH_X30_X17_X25 = 0b00000011100110001001111100110011;

	static bool mulh_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
						 uint32_t expected_val, Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(17, a_val, a_tag);
		cpu.set_register(25, b_val, b_tag);
		cpu.execute_instruction(MULH_X30_X17_X25);

		const auto registers = cpu.get_registers();

		const bool passed_data = registers[30].data == expected_val;
		const bool passed_tag = registers[30].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool MulhTester::i8_i8_test() {
        int8_t a = -128;
        int8_t b = 127;
        return mulh_test(a, b, Simulator::Tag::SB, Simulator::Tag::SB, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::i16_i16_test() {
        int16_t a = -32768;
        int16_t b = 32767;
        return mulh_test(a, b, Simulator::Tag::SH, Simulator::Tag::SH, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::i32_i32_test() {
        int32_t a = 2147483647;
        int32_t b = 2147483647;
        return mulh_test(a, b, Simulator::Tag::SW, Simulator::Tag::SW, 0x3FFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::ui8_ui8_test() {
        uint8_t a = 255;
        uint8_t b = 255;
        return mulh_test(a, b, Simulator::Tag::UB, Simulator::Tag::UB, 0, Simulator::Tag::SW);
    }

    bool MulhTester::ui16_ui16_test() {
        uint16_t a = 65535;
        uint16_t b = 65535;
        return mulh_test(a, b, Simulator::Tag::UH, Simulator::Tag::UH, 0, Simulator::Tag::SW);
    }

    bool MulhTester::ui32_ui32_test() {
        uint32_t a = 0xFFFFFFFFu;
        uint32_t b = 0xFFFFFFFFu;
        return mulh_test(a, b, Simulator::Tag::UW, Simulator::Tag::UW, 0xFFFFFFFEu, Simulator::Tag::UW);
    }

    bool MulhTester::i8_i16_test() {
        int8_t a = -128;
        int16_t b = 32767;
        return mulh_test(a, b, Simulator::Tag::SB, Simulator::Tag::SH, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::i8_i32_test() {
        int8_t a = -128;
        int32_t b = 2147483647;
        return mulh_test(a, b, Simulator::Tag::SB, Simulator::Tag::SW, 0xFFFFFFC0u, Simulator::Tag::SW);
    }

    bool MulhTester::i8_ui8_test() {
        int8_t a = -128;
        uint8_t b = 255;
        return mulh_test(a, b, Simulator::Tag::SB, Simulator::Tag::UB, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::i8_ui16_test() {
        int8_t a = -128;
        uint16_t b = 65535;
        return mulh_test(a, b, Simulator::Tag::SB, Simulator::Tag::UH, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::i8_ui32_test() {
        int8_t a = -128;
        uint32_t b = 0xFFFFFFFFu;
        return mulh_test(a, b, Simulator::Tag::SB, Simulator::Tag::UW, 0xFFFFFF80u, Simulator::Tag::UW);
    }

    bool MulhTester::i16_i8_test() {
        int16_t a = 32767;
        int8_t b = -128;
        return mulh_test(a, b, Simulator::Tag::SH, Simulator::Tag::SB, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::i16_i32_test() {
        int16_t a = -32768;
        int32_t b = 2147483647;
        return mulh_test(a, b, Simulator::Tag::SH, Simulator::Tag::SW, 0xFFFFC000u, Simulator::Tag::SW);
    }

    bool MulhTester::i16_ui8_test() {
        int16_t a = -32768;
        uint8_t b = 255;
        return mulh_test(a, b, Simulator::Tag::SH, Simulator::Tag::UB, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::i16_ui16_test() {
        int16_t a = -32768;
        uint16_t b = 65535;
        return mulh_test(a, b, Simulator::Tag::SH, Simulator::Tag::UH, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::i16_ui32_test() {
        int16_t a = -32768;
        uint32_t b = 0xFFFFFFFFu;
        return mulh_test(a, b, Simulator::Tag::SH, Simulator::Tag::UW, 0xFFFF8000u, Simulator::Tag::UW);
    }

    bool MulhTester::i32_i8_test() {
        int32_t a = 2147483647;
        int8_t b = 127;
        return mulh_test(a, b, Simulator::Tag::SW, Simulator::Tag::SB, 0x0000003Fu, Simulator::Tag::SW);
    }

    bool MulhTester::i32_i16_test() {
        int32_t a = 2147483647;
        int16_t b = 32767;
        return mulh_test(a, b, Simulator::Tag::SW, Simulator::Tag::SH, 0x00003FFFu, Simulator::Tag::SW);
    }

    bool MulhTester::i32_ui8_test() {
        int32_t a = (-2147483647 - 1);
        uint8_t b = 255;
        return mulh_test(a, b, Simulator::Tag::SW, Simulator::Tag::UB, 0xFFFFFF80u, Simulator::Tag::SW);
    }

    bool MulhTester::i32_ui16_test() {
        int32_t a = (-2147483647 - 1);
        uint16_t b = 65535;
        return mulh_test(a, b, Simulator::Tag::SW, Simulator::Tag::UH, 0xFFFF8000u, Simulator::Tag::SW);
    }

    bool MulhTester::i32_ui32_test() {
        int32_t a = (-2147483647 - 1);
        uint32_t b = 0xFFFFFFFFu;
        return mulh_test(a, b, Simulator::Tag::SW, Simulator::Tag::UW, 0x80000000u, Simulator::Tag::UW);
    }

    bool MulhTester::ui8_i8_test() {
        uint8_t a = 255;
        int8_t b = -128;
        return mulh_test(a, b, Simulator::Tag::UB, Simulator::Tag::SB, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::ui8_i16_test() {
        uint8_t a = 255;
        int16_t b = -32768;
        return mulh_test(a, b, Simulator::Tag::UB, Simulator::Tag::SH, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::ui8_i32_test() {
        uint8_t a = 255;
        int32_t b = (-2147483647 - 1);
        return mulh_test(a, b, Simulator::Tag::UB, Simulator::Tag::SW, 0xFFFFFF80u, Simulator::Tag::SW);
    }

    bool MulhTester::ui8_ui16_test() {
        uint8_t a = 255;
        uint16_t b = 65535;
        return mulh_test(a, b, Simulator::Tag::UB, Simulator::Tag::UH, 0, Simulator::Tag::SW);
    }

    bool MulhTester::ui8_ui32_test() {
        uint8_t a = 255;
        uint32_t b = 0xFFFFFFFFu;
        return mulh_test(a, b, Simulator::Tag::UB, Simulator::Tag::UW, 0x000000FEu, Simulator::Tag::UW);
    }

    bool MulhTester::ui16_i8_test() {
        uint16_t a = 65535;
        int8_t b = -128;
        return mulh_test(a, b, Simulator::Tag::UH, Simulator::Tag::SB, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::ui16_i16_test() {
        uint16_t a = 65535;
        int16_t b = -32768;
        return mulh_test(a, b, Simulator::Tag::UH, Simulator::Tag::SH, 0xFFFFFFFFu, Simulator::Tag::SW);
    }

    bool MulhTester::ui16_i32_test() {
        uint16_t a = 65535;
        int32_t b = (-2147483647 - 1);
        return mulh_test(a, b, Simulator::Tag::UH, Simulator::Tag::SW, 0xFFFF8000u, Simulator::Tag::SW);
    }

    bool MulhTester::ui16_ui8_test() {
        uint16_t a = 65535;
        uint8_t b = 255;
        return mulh_test(a, b, Simulator::Tag::UH, Simulator::Tag::UB, 0, Simulator::Tag::SW);
    }

    bool MulhTester::ui16_ui32_test() {
        uint16_t a = 65535;
        uint32_t b = 0xFFFFFFFFu;
        return mulh_test(a, b, Simulator::Tag::UH, Simulator::Tag::UW, 0x0000FFFEu, Simulator::Tag::UW);
    }

    bool MulhTester::ui32_i8_test() {
        uint32_t a = 0xFFFFFFFFu;
        int8_t b = -128;
        return mulh_test(a, b, Simulator::Tag::UW, Simulator::Tag::SB, 0xFFFFFF80u, Simulator::Tag::UW);
    }

    bool MulhTester::ui32_i16_test() {
        uint32_t a = 0xFFFFFFFFu;
        int16_t b = -32768;
        return mulh_test(a, b, Simulator::Tag::UW, Simulator::Tag::SH, 0xFFFF8000u, Simulator::Tag::UW);
    }

    bool MulhTester::ui32_i32_test() {
        uint32_t a = 0xFFFFFFFFu;
        int32_t b = (-2147483647 - 1);
        return mulh_test(a, b, Simulator::Tag::UW, Simulator::Tag::SW, 0x80000000u, Simulator::Tag::UW);
    }

    bool MulhTester::ui32_ui8_test() {
        uint32_t a = 0xFFFFFFFFu;
        uint8_t b = 255;
        return mulh_test(a, b, Simulator::Tag::UW, Simulator::Tag::UB, 0x000000FEu, Simulator::Tag::UW);
    }

    bool MulhTester::ui32_ui16_test() {
        uint32_t a = 0xFFFFFFFFu;
        uint16_t b = 65535;
        return mulh_test(a, b, Simulator::Tag::UW, Simulator::Tag::UH, 0x0000FFFEu, Simulator::Tag::UW);
    }
} // namespace Test::Unit