#include <iostream>

using namespace std;

class CElementy
{
public:
	unsigned int elementA, elementB;

	void show()
	{
		cout << "<<" << elementA << ", " << elementB << ">>" << endl;
	}
};

int main()
{
	CElementy elementy{ 15,30 };
	elementy.show();

	return 0;
}