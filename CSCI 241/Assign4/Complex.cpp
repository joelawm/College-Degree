/***************************************************************
CSCI 241         Program 4    Fall 2017
Programmer: Joe Meyer
Date Due: 10/19/17
Purpose: 
***************************************************************/

#include <iomanip>
#include "Complex.h"

//Constructor
Complex::Complex(double newRealPart, double newImagPart)
{
	//this is part of the testing phase
	RealPart = newRealPart;
	ImagPart = newImagPart;
}

//Methods

//this is where we set the varibales taken in to be examined by the varioues operators
//Takes in 2 variables
void Complex::setComplex(double newRealPart, double newImagPart)
{
	//Setting the variables that are inputed
	ImagPart = newImagPart;
	RealPart = newRealPart;
}

//this grabs the response from the system and then will give it back to the system to dsplay 
void Complex::getComplex(double& RealPart, double& ImagPart) const
{	
//setting the data members
	RealPart = this -> RealPart;
	ImagPart = this->ImagPart;
}

//This returns the variable to be passed in for others to be read from
void Complex::setRealPart(double newRealPart)
{
	//Assign the data member
	RealPart = newRealPart;
}

//this reutrns the real part of the system and sends it to the end user to be displayed
double Complex::getRealPart() const
{
	//Return the data member
	return RealPart;
}

//This sets the imag part for the system when the variable is passed in
void Complex::setImaginaryPart(double newImagPart)
{
	//Assign the data member
	ImagPart = newImagPart;
}

//This returns the imag part for the user after being passed in. It will return the double varible for the system
double Complex::getImaginaryPart() const
{
	//return the data members
	return ImagPart;
}

//This operator will add to given parameters together when passed in. After adding it returns
//the amount back to gehr system to be displayed for the end user
Complex Complex::operator+(const Complex& rightObj) const
{
	Complex endAmount;
	
	endAmount.RealPart = RealPart + rightObj.RealPart;
	endAmount.ImagPart = ImagPart + rightObj.ImagPart;
	
	return endAmount;
} 

//This operator will muiply to given statments to gether and
//return the output back to the system to be read out
Complex Complex::operator*(const Complex& rightObj ) const
{
	Complex endAmount;
	
	endAmount.RealPart = (RealPart * rightObj.RealPart)- (ImagPart * rightObj.ImagPart);
	endAmount.ImagPart = (RealPart * rightObj.ImagPart) + (ImagPart * rightObj.RealPart);
	
	return endAmount;
	
}

//This check for true contions and will output wether ometing is true or not
//Used for comparing 2 number together
bool Complex::operator==(const Complex& rightOperand) const
{
	if (rightOperand.RealPart == RealPart && rightOperand.ImagPart == ImagPart)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//this is the out operator that will baically take what the machine is given
//and output it back to the system
ostream& operator<<(ostream& leftOperand, const Complex& rightOperand)
{
	leftOperand << '('<<rightOperand.RealPart<<','<< rightOperand.ImagPart<<')';
	//return th ostream obj
	return leftOperand;
}

//This is for the cin in operartor and basically takes the input and ut will be saved to a char to be
//used later in some way
istream& operator>>(istream& leftOperand, Complex& rightOperand)
{
	char ch;
	leftOperand >> ch;
	leftOperand >> rightOperand.RealPart;
	leftOperand >> ch;
	leftOperand >>rightOperand.ImagPart;
	leftOperand >> ch;
	
	return leftOperand;
}


