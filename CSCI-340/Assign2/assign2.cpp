#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;

void genRndNums( vector<int>& v, int seed )
{
	int LOW = 1;
	int HIGH = 100;
	srand(seed);

	for (unsigned int i = 0; i < v.size(); i++)
	{
		v[i] = rand() % (HIGH - LOW + 1)+ LOW;
	}
}

bool linearSearch( const vector<int>& inputVec, int x) 
{
	vector<int>::const_iterator found = find(inputVec.begin(), inputVec.end(), x);
	if (found == inputVec.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool binarySearch( const vector<int>& inputVec, int x) 
{
	if (binary_search(inputVec.begin(), inputVec.end(), x))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int search( const vector<int>& inputVec, const vector<int>& searchVec, bool (*p)( const vector<int>&, int) )
{
	int search = 0;

	for (unsigned int i = 0; i < searchVec.size(); i++)
	{
		if (p(inputVec, searchVec[i] != false))
		{
			search++;
		}
		return search;
	}
}

void sortVector (vector<int>& inputVec)
{
	sort(inputVec.begin(), inputVec.end());
}

void printStat (int totalSucCnt, int vec_size) 
{
	double good = totalSucCnt / vec_size;
	cout << "Successful Searches: " << fixed << setprecision(2) << good << "%";
}

void print_vec( const vector<int>& vec )
{
	int NO_ITEMS = 10;

	for (unsigned int i = 0; i < vec.size(); i++)
	{
		cout << setw(5) << vec[i];
		if (((i + 1) % NO_ITEMS) == 0)
		{
			cout << endl;
		}
	}
}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}


