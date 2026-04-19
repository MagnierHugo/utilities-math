#pragma once
#ifndef MH_MATH_COMMON_HPP
#define MH_MATH_COMMON_HPP


#include <type_traits>
#include <stdexcept>


namespace mh::math {

	template<class T>
	concept ArithmeticType = std::is_arithmetic_v<T>;

	template<class T, T N1>
	concept NonZero = ArithmeticType<T> && (N1 != T{});

	#define _NonZero(N1) NonZero<decltype(N1), N1>

	#pragma region power_of

	template<class T, T N, int Exponent>
	requires(
		ArithmeticType<T>
	)
	struct power_of {
		static constexpr inline T value = N * power_of<T, N, Exponent - 1>::value;
	};

	template<class T, T N>
	requires(
		ArithmeticType<T>
	)
	struct power_of<T, N, 1> {
		static constexpr inline T value = N;
	};

	template<class T, T N>
	requires(
		ArithmeticType<T>
	)
	struct power_of<T, N, 0> {
		static constexpr inline T value = 1;
	};

	#pragma endregion

#define UNIMPLMENTED { throw std::runtime_error("Function not implemented yet: " __FUNCTION__); }

}

#endif // MH_MATH_COMMON_HPP