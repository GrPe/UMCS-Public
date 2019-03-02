#pragma once
#include <iostream>

template<typename T>
class Deque
{
	class node
	{
	public:
		T value;
		node* next;
		node* previous;
	};
	node* head;
	node* tail;

	class iterator
	{
		node* ptr;
	public:
		iterator() { ptr = nullptr; }
		iterator(node* ptr) { this->ptr = ptr; }
		iterator& operator++()
		{
			ptr = ptr->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator temp = *this;
			ptr = ptr->next;
			return temp;
		}
		T& operator*()
		{
			return ptr->value;
		}
		T* operator->()
		{
			return &ptr->value;
		}
		bool operator==(const iterator& iter)
		{
			return ptr == iter.ptr;
		}
		bool operator!=(const iterator& iter)
		{
			return ptr != iter.ptr;
		}
		iterator& operator--()
		{
			ptr = ptr->previous;
			return *this;
		}
		iterator operator--(int)
		{
			iterator temp = *this;
			ptr = ptr->previous;
			return temp;
		}

	};
public:
	Deque();
	~Deque();
	void push_front(T elem);
	void push_back(T elem);
	void pop_back();
	void pop_front();
	Deque(const Deque&) = delete;
	Deque(const Deque&&) = delete;
	Deque& operator=(const Deque&) = delete;
	iterator begin();
	iterator end();

	void Display() const;
};

template<typename T>
Deque<T>::Deque()
{
	head = nullptr;
	tail = nullptr;
}

template<typename T>
Deque<T>::~Deque()
{
	node* temp = head;
	node* temp2 = nullptr;
	while (temp)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
}

template<typename T>
void Deque<T>::push_front(T elem)
{
	if (head == nullptr)
	{
		node* newNode = new node{ elem, nullptr, nullptr };
		head = newNode;
		tail = newNode;
	}
	else
	{
		node* newNode = new node{elem, head, nullptr };
		head->previous = newNode;
		head = newNode;
		//head->nextprevious = head;
	}
}

template<typename T>
void Deque<T>::push_back(T elem)
{
	if (tail == nullptr)
	{
		node* newNode = new node{ elem, nullptr, nullptr };
		head = newNode;
		tail = newNode;
	}
	else
	{
		node* newNode = new node{ elem,nullptr, tail };
		tail->next = newNode;
		tail = newNode;
	}
}

template<typename T>
void Deque<T>::pop_front()
{
	if (head == nullptr) return;
	else if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		node* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
typename Deque<T>::iterator Deque<T>::begin()
{
	return iterator(head);
}

template<typename T>
typename Deque<T>::iterator Deque<T>::end()
{
	return iterator(nullptr);
}

template<typename T>
void Deque<T>::Display() const
{
	node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}

template<typename T>
void Deque<T>::pop_back()
{
	if (tail == nullptr) return;
	else if (tail == head)
	{
		delete tail;
		tail = nullptr;
		head = nullptr;
	}
	else
	{
		node* temp = tail;
		tail = tail->previous;
		tail->next = nullptr;
		delete temp;
	}
}
