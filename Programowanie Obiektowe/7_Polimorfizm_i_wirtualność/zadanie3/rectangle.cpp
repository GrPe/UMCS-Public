
#include "rectangle.hpp"


Rectangle::Rectangle(float a, float b, float c, float d)
    : a(a),b(b),c(c),d(d) {}

float Rectangle::circ()
{
    return a+b+c+d;
}
