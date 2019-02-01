/***************************************************************
CSCI 241         Program 3     Fall 2017

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
ProviderDB::ProviderDB(){}

//What does this method do?
//This method basically helps set the file to be loaded which is taken fomr the 
//main function in the assing 2 file
ProviderDB::ProviderDB(const char* fileName)
{	
	//Setup the file stream
	ifstream inFile;
	
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
	cout << "\nHealth Care Provider Listing\n" << endl;
	
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

//This transaction reads the file Transactions.txt into stream to be
//read and broken into useful parts
//The parameters are passed in from the beguinning of the TranData, it uploads .txt file
void ProviderDB::processTransactions(const char* TransactionData)
{
	//Load the file
	ifstream fileData;
	
	//Data type variables
	string Specialty, Number, Name, TransactionType;
	
	//Open the file Transaction Data
	fileData.open(TransactionData, ios::binary);
	//error check
	if (!fileData)
	{
		cout << "File is locked or is not there.\n";
	}
	
	//This loads the filedata to the transaction type and then compares it
	while (fileData >> TransactionType)
	{
		//Type ALL
		if (TransactionType == "all")
		{
			//This sorts the data by name
			sortByName();
			//This prints the sorted data
			print();
		}
		
		//Type Speciality
		else if (TransactionType == "specialty")
		{
			int x, count;
			//Remove the white spaces in the reading
	        fileData >> ws;
			//Getline command to get the specialty from file.
			getline(fileData, Specialty);
			//call the sort speciality method
			sortBySpeciality();
			//loop through the data and display mathches
			for (x=0; x < AmountStored; x++)
			{
				//loop through and match the objects
				if(strcmp(Specialty.c_str(), StoredObj[x].getSpecialty()) == 0)
				{
					count++;
				}
			}
			cout << "The amount of Provider(s) that offer " << Specialty << " are: " << count << "\n"<< endl;	
			//reset the count
			count = 0;
		}
		
		//Type Number
		else if (TransactionType == "number")
		{
			//calling the sort method
			sortByProviderNumber();
			//fileData >> ws;
			fileData >> Number;
			
			//calling the search provider number
			int index = searchForProviderNumber(Number.c_str());
			
			//Chech what the return is for the search
			if (index == -1)
			{
				cout << "The Provider Number was not found!\n" << endl;
			}
			else
			{
				cout << "Number Found in data: \n" << endl;
				//Print the Number returned by the search
				StoredObj[index].print();
			}
		}	
	}
	//close the file
	fileData.close();
}

//This mehtod searches through the provide file to provide a number
// and then it will return the provide number, if not it returns -1
//This method returns a int to be outputed in the transatcion type loop
//The parameters are assing in a number from the data .txt file to search for and compare aganist
int ProviderDB::searchForProviderNumber(const char* searchNumber)
{
	int low = 0;
	int high = AmountStored-1;
	int mid;
	
	while (low <= high)
	{
		mid = (low + high) / 2;
		//If the 2 numbers are equal to eachother
		if (strcmp(searchNumber, StoredObj[mid].getProviderNumber()) == 0)
		{
			return mid;
		}
		if (strcmp(searchNumber, StoredObj[mid].getProviderNumber()) < 0)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}



