#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>

//////////////////////////////////////////
// Programer: Joe Meyer
// Program: Assign 1
//
// Function: To disply the use of fork and 
//////////////////////////////////////////

int main()
{
	//variable save area
	int p_id;
	int p_id2;

	//Original PID and output
	if(p_id != 0)
	{
		std::cerr << "\nI am the original " << getppid();
	}

	//call first fork
	std::cerr << "\nCalling the first fork";

	p_id=fork();

	//output the first output for the fork
	if(p_id==-1)
	{
		std::cerr << "\nThe first fork failed.";
		exit(-1);
	}
	else if(p_id==0)
	{	
		std::cerr << "\nThe child process is " << getpid();
		sleep(2);
		wait(0);
		std::cerr << "\nWere about to exit\n";
		exit(0);
	}
	else
	{
		std::cerr << "\nThe parent process is " << getpid();
		std::cerr << " Our parent is " << getppid();
		//exit(0);
	}
	
	//call the second fork
	if(p_id != 0)
	{
		std::cerr << "\nCalling the second fork";
	}
	p_id2=fork();

	//output for the second fork
	if(p_id2==-1)
	{
		std::cerr << "The second fork failed." << getpid();
		exit(1);
	}
	else if(p_id2==0)
	{
		std::cerr << "\nThe grand child process is " << getpid();
		sleep(2);
		std::cerr << "\nWere about to exit\n";
		exit(0);
	}
	else
	{
		std::cerr << "\nThe parent process " << getpid();
		sleep(2);
		//call ps
		std::cerr << "\nAbout to call ps";
		std::system("ps");
		wait(0);
		std::cerr << "\nWere about to exit\n";
		exit(0);
	}
	return 0;
}