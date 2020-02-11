////////////////////////////////////////////
//
// Name: Joe Meyer
// Class: 480
// Date: 10/12/19
// Example: This is a example of proirty scehudling
//
/////////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Process.h"

//function prototypes
void output(Process*, int);

//The basic start to the program
int main() {
	//Constant Variables
	const int AT_ONCE = 5;
	const int MAX_TIME = 500;
	const int QUEUE_SIZE = 20;
	const int HOW_OFTEN = 25;
	const int ARRAY_SIZE = 10;

	//variables
	int timeproc = 0;
	int idle = 0;
	Process* Active = NULL;
	Process* IActive = NULL;
	Process* OActive = NULL;
	Queue* Entry = new Queue();
	Priorityqueue* Ready = new Priorityqueue();
	Priorityqueue* Input = new Priorityqueue();
	Priorityqueue* Output = new Priorityqueue();
	int Timer = 0;
	char temp;
	char* buffer = new char[500];
	int i = 0;
	int pidC = 100;
	bool com = false;
	Process* p = NULL;

	//file to check if its open
	FILE *fp;
	fp = fopen("./data4.txt", "r");

	//read to the end of the file and keep chechkig for new element
	while((temp = fgetc(fp)) != EOF)
	{

		//make sure the file isnt tmeportat
		if(temp == '\n')
		{
			//make sure the file is new
			com = !com;
			//buffer of the index
			buffer[i+1] = '\0';
			i = 0;

			//make sure the file is open
			if (com)
			{
				//a name bugger
				int aName = strchr(buffer, ' ') - buffer;
				//buffer move
				buffer[aName] = '\0';
				//alpha more primray
				int alpha = strchr(&buffer[aName+1], ' ') - buffer;
				//check the primary buffer for aplha
				buffer[alpha] = '\0';
				//create the new process after done
				p = new Process(buffer, &buffer[aName + 2], &buffer[alpha + 2]);
			}
			//if not open the open it
			else
			{
				//variables
				char action = NULL;
				int index = 0;

				//start of the do while statment
				do
				{
					//cehck the buffer to the index on a zero
					buffer[index+5] = '\0';

					//check the action of the element
					action = buffer[index];

					//make sure the history is accurate
					p->history[index/8] = new historyO(action, atoi(&buffer[index+1]));

					//add 8 to the index
					index += 8;

				}
				while (action != 'N');

				//add one to the pidc
				pidC ++;

				//processid
				p->ProcessID = pidC;
				//push the entry
				Entry->push(p);
			}
			//
			if(strcmp(p->ProcessName, "STOPHERE") == 0 )
				break;
		}
		else
		{
			//cehck thte buffer temp
			buffer[i] = temp;
			i++;
		}
	}
	fclose(fp);

	//start of the output for a priority scehduling device
	std::cerr << "\nSimulation of Priority Scheduling\n\n";

	//for all the time make sure it doesnt go back the max allocated time
	for(;Timer < MAX_TIME; Timer++)
	{
		//active and check null
		if(Active == NULL && IActive == NULL && OActive == NULL)
		{
			//check idle time
			idle++;
		}

		//check if null
		if(Active != NULL)
		{
			//check if the value of subtracting one
			Active->history[Active->sub]->value--;
			//cputototal plus one
			Active->CPUTotal++;

			//check if eaul to 0
			if(Active->history[Active->sub]->value == 0)
			{
				//active sub move
				Active->sub++;

				//check if active is i
				if(Active->history[Active->sub]->type == 'I')
				{
					//push to the next
					Input->push(Active);
					Active = NULL;
				}

				//check if O
				else if(Active->history[Active->sub]->type == 'O')
				{
					//push the active
					Output->push(Active);
					Active = NULL;
				}

				//check if N
				else if(Active->history[Active->sub]->type == 'N')
				{
					//output the active and timer
					output(Active, Timer);

					//add one
					timeproc++;
					Active = NULL;
				}
			}
		}

		//ready is bigger than 0
		else if(Ready->length > 0)
		{
			//pop the end element
			Active = Ready->pop();
			//add one
			Active->CPUCount++;
			//pointer point to first
			queueO* ptr = Ready->first;

			//make sure the ptr isnt null
			while(ptr != NULL)
			{
				//wait add one
				ptr->value->wait++;
				//next ptr
				ptr = ptr->next;
			}
		}

		//check if it is active adn not null
		if(IActive != NULL)
		{
			//cehck the value greater than one and subtract one
			IActive->history[IActive->sub]->value--;

			//add one to ttoal
			IActive->ITotal++;

			//move the total to 0
			if(IActive->history[IActive->sub]->value == 0)
			{
				// sub one form total
				IActive->sub++;

				//check if C
				if(IActive->history[IActive->sub]->type == 'C')
				{
					//push the active
					Ready->push(IActive);
					//null it out
					IActive = NULL;
				}

				//check if O
				else if(IActive->history[IActive->sub]->type == 'O')
				{
					//push to output
					Output->push(IActive);
					IActive = NULL;
				}

				//check if N
				else if(IActive->history[IActive->sub]->type == 'N')
				{
					//output the last statment
					output(IActive, Timer);
					timeproc++;
					//null it out
					IActive = NULL;
				}
			}
		}

		//check if greater than length 0
		else if(Input->length > 0)
		{
			//pop the amount done
			IActive = Input->pop();
			//add one
			IActive->ICount++;
			//move the ptr
			queueO* ptr = Input->first;

			//check if null
			while(ptr != NULL)
			{
				//add one
				ptr->value->wait++;
				ptr = ptr->next;
			}
		}

		//check if O active is greater
		if(OActive != NULL)
		{
			//sub one
			OActive->history[OActive->sub]->value--;
			//ative
			OActive->OTotal++;
			if(OActive->history[OActive->sub]->value == 0) {
				OActive->sub++;
				//check for I
				if(OActive->history[OActive->sub]->type == 'I')
				{
					//push active
					Input->push(OActive);
					Active = NULL;
				}
				//check for C
				else if(OActive->history[OActive->sub]->type == 'C')
				{
					//push the ready
					Ready->push(OActive);
					OActive = NULL;
				}
				//check for N
				else if(OActive->history[OActive->sub]->type == 'N')
				{
					output(OActive, Timer);
					timeproc++;
					OActive = NULL;
				}
			}
		}

		//Makesure the output length is the right size
		else if(Output->length > 0)
		{
			//if it is the pop the element
			OActive = Output->pop();
			//count add to one
			OActive->OCount++;

			//output the first ptr
			queueO* ptr = Output->first;
			//check to make sure the while ptr
			while(ptr != NULL)
			{
				//wait add one
				ptr->value->wait++;
				//ptr point to next
				ptr = ptr->next;
			}
		}

		//ptr to the ready first
		queueO* ptrr = Ready->first;

		//ptr not null
		while(ptrr != NULL)
		{
			//value to wait
			ptrr->value->wait++;
			//ptr to equal next
			ptrr = ptrr->next;
		}

		//move ptrr to input to first
		ptrr = Input->first;

		while (Ready->length < AT_ONCE && Entry->first != NULL && Entry->first->value->ArrivalTime == Timer)
		{
			//output the process for entry queue
			std::cerr << "Process " << Entry->first->value->ProcessID << " moved from the Entry Queue into the Ready Queue at time " << Timer << "\n\n";
			//pop the last element
			Process* t = Entry->pop();
			//push to the ready queue
			Ready->push(t);
		}

		//if the timer is how often
		if(Timer% HOW_OFTEN == 0)
		{

			//stadnard output for the timer
			std::cerr << "\nStatus at time " << Timer << '\n';

			if(Active != NULL)
			{
				//check if active
				std::cerr << "Active is " << Active->ProcessID << '\n';
			}
			else
			{
				//not active
				std::cerr << "Active is 0\n";
			}

			if(IActive != NULL)
			{
				//is active
				std::cerr << "IActive is " << IActive->ProcessID << '\n';
			}
			else
			{
				std::cerr << "IActive is 0\n";
			}
			//print output process
			if(OActive != NULL)
			{
				std::cerr << "OActive is " << OActive->ProcessID << '\n';
			}
			else
			{
				//o is active
				std::cerr << "OActve is 0\n";
			}

			std::cerr << "Contents of the Entry Queue:\n";
			queueO* ptrE = Entry->first;

			//while the ptr is not empty then search the priority
			while (ptrE != NULL)
			{
				//output for the priorty queue
				std::cerr << ptrE->value->ProcessID << " Priotiry = " << ptrE->value->Priority << " ariving at time = " << ptrE->value->ArrivalTime << '\n';
				//ptr to point to the next
				ptrE = ptrE->next;
			}

			std::cerr << "Contents of the Ready Queue:\n";

			//cehck if the ptr is null
			queueO* ptr = Ready->first;
			if(ptr == NULL)
			{
				std::cerr << "(Empty)";
			}

			while (ptr != NULL)
			{
				std::cerr << ptr->value->ProcessID << '(' << ptr->value->Priority << ')' << "     ";
				ptr = ptr->next;
			}

			//output the input queue header
			std::cerr << "\nContents of the Input Queue:\n";
			//ptr to point first
			ptr = Input->first;

			//cehck if the ptr is null
			if(ptr == NULL)
			{
				//output empty
				std::cerr << "(Empty)";
			}

			//while ptr isnt null
			while (ptr != NULL)
			{
				//output for the program
				std::cerr << ptr->value->ProcessID << '(' << ptr->value->Priority << ')' << "     ";
				//move ptr to next
				ptr = ptr->next;
			}

			//outptu for content queue header
			std::cerr << "\nContents of the Output Queue:\n";
			//check the output first
			ptr = Output->first;

			//cehck if the ptr is null
			if(ptr == NULL)
			{
				std::cerr << "(Empty)";
			}

			//Make sure the pointer isnt null
			while (ptr != NULL)
			{
				//ouput
				std::cerr << ptr->value->ProcessID << '(' <<  ptr->value->Priority << ')' << "     ";
				//move on to the next point
				ptr = ptr->next;
			}
			//check the output
			std::cerr << "\n\n";
		}

		//
		if(Entry->length == 0 && Ready->length == 0 && Input->length == 0 && Output->length == 0 && Active == NULL && IActive == NULL && OActive == NULL)
		{

			///basic standard output of the queue
			std::cerr << "The run has ended.\n";
			std::cerr << "The final value of the timer was:  " << Timer << '\n';
			std::cerr << "The amount of time spent idle was: " << idle << '\n';
			std::cerr << "Number of terminated processes =   " << timeproc << '\n';

			//check the active status for each element
			if(Active != NULL)
			{
				//is active
				std::cerr << "Active is " << Active->ProcessID << '\n';
			}
			else
			{
				//is active
				std::cerr << "Active is 0\n";
			}


          	if(IActive != NULL)
			{
				//i is active
				std::cerr << "IActive is " << IActive->ProcessID << '\n';
			}
			else
			{
				//check i is active
				std::cerr << "IActive is 0\n";
			}


			if(OActive != NULL)
			{
				//check if output is active
				std::cerr << "OActive is " << OActive->ProcessID << '\n';
			}
			else
			{
				//check if output is active
				std::cerr << "OActive is 0\n";
			}
			//end

			//check the end for the second basic output
			std::cerr << "Contents of the Entry Queue:\n";
			queueO* ptrE = Entry->first;

			//first check for the ptr
			while (ptrE != NULL)
			{
				//end process amount
				std::cerr << ptrE->value->ProcessID << " Priotiry = " << ptrE->value->Priority << " ariving at time = " << ptrE->value->ArrivalTime << '\n';
				ptrE = ptrE->next;
			}

			//check the contents of the ready queue
			std::cerr << "Contents of the Ready Queue:\n";
			//ptr to be ready
			queueO* ptr = Ready->first;

			//cehck if the ptr is null
			if(ptr == NULL)
			{
				std::cerr << "(Empty)";
			}

			//check to make sure its not empty again
			while (ptr != NULL)
			{
				//output
				std::cerr << ptr->value->ProcessID << '(' << ptr->value->Priority << ')' << "     ";
				//move on to the next
				ptr = ptr->next;
			}

			//check the output
			std::cerr << "\nContents of the Input Queue:\n";
			//make sure the ptr is pointing first
			ptr = Input->first;

			//cehck if the ptr is null
			if(ptr == NULL)
			{
				//check to make sure its empty
				std::cerr << "(Empty)";
			}

			//make sure the object isnt null
			while (ptr != NULL)
			{
				//output
				std::cerr << ptr->value->ProcessID << '(' << ptr->value->Priority << ')' << "     ";

				//go to the next element
				ptr = ptr->next;
			}
			//output
			std::cerr << "\nContents of the Output Queue:\n";

			//check the output first
			ptr = Output->first;

			//cehck if the ptr is null
			if(ptr == NULL)
			{
				//output empty
				std::cerr << "(Empty)";
			}

			while (ptr != NULL)
			{
				//next output
				std::cerr << ptr->value->ProcessID << '(' <<  ptr->value->Priority << ')' << "     ";
				//ptr equal to next
				ptr = ptr->next;
			}
			//end the line
			break;
		}
	}
	//reutrn 0 at the end of the program
	return 0;
}

////////////////////////////////////////////////////
//output for the end of a process to display results
////////////////////////////////////////////////////
void output(Process* p, int time)
{
	std::cerr << "A process has terminated." << '\n';
	std::cerr << "Process ID:         " << p->ProcessID << '\n';
     std::cerr << "Name:               " << p->ProcessName << '\n';
     std::cerr << "Priority:           " << p->Priority << '\n';
     std::cerr << "Started at time     " << p->ArrivalTime  << " and ended at time " << time << '\n';
     std::cerr << "Total CPU time =    " << p->CPUTotal << " in " << p->CPUCount << " CPU bursts" << '\n';
     std::cerr << "Total Input time =  " << p->ITotal << " in " << p->ICount << " Input bursts" << '\n';
     std::cerr << "Total Output time = " << p->OTotal << " in " << p->OCount << " Output bursts" << '\n';
     std::cerr << "Time spent waiting: " << p->wait << "\n\n";
}
