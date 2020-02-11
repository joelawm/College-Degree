#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <sys/wait.h>

//////////////////////////////////////////
// Programer: Joe Meyer
// Program: Assign 2
//
// Function: To disply the use of fork and pipe.
//////////////////////////////////////////


/////////////////////////////////
//This is the Parent function computing
/////////////////////////////////
void PWork(int* pipeA, int* pipeC)
{
	//varviables
	char buffer[15] = "1";
	char value[15] = "1";
	long int M = 1;
	char stringToConvert[15];
	long int temp;
	bool go = true;


	while (M <= 99999999999)
	{

		if(go)
		{
			//parent output
			std::cerr << "\nParent        Value:  " << M;
			write(pipeA[1], buffer, 15);
			go = false;
		}
		read(pipeC[0], value,15);
		for (int i=0; i < 15; ++i)
		{
			if (value[i] == '\0')
			{
				stringToConvert[i] = value[i];
				break;
			}
			stringToConvert[i] = value[i];
		}
		//parent output
		temp = atol(stringToConvert);
		M = 3 * temp +7;
		std::cerr << "\nParent        Value:  " << M;
		sprintf(buffer,"%ld", M);
		write(pipeA[1],buffer,15);
	}
}

/////////////////////////////////
//This is the Child function for computing
/////////////////////////////////
void CWork(int* pipeA, int* pipeB)
{
	//variables
	char buffer[15];
	char value[15];
	long int M=0;
	char stringToConvert[15];
	long int temp;

	while (M <= 99999999999)
	{
		read(pipeA[0], value,15);
		for (int i=0; i < 15; ++i)
		{
			if (value[i] == '\0')
			{
				stringToConvert[i] = value[i];
				break;
			}
			stringToConvert[i] = value[i];
		}
		temp = atol(stringToConvert);
		M = 2 * temp +5;
		std::cerr << std::setw(15);
		std::cerr << "\nChild         Value:  " << M;
		sprintf(buffer,"%ld", M);
		write(pipeB[1],buffer,15);
	}
}

/////////////////////////////////
//This is the Grandhcild function for computing
/////////////////////////////////
void GWork(int* pipeB, int* pipeC)
{
	//varabiles
	char buffer[15];
	char value[15];
	long int M=0;
	char stringToConvert[15];
	long int temp;

	while (M <= 99999999999)
	{
		read(pipeB[0], value,15);
		for (int i=0; i < 15; ++i)
		{
			if (value[i] == '\0')
			{
				stringToConvert[i] = value[i];
				break;
			}
			stringToConvert[i] = value[i];
		}
		temp = atol(stringToConvert);
		M = 5 * temp +1;
		std::cerr << std::setw(15);
		std::cerr << "\nGrandchild    Value:  " << M;
		sprintf(buffer,"%ld", M);
		write(pipeC[1],buffer,15);
	}
}



/////////////////////////////////
//This is the main function preforming the steps of the program
/////////////////////////////////
int main()
{
	//variable save area
	int p_id;
	int p_id2;
	int pipeA[2];
	int pipeB[2];
	int pipeC[2];

	//call each of the pipes
	pipe(pipeA);
	pipe(pipeB);
	pipe(pipeC);

	//pipe error checking
	if(pipe(pipeA) == -1)
	{
		//error
		std::cerr << "\nPipe A error.";
		exit(-5);
	}

	//pipe error checking
	if(pipe(pipeB) == -1)
	{
		//error
		std::cerr << "\nPipe B error.";
		exit(-5);
	}

	//pipe error checking
	if(pipe(pipeC) == -1)
	{
		//error
		std::cerr << "\nPipe C error.";
		exit(-5);
	}

	//1st forks
	int  originalFork = fork();
	if(p_id==-1)
	{
		std::cerr << "\nThe first fork failed.";
		exit(-5);
	}
	//child
	if ( originalFork == -1)
	{
		std::cerr << "\nThe first fork failed.";
		exit(-5);
	}
	else
	{
		//child process
		if (originalFork == 0 )
		{
			int secondFork = fork();
			if ( secondFork == -1)
			{
				std::cerr << "\nThe second fork failed.";
				exit(-5);
			}
			else
			{
				//This is the grandchild process
				if (secondFork == 0 )
				{
					//Close the unused pipes
					close(pipeB[1]);//close the write side
					close(pipeC[0]);//close the read side
					close(pipeA[0]);
					close(pipeA[1]);
                       	std::cerr << "\nThis is the Grandchild and it is ready to proceed.";
					GWork(pipeB,pipeC);
				}
				//Parent Process
				else
				{
					close(pipeB[0]);//close the read side
					close(pipeA[1]);//close the write side
					close(pipeC[0]);
					close(pipeC[1]);
					std::cerr << "\nThis is the Child and it is ready to proceed.";
					CWork(pipeA,pipeB);
					wait(0);
				}
			}
		}
		else
		{
			close(pipeC[1]);//close the write side
			close(pipeA[0]);//close the read side
			close(pipeB[0]);
			close(pipeB[1]);
			std::cerr << "\nThis is the Parent and it is ready to proceed.";
			PWork(pipeA,pipeC);
			wait(0);
		}
	}
	return 0;
}
