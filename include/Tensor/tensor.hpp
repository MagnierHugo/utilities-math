#pragma once
#ifndef MH_MATH_TENSOR_HPP
#define MH_MATH_TENSOR_HPP

#include <array>

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
		using value_type = T;
		using geometry_type = Geometry;
		using size_type = typename Geometry::size_type;
		using geometry_array_type = typename Geometry::geometry_array_type;
		
	private:
		std::array<value_type, geometry_type::size()> m_data;
	};

}

#endif // MH_MATH_TENSOR_HPP