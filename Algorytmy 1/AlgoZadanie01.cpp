#include <iostream>
#include <string>
#include <cstdint>
#include <memory>


using namespace std;

constexpr double PI = 3.141593;
constexpr double Inch = 0.0000254;

class Car
{
public:
	std::string name;
	long double p;
	uint32_t d;
	uint64_t rotations;

	void CalcRotation();
	bool operator<(const Car&);
};

void Car::CalcRotation()
{
#ifdef TEST
	cout << PI << endl;
	cout << d << endl;
	cout << Inch << endl;
	cout << "POLE " << PI * d * Inch << endl;
	cout << p / (PI * d * Inch) << endl;
#endif // TEST

	rotations = static_cast<uint64_t>(p/(PI * d * Inch));
#ifdef TEST
	cout << rotations << endl;
#endif // TEST
}

bool Car::operator<(const Car& car)
{
	if (this->rotations == car.rotations)
	{
		return this->name < car.name;
	}
	return this->rotations < car.rotations;
}

void SortFirst3(shared_ptr<Car[]>& cars)
{
	if (cars[2] < cars[0]) swap(cars[0], cars[2]);
	if (cars[1] < cars[0])  swap(cars[0], cars[1]);
	if (cars[2] < cars[1]) swap(cars[1], cars[2]);
}

void AddToTable(std::unique_ptr<Car>&& car, shared_ptr<Car[]>& cars)
{
	if (*car < cars[0])
	{
		cars[2] = cars[1];
		cars[1] = cars[0];
		cars[0] = *car;
	}
	else if (*car < cars[1])
	{
		cars[2] = cars[1];
		cars[1] = *car;
	}
	else if (*car < cars[2])
	{
		cars[2] = *car;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	string buffStr;
	uint32_t n;
	cin >> n;

	shared_ptr<Car[]> cars(new Car[3]);
	unique_ptr<Car> buffer(new Car);

	for (uint32_t i = 0; i < 3; i++)
	{
		cin.ignore(100, '\n');
		getline(cin, buffStr);
		cars[i].name = buffStr;
		cin >> cars[i].p >> cars[i].d;
		cars[i].CalcRotation();
#ifdef TEST
		cout << cars[i].rotations << endl;
#endif
	}


	SortFirst3(cars);

	for (uint32_t i = 3; i < n; i++)
	{
		cin.ignore(100, '\n');
		getline(cin, buffStr);
		buffer->name = buffStr;
		cin >> buffer->p >> buffer->d;
		buffer->CalcRotation();
		AddToTable(std::move(buffer), cars);
	}


	//Display
	for (int i = 0; i < 3; i++)
	{
		cout << cars[i].name << endl;
		cout << cars[i].rotations << endl;
	}


	return 0;
}