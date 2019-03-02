#include "regularpyramid.hpp"

using namespace poly;

RegularPyramid::RegularPyramid(double length, double height, int number)
    : RegularPolyhedron(length,height,number){}

double RegularPyramid::volume()
{
    return area()*getHeight()/3;
}
