#ifndef REGULARPOLYHEDRON_HPP
#define REGULARPOLYHEDRON_HPP

namespace poly
{
    class RegularPolyhedron
    {
    private:
        double length, height;
        int number;
    public:
        RegularPolyhedron(double length,double height, int number);
        virtual double volume() = 0;
    protected:
        double area() const;
        double getHeight() const {return height;}
    };
}



#endif // REGULARPOLYHEDRON_HPP
