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
		using base_type = const float;

		using expected_element_type = base_type;
		using expected_reference_type = base_type&;
		using expected_value_type = std::remove_cv_t<base_type>;
		using expected_geometry_type = Geometry<3, 3>;
		using expected_index_type = size_t;
		using expected_geometry_array_type = const std::array<size_t, 2>;
		using expected_data_storage_type = std::array<expected_value_type, expected_geometry_type::size()>;

		using tensor_type = Tensor<base_type, Geometry<3, 3>>;

		REQUIRE(std::is_same_v<typename tensor_type::element_type, expected_element_type>);
		REQUIRE(std::is_same_v<typename tensor_type::reference_type, expected_reference_type>);
		REQUIRE(std::is_same_v<typename tensor_type::value_type, expected_value_type>);
		REQUIRE(std::is_same_v<typename tensor_type::data_storage_type, expected_data_storage_type>);
		REQUIRE(std::is_same_v<typename tensor_type::index_type, expected_index_type>);
		REQUIRE(std::is_same_v<typename tensor_type::geometry_type, expected_geometry_type>);
		REQUIRE(std::is_same_v<typename tensor_type::geometry_array_type, expected_geometry_array_type>);
	}

	TEST_CASE("Tensor accessors return correct values", "[Tensor]") {
		Tensor<float, Geometry<2, 2>> mat2x2{};

		REQUIRE(mat2x2[0] == .0f);
		REQUIRE(mat2x2[1] == .0f);
		REQUIRE(mat2x2[2] == .0f);
		REQUIRE(mat2x2[3] == .0f);
		REQUIRE(mat2x2[0, 0] == .0f);
		REQUIRE(mat2x2[0, 1] == .0f);
		REQUIRE(mat2x2[1, 0] == .0f);
		REQUIRE(mat2x2[1, 1] == .0f);

		REQUIRE(mat2x2.at(0) == .0f);

		SECTION("Modifying values through non-const reference accessors") {
			float value = 2.0f;

			size_t index = 1;
			size_t indices1, indices2 = (1, 0);

			mat2x2[index] = value;
			mat2x2[indices1, indices2] = value;

			REQUIRE(mat2x2[index] == value);
			REQUIRE(mat2x2[indices1, indices2] == value);
		}
	}

}