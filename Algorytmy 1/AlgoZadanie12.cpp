#include <iostream>

using namespace std;

class Chest final
{
	int size;
	double* bottles = nullptr;
	double sum;
public:
	Chest()
	{
		this->size = 0;
		bottles = nullptr;
		sum = 0;
	}

	~Chest()
	{
		delete[] bottles;
	}

	void SetSize(int size)
	{
		this->size = size;
		bottles = new double[this->size];
	}

	double GetSum() const
	{
		return sum;
	}

	Chest(const Chest& chest)
	{
		if (this == &chest)
			return;

		delete[] bottles;
		size = chest.size;
		sum = chest.sum;
		bottles = new double[this->size];

		for (int i = 0; i != size; i++)
			bottles[i] = chest.bottles[i];
	}
	Chest& operator=(const Chest& chest)
	{
		if (this == &chest)
			return *this;

		delete[] bottles;
		size = chest.size;
		sum = chest.sum;
		bottles = new double[size];

		for (int i = 0; i != size; i++)
			bottles[i] = chest.bottles[i];
		return *this;
	}
	Chest(Chest&& chest) noexcept
	{
		delete[] bottles;
		bottles = chest.bottles;
		sum = chest.sum;
		chest.bottles = nullptr;
		chest.sum = 0;
		size = chest.size;
		chest.size = 0;
	}
	Chest& operator=(Chest&& chest) noexcept
	{
		delete[] bottles;
		bottles = chest.bottles;
		sum = chest.sum;
		chest.bottles = nullptr;
		chest.sum = 0;
		size = chest.size;
		chest.size = 0;
		return *this;
	}

	friend istream& operator>>(istream& is, Chest& chest);
	friend ostream& operator<<(ostream& os, const Chest& chest);
};

istream& operator>>(istream& is, Chest& chest)
{
	chest.sum = 0;
	for (size_t i = 0; i < chest.size; i++)
	{
		is >> chest.bottles[i];
		chest.sum += chest.bottles[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const Chest& chest)
{
	for (int i = 0; i < chest.size; i++)
	{
		os << chest.bottles[i] << " ";
	}
	return os;
}

template <typename T>
class Vector final
{
	T* table = nullptr;
	size_t size;
	size_t reserveSize;

public:
	Vector()
	{
		table = new T[1];
		size = 0;
		reserveSize = 1;
	}

	explicit Vector(size_t size)
	{
		this->size = size;
		reserveSize = size;
		table = new T[reserveSize];
	}

	Vector(const Vector&) = delete;
	Vector& operator=(const Vector&) = delete;
	Vector(Vector&&) = delete;
	Vector& operator=(Vector&&) = delete;

	~Vector()
	{
		delete[] table;
	}

	void push_back(T&& value)
	{
		if (size >= reserveSize)
		{
			reserveSize *= 2;
			T* newTab = new T[reserveSize];
			for (size_t i = 0; i < size; i++)
			{
				newTab[i] = std::move(table[i]);
			}
			delete[] table;
			table = newTab;
		}
		table[size++] = std::move(value);
	}

	T& operator[](int index)
	{
		return table[index];
	}

	T* GetRawPointer()
	{
		return table;
	}

	int GetSize()
	{
		return size;
	}
};

void InsertSort(Chest* chest, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i - 1;
		Chest key = chest[i];
		while (j >= 0 && chest[j].GetSum() < key.GetSum())
		{
			chest[j + 1] = std::move(chest[j]);
			j--;
		}
		chest[j + 1] = std::move(key);
	}
}

void BasketSort(Vector<Chest>& chests, const int sizeOfBasket, const int elementToDisplaying)
{
	Vector<Vector<Chest>> table(sizeOfBasket + 1);

	for (int i = 0; i < chests.GetSize(); i++)
	{
		table[static_cast<int>(chests[i].GetSum())].push_back(std::move(chests[i]));
	}

	int sortedValues = 0;
	for (int i = sizeOfBasket; i >= 0 ; i--)
	{
		InsertSort(table[i].GetRawPointer(), table[i].GetSize());
		sortedValues += table[i].GetSize();
		if (sortedValues >= elementToDisplaying) break;
	}

	int out = 0;
	int currentPosition = sizeOfBasket;
	int currentIndex = 0;
	while (out < elementToDisplaying)
	{
		if (currentIndex >= table[currentPosition].GetSize())
		{
			currentPosition--;
			currentIndex = 0;
			continue;
		}

		cout << table[currentPosition][currentIndex] << "\n";
		out++;
		currentIndex++;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	int numberOfChest, numberOfBottles, capacity;
	cin >> numberOfChest >> numberOfBottles >> capacity;

	Vector<Chest> chests(numberOfChest);
	for (int i = 0; i < numberOfChest; i++)
	{
		chests[i].SetSize(numberOfBottles);
		cin >> chests[i];
	}

	BasketSort(chests, numberOfBottles, capacity);

	return 0;
}