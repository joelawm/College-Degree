#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

////////////////////////////////////////
//
// By Joe Meyer
//
// Assign 3
//
// Fucntion: This is to mimic a shell that could be used in a program using pipe, fork and dup.
//
////////////////////////////////////////
int main(void) {
	//Variables
	int argNum = 32;
	char buf[1024];
	int pid;
	int status;

	//output Message
	printf("480shell>");

	//The main loop for the program to run
	while (fgets(buf,1024,stdin) != NULL)
	{
		//Variables to be reset each run
		buf[strlen(buf) -1] = '\0';
		char* com[argNum];
		com[0] = strtok(buf, " ");
		int lastIndex = 0;

		//Seperate the words into one string
		for(int i = 1; i < argNum; i ++)
		{
			com[i] = strtok(NULL, " ");
			if(com[i] == NULL)
			{
				lastIndex = i - 1;
				com[i] = NULL;
				break;
			}
		}

		//Check if the user wants to exit the current program
		if(strcmp(com[0], "q") == 0 || strcmp(com[0], "quit") == 0)
		{
			exit(1);
		}

		//Move throught the pipe and read the various commands being sent through
		int indexOfPipe = -1;
		for(int i = 1; i < argNum; i ++)
		{
			if(com[i] != NULL)
			{
				if(strcmp(com[i], "||") == 0)
				{
					indexOfPipe = i;
					com[i] = NULL;
				}
			}
			else
			{
				break;
			}
		}
		//Variables
		int pipeA[2];
		int pipeB[2];

		//pipe the data through the program to the various program
		if(indexOfPipe > 0)
		{
			pipe(pipeA);
			pipe(pipeB);

			//Check for a fork error
			if ((pid = fork()) < 0)
			{
				printf("fork error");
			}
			//child
			else if (pid == 0)
			{
				close(1);
				close(pipeB[0]);
				close(pipeA[0]);
				close(pipeA[1]);
				dup2(pipeB[1],1);

				//execute the command
				execvp(com[0], com);
				printf("Not able to execute: %s\n", com[0]);
				exit(127);
			}
			//check for a fork error
			if ((pid = fork()) < 0)
			{
				printf("fork error");
			}
			//child
			else if (pid == 0)
			{
				close(1);
				close(0);
                    close(pipeA[0]);
                    close(pipeB[1]);
				dup2(pipeB[0],0);
				dup2(pipeA[1],1);

				//execute the command
				execvp(&com[indexOfPipe+1][0], &com[indexOfPipe+1]);
				printf("Not able to execute: %s\n", &com[indexOfPipe+1][0]);
				exit(127);
			}

			//Terminate tall the extra pipes
			close(pipeB[0]);
			close(pipeB[1]);
			close(pipeA[1]);
		}
		else
		{
			pipe(pipeA);
			//pipe error checking
			if ((pid = fork()) < 0)
			{
				printf("fork error");
			}
			//child
			else if (pid == 0)
			{
				close(1);
				close(pipeA[0]);
				dup2(pipeA[1],1);

				//execute the commadn
				execvp(com[0], com);
				printf("Not able to execute: %s\n", com[0]);
				exit(127);
			}

			//Terminate the extra pipe
			close(pipeA[1]);
		}

		//pid error
		if ( (pid = waitpid(pid, &status, 0)) < 0)
		{
			printf("waitpid error");
		}

		//variables
		char buff[2];
		buff[1] = '\0';

		//read the next buffer
		while(read(pipeA[0], buff, 1) != 0)
		{
			std::cerr << buff;
		}
		//output
		printf("\n480shell>");
	}
	exit(0);
}
