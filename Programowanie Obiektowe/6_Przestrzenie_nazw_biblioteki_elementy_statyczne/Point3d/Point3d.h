#pragma once
#include <Point.hpp>

class Point3d : public pt::Point
{
private:
	double z;
public:
	Point3d(double x = 0, double y = 0, double z = 0) : pt::Point(x, y), z(z) {};
	double getZ() const { return z; }
};

