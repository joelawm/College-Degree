/***************************************************************
CSCI 240         Program 1     Spring 2017

Programmer: Joe Meyer

Section: 1

Date Due: 1/18/17

Purpose: This program will take the users input for a subscription
         and then return the cost for it.
***************************************************************/
#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
	//setting the basic variables to be used.
	string userinputpack;
	string packageoption1, packageoption2;
	int userinputmin;
	float billtotal;
	float packageA = 39.99, packageB = 59.99, packageC = 69.99;
	int packageAam = 450, packageBam = 900;
	float overA = .45, overB = .4;
	float amount1, amount2, moneyspent, moneyspentsec;
		
	//asking for the users input
	cout << "Which package do you have (A, B, or C)? ";
	cin >> userinputpack;
	cout << "How many minutes were used this month? ";
	cin >> userinputmin; 
	
	//Math section to determine the bill
	if (userinputpack == "A")
	{
		//setting package options
		string packageoption1 = "B";
		packageoption2 == "C";
		moneyspent = packageB;
		moneyspentsec = packageC;
		
		if (userinputmin >= 450)
		{
			int newaddA = userinputmin - 450;
			billtotal = newaddA * overA;
			billtotal = billtotal + packageA;
		}
		else
		{
			billtotal = packageA;
		}
	}
	else if (userinputpack == "B")
	{
		//setting package options
		string packageoption1 = "A";
		string packageoption2 = "C";
		moneyspent = packageA;
		moneyspentsec = packageC;
		
		
		if (userinputmin >= 900)
		{
			int newaddB = userinputmin - 900;
			billtotal = newaddB * overB;
			billtotal = billtotal + packageB;
		}
		else
		{
			billtotal = packageB;
		}
	}
	else if (userinputpack == "C")
	{
		//setting package options
		string packageoption1 = "A";
		string packageoption2 = "B";
		moneyspent = packageA;
		moneyspentsec = packageB;
		
		billtotal = packageC;
	}
	
	//outputing the bill.
	cout << "\nThe bill is $" << billtotal;
	
	//Extra Credit Portion
	//Math portion
	//amount1 = 

	
	//Output for extra credit
	//cout << "\n\nPackage " << packageoption1 << " would have cost $" << moneyspent << " and saved you $" << amount1;
	//cout << "\nPackage " << packageoption2 << " would have cost $" << moneyspentsec << " and saved you $" << amount2;
	
	return 0;
}


