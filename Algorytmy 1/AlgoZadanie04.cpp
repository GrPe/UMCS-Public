#include <iostream>
#include <string>
#include <cstdint>
#include <cctype>

class Value
{
public:
	int64_t num;
	char sign;
};

template <typename T>
class Stack
{
	class Element
	{
	public:
		Element* next = nullptr;
		T value;
		Element() { next = nullptr; }
	};

	Element* top = nullptr;
public:
	void push(T value);
	T& get();
	void pop();
	Stack();
	~Stack();
	bool isEmpty() const { return top == nullptr; }
};

template <typename T>
class Queue
{
	class Element
	{
	public:
		Element* next = nullptr;
		T value;
		Element() { next = nullptr; }
	};
	Element* head;
	Element* tail;

public:
	void push(T value);
	T& get();
	void pop();
	Queue();
	~Queue();
	bool isEmpty() const { return head == nullptr; }
};

//utils
bool isOpenBracket(char c)
{
	return (c == '(' || c == '[' || c == '{');
}

bool isCloseBracket(char c)
{
	return (c == ')' || c == ']' || c == '}');
}

bool isEqualBracket(char b1, char b2)
{
	if (b1 == '(' && b2 == ')') return true;
	if (b1 == '[' && b2 == ']') return true;
	if (b1 == '{' && b2 == '}') return true;
	return false;
}

bool isCorrect(const std::string& expr)
{
	Stack<char> stack;
	for (auto x : expr)
	{
		if (isOpenBracket(x))
		{
			stack.push(x);
		}
		else if (isCloseBracket(x))
		{
			if (stack.isEmpty()) return false;
			if (isEqualBracket(stack.get(), x))
			{
				stack.pop();
			}
			else return false;
		}
	}
	if (stack.isEmpty()) return true;
	else return false;
}

bool HaveHigherOrEqualPriority(char op1, char op2)
{
	if (isOpenBracket(op1) || isCloseBracket(op1)) return false;
	if (op1 == '*' || op1 == '/') return true;
	else return (op2 == '+' || op2 == '-');
}



int main()
{
	std::ios::sync_with_stdio(false);

	uint32_t n;
	std::cin >> n;
	std::string expr;

	for (uint32_t i = 0; i < n; i++)
	{
		std::cin >> expr;
		if (!isCorrect(expr))
		{
			std::cout << "BLAD\n";
			continue;
		}

		Queue<Value> queue;
		Stack<Value> stack;

		int32_t sum = 0;
		bool isSumed = false;

		for (auto x : expr)
		{
			if (isdigit(x))
			{
				sum = sum*10 + (static_cast<int32_t>(x) - 48);
				isSumed = true;
				continue;
			}
			else if(isSumed)
			{
				queue.push(Value{ sum,'0' });
				sum ^= sum;
				isSumed = false;
			}

			if (isOpenBracket(x))
			{
				stack.push(Value{ 0,x });
				continue;
			}

			if (isCloseBracket(x))
			{
				Value tmp = stack.get();
				while (!isOpenBracket(tmp.sign))
				{
					queue.push(tmp);
					stack.pop();
					tmp = stack.get();
				} 
				stack.pop();
				continue;
			}

			//is operator
			while ( !stack.isEmpty() && HaveHigherOrEqualPriority(stack.get().sign, x))
			{
				queue.push(stack.get());
				stack.pop();
			}
			stack.push(Value{ 0,x });
		}

		//pop operators
		if (isSumed) queue.push(Value{ sum,'0' });
		while (!stack.isEmpty())
		{
			queue.push(stack.get());
			stack.pop();
		}

		//calculate expression
	/*	while (!queue.isEmpty())
		{
			if (isdigit(queue.get().sign))
			{
				std::cout << queue.get().num<<" ";
			}
			else
			{
				std::cout << queue.get().sign<<" ";
			}
			queue.pop();
		}
		continue;*/

		Stack<double> numbers;

		while (!queue.isEmpty())
		{
			if (isdigit(queue.get().sign))
			{
				numbers.push(queue.get().num);
				queue.pop();
			}
			else
			{
				char sign = queue.get().sign;
				queue.pop();
				double second = numbers.get();
				numbers.pop();
				double first = numbers.get();
				numbers.pop();
				switch (sign)
				{
				case '+':
					first += second;
					break;
				case '-':
					first -= second;
					break;
				case '*':
					first *= second;
					break;
				case '/':
					first /= second;
					break;
				}
				numbers.push(first);
			}
		}
		std::cout << numbers.get() << "\n";
	}

	return 0;
}

template <typename T>
void Stack<T>::push(T value)
{
	Element* elem = new Element;
	elem->value = value;
	elem->next = top;
	top = elem;
}

template <typename T>
T & Stack<T>::get()
{
	return top->value;
}

template <typename T>
void Stack<T>::pop()
{
	Element* tmp = top->next;
	delete top;
	top = tmp;
}

template<typename T>
Stack<T>::Stack()
{
	top = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
	while (!isEmpty()) pop();
}

template <typename T>
void Queue<T>::push(T value)
{
	Element* elem = new Element;
	elem->value = value;
	if (head == nullptr)
	{
		head = elem;
		tail = elem;
		return;
	}
	tail->next = elem;
	tail = elem;
}

template <typename T>
T & Queue<T>::get()
{
	return head->value;
}

template <typename T>
void Queue<T>::pop()
{
	Element* tmp = head;
	head = head->next;
	delete tmp;
	if (head == nullptr) tail = nullptr;
}

template<typename T>
Queue<T>::Queue()
{
	head = nullptr;
	tail = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
	while (!isEmpty()) pop();
}
