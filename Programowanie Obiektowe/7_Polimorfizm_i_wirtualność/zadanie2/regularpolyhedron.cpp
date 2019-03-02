#include "regularpolyhedron.hpp"
#include <cmath>

using namespace poly;

RegularPolyhedron::RegularPolyhedron(double length, double height, int number)
{
    this->length = length;
    this->height = height;
    this->number = number;
}

double RegularPolyhedron::area() const
{
    return 0.25*number*length*length*(1/std::tan(M_PI/number));
}
