/***************************************************************
CSCI 241         Program 2     Spring 2017

Programmer: Joe Meyer

***************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include "Provider.h"

using namespace std;

//this helps just construct the method below
Provider::Provider()
{
}

//this method helps pass in all the variables and make sure they get copied into
//the specific print mthod
Provider::Provider(const char* NewProvNum, const char* NewSpeciality, const char* NewName, const char* NewFirstPart, const char* NewSecondPart, const char* NewCity, const char* NewState, const char* NewZip, const char* NewPhone)
{
	strcpy(ProvNum, NewProvNum);
	strcpy(SpecialityC, NewSpeciality);
	strcpy(NameC, NewName);
	strcpy(FirstPart, NewFirstPart);
	strcpy(SecondPart, NewSecondPart);
	strcpy(CityC, NewCity);
	strcpy(StateC, NewState);
	strcpy(ZipC, NewZip);
	strcpy(PhoneC, NewPhone);
}
// Method definition to be coded in Provider.cpp
//This prints the data when it is needed in the program
void Provider::print() const
{
	//The output screen for the database
	cout << '#' << ProvNum << endl
        << NameC << endl
        << SpecialityC << endl
        << FirstPart << endl
        << SecondPart << endl
        << CityC << ", " << StateC << ' ' << ZipC << endl
        << PhoneC << endl << "\n";	
}

//returns the provider number to print method
const char* Provider::getProviderNumber() const
{
	return ProvNum;
}

//returns the spefiality to print
const char* Provider::getSpecialty() const
{
	//return the speciality of the listing
	return SpecialityC;
}

//returns the name to print
const char* Provider::getName() const
{
	//return the name listing
	return NameC;
}



