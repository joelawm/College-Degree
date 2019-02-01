/***************************************************************
CSCI 240         Program 4     Spring 2017

Programmer: Joe Meyer

Section: 1

Date Due: 3/3/17

Purpose: 
***************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
	//variables/random number generator
	float amountrand, w1,w2,n, randomnum, amountwon, betnum;
	int numchosen;
	string proc, letterchosen, letterrand, outputletter;
	bool b1 = true;
	
	while (b1 == true)
	{
		//random variables
		srand(time(0));
		amountrand = 0 +(rand() % (36 - 0 + 1));
		randomnum = 1 +(rand() % (4 - 1 +1));
		
		//output 
		cout << "What type of bet would you like\n\t(S = Single number, R = Red, B = Black, E = Even, O = Odd)? ";
		cin >> letterchosen;
		
		cout << "How much would you like to wager ($5 minimum bet)? ";
		cin >> betnum;
		
		//checking if its not a radnom letter
		if (letterchosen == "S")
		{
			cout << "What number would you like to bet on (0 - 36)? ";
			cin >> numchosen;
		}
		
		//random letter gererator
		if (randomnum == 1)
		{
			letterrand = "B";
			outputletter = "Black";
		}
		else if (randomnum == 2)
		{
			letterrand = "R";
			outputletter = "Red";
		}
		else if (randomnum == 3)
		{
			letterrand = "O";
			outputletter = "Odd";
		}
		else if (randomnum == 4)
		{
			letterrand = "E";
			outputletter = "Even";
		}
		
		//Outputting the wheel spin
		if (letterchosen == "S")
		{
			cout << "The wheel is spinning....and landed on " << amountrand << endl;
		}
		else if (letterchosen == "R")
		{
			cout << "The wheel is spinning....and landed on " << outputletter << "("<< amountrand << ")" << endl;
		}
		else if (letterchosen == "B")
		{
			cout << "The wheel is spinning....and landed on " << outputletter << "("<< amountrand << ")" << endl;
		}
		else if (letterchosen == "E")
		{
			cout << "The wheel is spinning....and landed on " << outputletter << "("<< amountrand << ")" << endl;
		}
		else if (letterchosen == "O")
		{
			cout << "The wheel is spinning....and landed on " << outputletter << "("<< amountrand << ")" << endl;
		}
		else
		{
			cout << "Didn't choose a correct letter";
		}
		
		//math if statements for bets
		if (betnum >= 5)
		{
			if (letterchosen == "S")
			{
				amountwon = betnum + (betnum * 35 / 1);
			}
			else if (letterchosen == "B" ||letterchosen == "R"||letterchosen == "E"||letterchosen == "O")
			{
				amountwon = betnum + (betnum * 1 /1);
			}
		}

		
		//Checking if the user won
		if(numchosen == amountrand || letterchosen == letterrand)
		{
			cout << "You Won! $" << amountwon << "!";
		}
		else
		{
			cout << "You Lost!";
		}
		//sets replay
		b1 = false;

	
		//Extra Credit
		cout << "\nWould you like to play again ('Y' for yes)?"; 
		cin >> proc;
		if (proc == "Y")
		{
			b1 = true;
		}
		else if (proc == "N")
		{
			b1 = false;
			continue;
		}
		else
		{
			cout << "You did not enter a valid letter";
		}
		cout << endl;
	}
}
