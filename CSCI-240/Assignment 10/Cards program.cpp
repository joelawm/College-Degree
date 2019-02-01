/***************************************************************
CSCI 240         Program 10     Spring 2017

Programmer: Joe Meyer

Section: 1

Date Due: 5/4/17

Purpose: This is a game to make a simulate card game called
black jack. It has 2 players and is a fun game.
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
		void setCard( int faceVal, char suitVals);
		char suit;
		int faceValue;
};

/***************************************************************************/


//Definition for a class that represents a deck of cards

class DeckOfCards
{
public:
  DeckOfCards();

  Card draw();
  void shuffle();
  bool isEmpty();

private:
  static const int MAX_CARDS = 52;       //Maximum number of cards in a deck
  static const int NUM_SUITS = 4;        //Number of card suits
  static const int CARDS_PER_SUIT = 13;  //Number of cards of each suit

  Card deck[MAX_CARDS];     //The deck of cards
  int topCard;              //The subscript of the card on the top of the deck

};


int main()
{
	//setting the radnom numbver generator
	srand(0);
	
	//setting the card and doc
	Card card1; 
	Card card2;
	Card card3;
	DeckOfCards doc1;

	//itializing the intergers
	int sumofCards, drawingCards, player1score, player2score;

	int drawCount=0;
	while(!doc1.isEmpty() && drawCount<3) 
	{
		//setting the players cards exactly to zero
		sumofCards = 0;

		//intialzing each event
		card1 = doc1.draw();	
		card2 = doc1.draw();
		card3 = doc1.draw();
		//player 
		cout << "Player 1:" << endl;
		sumofCards = card1.faceValue;
		cout << "\t" << card1.faceValue << " of " << card1.suit << "\t" << " Total: " << sumofCards << endl;
		sumofCards = card1.faceValue + card2.faceValue;
		cout << "\t" << card2.faceValue << " of " << card2.suit << "\t" << " Total: " << sumofCards << endl;
		sumofCards = card1.faceValue + card2.faceValue + card3.faceValue;
		cout << "\t" << card3.faceValue << " of " << card3.suit << "\t" << " Total: " << sumofCards << endl;
		
		if (sumofCards == 21)
		{
			cout << "Congratulations player 1! You've earned 15 points!" << endl;
			cout << "-------------------------"<< endl;
			player1score = player1score + 15;
		}
		else if (sumofCards > 21)
		{
			cout << "Sorry Player 1 -- you've busted" << endl;
			cout << "-------------------------"<< endl;
		}
		else if (sumofCards < 21)
		{
			cout << "Congratulations player 1! You've earned 10 points!" << endl;
			cout << "-------------------------"<< endl;
			player1score = player1score + 10;
		}
		
		sumofCards = 0;
		//intilaizing each event
		card1 = doc1.draw();	
		card2 = doc1.draw();	
		card3 = doc1.draw();
		
		//player 2
		cout << "Player 2:" << endl;
		sumofCards = card1.faceValue;
		cout << "\t" << card1.faceValue << " of " << card1.suit << "\t" << " Total: " << sumofCards << endl;
		sumofCards = card1.faceValue + card2.faceValue;
		cout << "\t" << card2.faceValue << " of " << card2.suit << "\t" << " Total: " << sumofCards << endl;
		sumofCards = card1.faceValue + card2.faceValue + card3.faceValue;
		cout << "\t" << card3.faceValue << " of " << card3.suit << "\t" << " Total: " << sumofCards << endl;
		
		if (sumofCards == 21)
		{
			cout << "Congratulations player 2! You've earned 15 points!" << endl;
			cout << "-------------------------"<< endl;
			player2score = player1score + 15;
		}
		else if (sumofCards > 21)
		{
			cout << "Sorry Player 2 -- you've busted" << endl;
			cout << "-------------------------"<< endl;
		}
		else if (sumofCards < 21)
		{
			cout << "Congratulations player 2! You've earned 10 points!" << endl;
			cout << "-------------------------"<< endl;
			player2score = player1score + 10;
		}
		
		
		drawCount++;
	}
	
	//Score output
	if(player1score > player2score)
	{
		cout << "Congratulations Player 1!" << endl;
		cout << "Player 1 score: " << player1score << endl;
		cout << "Player 2 score: " << player2score << endl;
	}
	else if (player2score > player1score)
	{
		cout << "Congratulations Player 2!" << endl;
		cout << "Player 1 score: " << player1score << endl;
		cout << "Player 2 score: " << player2score << endl;
	}
	
	return 0;
}


/**********   Code the Card class methods between these lines   **********/

void Card::setCard(int faceVal, char suitVals)
{
		//setting the face value since its wrong
	if(faceVal > 13 || faceVal < 1)
	{
		faceValue = 1;
	}
	else
	{
		faceValue = faceVal;
	}
	
	//Setting the Suit value since its probably wrong
	if (suitVals != 'C' && suitVals != 'D' && suitVals != 'H' && suitVals != 'S')
	{
		suit = 'H';
	}
	else
	{
		suit = suitVals;
	}
	
}



/***************************************************************
Constructor

Use: This creates a DeckOfCards object and then shuffles the
     cards

Arguments: none

Note: -1 is used to signal that no cards have been removed from
      the deck
***************************************************************/

DeckOfCards::DeckOfCards()
{
//An array of the 4 possible values for the card suit
char suitVals[NUM_SUITS] = { 'C', 'D', 'H', 'S' };

int cardSub = 0;    //subscript to process the deck of cards

//Go through all 52 spots in the array of Cards and put a card
//at the location

for( int suitSub = 0; suitSub < NUM_SUITS; suitSub++ )
  {
  //For each of the suits, put in all of the cards for the suit
  for( int faceVal = 1; faceVal <= CARDS_PER_SUIT; faceVal++ )
    {
    //Put the card into the deck
    deck[ cardSub ].setCard( faceVal, suitVals[suitSub] );

    //Move to the next card in the deck
    cardSub++;
    }
  }

//shuffle the playing cards
shuffle();

//Set the top card location to -1 to indicate the deck is brand new
topCard = -1;
}



/***************************************************************
Method:  Card draw()

Use: This method draws a card from the top of the deck

Arguments: none

Returns: a Card object (the card on the top of the deck)
***************************************************************/

Card DeckOfCards::draw()
{
//Increment to get the subscript of the current top card
topCard++;

//return the card that is currently on the top of the deck
return deck[topCard];
}



/***************************************************************
Method:  void shuffle()

Use: This method shuffles the deck of cards

Arguments: none

Returns: nothing

Note: this method uses the random_shuffle function that is part
      of the algorithm library to shuffle the 52 cards
***************************************************************/

void DeckOfCards::shuffle()
{
//Shuffle all 52 cards that are in the deck

random_shuffle(deck, deck+MAX_CARDS);
}


/***************************************************************
Method:  bool isEmpty()

Use: This method determines if the deck of cards is empty( have
     all of the cards been drawn)

Arguments: none

Returns: boolean value: true if all of the cards have been drawn
                        false if there are still cards in the deck
***************************************************************/

bool DeckOfCards::isEmpty()
{
return topCard + 1 >= MAX_CARDS;
}
