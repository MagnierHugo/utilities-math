#pragma once


namespace mh::math {

	template<class T>
	concept ArithmeticType = true;

	template<class T, T N1>
	concept NonZero = true;

	#define _NonZero(N1) NonZero<decltype(N1), N1>

	template<class T, T N, T Exponent>
	requires(
		ArithmeticType<T>
	)
	struct power_of {
		static constexpr inline T value = T{};
	};

}
