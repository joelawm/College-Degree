#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//Prototypes
template <class T>
void quicksort(vector<T>&, bool);

template <class T>
void quickSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));

template <class T>
int partition(vector<T>&, int, int, bool (*compare)(const T&, const T&));

//Actual Functions

//This function sends infmations to its self
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	quickSort(set, 0, set.size()-1, compare);
}

//
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotPoint;

   if (start < end)
      {
      pivotPoint = partition(set, start, end, compare);     // Get the pivot point
      quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
      quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
      }
}

//This is the sepearting function
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotIndex, mid;
	T pivotValue;
	
	mid = (start + end) / 2;
	
	//Swap elements start and mid of the vector
	T temp;
	temp = set[start];
	set[start] = set[mid];
	set[mid] = temp;
	
	pivotIndex = start;
	pivotValue = set[start];
	
	for (int scan = start + 1; scan <= end; scan++)
	  {
	  if (compare(set[scan], pivotValue))
	     {
	     	T temp2;
	     	pivotIndex++;
	    	//Swap elements pivotIndex and scan of the vector
	    	temp2 = set[pivotIndex];
		set[pivotIndex] =set[scan]; 
		set[scan] = temp2;
	     }
	  }
	
	//Swap elements start and pivotIndex of the vector
	T temp3;
	temp3 = set[start];
	set[start] = set[pivotIndex];
	set[pivotIndex] = temp3;
	
	return pivotIndex; 
}
#endif 
