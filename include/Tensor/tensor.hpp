#pragma once
#ifndef MH_MATH_TENSOR_HPP
#define MH_MATH_TENSOR_HPP

#include <array>
#include <stdexcept>

#include "common.hpp"
#include "Geometry/geometry_concepts.hpp"


namespace mh::math {

	template<
		ArithmeticType T,
		GeometryPolicy Geometry
	>
	class Tensor {
		static_assert(Geometry::size() > 1, "Tensor can't be a scalar (need more than 1 element)");

	public:
		#pragma region Type Aliases

		using element_type = T;
		using reference_type = T&;
		using value_type = std::remove_cv_t<T>;
		using geometry_type = Geometry;
		using index_type = typename Geometry::size_type;
		using geometry_array_type = typename Geometry::geometry_array_type;
		using data_storage_type = std::array<value_type, Geometry::size()>;

		#pragma endregion

		#pragma region Accessors

		// flat access - raw storage indexing
		constexpr inline element_type operator[](const index_type index) const UNIMPLMENTED
		constexpr inline reference_type operator[](const index_type index) UNIMPLMENTED

		// multi-dimensional access - geometry-based indexing
		template<class... Indices>
		requires(
			sizeof...(Indices) == geometry_type::rank()&&
			(std::is_convertible_v<Indices, index_type>&& ...)
		)
		constexpr inline element_type operator()(const Indices... indices) const UNIMPLMENTED

		template<class... Indices>
		requires(
			sizeof...(Indices) == geometry_type::rank()&&
			(std::is_convertible_v<Indices, index_type>&& ...)
		)
		constexpr inline reference_type operator()(const Indices... indices) UNIMPLMENTED

		// Without bounds checking variants
		constexpr inline element_type at(const index_type index) const UNIMPLMENTED
		constexpr inline reference_type at(const index_type index) UNIMPLMENTED

		template<class... Indices>
		requires(
			sizeof...(Indices) == geometry_type::rank()&&
			(std::is_convertible_v<Indices, index_type>&& ...)
		)
		constexpr inline element_type at(const Indices... indices) const UNIMPLMENTED
		
		template<class... Indices>
		requires(
			sizeof...(Indices) == geometry_type::rank()&&
			(std::is_convertible_v<Indices, index_type>&& ...)
		)
		constexpr inline reference_type at(const Indices... indices) UNIMPLMENTED

		#pragma endregion
		
	private:
		data_storage_type m_data;
	};

}

#endif // MH_MATH_TENSOR_HPP