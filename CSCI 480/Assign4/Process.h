#ifndef PROCESS
#define PROCESS

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////
//CLASSES AND STRUCTS
////////////////////////////////////////////

//checking throught the history of the object
struct historyO
{
	#define NULL 0
	//variables
	char type = NULL;
	int value = NULL;

	//datata types to use
	historyO(char _type, int _value){ type = _type; value = _value;}
	historyO(){}
};

//process the data with the process daata type
class Process {
        public:
		//Variables
		char* ProcessName = NULL;
		int Priority = -1;
		int ArrivalTime = -1;
		int ProcessID = -1;
		int CPUCount = 0;
		historyO *history[10];
		int sub = 0;
		int CPUTimer = 0;
		int OCount = 0;
		int CPUTotal = 0;
		int ITotal = 0;
		int OTotal = 0;
		int IOTimer = 0;
		int wait = 0;
		int ICount = 0;

		//functions
		Process();
		Process(char*, char*, char*);

};

//the basic stucture for the process
struct queueO
{
	//basic variables
	Process* value = NULL;
	queueO* next;

	//datatypes to use
	queueO(Process* p, queueO* _next){ value=p; next=_next;}
};

//queue class containg basic structure for a queue
class Queue
{
	public:
		//variables
		Queue();
		queueO* first = NULL;
		queueO* last = NULL;
		int length = 0;

		//functions
		Process* pop();
		void push(Process* p);
};

//priority queue class containtng basic information for a proirty queue
class Priorityqueue
{
	public:
		//variables
		Priorityqueue();
		queueO* first = NULL;
		queueO* last = NULL;
		int length = 0;

		//functions
		Process* pop();
		void push(Process* p);
};
#endif
