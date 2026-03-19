#include "../include/cpu.hpp"

namespace Simulator {
    void run_sim(const std::string& filepath) {
        CPU cpu;
        cpu.load_program(filepath);
        cpu.run();
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1) return 1;

    Simulator::run_sim(argv[1]);
    return 0;
}