#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

class Kontener
{
	vector<int> vec;
public:
	Kontener operator+(const Kontener& kontener)
	{
		Kontener nowy;
		for (int i = 0; i < vec.size(); i++)
			nowy.vec.push_back(vec[i]);
		for (int i = 0; i < kontener.vec.size(); i++)
			nowy.vec.push_back(kontener.vec[i]);
		return nowy;
	}
	Kontener& operator+=(int x)
	{
		for (int i = 0; i < vec.size(); i++)
			vec[i] += x;
		return *this;
	}
	int& operator[](int index) 
	{
		if (index > vec.size() || index < 0) throw out_of_range("OUT OF RANGE");
		return vec[index];
	}

	friend istream& operator>> (istream& is, Kontener& kontener);
	friend ostream& operator<< (ostream& os, Kontener& kontener);

};

istream& operator>> (istream& is, Kontener& kontener)
{
	int x;
	is >> x;
	kontener.vec.push_back(x);
	return is;
}

ostream& operator<< (ostream& os, Kontener& kontener)
{
	os << kontener.vec[kontener.vec.size() - 1];
	kontener.vec.pop_back();
	return os;
}

//test
int main()
{
	Kontener kontener;
	cin >> kontener;
	cin >> kontener;
	cin >> kontener;
	Kontener kontener2 = kontener;
	cout << kontener2 << endl;
	Kontener kontener3 = kontener2 + kontener;
	kontener3 += 14;
	cout << kontener3[4] << endl;
	try
	{
		cout << kontener3[15623] << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
	
}