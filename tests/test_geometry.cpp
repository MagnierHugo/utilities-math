#include <type_traits>
#include <array>

#include "catch2/catch_test_macros.hpp"

#include "Geometry/geometry.hpp"

namespace mh::math {

	TEST_CASE("Geometry::size() return correct total size", "[Geometry]") {
		constexpr size_t N1 = 3;
		constexpr size_t N2 = 3;

		using type_test = Geometry<N1, N2>;
		using array_type_test = const std::array<size_t, 2>;

		REQUIRE(type_test::size() == N1 * N2);
	}

	TEST_CASE("Geometry::rank() return correct number of dimensions", "[Geometry]") {
		constexpr size_t N1 = 4;
		constexpr size_t N2 = 2;
		constexpr size_t N3 = 3;

		using type_test = Geometry<N1, N2, N3>;

		REQUIRE(type_test::rank() == 3);
	}

	TEST_CASE("Geometry::geometry() return the correct array of sizes", "[Geometry]") {
		constexpr size_t N1 = 2;
		constexpr size_t N2 = 2;
		constexpr size_t N3 = 3;

		using type_test = Geometry<N1, N2, N3>;
		using array_type_test = const std::array<size_t, 3>;

		REQUIRE(std::is_same_v<type_test::geometry_array_type, array_type_test>);
		REQUIRE(type_test::geometry() == array_type_test{ N1, N2, N3 });
	}

}
