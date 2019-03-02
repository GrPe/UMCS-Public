#pragma once
#include <iostream>

template<typename T>
class list
{
    class node
    {
    public:
        T value;
        node* next;
    };
    node* head;
    node* tail;

    class iterator
    {
        node* ptr;
    public:
        iterator(node* ptr) {this->ptr = ptr;}
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
    };
public:
    list();
    ~list(); // to implement
    void push_front(T elem);
    void push_back(T elem);
    void pop_back();
    void pop_front();
    list(const list&) = delete;
    list(const list&&) = delete;
    list& operator=(const list&) = delete;
    iterator begin();
    iterator end();

    void Display() const;
};

template<typename T>
list<T>::list()
{
    head = nullptr;
    tail = nullptr;
}

template<typename T>
list<T>::~list()
{
    node* temp = head;
    node* temp2 = nullptr;
    while(temp)
    {
        temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
}

template<typename T>
void list<T>::push_front(T elem)
{
    if(head == nullptr)
    {
        node* newNode = new node{elem,nullptr};
        head = newNode;
        tail = newNode;
    }
    else
    {
        node* newNode = new node{elem,head};
        head = newNode;
    }
}

template<typename T>
void list<T>::push_back(T elem)
{
    if(tail == nullptr)
    {
        node* newNode = new node{elem,nullptr};
        head = newNode;
        tail = newNode;
    }
    else
    {
        node* newNode = new node{elem,nullptr};
        tail->next = newNode;
        tail = newNode;
    }
}

template<typename T>
void list<T>::pop_front()
{
    if(head == nullptr) return;
    else if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        node* temp = head;
        head= head->next;
        delete temp;
    }
}

template<typename T>
typename list<T>::iterator list<T>::begin()
{
    return iterator(head);
}

template<typename T>
typename list<T>::iterator list<T>::end()
{
    return iterator(nullptr);
}

template<typename T>
void list<T>::Display() const
{
    node* temp = head;
    while(temp != nullptr)
    {
        std::cout<<temp->value<<std::endl;
        temp= temp->next;
    }
}

template<typename T>
void list<T>::pop_back()
{
    if(tail == nullptr) return;
    else if(tail == head)
    {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    else
    {
        node* temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }
}
