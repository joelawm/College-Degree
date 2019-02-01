/***************************************************************
CSCI 240         Program 8     Spring 2017

Programmer: Joe Meyer

Section:

Date Due:

Purpose: 
***************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

/**********   Put the Card class definition between these lines   **********/
class Card
{
public:
  Card();
  
  void setCard( int, char );
  
  int getFace();
  char getSuit();
  
  void displayCard();

private:
  int faceValue;
  char suit;
};

/***************************************************************************/



int main()
{
//Set the seed value for the random number generator
srand(240);

//Test 1: Constructor and displayCard method

//Create 5 Card objects
Card firstCard;
Card secondCard;
Card thirdCard;
Card fourthCard;
Card fifthCard;

//Display the 5 objects

cout << "Test 1: Constructor and displayCard method" << endl << endl
     << "  The first card should be the 4 of Diamonds. It is the ";
firstCard.displayCard();

cout << "." << endl << endl << "  The second card should be the 3 of Clubs. It is the ";
secondCard.displayCard();

cout << "." << endl << endl << "  The third card should be the King of Clubs. It is the ";
thirdCard.displayCard();

cout << "." << endl << endl << "  The fourth card should be the King of Spades. It is the ";
fourthCard.displayCard();

cout << "." << endl << endl << "  The fifth card should be the Jack of Clubs. It is the ";
fifthCard.displayCard();


//Test 2: setCard method on four of the objects


cout << "." << endl << endl << "Test 2: setCard method" << endl << endl;

//Change the first card to the 9 of Clubs

firstCard.setCard( 9, 'C' );

cout << "  The first card should be the 9 of Clubs. It is now the ";
firstCard.displayCard();

//Change the second card with invalid value for the face

secondCard.setCard( 15, 'D' );

cout << "." << endl << endl << "  The second card should be the Ace of Diamonds. It is now the ";
secondCard.displayCard();

//Change the third card with invalid value for the suit

thirdCard.setCard( 7, 'G' );

cout << "." << endl << endl << "  The third card should be the 7 of Hearts. It is now the ";
thirdCard.displayCard();

//Change the fourth card with invalid value for both the face and the suit

fourthCard.setCard( -5, 'R' );

cout << "." << endl << endl << "  The fourth card should be the Ace of Hearts. It is now the ";
fourthCard.displayCard();


//Test 3: getFace and getSuit methods on the fourth and fifth objects

cout << "." << endl << endl << "Test 3: getFace and getSuit methods" << endl << endl;

cout << "  The fourth card should have a face value of 1. It is "
     << fourthCard.getFace() << "." << endl
     << "  The suit value should be H. It is " << fourthCard.getSuit() << ".";

cout << endl << endl << "  The fifth card should have a face value of 11. It is "
     << fifthCard.getFace() << "." << endl
     << "  The suit value should be C. It is " << fifthCard.getSuit() << endl;

return 0;
}


/************   Code the Card class methods AFTER this line   ************/


/*********************************************************
Access Method 1: Card::setCard(int newface, char newSuit)
This method just makes sure that all the values exist.
If they dont it will fill it with one that does.
*********************************************************/
void Card::setCard(int newface, char newSuit)
{
	//setting the face value since its wrong
	if(newface > 13 || newface < 1)
	{
		faceValue = 1;
	}
	else
	{
		faceValue = newface;
	}
	
	//Setting the Suit value since its probably wrong
	if (newSuit != 'C' && newSuit != 'D' && newSuit != 'H' && newSuit != 'S')
	{
		suit = 'H';
	}
	else
	{
		suit = newSuit;
	}
}


/*********************************************************
Access Method 2: int Card::getFace()
This method just returns the value faceValue
*********************************************************/
int Card::getFace()
{
	return faceValue;
}


/*********************************************************
Access Method 3: char Card::getSuit()
THis Method just returns the suit value
*********************************************************/
char Card::getSuit()
{
	return suit;
}


/*********************************************************
Access Method 4: Card::displayCard()
This method will retrieve the facevalue set in the constructors
and append it to its specfic value
*********************************************************/
void Card::displayCard()
{
	//Setting the facevalue of the card
	if (faceValue == 1)
	{
		cout << "Ace";
	}
	else if (faceValue == 11)
	{
		cout << "Jack";
	}
	else if (faceValue == 12)
	{
		cout << "Queen";
	}
	else if (faceValue == 13)
	{
		cout << "King";
	}
	else
	{
		//Displays the regular value
		cout << faceValue;
	}
	
	cout << " of ";
	//Setting the suit of the card
	if (suit == 'C')
	{
		cout <<  "Clubs";
	}
	else if (suit == 'D')
	{
		cout <<  "Diamonds";
	}
	else if (suit == 'H')
	{
		cout <<  "Hearts";
	}
	else if (suit == 'S')
	{
		cout <<  "Spades";
	}
}


/*********************************************************
Constructor:
This constructor takes no arguments. It should intialize all the values
and set their values through this.
*********************************************************/
Card::Card()
{
	//Variables Set
	int randnum, randletter;
	//Radnom Number Generator
	randnum = 1 + (rand() % (13));
	randletter = 1 +(rand() % (4) );
	//set the card number
	faceValue = randnum;
	
	//Set the suit
	if (randletter == 1)
	{
		suit = 'C';
	}
	else if (randletter == 2)
	{
		suit = 'D';
	}
	else if (randletter == 3)
	{
		suit = 'H';
	}
	else
	{
		suit = 'S';
	}
}



