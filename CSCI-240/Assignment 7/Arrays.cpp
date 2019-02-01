/***************************************************************
CSCI 240         Program 7     Spring 2017

Programmer: Joe Meyer

Section: 1

Date Due: 3/10/17

Purpose: This program performs simple arithmetic calculations and
         displays the results.
***************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//constant variables
const int buildArrayMax = 100;
const int rand_max=32767;
const double LowBo = 0.0;
const double UpBo = 100.0;
const int DPL_max = 7;
const int NOV_min = 20;

//doublerand function
double randDouble()
{
	//variables
	double sumofnum, randomNum;
	
	//the random double
	randomNum = rand();  
	//randomNum = 10 + (rand() % (50 - 10 +1));
	
	//Math Section
	sumofnum = LowBo + (randomNum/(rand_max/(UpBo - LowBo)));
	
	return sumofnum; 
}

//buildArray function
int buildArray(double arrayMain[])
{
	//varibales defined
	int x;	
	double numberOfValues;
	
	//randomnumber generator
	numberOfValues = 20 +(rand() % (100 - 20 +1)); 
	
	//main addition
	for (x=0; x<numberOfValues; x++)
	{
		double sumofnum = randDouble();
		arrayMain[x] = sumofnum;
	}
	
	return numberOfValues;
}

void printArray(double arrayMain[], int numberOfValues)
{
	int i = 0;
	cout << "number of values: " << numberOfValues;
	cout << "\n";
	cout << "Unsorted\n";
	for(int x=0;x<numberOfValues;x++)
	{
		++i;
		cout.precision(5);
		double value = arrayMain[x];
		cout << fixed << value;
		cout << " ";
		
		if (i==7)
		{
			cout << endl;
			i=0;
		}
	}
	cout << "\n\n";	
}

void sortArray(double arrayMain[], int numberOfValues)
{
	cout << "Sorted Numbers" << endl;
	
	//pos_min is short for position of min
	int pos_min;
	double temp;

	for (int i=0; i < numberOfValues-1; i++)
	{
	    pos_min = i;//set pos_min to the current index of array
		
		for (int j=i+1; j < numberOfValues; j++)
		{

		if (arrayMain[j] < arrayMain[pos_min])
                   pos_min=j;
	//pos_min will keep track of the index that min is in, this is needed when a swap happens
		}
		
	//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
            if (pos_min != i)
            {
                 temp = arrayMain[i];
                 arrayMain[i] = arrayMain[pos_min];
                 arrayMain[pos_min] = temp;
            }
	}
	int z =0;
	for(int x=0;x<numberOfValues;x++)
	{
		++z;
		cout.precision(5);
		double value = arrayMain[x];
		cout << fixed << value;
		cout << " ";
		
		if (z==7)
		{
			cout << endl;
			z=0;
		}
	}
}

//MAIN FUNCTION
int main()
{
	srand(time(0));
	double arrayMain[buildArrayMax];
	int stuff = buildArray(arrayMain);
	printArray(arrayMain,stuff);
	sortArray(arrayMain, stuff);
	return 0;
}
