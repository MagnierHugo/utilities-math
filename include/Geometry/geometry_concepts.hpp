#pragma once


namespace mh::math {

	template<class T>
	concept GeometryPolicy = requires {
		typename T::size_type;
		typename T::geometry_array_type;
	}&& requires {
		{ T::rank() } -> std::same_as<typename T::size_type>;
		{ T::size() } -> std::same_as<typename T::size_type>;
		{ T::geometry() } -> std::same_as<typename T::geometry_array_type>;
	}&& requires {
		std::is_default_constructible_v<T>;
		std::is_trivially_copyable_v<T>;
	};

	template<class T>
	concept _1D = GeometryPolicy<T> && (T::rank() == 1);

	template<class T>
	concept _2D = GeometryPolicy<T> && (T::rank() == 2);

	template<class T>
	concept UniformGeometry = true;

}