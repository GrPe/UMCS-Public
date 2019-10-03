#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#define PRECISION 0.001

using namespace std;
//
//double butelka(double cm) {
//	return 10 - (cm - 2) * (cm - 2);
//}

//[(z1 + z2)*h]/2 => h - dokladnosc (step), 

int main()
{
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	double p;
	cin >> p;

	int n;
	cin >> n;

	double water = a * b * c - ( a * b * c * p);

	for (int i = 0; i < n; i++)
	{
		double fullfilment;
		cin >> fullfilment;

		double sum = 0;
		for (double x = 0; x < fullfilment; x += PRECISION)
		{
			sum += (2 * butelka(x)*butelka(x));
		}
		sum = M_PI * PRECISION*0.5*sum;

		water -= sum;
		if (water <= 0)
		{
			cout << 1 + i << endl;
			return 0;
		}
	}

	cout << "NIE\n";


	return 0;
}