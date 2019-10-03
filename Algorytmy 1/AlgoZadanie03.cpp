#include <iostream>
#include <utility>
#include <string>
#include <cstdint>

struct data
{
	std::string first;
	int second;
};

template <typename T>
class list
{
	uint32_t size;
	class element
	{
	public:
		element* next = nullptr;
		element* previous = nullptr;
		T value;
	};

	element* first = nullptr;
	element* current = nullptr;

	class iterator
	{
		element* ptr;
	public:
		iterator(element* ptr) { this->ptr = ptr; }
		iterator& operator++();
		iterator& operator--();
		T& operator*();
		T* operator->();
		bool operator==(const iterator&);
		bool operator!=(const iterator&);
	};

public:
	list();
	~list();
	list(const list&) = delete;
	list& operator=(list&) = delete;
	list(list&&);
	list& operator=(list&&);
	bool Empty() const;
	void push_back(T&);
	void push_back_move(T&&);
	void EraseCurrent();
	void Next();
	void Previous();
	void JumpNext(uint32_t);
	void JumpBack(uint32_t);
	T& GetCurrent();
	uint32_t GetSize() const { return size; }
	iterator GetIterator();
	iterator begin();
};

int main()
{

	std::ios::sync_with_stdio(false);

	//read data
	uint32_t n;
	std::cin >> n;
	list<list<data>> listy;

	list<data> ls;
	uint32_t m;
	for (uint32_t i = 0; i < n; i++)
	{
		std::cin >> m;
		data tmp;
		for (uint32_t j = 0; j < m; j++)
		{
			std::cin >> tmp.first >> tmp.second;
			ls.push_back(tmp);
		}
		listy.push_back_move(std::move(ls));
	}

	//read control numbers
	list<uint32_t> contronNumbers;
	uint32_t l;
	std::cin >> l;
	uint32_t tmp;
	for (uint32_t i = 0; i < l; i++)
	{
		std::cin >> tmp;
		contronNumbers.push_back(tmp);
	}

	//read sequences
	uint32_t h;
	std::cin >> h;
	std::pair<int, int>* sequenses;
	sequenses = new std::pair<int, int>[h];
	for (uint32_t i = 0; i < h; i++)
	{
		std::cin >> sequenses[i].first >> sequenses[i].second;
	}

	//algo
	uint32_t sequanceCounter = 0;
	
	int sum = 0;
	bool toSum = true; //sumowanie tylko jesli zostal znaleziony numer kontrolny
	//else odejmin i dodaj wartosc zmieniana
	while (sequanceCounter < h && !contronNumbers.Empty() && !listy.Empty())
	{
		if (toSum)
		{
			sum = 0;
			auto iter = listy.begin();
			for (uint32_t i = 0; i < listy.GetSize(); ++i)
			{
				sum += iter->GetCurrent().second;
				++iter;
			}
			toSum = false;
		}

		//check control number 
		for (uint32_t i = 0; i < l; i++)
		{
			if (sum == contronNumbers.GetCurrent())
			{
				contronNumbers.EraseCurrent();

				std::string ret = "";
				auto iter = listy.begin();
				for (uint32_t i = 0; i < listy.GetSize(); ++i)
				{
					ret += iter->GetCurrent().first;
					iter->EraseCurrent();
					++iter;
				}

				uint32_t size = listy.GetSize();
				for (uint32_t i = 0; i < size; ++i)
				{
					if (listy.GetCurrent().Empty()) listy.EraseCurrent();
					else listy.Next();
				}

				std::cout << sum << " " << ret << "\n";

				toSum = true;
				break;
			}
			contronNumbers.Next();
		}

		//execute sequence
		if(!toSum)
		{
			//optimization of jumping
			int size = static_cast<int>(listy.GetSize());
			int first = sequenses[sequanceCounter].first - (sequenses[sequanceCounter].first/size)*size;
			if(first > 0) first = (size - first < first) ? first - size : first;
			else first = (size + first < abs(first)) ? size + first : first;
			
			if (first > 0)
			{
				listy.JumpNext(first);
			}
			else
			{
				listy.JumpBack(-first);
			}

			//change sum
			sum -= listy.GetCurrent().GetCurrent().second;

			//optimization of jumping
			auto& ls = listy.GetCurrent();
			size = static_cast<int>(ls.GetSize());
			int second = sequenses[sequanceCounter].second - (sequenses[sequanceCounter].second / size)*size;
			if (second > 0) second = (size - second < second) ? second - size : second;
			else second = (size + second < abs(second)) ? size + second : second;

			if (second > 0)
			{
				ls.JumpNext(second);
			}
			else
			{
				ls.JumpBack(-second);
			}

			//set correct sum
			sum += listy.GetCurrent().GetCurrent().second;

			sequanceCounter++;
		}
	} 

	//clear
	delete[] sequenses;

	return 0;

}



