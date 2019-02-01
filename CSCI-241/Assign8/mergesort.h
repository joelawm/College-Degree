#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//Prototypes
template <class T>
void mergeSort(vector<T>&, bool (*compare)(const T&, const T&));

template <class T>
void mergeSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));

template <class T>
void merge(vector<T>&, int, int, int, bool (*compare)(const T&, const T&));

//Actual Functions

//This function sends infmations to its self
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	mergeSort(set, 0, set.size()-1, compare);
}


template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
	int mid;
	
	if (low < high)
	{
		mid = (low + high) / 2;
		
		// Divide and conquer
		
		mergeSort(set, low, mid, compare);
		mergeSort(set, mid+1, high, compare);
		
		// Combine
		merge(set, low, mid, high, compare);
	}
}

template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
   // Create temporary vector to hold merged subvectors
   vector<T> temp(high - low + 1);

   int i = low;      // Subscript for start of left sorted subvector
   int j = mid+1;    // Subscript for start of right sorted subvector
   int k = 0;        // Subscript for start of merged vector

   // While not at the end of either subvector
   while (i <= mid && j <= high)
      {
      if (compare(set[j], set[i]))
         {
			//Copy element j of set into element k of temp
			temp[k]= set[j];
			//Add one to j
			j++;
			//Add one to k
			k++;
         }
      else
         {
			//Copy element i of set into element k of temp
			temp[k] = set[i];
			//Add one to i
			i++;
			//Add one to k
			k++;
         }
      }

   // Copy over any remaining elements of left subvector
   while (i <= mid)
      {
			//Copy element i of set into element k of temp
			temp[k] = set[i];
			//Add one to i
			i++;
			//Add one to k 
			k++;
      }

   // Copy over any remaining elements of right subvector
   while (j <= high)
      {
			//Copy element j of set into element k of temp
			temp[k] = set[j];
			//Add one to j 
			j++;
			//Add one to k
			k++;
      }

   // Copy merged elements back into original vector
   for (i = 0, j = low; j <= high; i++, j++)
   {
   		//Copy element i of temp into element j of set; 
   		set[j] = temp[i];
   }
}
#endif 
