#include "../include/cpu.hpp"

namespace Simulator {
    constexpr auto tag_visitor = overloaded{
        [](int8_t) { return TAG::SB; },  [](int16_t) { return TAG::SH; },  [](int32_t) { return TAG::SW; },
        [](uint8_t) { return TAG::UB; }, [](uint16_t) { return TAG::UH; }, [](uint32_t) { return TAG::UW; },
    };

    CPU::CPU() : pc(0) { registers.fill({0, TAG::SW}); }

    // Getters/Setters
    std::array<Register, REGISTERNUM> &CPU::get_registers() { return registers; }

    const std::array<Register, REGISTERNUM> &CPU::get_registers() const { return registers; }

    void CPU::set_register(const char rd, const Data &data, const TAG &tag) { write_to_register(rd, {data, tag}); }

    void CPU::write_to_register(const char rd, const Register &r) {
        if (rd != 0) {
            registers[rd] = r;
        }
    }

    // Instruction functions
    void CPU::execute_instruction(const int instruction) {
        char opcode = instruction & 0x7F;

        switch (opcode) {
            case 0x13: {
                const char rd = (instruction >> OPCODE_LEN) & 0x1F;
                const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
                const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
                const short imm = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN));

                i_instruction(rd, func3, rs1, imm);
            } break;
            case 0x33: {
                const char rd = (instruction >> OPCODE_LEN) & 0x1F;
                const char func3 = (instruction >> (OPCODE_LEN + REG_ENC_LEN)) & 0x7;
                const char rs1 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN)) & 0x1F;
                const char rs2 = (instruction >> (OPCODE_LEN + REG_ENC_LEN + FUNC3_LEN + REG_ENC_LEN)) & 0x1F;

                r_instruction(rd, func3, rs1, rs2);
            } break;
            default:
                break;
        };

        pc += 4;
    }

    // r-type instruction functions
    Register _add_instruction(const Register &rs1, const Register &rs2) {
        const auto add_visitor = overloaded{
            [](auto a, auto b)
                requires(std::is_integral_v<std::decay_t<decltype(a)>> && std::is_integral_v<std::decay_t<decltype(b)>>)
            {
                using A = std::decay_t<decltype(a)>;
                using B = std::decay_t<decltype(b)>;
                using R = std::common_type_t<A, B>;
                return Data{static_cast<R>(a) + static_cast<R>(b)};
            }};

        const Data add_result = std::visit(add_visitor, rs1.data, rs2.data);
        const TAG tag_result = std::visit(tag_visitor, add_result);

        return {add_result, tag_result};
    }

    Register _sub_instruction(const Register &rs1, const Register &rs2) {
        const auto sub_visitor = overloaded{
            [](auto a, auto b)
                requires(std::is_integral_v<std::decay_t<decltype(a)>> && std::is_integral_v<std::decay_t<decltype(b)>>)
            {
                using A = std::decay_t<decltype(a)>;
                using B = std::decay_t<decltype(b)>;
                using R = std::common_type_t<A, B>;
                return Data{static_cast<R>(a) - static_cast<R>(b)};
            }};

        const Data sub_result = std::visit(sub_visitor, rs1.data, rs2.data);
        const TAG tag_result = std::visit(tag_visitor, sub_result);

        return {sub_result, tag_result};
    }

    Register _shift_instruction(const Register &rs1, const Register &rs2) { return {0, TAG::SW}; }

    void CPU::r_instruction(const char rd, const char func3, const char rs1, const char rs2) {
        switch (func3) {
            case 0x2: // SHIFT
            {
                Register result = _shift_instruction(registers[rs2], registers[rs2]);
                write_to_register(rd, result);
            } break;
            case 0x0: // ADD
            {
                Register result = _add_instruction(registers[rs1], registers[rs2]);
                write_to_register(rd, result);
            } break;
            case 0x1: // SUB
            {
                Register result = _sub_instruction(registers[rs1], registers[rs2]);
                write_to_register(rd, result);
            } break;
            default:
                break;
        }
    }

    // i-type instruction functions
    Register _sli_instruction(const Register &rs1, const int8_t imm) {
        const Data sli_result = std::visit(overloaded{[&](auto value)
                                                          requires(std::is_integral_v<std::decay_t<decltype(value)>>)
                                                      {
                                                          using A = std::decay_t<decltype(value)>;
                                                          const uint8_t shamt = static_cast<uint8_t>(imm);

                                                          using UA = std::make_unsigned_t<A>;
                                                          const UA v = static_cast<UA>(value);
                                                          return Data{static_cast<A>(v << shamt)};
                                                      }},
                                                      rs1.data);

        return {sli_result, rs1.tag};
    }

    void CPU::i_instruction(const char rd, const char func3, const char rs1, const short imm) {
        switch (func3) {
            case 0x1: // SLI
            {
                if (((imm >> 5) & 0x7F) != 0)
                    break;
                Register result = _sli_instruction(registers[rs1], imm & 0x1F);
                write_to_register(rd, result);
            } break;
            case 0x5: // SRI
                break;
            default:
                break;
        }
    }
} // namespace Simulator