#ifndef REGULARPYRAMID_HPP
#define REGULARPYRAMID_HPP
#include "regularpolyhedron.hpp"

namespace poly
{
    class RegularPyramid : public RegularPolyhedron
    {
    public:
        RegularPyramid(double length,double height, int number);
        virtual double volume() override;
    };
}


#endif // REGULARPYRAMID_HPP
