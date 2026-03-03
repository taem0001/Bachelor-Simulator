#include "sl.hpp"

namespace Test::Unit {
	static constexpr uint32_t SL_X20_X10_X11 = 0b00000000101101010101101000110011;

	static bool sl_test(uint32_t a_val, uint32_t b_val, Simulator::Tag a_tag, Simulator::Tag b_tag,
						uint32_t expected_val, Simulator::Tag expected_tag) {
		Simulator::CPU cpu;
		cpu.set_register(10, a_val, a_tag);
		cpu.set_register(11, b_val, b_tag);
		cpu.execute_instruction(SL_X20_X10_X11);

		const auto registers = cpu.get_registers();

		const bool passed_data = registers[20].data == expected_val;
		const bool passed_tag = registers[20].tag == expected_tag;
		return passed_data && passed_tag;
	}

	bool SlTester::i8_i8_test() {
		int8_t a = static_cast<int8_t>(0x5B);
		int8_t b = static_cast<int8_t>(0x05);

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint8_t>(a));
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint8_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::SB, 0x00000B60u, Simulator::Tag::SB);
	}
	bool SlTester::i16_i16_test() {
		int16_t a = static_cast<int16_t>(0x5B5B);
		int16_t b = static_cast<int16_t>(0x0005);

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint16_t>(a));
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint16_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::SH, 0x000B6B60u, Simulator::Tag::SH);
	}
	bool SlTester::i32_i32_test() {
		int32_t a = static_cast<int32_t>(0x5B5B5B5B);
		int32_t b = static_cast<int32_t>(5);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::SW, 0x6B6B6B60u, Simulator::Tag::SW);
	}
	bool SlTester::ui8_ui8_test() {
		uint8_t a = static_cast<uint8_t>(0xDB);
		uint8_t b = static_cast<uint8_t>(0x05);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::UB, 0x00001B60u, Simulator::Tag::UB);
	}
	bool SlTester::ui16_ui16_test() {
		uint16_t a = static_cast<uint16_t>(0xDBDB);
		uint16_t b = static_cast<uint16_t>(0x0005);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::UH, 0x001B7B60u, Simulator::Tag::UH);
	}
	bool SlTester::ui32_ui32_test() {
		uint32_t a = 0xDBDBDBDBu;
		uint32_t b = 5u;

		uint32_t in_a = a;
		uint32_t shamt = b;

		return sl_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::UW, 0x7B7B7B60u, Simulator::Tag::UW);
	}

	bool SlTester::i8_i16_test() {
		int8_t a = static_cast<int8_t>(0x5B);
		int16_t b = static_cast<int16_t>(0x0005);

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint8_t>(a));
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint16_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::SH, 0x00000B60u, Simulator::Tag::SB);
	}
	bool SlTester::i8_i32_test() {
		int8_t a = static_cast<int8_t>(0x5B);
		int32_t b = static_cast<int32_t>(5);

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint8_t>(a));
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::SW, 0x00000B60u, Simulator::Tag::SB);
	}
	bool SlTester::i8_ui8_test() {
		int8_t a = static_cast<int8_t>(0x5B);
		uint8_t b = static_cast<uint8_t>(0x05);

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint8_t>(a));
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::UB, 0x00000B60u, Simulator::Tag::SB);
	}
	bool SlTester::i8_ui16_test() {
		int8_t a = static_cast<int8_t>(0x5B);
		uint16_t b = static_cast<uint16_t>(0x0005);

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint8_t>(a));
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::UH, 0x00000B60u, Simulator::Tag::SB);
	}
	bool SlTester::i8_ui32_test() {
		int8_t a = static_cast<int8_t>(0x5B);
		uint32_t b = 5u;

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint8_t>(a));
		uint32_t shamt = b;

		return sl_test(in_a, shamt, Simulator::Tag::SB, Simulator::Tag::UW, 0x00000B60u, Simulator::Tag::SB);
	}

	bool SlTester::i16_i8_test() {
		int16_t a = static_cast<int16_t>(0x5B5B);
		int8_t b = static_cast<int8_t>(0x05);

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint16_t>(a));
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint8_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::SB, 0x000B6B60u, Simulator::Tag::SH);
	}
	bool SlTester::i16_i32_test() {
		int16_t a = static_cast<int16_t>(0x5B5B);
		int32_t b = static_cast<int32_t>(5);

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint16_t>(a));
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::SW, 0x000B6B60u, Simulator::Tag::SH);
	}
	bool SlTester::i16_ui8_test() {
		int16_t a = static_cast<int16_t>(0x5B5B);
		uint8_t b = static_cast<uint8_t>(0x05);

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint16_t>(a));
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::UB, 0x000B6B60u, Simulator::Tag::SH);
	}
	bool SlTester::i16_ui16_test() {
		int16_t a = static_cast<int16_t>(0x5B5B);
		uint16_t b = static_cast<uint16_t>(0x0005);

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint16_t>(a));
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::UH, 0x000B6B60u, Simulator::Tag::SH);
	}
	bool SlTester::i16_ui32_test() {
		int16_t a = static_cast<int16_t>(0x5B5B);
		uint32_t b = 5u;

		uint32_t in_a = static_cast<uint32_t>(static_cast<uint16_t>(a));
		uint32_t shamt = b;

		return sl_test(in_a, shamt, Simulator::Tag::SH, Simulator::Tag::UW, 0x000B6B60u, Simulator::Tag::SH);
	}

	bool SlTester::i32_i8_test() {
		int32_t a = static_cast<int32_t>(0x5B5B5B5B);
		int8_t b = static_cast<int8_t>(0x05);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint8_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::SB, 0x6B6B6B60u, Simulator::Tag::SW);
	}
	bool SlTester::i32_i16_test() {
		int32_t a = static_cast<int32_t>(0x5B5B5B5B);
		int16_t b = static_cast<int16_t>(0x0005);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint16_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::SH, 0x6B6B6B60u, Simulator::Tag::SW);
	}
	bool SlTester::i32_ui8_test() {
		int32_t a = static_cast<int32_t>(0x5B5B5B5B);
		uint8_t b = static_cast<uint8_t>(0x05);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::UB, 0x6B6B6B60u, Simulator::Tag::SW);
	}
	bool SlTester::i32_ui16_test() {
		int32_t a = static_cast<int32_t>(0x5B5B5B5B);
		uint16_t b = static_cast<uint16_t>(0x0005);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::UH, 0x6B6B6B60u, Simulator::Tag::SW);
	}
	bool SlTester::i32_ui32_test() {
		int32_t a = static_cast<int32_t>(0x5B5B5B5B);
		uint32_t b = 5u;

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = b;

		return sl_test(in_a, shamt, Simulator::Tag::SW, Simulator::Tag::UW, 0x6B6B6B60u, Simulator::Tag::SW);
	}

	bool SlTester::ui8_i8_test() {
		uint8_t a = static_cast<uint8_t>(0xDB);
		int8_t b = static_cast<int8_t>(0x05);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint8_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::SB, 0x00001B60u, Simulator::Tag::UB);
	}
	bool SlTester::ui8_i16_test() {
		uint8_t a = static_cast<uint8_t>(0xDB);
		int16_t b = static_cast<int16_t>(0x0005);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint16_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::SH, 0x00001B60u, Simulator::Tag::UB);
	}
	bool SlTester::ui8_i32_test() {
		uint8_t a = static_cast<uint8_t>(0xDB);
		int32_t b = static_cast<int32_t>(5);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::SW, 0x00001B60u, Simulator::Tag::UB);
	}
	bool SlTester::ui8_ui16_test() {
		uint8_t a = static_cast<uint8_t>(0xDB);
		uint16_t b = static_cast<uint16_t>(0x0005);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::UH, 0x00001B60u, Simulator::Tag::UB);
	}
	bool SlTester::ui8_ui32_test() {
		uint8_t a = static_cast<uint8_t>(0xDB);
		uint32_t b = 5u;

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = b;

		return sl_test(in_a, shamt, Simulator::Tag::UB, Simulator::Tag::UW, 0x00001B60u, Simulator::Tag::UB);
	}

	bool SlTester::ui16_i8_test() {
		uint16_t a = static_cast<uint16_t>(0xDBDB);
		int8_t b = static_cast<int8_t>(0x05);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint8_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::SB, 0x001B7B60u, Simulator::Tag::UH);
	}
	bool SlTester::ui16_i16_test() {
		uint16_t a = static_cast<uint16_t>(0xDBDB);
		int16_t b = static_cast<int16_t>(0x0005);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint16_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::SH, 0x001B7B60u, Simulator::Tag::UH);
	}
	bool SlTester::ui16_i32_test() {
		uint16_t a = static_cast<uint16_t>(0xDBDB);
		int32_t b = static_cast<int32_t>(5);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::SW, 0x001B7B60u, Simulator::Tag::UH);
	}
	bool SlTester::ui16_ui8_test() {
		uint16_t a = static_cast<uint16_t>(0xDBDB);
		uint8_t b = static_cast<uint8_t>(0x05);

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::UB, 0x001B7B60u, Simulator::Tag::UH);
	}
	bool SlTester::ui16_ui32_test() {
		uint16_t a = static_cast<uint16_t>(0xDBDB);
		uint32_t b = 5u;

		uint32_t in_a = static_cast<uint32_t>(a);
		uint32_t shamt = b;

		return sl_test(in_a, shamt, Simulator::Tag::UH, Simulator::Tag::UW, 0x001B7B60u, Simulator::Tag::UH);
	}

	bool SlTester::ui32_i8_test() {
		uint32_t a = 0xDBDBDBDBu;
		int8_t b = static_cast<int8_t>(0x05);

		uint32_t in_a = a;
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint8_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::SB, 0x7B7B7B60u, Simulator::Tag::UW);
	}
	bool SlTester::ui32_i16_test() {
		uint32_t a = 0xDBDBDBDBu;
		int16_t b = static_cast<int16_t>(0x0005);

		uint32_t in_a = a;
		uint32_t shamt = static_cast<uint32_t>(static_cast<uint16_t>(b));

		return sl_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::SH, 0x7B7B7B60u, Simulator::Tag::UW);
	}
	bool SlTester::ui32_i32_test() {
		uint32_t a = 0xDBDBDBDBu;
		int32_t b = static_cast<int32_t>(5);

		uint32_t in_a = a;
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::SW, 0x7B7B7B60u, Simulator::Tag::UW);
	}
	bool SlTester::ui32_ui8_test() {
		uint32_t a = 0xDBDBDBDBu;
		uint8_t b = static_cast<uint8_t>(0x05);

		uint32_t in_a = a;
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::UB, 0x7B7B7B60u, Simulator::Tag::UW);
	}
	bool SlTester::ui32_ui16_test() {
		uint32_t a = 0xDBDBDBDBu;
		uint16_t b = static_cast<uint16_t>(0x0005);

		uint32_t in_a = a;
		uint32_t shamt = static_cast<uint32_t>(b);

		return sl_test(in_a, shamt, Simulator::Tag::UW, Simulator::Tag::UH, 0x7B7B7B60u, Simulator::Tag::UW);
	}
} // namespace Test::Unit