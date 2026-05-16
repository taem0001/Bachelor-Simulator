#ifndef R_TEST_HPP
#define R_TEST_HPP

#include "r-type/add.hpp"
#include "r-type/and.hpp"
#include "r-type/div.hpp"
#include "r-type/rem.hpp"
#include "r-type/or.hpp"
#include "r-type/sl.hpp"
#include "r-type/slt.hpp"
#include "r-type/sr.hpp"
#include "r-type/sub.hpp"
#include "r-type/xor.hpp"
#include "r-type/mul.hpp"
#include "r-type/mulh.hpp"

namespace Test {
	using TestFn = bool (*)();

	static const std::array<TestFn, 36> add_tests = {
		&Unit::AddTester::i8_i8_test,	 &Unit::AddTester::i16_i16_test,   &Unit::AddTester::i32_i32_test,
		&Unit::AddTester::ui8_ui8_test,	 &Unit::AddTester::ui16_ui16_test, &Unit::AddTester::ui32_ui32_test,

		&Unit::AddTester::i8_i16_test,	 &Unit::AddTester::i8_i32_test,	   &Unit::AddTester::i8_ui8_test,
		&Unit::AddTester::i8_ui16_test,	 &Unit::AddTester::i8_ui32_test,

		&Unit::AddTester::i16_i8_test,	 &Unit::AddTester::i16_i32_test,   &Unit::AddTester::i16_ui8_test,
		&Unit::AddTester::i16_ui16_test, &Unit::AddTester::i16_ui32_test,

		&Unit::AddTester::i32_i8_test,	 &Unit::AddTester::i32_i16_test,   &Unit::AddTester::i32_ui8_test,
		&Unit::AddTester::i32_ui16_test, &Unit::AddTester::i32_ui32_test,

		&Unit::AddTester::ui8_i8_test,	 &Unit::AddTester::ui8_i16_test,   &Unit::AddTester::ui8_i32_test,
		&Unit::AddTester::ui8_ui16_test, &Unit::AddTester::ui8_ui32_test,

		&Unit::AddTester::ui16_i8_test,	 &Unit::AddTester::ui16_i16_test,  &Unit::AddTester::ui16_i32_test,
		&Unit::AddTester::ui16_ui8_test, &Unit::AddTester::ui16_ui32_test,

		&Unit::AddTester::ui32_i8_test,	 &Unit::AddTester::ui32_i16_test,  &Unit::AddTester::ui32_i32_test,
		&Unit::AddTester::ui32_ui8_test, &Unit::AddTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> add_test_names = {
		"i8 + i8",	   "i16 + i16",	 "i32 + i32",  "ui8 + ui8",	 "ui16 + ui16", "ui32 + ui32",
		"i8 + i16",	   "i8 + i32",	 "i8 + ui8",   "i8 + ui16",	 "i8 + ui32",	"i16 + i8",
		"i16 + i32",   "i16 + ui8",	 "i16 + ui16", "i16 + ui32", "i32 + i8",	"i32 + i16",
		"i32 + ui8",   "i32 + ui16", "i32 + ui32", "ui8 + i8",	 "ui8 + i16",	"ui8 + i32",
		"ui8 + ui16",  "ui8 + ui32", "ui16 + i8",  "ui16 + i16", "ui16 + i32",	"ui16 + ui8",
		"ui16 + ui32", "ui32 + i8",	 "ui32 + i16", "ui32 + i32", "ui32 + ui8",	"ui32 + ui16",
	};

	static const std::array<TestFn, 36> sub_tests = {
		&Unit::SubTester::i8_i8_test,	 &Unit::SubTester::i16_i16_test,   &Unit::SubTester::i32_i32_test,
		&Unit::SubTester::ui8_ui8_test,	 &Unit::SubTester::ui16_ui16_test, &Unit::SubTester::ui32_ui32_test,

		&Unit::SubTester::i8_i16_test,	 &Unit::SubTester::i8_i32_test,	   &Unit::SubTester::i8_ui8_test,
		&Unit::SubTester::i8_ui16_test,	 &Unit::SubTester::i8_ui32_test,

		&Unit::SubTester::i16_i8_test,	 &Unit::SubTester::i16_i32_test,   &Unit::SubTester::i16_ui8_test,
		&Unit::SubTester::i16_ui16_test, &Unit::SubTester::i16_ui32_test,

		&Unit::SubTester::i32_i8_test,	 &Unit::SubTester::i32_i16_test,   &Unit::SubTester::i32_ui8_test,
		&Unit::SubTester::i32_ui16_test, &Unit::SubTester::i32_ui32_test,

		&Unit::SubTester::ui8_i8_test,	 &Unit::SubTester::ui8_i16_test,   &Unit::SubTester::ui8_i32_test,
		&Unit::SubTester::ui8_ui16_test, &Unit::SubTester::ui8_ui32_test,

		&Unit::SubTester::ui16_i8_test,	 &Unit::SubTester::ui16_i16_test,  &Unit::SubTester::ui16_i32_test,
		&Unit::SubTester::ui16_ui8_test, &Unit::SubTester::ui16_ui32_test,

		&Unit::SubTester::ui32_i8_test,	 &Unit::SubTester::ui32_i16_test,  &Unit::SubTester::ui32_i32_test,
		&Unit::SubTester::ui32_ui8_test, &Unit::SubTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> sub_test_names = {
		"i8 - i8",	   "i16 - i16",	 "i32 - i32",  "ui8 - ui8",	 "ui16 - ui16", "ui32 - ui32",
		"i8 - i16",	   "i8 - i32",	 "i8 - ui8",   "i8 - ui16",	 "i8 - ui32",	"i16 - i8",
		"i16 - i32",   "i16 - ui8",	 "i16 - ui16", "i16 - ui32", "i32 - i8",	"i32 - i16",
		"i32 - ui8",   "i32 - ui16", "i32 - ui32", "ui8 - i8",	 "ui8 - i16",	"ui8 - i32",
		"ui8 - ui16",  "ui8 - ui32", "ui16 - i8",  "ui16 - i16", "ui16 - i32",	"ui16 - ui8",
		"ui16 - ui32", "ui32 - i8",	 "ui32 - i16", "ui32 - i32", "ui32 - ui8",	"ui32 - ui16",
	};

	static const std::array<TestFn, 36> sl_tests = {
		&Unit::SlTester::i8_i8_test,	&Unit::SlTester::i16_i16_test,	 &Unit::SlTester::i32_i32_test,
		&Unit::SlTester::ui8_ui8_test,	&Unit::SlTester::ui16_ui16_test, &Unit::SlTester::ui32_ui32_test,

		&Unit::SlTester::i8_i16_test,	&Unit::SlTester::i8_i32_test,	 &Unit::SlTester::i8_ui8_test,
		&Unit::SlTester::i8_ui16_test,	&Unit::SlTester::i8_ui32_test,

		&Unit::SlTester::i16_i8_test,	&Unit::SlTester::i16_i32_test,	 &Unit::SlTester::i16_ui8_test,
		&Unit::SlTester::i16_ui16_test, &Unit::SlTester::i16_ui32_test,

		&Unit::SlTester::i32_i8_test,	&Unit::SlTester::i32_i16_test,	 &Unit::SlTester::i32_ui8_test,
		&Unit::SlTester::i32_ui16_test, &Unit::SlTester::i32_ui32_test,

		&Unit::SlTester::ui8_i8_test,	&Unit::SlTester::ui8_i16_test,	 &Unit::SlTester::ui8_i32_test,
		&Unit::SlTester::ui8_ui16_test, &Unit::SlTester::ui8_ui32_test,

		&Unit::SlTester::ui16_i8_test,	&Unit::SlTester::ui16_i16_test,	 &Unit::SlTester::ui16_i32_test,
		&Unit::SlTester::ui16_ui8_test, &Unit::SlTester::ui16_ui32_test,

		&Unit::SlTester::ui32_i8_test,	&Unit::SlTester::ui32_i16_test,	 &Unit::SlTester::ui32_i32_test,
		&Unit::SlTester::ui32_ui8_test, &Unit::SlTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> sl_test_names = {
		"i8 << i8",		"i16 << i16",  "i32 << i32",  "ui8 << ui8",	 "ui16 << ui16", "ui32 << ui32",
		"i8 << i16",	"i8 << i32",   "i8 << ui8",	  "i8 << ui16",	 "i8 << ui32",	 "i16 << i8",
		"i16 << i32",	"i16 << ui8",  "i16 << ui16", "i16 << ui32", "i32 << i8",	 "i32 << i16",
		"i32 << ui8",	"i32 << ui16", "i32 << ui32", "ui8 << i8",	 "ui8 << i16",	 "ui8 << i32",
		"ui8 << ui16",	"ui8 << ui32", "ui16 << i8",  "ui16 << i16", "ui16 << i32",	 "ui16 << ui8",
		"ui16 << ui32", "ui32 << i8",  "ui32 << i16", "ui32 << i32", "ui32 << ui8",	 "ui32 << ui16",
	};

	static const std::array<TestFn, 36> div_tests = {
		&Unit::DivTester::i8_i8_test, 	 &Unit::DivTester::i16_i16_test,   &Unit::DivTester::i32_i32_test,
		&Unit::DivTester::ui8_ui8_test, 	 &Unit::DivTester::ui16_ui16_test, &Unit::DivTester::ui32_ui32_test,

		&Unit::DivTester::i8_i16_test, 	 &Unit::DivTester::i8_i32_test, 	   &Unit::DivTester::i8_ui8_test,
		&Unit::DivTester::i8_ui16_test, 	 &Unit::DivTester::i8_ui32_test,

		&Unit::DivTester::i16_i8_test, 	 &Unit::DivTester::i16_i32_test,   &Unit::DivTester::i16_ui8_test,
		&Unit::DivTester::i16_ui16_test, &Unit::DivTester::i16_ui32_test,

		&Unit::DivTester::i32_i8_test, 	 &Unit::DivTester::i32_i16_test,   &Unit::DivTester::i32_ui8_test,
		&Unit::DivTester::i32_ui16_test, &Unit::DivTester::i32_ui32_test,

		&Unit::DivTester::ui8_i8_test, 	 &Unit::DivTester::ui8_i16_test,   &Unit::DivTester::ui8_i32_test,
		&Unit::DivTester::ui8_ui16_test, &Unit::DivTester::ui8_ui32_test,

		&Unit::DivTester::ui16_i8_test, 	 &Unit::DivTester::ui16_i16_test,  &Unit::DivTester::ui16_i32_test,
		&Unit::DivTester::ui16_ui8_test, &Unit::DivTester::ui16_ui32_test,

		&Unit::DivTester::ui32_i8_test, 	 &Unit::DivTester::ui32_i16_test,  &Unit::DivTester::ui32_i32_test,
		&Unit::DivTester::ui32_ui8_test, &Unit::DivTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> div_test_names = {
		"i8 / i8", 		"i16 / i16",  "i32 / i32",  "ui8 / ui8", 	 "ui16 / ui16", "ui32 / ui32",
		"i8 / i16", 	"i8 / i32",   "i8 / ui8", 	  "i8 / ui16", 	 "i8 / ui32", 	"i16 / i8",
		"i16 / i32",   "i16 / ui8", 	 "i16 / ui16", "i16 / ui32", "i32 / i8", 	"i32 / i16",
		"i32 / ui8",   "i32 / ui16", "i32 / ui32", "ui8 / i8", 	 "ui8 / i16", 	"ui8 / i32",
		"ui8 / ui16",  "ui8 / ui32", "ui16 / i8",  "ui16 / i16", "ui16 / i32", 	"ui16 / ui8",
		"ui16 / ui32", "ui32 / i8", 	 "ui32 / i16", "ui32 / i32", "ui32 / ui8", 	"ui32 / ui16",
	};

	static const std::array<TestFn, 36> rem_tests = {
		&Unit::RemTester::i8_i8_test, 	 &Unit::RemTester::i16_i16_test,   &Unit::RemTester::i32_i32_test,
		&Unit::RemTester::ui8_ui8_test, 	 &Unit::RemTester::ui16_ui16_test, &Unit::RemTester::ui32_ui32_test,

		&Unit::RemTester::i8_i16_test, 	 &Unit::RemTester::i8_i32_test, 	   &Unit::RemTester::i8_ui8_test,
		&Unit::RemTester::i8_ui16_test, 	 &Unit::RemTester::i8_ui32_test,

		&Unit::RemTester::i16_i8_test, 	 &Unit::RemTester::i16_i32_test,   &Unit::RemTester::i16_ui8_test,
		&Unit::RemTester::i16_ui16_test, &Unit::RemTester::i16_ui32_test,

		&Unit::RemTester::i32_i8_test, 	 &Unit::RemTester::i32_i16_test,   &Unit::RemTester::i32_ui8_test,
		&Unit::RemTester::i32_ui16_test, &Unit::RemTester::i32_ui32_test,

		&Unit::RemTester::ui8_i8_test, 	 &Unit::RemTester::ui8_i16_test,   &Unit::RemTester::ui8_i32_test,
		&Unit::RemTester::ui8_ui16_test, &Unit::RemTester::ui8_ui32_test,

		&Unit::RemTester::ui16_i8_test, 	 &Unit::RemTester::ui16_i16_test,  &Unit::RemTester::ui16_i32_test,
		&Unit::RemTester::ui16_ui8_test, &Unit::RemTester::ui16_ui32_test,

		&Unit::RemTester::ui32_i8_test, 	 &Unit::RemTester::ui32_i16_test,  &Unit::RemTester::ui32_i32_test,
		&Unit::RemTester::ui32_ui8_test, &Unit::RemTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> rem_test_names = {
		"i8 % i8", 		"i16 % i16",  "i32 % i32",  "ui8 % ui8", 	 "ui16 % ui16", "ui32 % ui32",
		"i8 % i16", 	"i8 % i32",   "i8 % ui8", 	  "i8 % ui16", 	 "i8 % ui32", 	"i16 % i8",
		"i16 % i32",   "i16 % ui8", 	 "i16 % ui16", "i16 % ui32", "i32 % i8", 	"i32 % i16",
		"i32 % ui8",   "i32 % ui16", "i32 % ui32", "ui8 % i8", 	 "ui8 % i16", 	"ui8 % i32",
		"ui8 % ui16",  "ui8 % ui32", "ui16 % i8",  "ui16 % i16", "ui16 % i32", 	"ui16 % ui8",
		"ui16 % ui32", "ui32 % i8", 	 "ui32 % i16", "ui32 % i32", "ui32 % ui8", 	"ui32 % ui16",
	};

	static const std::array<TestFn, 36> sr_tests = {
		&Unit::SrTester::i8_i8_test,	&Unit::SrTester::i16_i16_test,	 &Unit::SrTester::i32_i32_test,
		&Unit::SrTester::ui8_ui8_test,	&Unit::SrTester::ui16_ui16_test, &Unit::SrTester::ui32_ui32_test,

		&Unit::SrTester::i8_i16_test,	&Unit::SrTester::i8_i32_test,	 &Unit::SrTester::i8_ui8_test,
		&Unit::SrTester::i8_ui16_test,	&Unit::SrTester::i8_ui32_test,

		&Unit::SrTester::i16_i8_test,	&Unit::SrTester::i16_i32_test,	 &Unit::SrTester::i16_ui8_test,
		&Unit::SrTester::i16_ui16_test, &Unit::SrTester::i16_ui32_test,

		&Unit::SrTester::i32_i8_test,	&Unit::SrTester::i32_i16_test,	 &Unit::SrTester::i32_ui8_test,
		&Unit::SrTester::i32_ui16_test, &Unit::SrTester::i32_ui32_test,

		&Unit::SrTester::ui8_i8_test,	&Unit::SrTester::ui8_i16_test,	 &Unit::SrTester::ui8_i32_test,
		&Unit::SrTester::ui8_ui16_test, &Unit::SrTester::ui8_ui32_test,

		&Unit::SrTester::ui16_i8_test,	&Unit::SrTester::ui16_i16_test,	 &Unit::SrTester::ui16_i32_test,
		&Unit::SrTester::ui16_ui8_test, &Unit::SrTester::ui16_ui32_test,

		&Unit::SrTester::ui32_i8_test,	&Unit::SrTester::ui32_i16_test,	 &Unit::SrTester::ui32_i32_test,
		&Unit::SrTester::ui32_ui8_test, &Unit::SrTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> sr_test_names = {
		"i8 >> i8",		"i16 >> i16",  "i32 >> i32",  "ui8 >> ui8",	 "ui16 >> ui16", "ui32 >> ui32",
		"i8 >> i16",	"i8 >> i32",   "i8 >> ui8",	  "i8 >> ui16",	 "i8 >> ui32",	 "i16 >> i8",
		"i16 >> i32",	"i16 >> ui8",  "i16 >> ui16", "i16 >> ui32", "i32 >> i8",	 "i32 >> i16",
		"i32 >> ui8",	"i32 >> ui16", "i32 >> ui32", "ui8 >> i8",	 "ui8 >> i16",	 "ui8 >> i32",
		"ui8 >> ui16",	"ui8 >> ui32", "ui16 >> i8",  "ui16 >> i16", "ui16 >> i32",	 "ui16 >> ui8",
		"ui16 >> ui32", "ui32 >> i8",  "ui32 >> i16", "ui32 >> i32", "ui32 >> ui8",	 "ui32 >> ui16",
	};

	static const std::array<TestFn, 36> slt_tests = {
		&Unit::SltTester::i8_i8_test,	 &Unit::SltTester::i16_i16_test,   &Unit::SltTester::i32_i32_test,
		&Unit::SltTester::ui8_ui8_test,	 &Unit::SltTester::ui16_ui16_test, &Unit::SltTester::ui32_ui32_test,

		&Unit::SltTester::i8_i16_test,	 &Unit::SltTester::i8_i32_test,	   &Unit::SltTester::i8_ui8_test,
		&Unit::SltTester::i8_ui16_test,	 &Unit::SltTester::i8_ui32_test,

		&Unit::SltTester::i16_i8_test,	 &Unit::SltTester::i16_i32_test,   &Unit::SltTester::i16_ui8_test,
		&Unit::SltTester::i16_ui16_test, &Unit::SltTester::i16_ui32_test,

		&Unit::SltTester::i32_i8_test,	 &Unit::SltTester::i32_i16_test,   &Unit::SltTester::i32_ui8_test,
		&Unit::SltTester::i32_ui16_test, &Unit::SltTester::i32_ui32_test,

		&Unit::SltTester::ui8_i8_test,	 &Unit::SltTester::ui8_i16_test,   &Unit::SltTester::ui8_i32_test,
		&Unit::SltTester::ui8_ui16_test, &Unit::SltTester::ui8_ui32_test,

		&Unit::SltTester::ui16_i8_test,	 &Unit::SltTester::ui16_i16_test,  &Unit::SltTester::ui16_i32_test,
		&Unit::SltTester::ui16_ui8_test, &Unit::SltTester::ui16_ui32_test,

		&Unit::SltTester::ui32_i8_test,	 &Unit::SltTester::ui32_i16_test,  &Unit::SltTester::ui32_i32_test,
		&Unit::SltTester::ui32_ui8_test, &Unit::SltTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> slt_test_names = {
		"i8 < i8",	   "i16 < i16",	 "i32 < i32",  "ui8 < ui8",	 "ui16 < ui16", "ui32 < ui32",
		"i8 < i16",	   "i8 < i32",	 "i8 < ui8",   "i8 < ui16",	 "i8 < ui32",	"i16 < i8",
		"i16 < i32",   "i16 < ui8",	 "i16 < ui16", "i16 < ui32", "i32 < i8",	"i32 < i16",
		"i32 < ui8",   "i32 < ui16", "i32 < ui32", "ui8 < i8",	 "ui8 < i16",	"ui8 < i32",
		"ui8 < ui16",  "ui8 < ui32", "ui16 < i8",  "ui16 < i16", "ui16 < i32",	"ui16 < ui8",
		"ui16 < ui32", "ui32 < i8",	 "ui32 < i16", "ui32 < i32", "ui32 < ui8",	"ui32 < ui16",
	};

	static const std::array<TestFn, 36> xor_tests = {
		&Unit::XorTester::i8_i8_test,	 &Unit::XorTester::i16_i16_test,   &Unit::XorTester::i32_i32_test,
		&Unit::XorTester::ui8_ui8_test,	 &Unit::XorTester::ui16_ui16_test, &Unit::XorTester::ui32_ui32_test,

		&Unit::XorTester::i8_i16_test,	 &Unit::XorTester::i8_i32_test,	   &Unit::XorTester::i8_ui8_test,
		&Unit::XorTester::i8_ui16_test,	 &Unit::XorTester::i8_ui32_test,

		&Unit::XorTester::i16_i8_test,	 &Unit::XorTester::i16_i32_test,   &Unit::XorTester::i16_ui8_test,
		&Unit::XorTester::i16_ui16_test, &Unit::XorTester::i16_ui32_test,

		&Unit::XorTester::i32_i8_test,	 &Unit::XorTester::i32_i16_test,   &Unit::XorTester::i32_ui8_test,
		&Unit::XorTester::i32_ui16_test, &Unit::XorTester::i32_ui32_test,

		&Unit::XorTester::ui8_i8_test,	 &Unit::XorTester::ui8_i16_test,   &Unit::XorTester::ui8_i32_test,
		&Unit::XorTester::ui8_ui16_test, &Unit::XorTester::ui8_ui32_test,

		&Unit::XorTester::ui16_i8_test,	 &Unit::XorTester::ui16_i16_test,  &Unit::XorTester::ui16_i32_test,
		&Unit::XorTester::ui16_ui8_test, &Unit::XorTester::ui16_ui32_test,

		&Unit::XorTester::ui32_i8_test,	 &Unit::XorTester::ui32_i16_test,  &Unit::XorTester::ui32_i32_test,
		&Unit::XorTester::ui32_ui8_test, &Unit::XorTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> xor_test_names = {
		"i8 ^ i8",	   "i16 ^ i16",	 "i32 ^ i32",  "ui8 ^ ui8",	 "ui16 ^ ui16", "ui32 ^ ui32",
		"i8 ^ i16",	   "i8 ^ i32",	 "i8 ^ ui8",   "i8 ^ ui16",	 "i8 ^ ui32",	"i16 ^ i8",
		"i16 ^ i32",   "i16 ^ ui8",	 "i16 ^ ui16", "i16 ^ ui32", "i32 ^ i8",	"i32 ^ i16",
		"i32 ^ ui8",   "i32 ^ ui16", "i32 ^ ui32", "ui8 ^ i8",	 "ui8 ^ i16",	"ui8 ^ i32",
		"ui8 ^ ui16",  "ui8 ^ ui32", "ui16 ^ i8",  "ui16 ^ i16", "ui16 ^ i32",	"ui16 ^ ui8",
		"ui16 ^ ui32", "ui32 ^ i8",	 "ui32 ^ i16", "ui32 ^ i32", "ui32 ^ ui8",	"ui32 ^ ui16",
	};

	static const std::array<TestFn, 36> or_tests = {
		&Unit::OrTester::i8_i8_test,	&Unit::OrTester::i16_i16_test,	 &Unit::OrTester::i32_i32_test,
		&Unit::OrTester::ui8_ui8_test,	&Unit::OrTester::ui16_ui16_test, &Unit::OrTester::ui32_ui32_test,

		&Unit::OrTester::i8_i16_test,	&Unit::OrTester::i8_i32_test,	 &Unit::OrTester::i8_ui8_test,
		&Unit::OrTester::i8_ui16_test,	&Unit::OrTester::i8_ui32_test,

		&Unit::OrTester::i16_i8_test,	&Unit::OrTester::i16_i32_test,	 &Unit::OrTester::i16_ui8_test,
		&Unit::OrTester::i16_ui16_test, &Unit::OrTester::i16_ui32_test,

		&Unit::OrTester::i32_i8_test,	&Unit::OrTester::i32_i16_test,	 &Unit::OrTester::i32_ui8_test,
		&Unit::OrTester::i32_ui16_test, &Unit::OrTester::i32_ui32_test,

		&Unit::OrTester::ui8_i8_test,	&Unit::OrTester::ui8_i16_test,	 &Unit::OrTester::ui8_i32_test,
		&Unit::OrTester::ui8_ui16_test, &Unit::OrTester::ui8_ui32_test,

		&Unit::OrTester::ui16_i8_test,	&Unit::OrTester::ui16_i16_test,	 &Unit::OrTester::ui16_i32_test,
		&Unit::OrTester::ui16_ui8_test, &Unit::OrTester::ui16_ui32_test,

		&Unit::OrTester::ui32_i8_test,	&Unit::OrTester::ui32_i16_test,	 &Unit::OrTester::ui32_i32_test,
		&Unit::OrTester::ui32_ui8_test, &Unit::OrTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> or_test_names = {
		"i8 | i8",	   "i16 | i16",	 "i32 | i32",  "ui8 | ui8",	 "ui16 | ui16", "ui32 | ui32",
		"i8 | i16",	   "i8 | i32",	 "i8 | ui8",   "i8 | ui16",	 "i8 | ui32",	"i16 | i8",
		"i16 | i32",   "i16 | ui8",	 "i16 | ui16", "i16 | ui32", "i32 | i8",	"i32 | i16",
		"i32 | ui8",   "i32 | ui16", "i32 | ui32", "ui8 | i8",	 "ui8 | i16",	"ui8 | i32",
		"ui8 | ui16",  "ui8 | ui32", "ui16 | i8",  "ui16 | i16", "ui16 | i32",	"ui16 | ui8",
		"ui16 | ui32", "ui32 | i8",	 "ui32 | i16", "ui32 | i32", "ui32 | ui8",	"ui32 | ui16",
	};

	static const std::array<TestFn, 36> and_tests = {
		&Unit::AndTester::i8_i8_test,	 &Unit::AndTester::i16_i16_test,   &Unit::AndTester::i32_i32_test,
		&Unit::AndTester::ui8_ui8_test,	 &Unit::AndTester::ui16_ui16_test, &Unit::AndTester::ui32_ui32_test,

		&Unit::AndTester::i8_i16_test,	 &Unit::AndTester::i8_i32_test,	   &Unit::AndTester::i8_ui8_test,
		&Unit::AndTester::i8_ui16_test,	 &Unit::AndTester::i8_ui32_test,

		&Unit::AndTester::i16_i8_test,	 &Unit::AndTester::i16_i32_test,   &Unit::AndTester::i16_ui8_test,
		&Unit::AndTester::i16_ui16_test, &Unit::AndTester::i16_ui32_test,

		&Unit::AndTester::i32_i8_test,	 &Unit::AndTester::i32_i16_test,   &Unit::AndTester::i32_ui8_test,
		&Unit::AndTester::i32_ui16_test, &Unit::AndTester::i32_ui32_test,

		&Unit::AndTester::ui8_i8_test,	 &Unit::AndTester::ui8_i16_test,   &Unit::AndTester::ui8_i32_test,
		&Unit::AndTester::ui8_ui16_test, &Unit::AndTester::ui8_ui32_test,

		&Unit::AndTester::ui16_i8_test,	 &Unit::AndTester::ui16_i16_test,  &Unit::AndTester::ui16_i32_test,
		&Unit::AndTester::ui16_ui8_test, &Unit::AndTester::ui16_ui32_test,

		&Unit::AndTester::ui32_i8_test,	 &Unit::AndTester::ui32_i16_test,  &Unit::AndTester::ui32_i32_test,
		&Unit::AndTester::ui32_ui8_test, &Unit::AndTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> and_test_names = {
		"i8 & i8",	   "i16 & i16",	 "i32 & i32",  "ui8 & ui8",	 "ui16 & ui16", "ui32 & ui32",
		"i8 & i16",	   "i8 & i32",	 "i8 & ui8",   "i8 & ui16",	 "i8 & ui32",	"i16 & i8",
		"i16 & i32",   "i16 & ui8",	 "i16 & ui16", "i16 & ui32", "i32 & i8",	"i32 & i16",
		"i32 & ui8",   "i32 & ui16", "i32 & ui32", "ui8 & i8",	 "ui8 & i16",	"ui8 & i32",
		"ui8 & ui16",  "ui8 & ui32", "ui16 & i8",  "ui16 & i16", "ui16 & i32",	"ui16 & ui8",
		"ui16 & ui32", "ui32 & i8",	 "ui32 & i16", "ui32 & i32", "ui32 & ui8",	"ui32 & ui16",
	};

	static const std::array<TestFn, 36> mul_tests = {
		&Unit::MulTester::i8_i8_test,     &Unit::MulTester::i16_i16_test,   &Unit::MulTester::i32_i32_test,
		&Unit::MulTester::ui8_ui8_test,   &Unit::MulTester::ui16_ui16_test, &Unit::MulTester::ui32_ui32_test,

		&Unit::MulTester::i8_i16_test,    &Unit::MulTester::i8_i32_test,    &Unit::MulTester::i8_ui8_test,
		&Unit::MulTester::i8_ui16_test,   &Unit::MulTester::i8_ui32_test,

		&Unit::MulTester::i16_i8_test,    &Unit::MulTester::i16_i32_test,   &Unit::MulTester::i16_ui8_test,
		&Unit::MulTester::i16_ui16_test,  &Unit::MulTester::i16_ui32_test,

		&Unit::MulTester::i32_i8_test,    &Unit::MulTester::i32_i16_test,   &Unit::MulTester::i32_ui8_test,
		&Unit::MulTester::i32_ui16_test,  &Unit::MulTester::i32_ui32_test,

		&Unit::MulTester::ui8_i8_test,    &Unit::MulTester::ui8_i16_test,   &Unit::MulTester::ui8_i32_test,
		&Unit::MulTester::ui8_ui16_test,  &Unit::MulTester::ui8_ui32_test,

		&Unit::MulTester::ui16_i8_test,   &Unit::MulTester::ui16_i16_test,  &Unit::MulTester::ui16_i32_test,
		&Unit::MulTester::ui16_ui8_test,  &Unit::MulTester::ui16_ui32_test,

		&Unit::MulTester::ui32_i8_test,   &Unit::MulTester::ui32_i16_test,  &Unit::MulTester::ui32_i32_test,
		&Unit::MulTester::ui32_ui8_test,  &Unit::MulTester::ui32_ui16_test,
	};

	static const std::array<std::string, 36> mul_test_names = {
		"i8 * i8",      "i16 * i16",    "i32 * i32",    "ui8 * ui8",    "ui16 * ui16", "ui32 * ui32",
		"i8 * i16",     "i8 * i32",     "i8 * ui8",     "i8 * ui16",    "i8 * ui32",   "i16 * i8",
		"i16 * i32",    "i16 * ui8",    "i16 * ui16",   "i16 * ui32",   "i32 * i8",    "i32 * i16",
		"i32 * ui8",    "i32 * ui16",   "i32 * ui32",   "ui8 * i8",     "ui8 * i16",   "ui8 * i32",
		"ui8 * ui16",   "ui8 * ui32",   "ui16 * i8",    "ui16 * i16",   "ui16 * i32",  "ui16 * ui8",
		"ui16 * ui32",  "ui32 * i8",    "ui32 * i16",   "ui32 * i32",   "ui32 * ui8",  "ui32 * ui16",
	};

	static const std::array<TestFn, 36> mulh_tests = {
		&Unit::MulhTester::i8_i8_test,     &Unit::MulhTester::i16_i16_test,   &Unit::MulhTester::i32_i32_test,
		&Unit::MulhTester::ui8_ui8_test,   &Unit::MulhTester::ui16_ui16_test, &Unit::MulhTester::ui32_ui32_test,

		&Unit::MulhTester::i8_i16_test,    &Unit::MulhTester::i8_i32_test,    &Unit::MulhTester::i8_ui8_test,
		&Unit::MulhTester::i8_ui16_test,   &Unit::MulhTester::i8_ui32_test,

		&Unit::MulhTester::i16_i8_test,    &Unit::MulhTester::i16_i32_test,   &Unit::MulhTester::i16_ui8_test,
		&Unit::MulhTester::i16_ui16_test,  &Unit::MulhTester::i16_ui32_test,

		&Unit::MulhTester::i32_i8_test,    &Unit::MulhTester::i32_i16_test,   &Unit::MulhTester::i32_ui8_test,
		&Unit::MulhTester::i32_ui16_test,  &Unit::MulhTester::i32_ui32_test,

		&Unit::MulhTester::ui8_i8_test,    &Unit::MulhTester::ui8_i16_test,   &Unit::MulhTester::ui8_i32_test,
		&Unit::MulhTester::ui8_ui16_test,  &Unit::MulhTester::ui8_ui32_test,

		&Unit::MulhTester::ui16_i8_test,   &Unit::MulhTester::ui16_i16_test,  &Unit::MulhTester::ui16_i32_test,
		&Unit::MulhTester::ui16_ui8_test,  &Unit::MulhTester::ui16_ui32_test,

		&Unit::MulhTester::ui32_i8_test,   &Unit::MulhTester::ui32_i16_test,  &Unit::MulhTester::ui32_i32_test,
		&Unit::MulhTester::ui32_ui8_test,  &Unit::MulhTester::ui32_ui16_test,
	};

	void add_test(Stats &stats) {
		int i = 0;
		for (auto test : add_tests) {
			bool ok = test();
			print_result(stats, "ADD", add_test_names[i], ok);
			i++;
		}
	}

	void sub_test(Stats &stats) {
		int i = 0;
		for (auto test : sub_tests) {
			bool ok = test();
			print_result(stats, "SUB", sub_test_names[i], ok);
			i++;
		}
	}

	void div_test(Stats &stats) {
		int i = 0;
		for (auto test : div_tests) {
			bool ok = test();
			print_result(stats, "DIV", div_test_names[i], ok);
			i++;
		}
	}

	void rem_test(Stats &stats) {
		int i = 0;
		for (auto test : rem_tests) {
			bool ok = test();
			print_result(stats, "REM", rem_test_names[i], ok);
			i++;
		}
	}

	void sl_test(Stats &stats) {
		int i = 0;
		for (auto test : sl_tests) {
			bool ok = test();
			print_result(stats, "SL", sl_test_names[i], ok);
			i++;
		}
	}

	void sr_test(Stats &stats) {
		int i = 0;
		for (auto test : sr_tests) {
			bool ok = test();
			print_result(stats, "SR", sr_test_names[i], ok);
			i++;
		}
	}

	void slt_test(Stats &stats) {
		int i = 0;
		for (auto test : slt_tests) {
			bool ok = test();
			print_result(stats, "SLT", slt_test_names[i], ok);
			i++;
		}
	}

	void xor_test(Stats &stats) {
		int i = 0;
		for (auto test : xor_tests) {
			bool ok = test();
			print_result(stats, "XOR", xor_test_names[i], ok);
			i++;
		}
	}

	void or_test(Stats &stats) {
		int i = 0;
		for (auto test : or_tests) {
			bool ok = test();
			print_result(stats, "OR", or_test_names[i], ok);
			i++;
		}
	}

	void and_test(Stats &stats) {
		int i = 0;
		for (auto test : and_tests) {
			bool ok = test();
			print_result(stats, "AND", and_test_names[i], ok);
			i++;
		}
	}

	void mul_test(Stats &stats) {
		int i = 0;
		for (auto test : mul_tests) {
			bool ok = test();
			print_result(stats, "MUL", mul_test_names[i], ok);
			i++;
		}
	}

	void mulh_test(Stats &stats) {
		int i = 0;
		for (auto test : mulh_tests) {
			bool ok = test();
			print_result(stats, "MULH", mul_test_names[i], ok);
			i++;
		}
	}

	void r_tests(Stats &stats) {
		add_test(stats);
		sub_test(stats);
		div_test(stats);
		rem_test(stats);
		sl_test(stats);
		sr_test(stats);
		slt_test(stats);
		xor_test(stats);
		or_test(stats);
		and_test(stats);
		mul_test(stats);
		mulh_test(stats);
	}
} // namespace Test

#endif