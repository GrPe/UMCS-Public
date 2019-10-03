#include <iostream>
#include <string>
#include <cstdint>
#include <memory>
#include <functional>

using namespace std;

class Child;

//global function's table
function<bool(const Child&, const Child&)> functions[3];
function<bool(const Child&, const Child&)> equality[3];

class Child
{
public:
	string code;
	double average;
	uint32_t distance;
	uint16_t month;
	bool operator<(const Child&);
};

bool Child::operator<(const Child& child)
{
	//if is greater return true
	//else if equal -> test another comparative criterion
	if (functions[0](*this, child))
	{
		return true;
	}
	if (equality[0](*this, child))
	{
		if (functions[1](*this, child))
		{
			return true;
		}
		else if (equality[1](*this, child))
		{
			if (functions[2](*this, child))
			{
				return true;
			}
			else
			{
				return equality[2](*this, child);
			}
		}
	}
	return false;
}

//Initialization of compare function's table. 
void InitFunctionsTable(char* orders)
{
	for (int i = 0; i < 3; i++)
	{
		switch (orders[i])
		{
		case 's': //if average have high priority
			functions[i] = [](const Child& child, const Child& child2)
			{return child.average > child2.average; };

			equality[i] = [](const Child& child, const Child& child2)
			{return child.average == child2.average; };
			break;
		case 'd': //distance
			functions[i] = [](const Child& child, const Child& child2)
			{return child.distance > child2.distance; };

			equality[i] = [](const Child& child, const Child& child2)
			{return child.distance == child2.distance; };
			break;
		case 'm': //month
			functions[i] = [](const Child& child, const Child& child2)
			{return child.month > child2.month; };

			equality[i] = [](const Child& child, const Child& child2)
			{return child.month == child2.month; };
		}
	}
}

//Add one element and insert it to correct position -> variations of insert sort
void Insert(shared_ptr<Child[]>& children, uint32_t size, Child& value)
{
	int32_t i;
	if (size == 0)
	{
		children[0] = value;
		return;
	}
	for (i = size -1; (i >= 0) && !(children[i]<value); i--)
	{
		children[i + 1] = children[i];
	}
	children[i + 1] = value;
}

int main()
{
	ios_base::sync_with_stdio(false);

	uint32_t n;
	cin >> n;

	char sortOrder[3];
	for (int i = 0; i < 3; i++) cin >> sortOrder[i];

	InitFunctionsTable(sortOrder);

	shared_ptr<Child[]> boys(new Child[n]);
	shared_ptr<Child[]> girls(new Child[n]);

	Child value;

	for (int i = 0; i < n; i++)
	{
		cin >> value.code >> value.average >> value.distance >> value.month;
		Insert(boys, i, value);
		cin >> value.code >> value.average >> value.distance >> value.month;
		Insert(girls, i, value);
	}

	for (int i = 0; i < n; i++)
	{
		cout << boys[i].code << " " << girls[i].code << " ";
	}

	return 0;
}