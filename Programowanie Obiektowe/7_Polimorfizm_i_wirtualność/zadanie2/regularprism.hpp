#ifndef REGULARPRISM_HPP
#define REGULARPRISM_HPP
#include "regularpolyhedron.hpp"

namespace poly
{
    class RegularPrism : public RegularPolyhedron
    {
    public:
        RegularPrism(double length,double height, int number);
        virtual double volume() override;
    };
}

#endif // REGULARPRISM_HPP
