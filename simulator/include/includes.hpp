#ifndef INCLUDES_HPP
#define INCLUDES_HPP

#include <array>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <variant>

#define REGISTERNUM 32

// Instruction specific
#define OPCODE_LEN	7
#define REG_ENC_LEN 5
#define FUNC3_LEN	3
#define SHAMT_LEN	5
#define FUNC7_LEN	7

// Tag specific
#define TAG_BYTE	 0x0
#define TAG_HALF	 0x1
#define TAG_WORD	 0x2
#define TAG_UNSIGNED 0
#define TAG_SIGNED	 1

#endif
