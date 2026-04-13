#pragma once


namespace mh::math {

	template<class T>
	concept GeometryPolicy = true;

	template<class T>
	concept _1D = true;

	template<class T>
	concept _2D = true;

}