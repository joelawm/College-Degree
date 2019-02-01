#ifndef PROVIDER_H
#define PROVIDER_H
//*****************************************************************
// FILE:      Provider.h
// AUTHOR:    Joe Meyer
// LOGON ID:  z1788150
// DUE DATE:  09/26/17
// 
// PURPOSE:   Declaration for the Provider class, which represents 
//            information about a health care provider.
//*****************************************************************
class Provider
{
	// Data members and method prototypes for the Provider class go here
	//Data Memebers for the assingment
	char ProvNum[7];
	char SpecialityC[41];
	char NameC[41];
	char FirstPart[41];
	char SecondPart[31];
	char CityC[21];
	char StateC[3];
	char ZipC[6];
	char PhoneC[15];
	
	public:
		//Method Prototypes for the assignment
        Provider();
		Provider(const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*);
		void print() const;
		const char* getProviderNumber() const;
		const char* getSpecialty() const;
		const char* getName() const;
        const char* getFirstPart() const;
};
#endif
