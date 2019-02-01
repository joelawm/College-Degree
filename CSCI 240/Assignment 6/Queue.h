#ifndef Queue_H
#define Queue_H
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

template <class T>
class Queue;

template <class T>
class Queue
  {
  		// Data members and method prototypes
  		//Data Memebers for the assingment
  		int* queueArrayPointer;
  		size_t queueCapacity;
  		size_t queueSize;
  		size_t queueFront;
  		size_t queueBack;
  		
  		
		//Method Prototypes for the assignment
		public:
           	Queue();
           	~Queue();
           	Queue(const Queue&);
           	Queue& operator=(const Queue&);
           	friend ostream& operator<<(ostream&, const Queue&);
           	void clear();
           	size_t size() const;
           	size_t capacity() const;
           	bool empty() const;
           	Queue<T>& Front() const;
           	Queue<T>& Back() const;
           	void push(int);
           	void pop();
           	void reserve(size_t);
           	int operator[](size_t) const;
           	int& operator[](size_t);
           	bool operator==(const Queue&) const;

  };
#endif
