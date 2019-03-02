#include "regularprism.hpp"

using namespace poly;

RegularPrism::RegularPrism(double length, double height, int number) :
    RegularPolyhedron(length,height,number) {}

double RegularPrism::volume()
{
    return area()*getHeight();
}
