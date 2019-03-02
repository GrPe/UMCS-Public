#include <list>
#include <memory> // smart pointers
#include <map>
#include <iostream>

using namespace std;

//-----------Nie trzeba tego pisac, ale bez tego sie nie skompiluje
class Shape
{
	float a, b;
public:
	Shape(float a = 4, float b = 4) : a(a), b(b) {}
	Shape(const Shape&) = default;
	Shape& operator=(const Shape&) = default;
	virtual float area() { return a * b; }
};
//-------------------------------------------

//----- odpowiedz na ostatnie pytanie: Nie
//struct ColoredShape
//{
//	const Shape& shape;
//	unsigned int color;
//};
//-------Mozna odkomentowac (wysypie siê :>)

struct ColoredShape
{
	Shape shape;
	unsigned int color;
};


class ShapeList
{
	list<unique_ptr<ColoredShape>> shapes;
public:
	void append(unique_ptr<ColoredShape> ptr)
	{
		shapes.push_back(move(ptr));
	}
	unsigned int commonColor()
	{
		if (shapes.empty()) throw "empty list";

		map<unsigned int, float> colors;
		for (auto& ptr : shapes) // dziala jak zwyk³y for i przechodzi po ka¿dym elemencie z listy
		{
			colors[ptr->color] = 0; // zerowanie mapy;
		}
		for (auto& ptr : shapes)
		{
			colors[ptr->color] += ptr->shape.area(); // sumowanie pol figur dla kazdego koloru
		}

		unsigned int maxColor = 0;
		float maxArea = 0;
		for (auto color : colors) // wyszukiwanie maksa w mapie
		{
			if (color.second > maxArea)
			{
				maxArea = color.second; // gdzie second to obliczona suma pol dla koloru
				maxColor = color.first; // first to kolor
			}
		}
		return maxColor;
	}
};

int main()
{
	ShapeList shapeList;

	//lista jest pusta -> lapiemy wyjatek
	try
	{
		shapeList.commonColor();
	}
	catch (const char ex[])
	{
		cout << ex << endl;
	}

	//dodawanie obiektow do listy
	unique_ptr<ColoredShape> shape(new ColoredShape{ Shape{2,4},0x00ffffff });
	shapeList.append(move(shape));
	shapeList.append(unique_ptr<ColoredShape>(new ColoredShape{ Shape{ 3,110 },0x002f2f2f }));
	shapeList.append(unique_ptr<ColoredShape>(new ColoredShape{ Shape{ 4,12 },0x00ffffff }));

	try 
	{
		cout << hex << shapeList.commonColor() << endl; // to hex wymusza wypisywanie danych w systemie 16.
														// nie jest obowiazkowe ale latwiej sprawdzic czy kolor siê zgadza
	}
	catch (const char ex[])
	{
		cout << ex << endl;
	}

	return 0;
}