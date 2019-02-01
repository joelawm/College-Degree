#ifndef sorts_H
#define sorts_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

template <class T>
class Sorts;

template <class T>
class Sorts
{
	//Data Members
	private:
		// friend declaration for the template function - note the
		// special syntax
	public:
		void buildList(vector<T>&, const char*);
		void printList(const vector<T>&, int, int);
};

//This builds the list and helps sperate it.
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
	T item;
	ifstream inFile;

	//opens the file
	inFile.open(fileName, ios::);
	//error check
	if (!inFile)
	{
		cout << "File is locked or is not there.\n";
	}
	//This helps grab the file to be read into the database
	while (inFile.eof() == false)
	{
		//add things to vector
		set.push_back(item);
	}
	inFile.close();
}

//Print List Function
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	int x;
	for (x = 0; x < set.size(); x++)
	{
		cout << set.at(x) << " ";
	}
}

#endif 