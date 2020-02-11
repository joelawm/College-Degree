////////////////////////////
//
//Name : Joe Meyer
//Date : 102519
//
//Function: Demonstrations of the producer consumer problem.
////////////////////////////
#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

// Constants and globals
#define P_NUMBER       7
#define C_NUMBER       5
#define BUFFER_SIZE    35
#define P_STEPS        5
#define C_STEPS        7
pthread_mutex_t lock;
sem_t NotFull;
sem_t NotEmpty;
std::queue<std::string> widgets;
std::vector<int> arrayqueue;

//This function displays the contents of the queue
void showq(std::queue <std::string> gq)
{
	//temp queue
    std::queue <std::string> g = gq;
    //make sure its empty and run till empty
    while (!g.empty())
    {
	    //print commdand
	   printf(" %s", g.front().c_str());
	   //remove first element
        g.pop();
    }
}

//this inserts a new thread and is lauinched from the producers thread
void Insert(void * threadid)
{
	//variables
	long tid = (long) threadid;
	pthread_mutex_lock(&lock);
	int totalcount = 0;

	//start appending variables
	std::string temp = "P";
	temp += std::to_string(tid);
	temp += "W";
	//itterate
	totalcount = std::count (arrayqueue.begin(), arrayqueue.end(), tid);
	//insert to vector at 0
	arrayqueue.insert(arrayqueue.end(), tid);
	temp += std::to_string(totalcount);
	widgets.push(temp);
	//display message
	printf("\nProducers %li inserted on item. Total is now %lu\n", tid, widgets.size());
	printf("Buffer now contains ");
	//display queue
	showq(widgets);
	pthread_mutex_unlock(&lock);
}

//This produces a insert command to insert a dnew thread if not locked
void * Produce(void * threadid)
{
	for(int i = 0; i < P_STEPS; i ++)
	{
		//check if full
		sem_wait(&NotFull);
		//insert a new thread
		Insert(threadid);
		//wait to post if not empty
		sem_post(&NotEmpty);
		sleep(1);
	}
	pthread_exit(NULL);
}

//this removes a thread and consumes it
void Remove(void * threadid)
{
	long tid = (long) threadid;
	//lock mutex
	pthread_mutex_lock(&lock);
	widgets.pop();
	printf("\nConsumers %li removed one item. Total is now %lu\n", tid, widgets.size());
	//erase the element found at 0
	arrayqueue.erase(arrayqueue.begin());
	if(widgets.size() == 0)
	{
		printf("Buffer is now empty");
	}
	else
	{
		printf("Buffer now contains ");
	}
	//show the queue again
	showq(widgets);
	pthread_mutex_unlock(&lock);// End of cpu lock
}

//this consumes one of the threads and creates a thread id
void * Consume(void * threadid)
{
	//check for the c steps
	for(int i = 0; i < C_STEPS; i ++) {
		sem_wait(&NotEmpty);
		//remove and consume
		Remove(threadid);
		sem_post(&NotFull);
		//sleep till thread is close
		sleep(1);
	}

	//exit the thread
	pthread_exit(NULL);
}

//main function that runs the producer and cinsumer problem
int main ()
{
	//Beguinning Message
	printf("\nSimulation of Producers and Consumers\n");
	printf("\n\nThe semaphores and mutex have been initialized\n");

	//check buffer size
	sem_init(&NotFull, 0, BUFFER_SIZE);
	sem_init(&NotEmpty, 0, 0);

	//make sure the mutex isnt locked down
	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n pthread mutex init failed\n");
		return 1;
	}

	//variable for the p and c number to find total threads
	int total_threads = P_NUMBER + C_NUMBER;
	//find total numbers of threads
	pthread_t threads[total_threads];
	int tempVar;

	//find temp thread
	for(long i = 0; i < P_NUMBER; i++)
	{
		tempVar = pthread_create(&threads[i], NULL, Produce, (void *) i);
		if (tempVar)
		{
			//exit if done
			exit(-1);
		}
	}

	//Find the total number of treads
	for(long i = P_NUMBER; i < total_threads; i++) {
		tempVar = pthread_create(&threads[i], NULL, Consume, (void *) (i - P_NUMBER));
		if (tempVar)
		{
			//exit if done
			exit(-1);
		}
	}

	//variable temp
	char *join;

	//check for the total number of thread
	for(int i = 0; i < total_threads; i ++)
	{
		pthread_join(threads[i], (void**)&join);
	}

	//print the end message
	printf("\n\nAll the producer and consumer threads have been closed.\n");
	printf("\n\nThe semphores and mutex have been deleted.\n");
	//lock the thread
	pthread_mutex_destroy(&lock);

	//check if actually still full
	sem_destroy(&NotFull);
	sem_destroy(&NotEmpty);
}
