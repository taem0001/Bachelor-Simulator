#ifndef ADD_HPP
#define ADD_HPP

#include "../../simulator/include/cpu.hpp"

namespace Test::Unit {
	class AddTester {
		public:
			void run_tests() {
                i8_i8_test();
            }

		private:
            void i8_i8_test() {
                Simulator::CPU cpu;
            }
	};
} // namespace Test::Unit

#endif