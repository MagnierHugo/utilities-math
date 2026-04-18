#include <type_traits>

#include "catch2/catch_test_macros.hpp"

#include "Tensor/tensor.hpp"
#include "Geometry/geometry.hpp"


namespace mh::math {

	TEST_CASE("Tensor instantiates for any valid set of template parameters", "[Tensor]") {
		Tensor<float, Geometry<3>> vector3{};
		Tensor<int, Geometry<2, 2>> mat2x2{};
		Tensor<double, Geometry<2, 3, 4>> tensor3D{};

		SUCCEED("Tensor instantiated successfully for valid template parameters");
	}

	TEST_CASE("Tensor satisfies expected type traits", "[Tensor]") {
		using test_type = Tensor<float, Geometry<3, 3>>;

		REQUIRE(std::is_default_constructible_v<test_type>);
		REQUIRE(std::is_copy_constructible_v<test_type>);
		REQUIRE(std::is_move_constructible_v<test_type>);
		REQUIRE(std::is_copy_assignable_v<test_type>);
		REQUIRE(std::is_move_assignable_v<test_type>);
		REQUIRE(std::is_trivially_destructible_v<test_type>);
	}

	TEST_CASE("Tensor has correct type aliases", "[Tensor]") {
		using test_type = Tensor<float, Geometry<3, 3>>;
		using expected_geometry_array_type = const std::array<size_t, 2>;

		REQUIRE(std::is_same_v<typename test_type::value_type, float>);
		REQUIRE(std::is_same_v<typename test_type::geometry_type, Geometry<3, 3>>);
		REQUIRE(std::is_same_v<typename test_type::size_type, size_t>);
		REQUIRE(std::is_same_v<typename test_type::geometry_array_type, expected_geometry_array_type>);
	}
}