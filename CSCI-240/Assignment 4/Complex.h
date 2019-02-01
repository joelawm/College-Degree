#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

//*****************************************************************
// FILE:      Complex.h
// AUTHOR:    Joe Meyer
// LOGON ID:  z1788150
// DUE DATE:  10/18/17
// 
// PURPOSE:   Declaration for the Provider class, which represents 
//            information about a health care provider.
//*****************************************************************

class Complex
  {
  		// Data members and method prototypes for the Provider class go here
  		//Data Memebers for the assingment
  		double RealPart;
  		double ImagPart;
		//Method Prototypes for the assignment
		public:
		    //Complex();
           	Complex(double=0, double=0);
			void setComplex(double, double);
			void getComplex(double&, double&) const;
			void setRealPart(double);
			double getRealPart() const;
			void setImaginaryPart(double);
			double getImaginaryPart() const;
			Complex operator+(const Complex&) const;
			Complex operator*(const Complex&) const;
			bool operator==(const Complex&) const;
			friend ostream& operator<<(ostream&, const Complex&);
			friend istream& operator>>(istream&,  Complex&);
  };

#endif
