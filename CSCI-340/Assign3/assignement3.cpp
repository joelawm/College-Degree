//Joe Meyer
//CSCI 340
#include <iostream>
#include <iomanip>
#include <set>
#include <string>
#include <cctype>
#include <algorithm>

const int NO_ITEMS = 8;
const int ITEM_W = 6;

using namespace std;

//This is the Sieve of Eratosthenes Algorithm it can calculate the prime numbers in a set
void sieve(set < int >& s, const int lower, const int upper)
{
	s.clear();
	for (int i = lower; i <= upper; i++)
	{
		if (i == 1)
		{
			cout << "";
		}
		else
		{
			s.insert(i);
		}
	}
	for (int outer = 2; (outer)*(outer) < upper; outer++)
	{
		for (int inner = (outer) * 2; inner <= upper; inner += outer)
		{
			s.erase(inner);
		}
	}
	return;
}

//This prints all the prime numbers in the group
void print_primes(const set < int >& s, const int lower, const int upper)
{
	int column = 0;
	cout << endl;
	cout << "There are " << s.size() << " prime numbers between " << lower << " and " << upper << ":" << endl;
	set <int>::iterator it;
	for(it = s.begin();it != s.end(); it++)
	{
		cout << setw(ITEM_W) << *it;
		column++;
		if (column%NO_ITEMS == 0)
		{
			cout << endl;
		}
	}
}

//This runs the game and asks for the upper and lower bound
void run_game(set<int>& s)
{
	int lower, upper;
	string answer = "yes";
	while (answer == "yes")
	{
			lower = upper = 0;
			cout << "Please input lower bound and upper bound and hit enter (e.g. 10 100): " << endl;
			cin >> lower;
			cin >> upper;
			cin.clear();
			//cin.ignore(256, '\n');
			while (lower <= upper)
			{
				sieve(s, lower, upper);

				print_primes(s, lower, upper);
				break;
			}
			cout << "\nDo you want to continue or not? Please answer yes or no and hit enter: " << endl;
			cin >> answer;
			for (unsigned int i = 0; i < answer.length(); ++i)
			{
				answer[i] = tolower(answer[i]);
			}
	}
	return;
}

//This is the main that essentailly starts everything
int main() 
{
	set<int> s;
	run_game(s);
	return 0;
}