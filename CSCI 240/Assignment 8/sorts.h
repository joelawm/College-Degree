#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
//using std::string;
//using std::vector;

//Prototypes
template <class T>
void buildList(vector<T>&, const char*);

template <class T>
void printList(const vector<T>&, int, int);

template<class T>
bool lessThan(const T&, const T&);

template<class T>
bool greaterThan(const T&, const T&);

//actual functions
//This builds the list and helps sperate it.
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
	T item;
	ifstream inFile;

	//opens the file
	inFile.open(fileName);
	//error check
	if (!inFile)
	{
		cout << "File is locked or is not there.\n";
		exit(-1);
	}
	//This helps grab the file to be read into the database
	inFile >> item;
	while (inFile.eof() == false)
	{
		//add things to vector
		set.push_back(item);
		inFile >> item;

	}
	inFile.close();
}

//Print List Function
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	//int x;
	for (unsigned x = 0; x < set.size(); x++)
	{
		if (x%numPerLine == 0)
		{
			cout << endl;
		}
		cout << setw(itemWidth) << set.at(x) << " ";

	}
}

//Check if the file is less than the other
template <class T>
bool lessThan(const T& item1, const T& item2)
{
	if (item1 < item2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//check if the file i greater thatn the other file, and will return accordingly
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	if (item1 > item2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif 
