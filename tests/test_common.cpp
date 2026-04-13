#include <string>
#include <vector>

#include "catch2/catch_test_macros.hpp"

#include "common.hpp"


namespace mh::math {

	TEST_CASE("ArithmeticType concept correctly validates types", "[Common] [Concept]") {

		REQUIRE(ArithmeticType<int>);
		REQUIRE(ArithmeticType<double>);
		REQUIRE(ArithmeticType<char>);
		REQUIRE_FALSE(ArithmeticType<std::string>);
		REQUIRE_FALSE(ArithmeticType<std::vector<int>>);

	}

	TEST_CASE("NonZero concept correctly validates types", "[Common] [Concept]") {

		REQUIRE(NonZero<int, 1>);
		REQUIRE(NonZero<int, int{ 1 }>);
		REQUIRE(NonZero<size_t, 0xffffffff>);
		REQUIRE(NonZero<size_t, size_t{ 0xffffffff }>);
		REQUIRE_FALSE(NonZero<int, 0>);
		REQUIRE_FALSE(NonZero<int, int{}>);
		REQUIRE_FALSE(NonZero<size_t, 0>);
		REQUIRE_FALSE(NonZero<size_t, size_t{}>);

	}

	TEST_CASE("_NonZero macro correctly validates types", "[Common] [Macro]") {

		REQUIRE(_NonZero(1));
		REQUIRE(_NonZero(int{ 1 }));
		REQUIRE(_NonZero(0xffffffff));
		REQUIRE(_NonZero(size_t{ 0xffffffff }));
		REQUIRE_FALSE(_NonZero(0));
		REQUIRE_FALSE(_NonZero(int{}));
		REQUIRE_FALSE(_NonZero(size_t{}));

	}

	TEST_CASE("power_of concept correctly validates types", "[Common]") {

		REQUIRE(power_of<int, 5, 0>::value == 1);
		REQUIRE(power_of<int, 1, 6>::value == 1);
		REQUIRE(power_of<int, 0, 5>::value == 0);
		REQUIRE(power_of<int, 5, 3>::value == 125);
		REQUIRE(power_of<size_t, 3, 4>::value == 81);
		REQUIRE(power_of<size_t, 2, 2>::value == 4);
		REQUIRE_FALSE(power_of<int, 6, 2>::value == 6);
		REQUIRE_FALSE(power_of<size_t, 3, 3>::value == 0);

	}

}