#include "Polygon.h"
#include <cmath>
#include <iostream>

Polygon::Polygon(int size)
{
	currentPos = 0;
	this->size = size;
	points = new pt::Point[size];
}

Polygon::Polygon(Polygon & polygon)
{
	this->size = polygon.size;
	this->currentPos = polygon.currentPos;
	std::memcpy(this->points, polygon.points, sizeof(pt::Point)*currentPos);
}

Polygon::Polygon(Polygon && polygon)
{
	this->size = polygon.size;
	this->currentPos = polygon.currentPos;
	this->points = polygon.points;
	polygon.points = nullptr;
}

Polygon::~Polygon()
{
	delete[] points;
}

void Polygon::AddPoint(const pt::Point & point)
{
	if (currentPos < size)
		points[currentPos++] = point;
}

bool Polygon::IsRectangle(const pt::Point & p1, const pt::Point & p2, const pt::Point & p3, const pt::Point & p4)
{
	double dist12 = Distance(p1, p2);
	double dist23 = Distance(p2, p3);
	double dist24 = Distance(p2, p4);
	if (std::fabs(dist24*dist24 - (dist12*dist12 + dist23 * dist23)) < 0.0001) return true; //float arithmetic 
	else return false;
}

double Polygon::Distance(const pt::Point & p1, const pt::Point & p2)
{
	return std::sqrt(std::pow(p2.getX() - p1.getX(),2) + std::pow(p2.getY() - p1.getY(),2));
}

Polygon Polygon::Triangle(const pt::Point& p1, const pt::Point& p2, const pt::Point& p3)
{
	Polygon poly(3);
	poly.AddPoint(p1);
	poly.AddPoint(p2);
	poly.AddPoint(p3);
	return poly;
}

Polygon Polygon::Rectangle(const pt::Point&  p1, const pt::Point&  p2, const pt::Point&  p3, const pt::Point&  p4)
{
	if (!IsRectangle(p1, p2, p3, p4))
	{
		return Polygon(4); //empty Polygon
	}
	Polygon poly(4);
	poly.AddPoint(p1);
	poly.AddPoint(p2);
	poly.AddPoint(p3);
	poly.AddPoint(p4);
	return poly;
}
