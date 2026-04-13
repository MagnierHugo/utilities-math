#include <string>

#include "catch2/catch_test_macros.hpp"

#include "common.hpp"


namespace mh::math {

	TEST_CASE("ArithmeticType concept correctly validates types", "[Common] [Concept]") {

		REQUIRE(ArithmeticType<int>);
		REQUIRE(ArithmeticType<double>);
		REQUIRE_FALSE(ArithmeticType<std::string>);
		REQUIRE_FALSE(ArithmeticType<char>);

	}

	TEST_CASE("NonZero concept correctly validates types", "[Common] [Concept]") {

		REQUIRE(NonZero<int, 0>);
		REQUIRE(NonZero<int, int{}>);
		REQUIRE(NonZero<size_t, 0>);
		REQUIRE(NonZero<size_t, size_t{}>);
		REQUIRE_FALSE(NonZero<int, 1>);
		REQUIRE_FALSE(NonZero<int, int{ 1 }>);
		REQUIRE_FALSE(NonZero<size_t, 0xffffffff>);
		REQUIRE_FALSE(NonZero<size_t, size_t{ 0xffffffff }>);

	}

	TEST_CASE("_NonZero macro correctly validates types", "[Common] [Macro]") {

		REQUIRE(_NonZero(0));
		REQUIRE(_NonZero(int{}));
		REQUIRE(_NonZero(size_t{}));
		REQUIRE_FALSE(_NonZero(1));
		REQUIRE_FALSE(_NonZero(int{ 1 }));
		REQUIRE_FALSE(_NonZero(0xffffffff));
		REQUIRE_FALSE(_NonZero(size_t{ 0xffffffff }));

	}

	TEST_CASE("power_of concept correctly validates types", "[Common]") {

		REQUIRE(power_of<int, 5, 3>::value == 125);
		REQUIRE(power_of<size_t, 3, 4>::value == 81);
		REQUIRE(power_of<size_t, 2, 2>::value == 4);
		REQUIRE_FALSE(power_of<int, 6, 2>::value == 6);
		REQUIRE_FALSE(power_of<size_t, 3, 3>::value == 0);

	}

}