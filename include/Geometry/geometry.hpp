#pragma once
#ifndef MH_MATH_GEOMETRY_HPP
#define MH_MATH_GEOMETRY_HPP

#include <array>

#include "common.hpp"


namespace mh::math {

	template<
		size_t FirstSize,
		size_t... OtherSizes
	>
	requires(
		NonZero<size_t, FirstSize> &&
		(NonZero<size_t, OtherSizes> && ...)
	)
	class Geometry {
	public:
		using size_type = size_t;
		using geometry_array_type = const std::array<size_type, sizeof...(OtherSizes) + 1>;

		static consteval inline size_type rank() noexcept {
			return sizeof...(OtherSizes) + 1;
		}

		static consteval inline size_type size() noexcept {
			return (FirstSize * ... * OtherSizes);
		}

		static consteval inline geometry_array_type geometry() noexcept {
			return { FirstSize, OtherSizes... };
		}
	};

}

#endif // MH_MATH_GEOMETRY_HPP