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


