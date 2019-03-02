#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "polygon.hpp"


class Triangle : public Polygon
{
    float a,b,c;
public:
    Triangle(float a,float b, float c);
    virtual float circ() override;
};

#endif // TRIANGLE_HPP
