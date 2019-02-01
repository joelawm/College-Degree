/***************************************************************
CSCI 240         Program 1     Spring 2017

Programmer: Joe Meyer

Section: 1

Date Due: 1/18/17

Purpose: This program performs simple arithmetic calculations and
         displays the results.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int firstnumber, secondnumber;
	cout << "Please enter the first number: ";
	cin >> firstnumber;
	cout << "\nPlease enter the second number: ";
	cin >> secondnumber;
	int additionnum = firstnumber + secondnumber;
	int subtractionnum = firstnumber - secondnumber;
	int multiplicationnum = firstnumber * secondnumber;
	int divisionnum = firstnumber / secondnumber;
	int modnumber = firstnumber % secondnumber;
	cout << "\n" << firstnumber << " + " << secondnumber << "= " << additionnum;
	cout << "\n" << firstnumber << " - " << secondnumber << "= " << subtractionnum;
	cout << "\n" << firstnumber << " * " << secondnumber << "= " << multiplicationnum;
	cout << "\n" << firstnumber << " / " << secondnumber << "= " << divisionnum;
	cout << "\n" << firstnumber << " % " << secondnumber << "= " << modnumber;
	int subtractionnumback = secondnumber - firstnumber;
	int divisionnumback = secondnumber / firstnumber;
	int modnumberback = secondnumber % firstnumber;
	cout << "\n\n" << secondnumber << " - " << firstnumber << "= " << subtractionnumback;
	cout << "\n" << secondnumber << " / " << firstnumber << "= " << divisionnumback;
	cout << "\n" << secondnumber << " % " << firstnumber << "= " << modnumberback;
	
	return 0;
}
