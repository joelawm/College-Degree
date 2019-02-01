#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

template <class T>
struct Node
{
	//Place info here
	T data;
	Node<T>* next;

	Node(const T& = T(), Node<T>* next = nullptr);
};

template <class T>
Node<T>::Node(const T& data, Node<T>* next)
{
	this->data = data;
	this->next = next;
}

// Method definitions for the Node class
// Forward declaration of the Stack template class
template <class T>
class Stack;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

template <class T>
class Stack
{
	//Data Members
	friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);
private:
	Node<T>* stkTop;
	size_t stackSize = 0;
	// friend declaration for the template function - note the
	// special syntax
public:
	Stack();
	~Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	//friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);
	void clear();
	size_t size() const;
	bool empty() const;
	int top() const;
	void push(int);
	void pop();
	void copyList(const Stack<T>&);
};


/* STACK_H */

//Constructor
//This sets the Stack size, capacity and stackarraypointer to 0/null
template <class T>
Stack<T>::Stack()
{
	//setting varaible
	stkTop = nullptr;
	stackSize = 0;
}

//this deletes the current array and makes it null
template<class T>
Stack<T>::~Stack()
{
	clear();
}

//this compares the size and capacity and makes it even
template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
	stackSize = other.stackSize;
	copyList(other);
}

//this redeifnes the operator to making evverything be equal to eachother
template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		//redfine the array
		clear();
		copyList(other);
		stackSize = other.stackSize;
	}
	return *this;
}

//redefine the operator and making the ouput section
template<class T>
ostream& operator<<(ostream& lhs, const Stack<T>& rhs)
{
	Node<T> *p;

	for (p = rhs.stkTop; p != nullptr; p = p->next)
	{
		lhs << p->data << ' ';
	}
	return lhs;

}

//clears out the stack size for recounting
template<class T>
void Stack<T>::clear()
{
	stackSize = 0;
	stkTop = nullptr;
}

//Returns the stack size to main to be used
template<class T>
size_t Stack<T>::size() const
{
	return stackSize;
}

//Returns wether the size is 0 or not
template<class T>
bool Stack<T>::empty() const
{
	if (stackSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	return true;
}

//Return the top part of the array
template <class T>
int Stack<T>::top() const
{
	if (stackSize == 0)
	{
		throw std::underflow_error("You have a underflow Error");
	}
	return stkTop->data;
}

template<class T>
void Stack<T>::push(int val)
{
	Node<T>* newNode = new Node<T>(val, stkTop);
	stkTop = newNode;
	stackSize++;
}

//subtract one when caliing the pop funtion
template<class T>
void Stack<T>::pop()
{
	if (stackSize == 0)
	{
		throw std::underflow_error("You have a underflow Error");
	}
	Node<T>* delNode = stkTop;
	stkTop = stkTop->next;
	delete delNode;
	stackSize--;
}

template<class T>
void Stack<T>::copyList(const Stack<T>& other)
{
	Node<T>* p;
	Node<T>* y;
	Node<T>* z = nullptr;

	for (p = other.stkTop; p != nullptr; p = p->next)
	{
		y = new Node<T>(p->data);
			if (z == nullptr)
			{
				stkTop = y;
			}
			else
			{
				z->next = y;
			}
		z = y;
	}
}
#endif 
