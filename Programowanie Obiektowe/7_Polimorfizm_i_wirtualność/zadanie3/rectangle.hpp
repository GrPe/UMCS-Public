#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "polygon.hpp"

class Rectangle : public Polygon
{
    float a,b,c,d;
public:
    Rectangle(float a,float b,float c,float d);
    virtual float circ() override;

};

#endif // RECTANGLE_HPP
