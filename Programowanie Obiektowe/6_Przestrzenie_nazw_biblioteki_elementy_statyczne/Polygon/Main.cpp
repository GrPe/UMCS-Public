#include "Polygon.h"
#include <Point.hpp>
#include <iostream>

int main()
{
	using pt::Point;
	Polygon poly(12);
	Polygon rect = Polygon::Rectangle(Point{ 1,2 }, Point{ 7,2 }, Point{ 7,5 }, Point{ 1,5 });
	
	std::cout << "Praise the C++" << std::endl;
	return 0;
}