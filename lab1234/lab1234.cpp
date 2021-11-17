#include <iostream>
#include <stdio.h>
using namespace std;

struct StackItem
{
	int* data;
	StackItem* prev = nullptr;
	friend istream& operator >> (istream& is, StackItem& some_data)
	{
		cout << "Enter data: ";
		int any_data;
		is >> any_data;
		some_data.data = &any_data;
		return is;
	}
};

class Stack
{
	StackItem* stack = nullptr;
	int size_of_stack;
public:
	Stack()
	{
		stack = nullptr;
		size_of_stack = 0;
	}
	Stack(int size)
	{
		StackItem* elem;
		size_of_stack = size;
		for (int i = 0; i < size_of_stack; ++i)
		{
			elem = new StackItem;
			int* newdata = new int;
			cout << "Enter: ";
			cin >> *newdata;
			elem->data = newdata;
			elem->prev = stack;
			stack = elem;
		}
	}
	Stack(const Stack& other)
	{
		StackItem* otherelem = other.stack;
		StackItem* elem = stack;
		int* mass = new int[other.size_of_stack];
		for (int i = 0; i < other.size_of_stack; ++i)
		{
			mass[i] = *(otherelem->data);
			otherelem = otherelem->prev;
		}
		for (int i = other.size_of_stack - 1; i >= 0; --i)
		{
			elem = new StackItem;
			int* newdata = new int;
			*newdata = mass[i];
			elem->data = newdata;
			elem->prev = stack;
			stack = elem;
		}
		delete[] mass;
	}
	void push()
	{
		StackItem* elem;
		elem = new StackItem;
		int* newdata = new int;
		cout << "Enter: ";
		cin >> *newdata;
		elem->data = newdata;
		elem->prev = stack;
		stack = elem;
		size_of_stack += size_of_stack;
	}
	int pop()
	{
		StackItem* elem;
		elem = stack;
		int data1 = *elem->data;
		stack = elem->prev;
		delete elem;
		return data1;
		size_of_stack -= 1;
	}
	void Init()
	{
		while (stack != nullptr)
		{
			pop();
		}
	}
	friend void Print(const Stack& some_stack)
	{
		cout << "stack: " << endl;
		StackItem* elem = some_stack.stack;
		while (elem != nullptr)
		{
			cout << *(elem->data) << endl;
			elem = elem->prev;
		}
	}
	Stack& operator=(const Stack& other)
	{
		if (stack != nullptr)
		{
			while (stack != nullptr)
			{
				this->pop();
			}
		}
		StackItem* otherelem = other.stack;
		StackItem* elem = stack;
		int* mass = new int[other.size_of_stack];
		for (int i = 0; i < other.size_of_stack; ++i)
		{
			mass[i] = *(otherelem->data);
			otherelem = otherelem->prev;
		}
		for (int i = other.size_of_stack - 1; i >= 0; --i)
		{
			elem = new StackItem;
			int* newdata = new int;
			*newdata = mass[i];
			elem->data = newdata;
			elem->prev = stack;
			stack = elem;
		}
		delete[] mass;
		return *this;
	}

	Stack& operator<<(int* const some_data)
	{
		StackItem* elem;
		elem = new StackItem;
		elem->data = some_data;
		elem->prev = stack;
		stack = elem;
		size_of_stack += 1;
		return *this;
	}; //поместить данные в стек

	Stack& operator>>(int* const counter)
	{
		if (*counter < size_of_stack)
		{
			for (int i = 0; i < *counter; ++i)
			{
				pop();
			}
		}

		return *this;
	};//извлечь данные из стека

	friend ostream& operator<<(ostream& os, const Stack& my_stack)
	{
		StackItem* elem = my_stack.stack;
		while (elem != nullptr)
		{
			os << *(elem->data) << endl;
			elem = elem->prev;
		}
		return os;
	}

	~Stack()
	{
		while (stack != nullptr)
		{
			pop();
		}
	}
};


int main()
{
	cout << "Kol-vo elementov v stack: ";
	int a;
	cin >> a;
	Stack stack_1(a);
	Print(stack_1);
	//Stack stack_2(stack_1);
	//Print(stack_2);
	//stack_2.push();
	//Print(stack_2);
	//stack_1.pop();
	//Print(stack_1);

	/*Stack stack_2(5);
	Print(stack_2);
	stack_2 = stack_1;
	Print(stack_2);*/

	/*int d = 11;
	stack_1 << &d;
	Print(stack_1);
	int b = 3;
	stack_1 >> &b;
	Print(stack_1);*/
	cout << endl<<endl;

	cout << stack_1;

	StackItem some_data;
	cin >> some_data;
	cout << *(some_data.data) << endl;
	return 0;
}
