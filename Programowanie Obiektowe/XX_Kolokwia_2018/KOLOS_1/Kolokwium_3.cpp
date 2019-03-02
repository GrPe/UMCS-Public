#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class Shape
{
public:
	struct Point
	{
		double x, y;
	};
	virtual bool save(const string&) = 0;
};


class Triangle : public Shape
{
	Point p1, p2, p3;
	double DlugoscOdcinka(const Point& p1, const Point& p2)
	{
		return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
	}
	double Obwod()
	{
		return DlugoscOdcinka(p1, p2) + DlugoscOdcinka(p2, p3) + DlugoscOdcinka(p3, p1);
	}
	double Pole()
	{
		double p = Obwod() / 2;
		double a = DlugoscOdcinka(p1, p2);
		double b = DlugoscOdcinka(p2, p3);
		double c = DlugoscOdcinka(p3, p1);
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
public:
	Triangle(const Point& p1, const Point& p2, const Point& p3)
	{
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;
	}
	virtual bool save(const string& fileName) override
	{
		ofstream file(fileName);
		file << "Triangle" << endl;
		file << p1.x << " " << p1.y << endl;
		file << p2.x << " " << p2.y << endl;
		file << p3.x << " " << p3.y << endl;
		file << Obwod() << endl;
		file << Pole() << endl;
		if (file.fail() || file.bad())
		{
			file.close();
			return false;
		}
		file.close();
		return true;
	}
};

class Circle : public Shape
{
	const double pi = 3.1415;
	Point p1;
	double r;
	double Obwod()
	{
		return 2 * pi * r;
	}
	double Pole()
	{
		return pi * r*r;
	}
public:
	Circle(const Point& p1, const double r)
	{
		this->p1 = p1;
		this->r = r;
	}
	virtual bool save(const string& fileName) override
	{
		ofstream file(fileName);
		file << "Circle" << endl;
		file << p1.x << " " << p1.y << endl;
		file << r << endl;
		file << Obwod() << endl;
		file << Pole() << endl;
		if (file.bad() || file.fail())
		{
			file.close();
			return false;
		}
		file.close();
		return true;
	}
};

void foo(Shape** tab, int size, const string& path)
{
	for (int i = 0; i < size; i++)
	{
		tab[i]->save(path + to_string(i)+".txt");
	}
}


//test
int main()
{
	Shape** shapes = new Shape*[4];
	shapes[0] = new Circle(Circle::Point{ 1,2 }, 4);
	shapes[1] = new Circle(Circle::Point{ 3,4 }, 12);
	shapes[2] = new Triangle(Triangle::Point{ 32,43 }, Triangle::Point{ 12,23 }, Triangle::Point{ 39,29 });
	shapes[3] = new Circle(Circle::Point{ 2,4 }, 12);
	foo(shapes, 4, "");

	return 0;
}