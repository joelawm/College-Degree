/***************************************************************
CSCI 241         Program 6   Fall 2017
Programmer: Joe Meyer
Date Due: 11/9/17
Purpose: 
***************************************************************/

#include <iomanip>
#include <stdexcept>
#include "Queue.h"

template <class T>
//Constructor
//This sets the Stack size, capacity and stackarraypointer to 0/null
Queue<T>::Queue()
{
	//setting varaible
	queueCapacity = 0;
	queueSize = 0;
	queueArrayPointer = nullptr;
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
		queueArrayPointer = nullptr;
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
Queue& Queue::operator=(const Queue& other)
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
			queueArrayPointer = nullptr;
		}
		else
		{
			queueArrayPointer = new int [stackCapacity];
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
ostream& operator<<(ostream& lhs, const Queue& rhs)
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
size_t Queue::size() const
{
	return queueSize;
}

//Returns the cpacity of the stack to main
size_t Queue::capacity() const
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
Queue<T>& Queue<T>::Front()
{
	if(queueArrayPointer.empty)
	{
		throw underflow_error& e;
	}
	return queueFront;
}

Queue<T>& Queue<T>::Back()
{
	if (queueArrayPointer.empty)
	{
		throw underflow_error& e;
	}
	return queueBack;
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
	queueArrayPointer[QueueSize] = val;
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
		tempPointer = nullptr;
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
