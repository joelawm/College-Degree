#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

//*****************************************************************
// FILE:      Complex.h
// AUTHOR:    Joe Meyer
// LOGON ID:  z1788150
// DUE DATE:  10/18/17
// 
// PURPOSE:  Sets all the info need to make stack methods
//*****************************************************************

class Stack
  {
  		// Data members and method prototypes
  		//Data Memebers for the assingment
  		int* stackArrayPointer;
  		size_t stackCapacity;
  		size_t stackSize;
  		
		//Method Prototypes for the assignment
		public:
           	Stack();
           	~Stack();
           	Stack(const Stack&);
           	Stack& operator=(const Stack&);
           	friend ostream& operator<<(ostream&, const Stack&);
           	void clear();
           	size_t size() const;
           	size_t capacity() const;
           	bool empty() const;
           	int top() const;
           	void push(int);
           	void pop();
           	void reserve(size_t);
           	int operator[](size_t) const;
           	int& operator[](size_t);
           	bool operator==(const Stack&) const;

  };
#endif
