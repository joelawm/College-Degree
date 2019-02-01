#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

//*****************************************************************
// FILE:      Queue.h
// AUTHOR:    Joe Meyer
// LOGON ID:  z1788150
// DUE DATE:  10/18/17
// 
// PURPOSE:  Sets all the info need to make stack methods
//*****************************************************************

template <class T>
class Queue;

template <class T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& = T(), Node<T>* next = NULL);
};
 
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
{
	data = newData;
	next = newNext;
}

template <class T> std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue
  {
		public:
			// Data members and method prototypes
	  		//Data Memebers for the assingment
	  		int* queueArrayPointer;
	  		size_t queueCapacity;
	  		size_t queueSize;
	  		int queueFront;
	  		int queueBack;
	  		
	  		//Method Prototypes for the assignment
           	Queue();
           	~Queue();
           	Queue(const Queue&);
           	Queue<T>& operator=(const Queue<T>&);
           	template <class U> friend std::ostream& operator<<(std::ostream&, const Queue<T>&);
           	void clear();
           	size_t size() const;
           	size_t capacity() const;
           	bool empty() const;
           	Queue<T>& front() const;
           	Queue<T>& back() const;
           	void push(int);
           	void pop();
           	void reserve(size_t);
           	int operator[](size_t) const;
           	int& operator[](size_t);
           	bool operator==(const Queue&) const;

  };


//Constructor
//This sets the Stack size, capacity and stackarraypointer to 0/null
template <class T>
Queue<T>::Queue()
{
	//setting varaible
	queueCapacity = 0;
	queueSize = 0;
	queueArrayPointer = NULL;
	queueFront = 0;
	queueBack = queueCapacity - 1;
}

//this deletes the current array and makes it null
template<class T>
Queue<T>::~Queue()
{
	delete[] queueArrayPointer;
}

//this compares the size and capacity and makes it even
template<class T>
Queue<T>::Queue(const Queue& other)
{
	size_t i;
	
	//making the variables equal eachother
	queueCapacity = other.queueCapacity;
	queueSize = other.queueSize;
	
	if(queueCapacity == 0)
	{
		queueArrayPointer = NULL;
	}
	else
	{
		queueArrayPointer = new int[queueCapacity];
	}
	
	for(i = 0; i < queueSize ;i++)
	{
		//making all variables equal
		queueArrayPointer[i]= other.queueArrayPointer[i];
	}
}

//this redeifnes the operator to making evverything be equal to eachother
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	size_t i;
	
	if(this != &other)
	{
		//redeine the array
		delete[] queueArrayPointer;
		queueCapacity = other.queueCapacity;
		queueSize = other.queueSize;
		
		if(queueCapacity == 0)
		{
			queueArrayPointer = NULL;
		}
		else
		{
			queueArrayPointer = new int [queueCapacity];
		}
		
		for(i = 0; i < queueSize ;i++)
		{
			//same as before making variables eaqual
			queueArrayPointer[i]= other.queueArrayPointer[i];	
		}
	}
	//return the array
	return *this;	
}

//redefine the operator and making the ouput section
template <class T>
ostream& operator<<(ostream& lhs, const Queue<T>& rhs)
{
    size_t i, current;
	for (current = rhs.queueFront, i = 0; i < rhs.queueSize; i++)
	{
		lhs << rhs.queueArrayPointer[current] << ' ';
		current = (current + 1) % rhs.queueCapacity;
		//return the ostream obj
		return lhs;
	}
}

//clears out the stack size for recounting
template<class T>
void Queue<T>::clear()
{
	queueSize = 0;
	queueFront = 0;
	queueBack = queueCapacity - 1;
}

//Returns the stack size to main to be used
template<class T>
size_t Queue<T>::size() const
{
	return queueSize;
}

//Returns the cpacity of the stack to main
template<class T>
size_t Queue<T>::capacity() const
{
	return queueCapacity;
}

//Returns wether the size is 0 or not
template<class T>
bool Queue<T>::empty() const
{
	if (queueSize == 0)
	{
		return true;
	}
	 
	else
        {
		return false;
	}

}

template <class T>
Queue<T>& Queue<T>::front() const
{
	if(empty())
	{
		throw new underflow_error("Underflow Error");
	}
	return queueArrayPointer[queueFront];
}

template <class T>
Queue<T>& Queue<T>::back() const
{
	if (empty())
	{
		throw new underflow_error("Underflow Error!");
	}
	return queueArrayPointer[queueBack];
}

template<class T>
void Queue<T>::push(int val)
{
	//check if theyere full
	if(queueSize == queueCapacity)
	{
		//call reserve to make room
		reserve(queueSize + 1);
	}
	else if(queueCapacity == 0)
	{
		reserve(1);
	}
	else
	{
		reserve(queueCapacity*2);
	}
	queueArrayPointer[queueSize] = val;
	queueSize++;
}

//ubtract one when caliing the pop funtion
template<class T>
void Queue<T>::pop()
{
	queueSize--;
}

template<class T>
//this function essentially takes a temp point and makes the equal while also comparing them in a seperate fucntion. its basically reserving the data
void Queue<T>::reserve(size_t n)
{
	size_t i;
	
	if(n < queueSize || n == queueCapacity)
	{
		return;
	}
	queueCapacity = n;
	//Setting the temp pointer
	int* tempPointer = new int[queueCapacity];
	
	if(queueCapacity == 0)
	{
		tempPointer = NULL;
	}
	else
	{
		for(i = 0; i < queueSize ;i++)
		{
			tempPointer[i] = queueArrayPointer[i];
		}
		delete[] queueArrayPointer;
		queueArrayPointer = tempPointer;
	}
}
