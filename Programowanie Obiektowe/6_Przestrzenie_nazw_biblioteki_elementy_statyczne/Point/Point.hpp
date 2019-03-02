#pragma once

#ifndef POINT
	#define POINT _declspec(dllexport)
#endif

namespace pt
{
	class POINT Point
	{
	private:
		double x, y;
	public:
		double  getX() const { return x; }
		double getY() const { return y; }
		Point(double x = 0, double y = 0) : x(x), y(y) {}
	};
}
