#ifndef CPU_HPP
#define CPU_HPP

#include "file.hpp"
#include "includes.hpp"
#include "register.hpp"
#include "tag.hpp"

namespace Simulator {
    // Shared functions
    uint32_t _bitwise_add(uint32_t a, uint32_t b);
    uint32_t bitwise_add(uint32_t a, uint32_t b);

    class CPU {
        public:
            CPU();
            void execute_instruction(const int instruction);
            void run();

            std::array<Register, REGISTERNUM> &get_registers();
            const std::array<Register, REGISTERNUM> &get_registers() const;
            const std::array<uint8_t, MEMORY_SIZE_BYTES> &get_memory() const;

            void load_program(const std::string &path);

            // TODO: THESE FUNCTIONS ARE ONLY FOR TESTING PURPOSES; REMOVE LATER
            void set_register(const char rd, const uint32_t data, const Tag &tag);
            void set_memory(uint32_t addr, uint32_t data, Tag tag);

            int get_pc() { return pc; }
            bool get_pc_modified() { return pc_modified; }
            bool get_ebreak() { return ebreak; }

        private:
            std::array<Register, REGISTERNUM> registers;
            std::array<uint8_t, MEMORY_SIZE_BYTES> memory{};
            std::size_t program_size_bytes;
            int pc;
            bool pc_modified;
            bool ebreak;

            void write_to_register(const char rd, const Register &r);
            void print_registers();

            void r_instruction(const char rd, const char func3, const char rs1, const char rs2, const char func7);
            void i_instruction(const char rd, const char func3, const char rs1, const short imm);
            void si_instruction(const char rd, const char func7);
            void l_instruction(const char rd, const char func3, const char rs1, const short imm);
            void s_instruction(const char imm4_0, const char func3, const char rs1, const char rs2, const char imm11_5);
            void b_instruction(const char func3, const char rs1, const char rs2, int imm);
            void j_instruction(const char rd, const int imm);
            void x_instruction(const int bits);

            void ecall_instruction();
            void jalr_instruction(const char rd, const char func3, const char rs1, const short imm);
            void lui_instruction(const char rd, const int imm);
            void auipc_instruction(const char rd, const int imm);
    };
} // namespace Simulator

#endif
