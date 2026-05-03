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

        SECTION("Flat operator[] returns zero-initialized values") {
            REQUIRE(mat2x2[0] == .0f);
            REQUIRE(mat2x2[1] == .0f);
            REQUIRE(mat2x2[2] == .0f);
            REQUIRE(mat2x2[3] == .0f);
        }

        SECTION("Multi-index operator() returns zero-initialized values") {
            REQUIRE(mat2x2(0, 0) == .0f);
            REQUIRE(mat2x2(0, 1) == .0f);
            REQUIRE(mat2x2(1, 0) == .0f);
            REQUIRE(mat2x2(1, 1) == .0f);
        }

        SECTION("Flat at() returns zero-initialized values") {
            REQUIRE(mat2x2.at(0) == .0f);
            REQUIRE(mat2x2.at(1) == .0f);
            REQUIRE(mat2x2.at(2) == .0f);
            REQUIRE(mat2x2.at(3) == .0f);
        }

        SECTION("Multi-index at() returns zero-initialized values") {
            REQUIRE(mat2x2.at(0, 0) == .0f);
            REQUIRE(mat2x2.at(0, 1) == .0f);
            REQUIRE(mat2x2.at(1, 0) == .0f);
            REQUIRE(mat2x2.at(1, 1) == .0f);
        }

        SECTION("Flat and multi-index access refer to the same element") {
            REQUIRE(mat2x2[0] == mat2x2(0, 0));
            REQUIRE(mat2x2[1] == mat2x2(0, 1));
            REQUIRE(mat2x2[2] == mat2x2(1, 0));
            REQUIRE(mat2x2[3] == mat2x2(1, 1));
        }

        SECTION("Non-const operator[] allows mutation") {
            mat2x2[1] = 2.0f;
            REQUIRE(mat2x2[1] == 2.0f);
        }

        SECTION("Non-const operator() allows mutation") {
            mat2x2(1, 0) = 2.0f;
            REQUIRE(mat2x2(1, 0) == 2.0f);
        }

        SECTION("Mutation is consistent across flat and multi-index access") {
            mat2x2[2] = 3.0f;
            REQUIRE(mat2x2(1, 0) == 3.0f);
        }

        SECTION("Const accessors compile and return correct values") {
            const Tensor<float, Geometry<2, 2>> const_mat2x2{};
            REQUIRE(const_mat2x2[0] == .0f);
            REQUIRE(const_mat2x2(0, 0) == .0f);
            REQUIRE(const_mat2x2.at(0) == .0f);
            REQUIRE(const_mat2x2.at(0, 0) == .0f);
        }
	}

    TEST_CASE("at() works with vectors", "[Tensor]") {
        Tensor<float, Geometry<3>> vector3{};
        REQUIRE(vector3.at(0) == .0f);
        REQUIRE(vector3.at(1) == .0f);
		REQUIRE(vector3.at(2) == .0f);
    }

	TEST_CASE("operator[] throws on out of bounds", "[Tensor]") {
		Tensor<float, Geometry<2, 2>> mat2x2{};

		REQUIRE_THROWS_AS(mat2x2[4], std::out_of_range);
		REQUIRE_THROWS_AS(mat2x2[100], std::out_of_range);
	}

	TEST_CASE("operator() throws on out of bounds", "[Tensor]") {
		Tensor<float, Geometry<2, 2>> mat2x2{};

		REQUIRE_THROWS_AS(mat2x2(2, 0), std::out_of_range);
		REQUIRE_THROWS_AS(mat2x2(0, 2), std::out_of_range);
		REQUIRE_THROWS_AS(mat2x2(100, 100), std::out_of_range);
	}

}