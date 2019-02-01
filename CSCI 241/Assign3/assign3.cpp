/***************************************************************
CSCI 241         Program 23    Fall 2017

Programmer: Joe Meyer
***************************************************************/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
//added files
#include "ProviderDB.h"

using namespace std;

int main()
{
	//Create the ProviderDB obj
	ProviderDB obj1 ("providerdb");
	
	//Passing in the transactions list into providerdb object
	obj1.processTransactions("transactions.txt");
	
	return 0;
}
