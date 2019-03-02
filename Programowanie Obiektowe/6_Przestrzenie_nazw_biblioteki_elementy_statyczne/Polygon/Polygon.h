#pragma once
#include <Point.hpp>

class Polygon
{
private:
	pt::Point* points{ nullptr };
	int size{ 0 };
	int currentPos{ 0 };

#pragma region Rectangle
	static bool IsRectangle(const pt::Point& p1, const pt::Point& p2, const pt::Point& p3, const pt::Point& p4);
	static double Distance(const pt::Point& p1, const pt::Point& p2);
#pragma endregion
public:
	explicit Polygon(int size);
	Polygon(Polygon& polygon);
	Polygon(Polygon&& polygon);
	~Polygon();
	void AddPoint(const pt::Point& point);

	static Polygon Triangle(const pt::Point& p1, const pt::Point& p2, const pt::Point& p3);
	static Polygon Rectangle(const pt::Point& p1, const pt::Point& p2, const pt::Point& p3, const pt::Point& p4);
};

