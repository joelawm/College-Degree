/***************************************************************
CSCI 241         Program 5    Fall 2017
Programmer: Joe Meyer
Date Due: 10/31/17
Purpose: 
***************************************************************/

#include <iomanip>
#include "Stack.h"

//Constructor
//This sets the Stack size, capacity and stackarraypointer to 0/null
Stack::Stack()
{
	//setting varaible
	stackCapacity = 0;
	stackSize = 0;
	stackArrayPointer = nullptr;
}

//this deletes the current array and makes it null
Stack::~Stack()
{
	delete[] stackArrayPointer;
}

//this compares the size and capacity and makes it even
Stack::Stack(const Stack& other)
{
	size_t i;
	
	//making the variables equal eachother
	stackCapacity = other.stackCapacity;
	stackSize = other.stackSize;
	
	
	if(stackCapacity == 0)
	{
		stackArrayPointer = nullptr;
	}
	else
	{
		stackArrayPointer = new int[stackCapacity];
	}
	
	for(i = 0; i < stackSize ;i++)
	{
		//making all variables equal
		stackArrayPointer[i]= other.stackArrayPointer[i];
	}
}

//this redeifnes the operator to making evverything be equal to eachother
Stack& Stack::operator=(const Stack& other)
{
	size_t i;
	
	if(this != &other)
	{
		//redeine the array
		delete[] stackArrayPointer;
		stackCapacity = other.stackCapacity;
		stackSize = other.stackSize;
		
		if(stackCapacity == 0)
		{
			stackArrayPointer = nullptr;
		}
		else
		{
			stackArrayPointer = new int [stackCapacity];
		}
		
		for(i = 0; i < stackSize ;i++)
		{
			//same as before making variables eaqual
			stackArrayPointer[i]= other.stackArrayPointer[i];	
		}
	}
	//return the array
	return *this;	
}

//redefine the operator and making the ouput section
ostream& operator<<(ostream& lhs, const Stack& rhs)
{
        size_t i;
	for (i = 0; i < rhs.stackSize; i++)
	
		lhs << rhs.stackArrayPointer[i] << ' ';
		//return the ostream obj
		return lhs;
	
}

//clears out the stack size for recounting
void Stack::clear()
{
	stackSize = 0;
}

//Returns the stack size to main to be used
size_t Stack::size() const
{
	return stackSize;
}

//Returns the cpacity of the stack to main
size_t Stack::capacity() const
{
	return stackCapacity;
}

//Returns wether the size is 0 or not
bool Stack::empty() const
{
	if (stackSize == 0)
	{
		return true;
	}
	 
	else
        {
		return false;
	}

}

//Return the top part of the array
int Stack::top() const
{
	return stackArrayPointer[stackSize-1];
}

void Stack::push(int val)
{
	//check if theyere full
	if(stackSize == stackCapacity)
	{
		//call reserve to make room
		reserve(stackSize + 1);
	}
	else if(stackCapacity == 0)
	{
		reserve(1);
	}
	else
	{
		reserve(stackCapacity*2);
	}
	stackArrayPointer[stackSize] = val;
	stackSize++;
}

//ubtract one when caliing the pop funtion
void Stack::pop()
{
	stackSize--;
}

//this function essentially takes a temp point and makes the equal while also comparing them in a seperate fucntion. its basically reserving the data
void Stack::reserve(size_t n)
{
	size_t i;
	//int tempArray[];
	if(n < stackSize || n == stackCapacity)
	{
		return;
	}
	stackCapacity=n;
	//Setting the temp pointer
	int* tempPointer = new int[stackCapacity];
	
	if(stackCapacity == 0)
	{
		tempPointer = nullptr;
	}
	else
	{
		for(i = 0; i < stackSize ;i++)
		{
			tempPointer[i] = stackArrayPointer[i];
		}
		delete[] stackArrayPointer;
		stackArrayPointer = tempPointer;
	}
}

//retunring a const version of the array
int Stack::operator[](size_t n) const
{
	return stackArrayPointer[n];
}

//returning the non const verion of the aray above
int& Stack::operator[](size_t n)
{
	return stackArrayPointer[n];
}

//this is the eualss to funtion and reutrns a bool adter comparing the two arrays
bool Stack::operator==(const Stack& rhs) const
{
	size_t i;
	if(stackSize < rhs.stackSize)
	{
		//will auto return false if not true
		return false;
	}
	else
	{
		for(i=0; i<stackSize; i++)
		{
			//comparision for both arrays
			if(stackArrayPointer[i]==rhs.stackArrayPointer[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
return true;
}
