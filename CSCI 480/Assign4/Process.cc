#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Process.h"

//constructor
Process::Process(char* name, char* priority, char* arrival)
{
	//start the process scheduling
	this->ProcessName = strdup(name);
	this->Priority = atoi(priority);
	this->ArrivalTime = atoi(arrival);
}

//constructors
Process::Process(){}

Priorityqueue::Priorityqueue(){}

Queue::Queue(){}

//pop to remove a a element from the queue
Process* Priorityqueue::pop()
{
	//check the length
	if (length > 0)
	{
		//check the length of the first element
		Process* out = this->first->value;
		this->first = this->first->next;
		this->length--;
		return out;
	}
	return NULL;
}

//push the element to the next posotion
void Priorityqueue::push(Process* p)
{
	//check the lengtht of the queue
	if(this->length > 0)
	{
		//add one to the length
		this->length++;
		queueO* pre;
		queueO* point = this->first;

		//if the porority is less than priprotiy max
		if(point->value->Priority > p->Priority)
		{
			//start a new queue
			this->first = new queueO(p, this->first);
			return;
		}

		//checking if the point is next with new ptr
		pre = point;
		//cehcking for next
		point = point->next;

		//while the pointer does not equal null the move on to the next value
		while(point != NULL)
		{
			//check to see if it has priorty
			if(point->value->Priority > p->Priority)
			{
				//check to see if the queue is next
				pre->next = new queueO(p, point);
				//reutrn if yes
				return;
			}

			//check the next pre point
			pre = point;
			point = point->next;
		}

		//next for the element check
		pre->next = new queueO(p, NULL);
	}

	//if length isnt long enough then add this
	else
	{
		//move to the next
		this->first = new queueO(p, NULL);
		//move last to first
		this->last = this->first;
		//add one to the element
		this->length++;
	}
}

//remove the element from the overall list
Process* Queue::pop()
{
	//chechk the length
	if (length > 0)
	{
		//make sure the firsr tvalue is preloaded
		Process* out = this->first->value;

		//move first to next
		this->first = this->first->next;

		//subtract one from the element
		this->length--;
		//return the output
		return out;
	}

	//return nothing
	return NULL;
}

//Push the element to the next spot of the list of thiungs to push
void Queue::push(Process* p)
{
	//check the length again
	if(this->length > 0)
	{
		//make sure the priority queue is the same length
		this->last->next = new queueO(p, NULL);
		//last to next
		this->last = this->last->next;
		//add one to length
		length++;
	}

	//check the if statemenet
	else
	{
		//first to the next element
		this->first = new queueO(p, NULL);
		//last element moved to the nexts
		this->last = this->first;
		//add on the to length
		length++;
	}
}
