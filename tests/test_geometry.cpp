#include <type_traits>
#include <array>
#include <string>
#include <vector>

#include "catch2/catch_test_macros.hpp"

#include "Geometry/geometry.hpp"
#include "Geometry/geometry_concepts.hpp"

namespace mh::math {

	// Geometry class

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

		REQUIRE(std::is_same_v<typename type_test::geometry_array_type, array_type_test>);
		REQUIRE(type_test::geometry() == array_type_test{ N1, N2, N3 });
	}

	// Geometry concepts

	TEST_CASE("GeometryPolicy concept correctly validates types", "[Geometry] [Concept]") {

		REQUIRE(GeometryPolicy<Geometry<3, 3>>);
		REQUIRE_FALSE(GeometryPolicy<int>);
		REQUIRE_FALSE(GeometryPolicy<std::array<size_t, 3>>);

	}

	TEST_CASE("_1D concept correctly validates types", "[Geometry] [Concept]") {

		REQUIRE(_1D<Geometry<3>>);
		REQUIRE_FALSE(_1D<Geometry<2, 2>>);
		REQUIRE_FALSE(_1D<Geometry<2, 3, 4>>);
		REQUIRE_FALSE(_1D<float>);
		REQUIRE_FALSE(_1D<std::string>);

	}

	TEST_CASE("_2D concept correctly validates types", "[Geometry] [Concept]") {

		REQUIRE(_2D<Geometry<4, 4>>);
		REQUIRE_FALSE(_2D<Geometry<4>>);
		REQUIRE_FALSE(_2D<Geometry<2, 2, 2>>);
		REQUIRE_FALSE(_2D<bool>);
		REQUIRE_FALSE(_2D<std::vector<size_t>>);

	}

	TEST_CASE("UniformGeometry concept correctly validates types", "[Geometry] [Concept]") {

		REQUIRE(UniformGeometry<Geometry<2, 2>>);
		REQUIRE(UniformGeometry<Geometry<3, 3, 3>>);
		REQUIRE(UniformGeometry<Geometry<4, 4, 4, 4>>);
		REQUIRE_FALSE(UniformGeometry<Geometry<5>>);
		REQUIRE_FALSE(UniformGeometry<Geometry<2, 3>>);
		REQUIRE_FALSE(UniformGeometry<Geometry<2, 3, 4>>);
		REQUIRE_FALSE(UniformGeometry<std::array<size_t, 4>>);

	}

}