//list implementation
template <typename T>
list<T>::list()
{
	size = 0;
	first = current = nullptr;
}

template <typename T>
list<T>::~list()
{
	element* tmp;
	for (uint32_t i = 0; i < size; i++)
	{
		tmp = first;
		first = first->next;
		delete tmp;
	}
}

template<typename T>
list<T>::list(list && lista)
{
	this->first = lista.first;
	this->current = lista.current;
	this->size = lista.size;
	lista.first = nullptr;
	lista.current == nullptr;
	lista.size = 0;
}

template<typename T>
list<T>& list<T>::operator=(list && lista)
{
	this->first = lista.first;
	this->current = lista.current;
	this->size = lista.size;
	lista.first = nullptr;
	lista.current == nullptr;
	lista.size = 0;
	return *this;
}

template <typename T>
bool list<T>::Empty() const
{
	return first == nullptr;
}

template<typename T>
void list<T>::push_back(T& value)
{
	size++;
	element* elem = new element;
	elem->value = value; 

	if (first == nullptr) 
	{
		first = elem;
		first->previous = first->next = first;
		current = first;
		return;
	}

	elem->next = first;
	elem->previous = first->previous;
	first->previous->next = elem;
	first->previous = elem;
}

template <typename T>
void list<T>::push_back_move(T&& value)
{
	size++;
	element* elem = new element;
	elem->value = std::move(value);

	if (first == nullptr)
	{
		first = elem; 
		first->previous = first->next = first;
		current = first;
		return;
	}

	elem->next = first;
	elem->previous = first->previous;
	first->previous->next = elem;
	first->previous = elem;
}

template <typename T>
void list<T>::EraseCurrent()
{
	if (first == nullptr) return; 
	size--;
	if (first->next == first) 
	{
		delete first;
		first = nullptr;
		return;
	}
	if (current == first) 
	{
		first = first->next;
		first->previous = current->previous;
		current->previous->next = first;
		delete current;
		current = first;
		return;
	}
	element* nextCurrent = current->next;
	current->previous->next = nextCurrent;
	current->next->previous = current->previous;
	delete current;
	current = nextCurrent;
}

template <typename T>
void list<T>::Next()
{
	current = current->next;
}

template <typename T>
void list<T>::Previous()
{
	current = current->previous;
}

template<typename T>
void list<T>::JumpNext(uint32_t jump)
{
	for (uint32_t i = 0; i < jump; i++)
	{
		current = current->next;
	}
}

template<typename T>
void list<T>::JumpBack(uint32_t jump)
{
	for (uint32_t i = 0; i < jump; i++)
	{
		current = current->previous;
	}
}

template <typename T>
T& list<T>::GetCurrent()
{
	return current->value;
}

//iterator implementation
template<typename T>
auto list<T>::GetIterator() ->iterator
{
	return iterator(current);
}

template<typename T>
auto list<T>::iterator::operator++() -> iterator&
{
	ptr = ptr->next;
	return *this;
}

template<typename T>
auto list<T>::iterator::operator--() ->iterator&
{
	ptr = ptr->previous;
	return *this;
}

template<typename T>
auto list<T>::iterator::operator*() -> T &
{
	return ptr->value;
}

template<typename T>
auto list<T>::iterator::operator->() -> T*
{
	return &ptr->value;
}

template<typename T>
bool list<T>::iterator::operator==(const iterator & iter)
{
	return ptr == iter.ptr;
}

template<typename T>
bool list<T>::iterator::operator!=(const iterator & iter)
{
	return ptr != iter.ptr;
}

template <typename T>
auto list<T>::begin() -> iterator
{
	return iterator(first);
}