/***************************************************************
CSCI 240         Program 6     Spring 2017

Programmer: Joe Meyer

Section: 1

Date Due: 3/10/17

Purpose: This program performs simple arithmetic calculations and
         displays the results.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

/***************************************************************
Function:Addition

Use: it helps add the 2 numbers together to produce a result

Arguments:

Returns: the result of the totals

Note: none
***************************************************************/

int addition(int num1, int num2)
{
	int result;
    //Add the numbers together
    result = num1 + num2;
    //Display the result of the addition
    cout << endl << num1 << " + " << num2 << " = " << result;
}
/***************************************************************
Function:subtraction

Use: it helps subtract 2 numbers together to proudce a result

Arguments: its designed to make sure the vaule isnt empty

Returns: the result of the totals

Note: none
***************************************************************/

int subtraction(int num1, int num2)
{    
	int result;
    //Subtract the second number from the first number
    result = num1 - num2;
    //Display the result of the subtraction
    cout << endl << num1 << " - " << num2 << " = " << result;
}

/***************************************************************
Function: multiplication 

Use: it helps mutiply 2 numbers to gethere to produce a result

Arguments: its designed to make sure the vaule isnt empty

Returns: the result of the totals

Note: none
***************************************************************/

int multiplication(int num1, int num2)
{
	int result;
    //Multiply the numbers together
    result = num1 * num2;
    //Display the result of the multiplication
    cout << endl << num1 << " * " << num2 << " = " << result;
}

/***************************************************************
Function: multipication

Use: it takes 2 numbers and multiplies them together

Arguments: its designed to make sure the vaule isnt empty

Returns: the result of the mutiplication

Note: none
***************************************************************/

int quotient(int num1, int num2)
{
	int result, remain;
    //Divide the first number by the second number, calculating both the quotient
    //and the remainder
    result = num1 / num2;
    remain = num1 % num2;
    //Display both results of the division
    cout << endl << num1 << " / " << num2 << " = " << result
	<< endl << num1 << " % " << num2 << " = " << remain;
}

/***************************************************************
Function: quotient

Use: it takes 2 numbers and divides them by each other to proudce a result

Arguments: its designed to make sure the vaule isnt empty

Returns: the result of the quotient

Note: none
***************************************************************/

int power(int num1, int num2)
{
	int result;
    //Calculate the result of raising the first number (num1) to a power (the
	//second number)    
    result = 1;
    for( int cnt = 1; cnt <= num2; cnt++ )
      {
      result *= num1;
      }
    //Display the result
    cout << endl << num1 << "^" << num2 << " = " << result;
}

/***************************************************************
Function: factorial

Use: it take one number and sets it factorial number it was derived from

Arguments: its designed to make sure the vaule isnt empty

Returns: the reuslt of the factorial

Note: none
***************************************************************/

int factorial(int num1)
{
	int result;
    //Calculate the result of multiplying 1 times each value through the number
    //entered by the user.
    result = 1;
    for( int cnt = 2; cnt <= num1; cnt++ )
      {
      result *= cnt;
      }
    //Display the result
    cout << endl << num1 << "! = " << result;
}

//The main function

int main()
{
char operation; 
int num1, num2, result, remain;

//onborading the file to be read from
ifstream infile;
infile.open( "math.txt" );

//check to make sure it opened correctly
if( infile.fail() )       
//if the input file failed to open
{
	cout << "input file did not open" << endl;
	exit(-1);  
	//stop execution of the program immediately
}
//Display the menu to the user and get their first choice
infile >> operation;
//While the user does not want to quit
while( infile )
  {
  //Addition operation
  infile >> num1;
  if (infile.peek()!='\n')
  	infile >> num2;
    
  if( operation == '+' )
    {
    	addition(num1, num2);
	}

  //Subtraction operation

  else if( operation == '-' )
    {
    	subtraction(num1, num2);
	}

  //Multiplication operation

  else if( operation == '*' )
    {
    	multiplication(num1, num2);
	}

  //Division operation

  else if( operation == '/' )
    {
    	quotient(num1, num2);
	}

  //Exponentiation operation (number raised to a power)

  else if( operation == '^' )
    {
    	power(num1, num2);
	}
	
  //Factorial operation
  else if( operation == '!' )
    { 
    	factorial(num1);
	}

  //Invalid operation
  //Display an error message
  else
    {
    cout << endl << "That is an invalid operation!";
	}
  infile >> operation;
  
  
  }
  infile.close();
  return 0;
}

