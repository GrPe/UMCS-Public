#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>


class Person
{
	std::string name;
	int age;
	std::vector<Person*> children;
public:

	std::string Name() const 
	{
		return name;
	}

	int Age() const
	{
		return age;
	}

	int Size() const 
	{
		return children.size();
	}

	Person(std::string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	bool operator<(const Person& person) const
	{
		if (age == person.age)
			return name < person.name;
		return age < person.age;
	}

	Person& operator<<=(Person* person)
	{
		for (auto child : children)
		{
			if (child == person) return *this;
		}
		children.push_back(person);
		return *this;
	}

	Person& operator[](unsigned int i)
	{
		return *children[i];
	}
};


int main()
{ 
	Person parent{ "ala",445 };
	Person child1{ "kot",14 };
	Person child2{ "niewiem",20 };
	

	return 0;

}

