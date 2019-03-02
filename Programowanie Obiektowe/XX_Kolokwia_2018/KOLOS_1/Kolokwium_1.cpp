#include <cmath>

//do testow----
#include <iostream>
using namespace std;
//------------

class Wielomian
{
	double* wspolczynniki;
	int size;
public:
	Wielomian(int n)
	{
		size = n+1;
		wspolczynniki = new double[size];
		for (int i = 0; i < size; i++) wspolczynniki[i] = 0;
	}
	Wielomian(const Wielomian& wielomian)
	{
		size = wielomian.size;
		if (wspolczynniki != nullptr)
		{
			delete[] wspolczynniki;
		}

		wspolczynniki = new double[wielomian.size];
		for (int i = 0; i < wielomian.size; i++)
		{
			wspolczynniki[i] = wielomian.wspolczynniki[i];
		}
	}
	~Wielomian()
	{
		delete[] wspolczynniki;
		wspolczynniki = nullptr;
	}

	double& GetWspolczynnik(int stopien)
	{
		if (stopien >= size)
		{
			double* newTab = new double[stopien + 1];
			for (int i = 0; i < size; i++) newTab[i] = wspolczynniki[i]; // przepisujemy
			for (int i = size; i <= stopien; i++) newTab[i] = 0; // zerujemy pozostale
			
			delete[] wspolczynniki;
			wspolczynniki = newTab;
			newTab = nullptr;
			size = stopien + 1;
		}
		return wspolczynniki[stopien];
	}

	const double& GetWspolczynnik(int stopien) const
	{
		if (stopien >= size) return 0;
		return wspolczynniki[stopien];
	}

	double Calc(double x)
	{
		double result = 0;
		for (int i = 0; i < size; i++)
		{
			result += (wspolczynniki[i] * pow(x, i));
		}
		return result;
	}
};

//test
int main()
{
	Wielomian wielomian(3);
	//x^3 + x^2 + 10x + 4
	wielomian.GetWspolczynnik(0) = 4;
	wielomian.GetWspolczynnik(1) = 10;
	wielomian.GetWspolczynnik(2) = 1;
	wielomian.GetWspolczynnik(3) = 1;
	cout << wielomian.Calc(1) << endl;

	Wielomian nowyWielomian(3);
	nowyWielomian = wielomian;
	nowyWielomian.GetWspolczynnik(4) = 10;
	cout << nowyWielomian.Calc(1) << endl;

	return 0;
}