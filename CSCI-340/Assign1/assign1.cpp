#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
const int DATA_SIZE = 200;
const int DATA_RANGE = 200;
const int DATA_SEED = 9;
const int SEARCH_SEED = 17;
const int NO_ITEMS = 8;
const int ITEM_W = 4;

//binary Search
//searches through the vector 1 by 1 till it finds the number or doesnt, returning the number
int binary_search(const vector<int>& inputVec, const int x, int& comparisons)
{
	if (binary_search(inputVec.begin(), inputVec.end(), x), comparisons += 1)
	{
		return x;
	}
	else
	{
		return -1;
	}
}

//linear search
//This sreaches by seeing if a element mathces, if it does it returns to spot
int linear_search(const vector<int>& inputVec, const int x, int& comparisons)
{
	for (unsigned int i = 0; i <= inputVec.size(); i++)
	{
		comparisons += 1;
		if (i == inputVec[i])
		{
			return i;
		}
	}
	return -1;
}

//print
//this outputs all the vectors contents before displaying everyhting else
void print_vec(const vector<int>& vec)
{
	for (unsigned int i = 0; i <= vec.size(); i++)
	{
		cout << setw(ITEM_W) << vec[i];
		if ((i % NO_ITEMS) == 2)
		{
			cout << endl;
		}
	}

}

void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, int(*search)(const vector<int>&, const int, int&)) {
	int i, comparison = 0, sum = 0, found = 0;
	int res = 0;
	for (i = 0; i < (int)searchVec.size(); i++) {
		res = search(inputVec, searchVec[i], comparison);
		sum += comparison;
		if (res >= 0)
			found++;
	}
	cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum / (double)searchVec.size() << endl << endl;
}

int random_number() {
	return rand() % DATA_RANGE + 1;
}

int main() {

	// -------- create unique random numbers ------------------//
	vector<int> inputVec(DATA_SIZE);
	srand(DATA_SEED);
	generate(inputVec.begin(), inputVec.end(), random_number);
	sort(inputVec.begin(), inputVec.end());
	vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
	inputVec.resize(it - inputVec.begin());
	random_shuffle(inputVec.begin(), inputVec.end());

	cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << endl;
	print_vec(inputVec);
	cout << endl;

	// -------- create random numbers to be searched ---------//
	vector<int> searchVec(DATA_SIZE / 2);
	srand(SEARCH_SEED);
	generate(searchVec.begin(), searchVec.end(), random_number);

	cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << endl;
	print_vec(searchVec);
	cout << endl;

	cout << "Linear search: ";
	average_comparisons(inputVec, searchVec, linear_search);
	cout << "Binary search: ";
	average_comparisons(inputVec, searchVec, binary_search);

	sort(inputVec.begin(), inputVec.end());
	cout << "------- numbers in data source are now sorted ---------" << endl << endl;
	cout << "Linear search: ";
	average_comparisons(inputVec, searchVec, linear_search);
	cout << "Binary search: ";
	average_comparisons(inputVec, searchVec, binary_search);

	return 0;
}
