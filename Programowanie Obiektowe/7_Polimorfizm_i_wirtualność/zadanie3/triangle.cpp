#include "triangle.hpp"

Triangle::Triangle(float a, float b, float c) : a(a), b(b),
    c(c) {}

float Triangle::circ()
{
    return a+b+c;
}
