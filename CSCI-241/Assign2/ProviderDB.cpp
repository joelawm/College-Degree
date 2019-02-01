/***************************************************************
CSCI 241         Program 2     Spring 2017

Programmer: Joe Meyer
Instructor

***************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <fstream>
#include "ProviderDB.h"

using namespace std;


//This method is basically a setter method
// It doesnt do anything but help construct
ProviderDB::ProviderDB()
{
}

//What does this method do>
//This method basically helps set the file to be loaded which is taken fomr the 
//main function in the assing 2 file
ProviderDB::ProviderDB(const char* fileName)
{	
	//Setup the file stream
	ifstream inFile;
	//int count = 0;
	
	//this opens the file fileName from ProviderDB
	inFile.open(fileName,ios::binary);
	//error check
	if (!inFile)
	{
		cout << "File is locked or is not there.\n";
	}
	
	//This helps grab the file to be read into the database
	inFile.read((char*) this, sizeof(ProviderDB));
	
	//closes the filestream, helps with memory
	inFile.close();

}

//This method is very simple in all that it does is print the health care label
//as well as help starting the calling method 
void ProviderDB::print() const
{
	//This is just a commonly used infomation display
	cout << "Health Care Provider Listing" << endl;
	
	int i = 0;
	//loop start
	for( i=0; i < AmountStored; i++)
	{
		//Calling method
		StoredObj[i].print();
	}
}

//This is the sort algorithm
//This sorts the list of patients in Providernumber order, which makes for easy viewing
//It is using the sort insertion algorithem
void ProviderDB::sortByProviderNumber()
{
	int i, j;
	
	Provider BProv;
	
	for (i = 1; i < AmountStored; i++)
	{
		BProv = StoredObj[i];
		
		for (j = i; (j > 0) && (strcmp(StoredObj[j-1].getProviderNumber(), BProv.getProviderNumber()) > 0); j--)
		{
			StoredObj[j] = StoredObj[j-1];
		}
		StoredObj[j] = BProv;
	}
}

//This alogithm helps sort out the spceiality , this method is using a insertion algirthm
void ProviderDB::sortBySpeciality()
{
	int i, j;
	Provider BProv;
	
	for (i = 1; i < AmountStored; i++)
	{
		BProv = StoredObj[i];
		
		for (j = i; (j > 0) && (strcmp(StoredObj[j-1].getSpecialty(), BProv.getSpecialty()) > 0); j--)
		{
			StoredObj[j] = StoredObj[j-1];
		}
		StoredObj[j] = BProv;
	}
}

//this helps sort the print statements by name using insertion alorithm
void ProviderDB::sortByName()
{
	int i, j;
	Provider BProv;
	
	for (i = 1; i < AmountStored; i++)
	{
		BProv = StoredObj[i];
		
		for (j = i; (j > 0) && (strcmp(StoredObj[j-1].getName(), BProv.getName()) > 0); j--)
		{
			StoredObj[j] = StoredObj[j-1];
		}
		StoredObj[j] = BProv;
	}
}





