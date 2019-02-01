/***************************************************************
CSCI 240         Program 8     Spring 2017

Programmer: Joe Meyer

Section: A?

Date Due: 4/21/17

Purpose: This is demonstrated my knowldege on classes.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string.h>

using namespace std;

class Player
{
public:
	//these are the constructors
  Player();
  Player( const char [], int, int, int );
    
  void printPlayer();

  void setName( const char [] );
  void setNumber( int );
  
  void changeGoals( int );
  void changeAssists( int );

  int getNumber();
  int getGoals();
  int getAssists();

private:
  char name[50];
  int number;
  int goals;
  int assists;
};



int main()
{
	
	//Creating the 6 player objects, which are also at this time filled with info 
	Player player1;
	Player player2;
	Player player3;
	Player player4;
	Player player5;
	Player player6;
	
	
	//Setting Player 1
	cout << "The first Player Object" << endl;
	player1.setName("Joe Meyer");
	player1.setNumber(66); 
	player1.changeGoals(1);
	player1.changeAssists(1);
	player1.printPlayer();
	
	//Setting Player 2; uses default constructor
	cout << "The second Player Object"<< endl;
	player2.printPlayer();
	player2.setName("Duncan Kieth");
	player2.setNumber(2); 
	player2.changeGoals(6);
	player2.changeAssists(44);
	player2.printPlayer();
	
	//Setting Player 3
	cout << "The third Player Object"<< endl;
	player3.setName("Jonathan Toews");
	player3.setNumber(19);
	player3.changeGoals(20);
	player3.changeAssists(35);
	player3.printPlayer();
	player3.setName("Jonathan Toews");
	player3.setNumber(19);
	player3.changeGoals(-8);
	player3.changeAssists(-2);
	player3.printPlayer();
	
	//Setting Player 4
	cout << "The forth Player Object"<< endl;
	player4.setName("Patrick Kane");
	player4.setNumber(88);
	player4.changeGoals(33);
	player4.changeAssists(48);
	player4.printPlayer();
	player4.setName("Patrick Kane");
	player4.setNumber(88);
	player4.changeGoals(33);
	player4.changeAssists(52);
	player4.printPlayer();
	
	//Setting Player 5
	cout << "The fifth Player Object"<< endl;
	player5.setName("Artemi Panarin");
	player5.setNumber(72);
	player5.changeGoals(24);
	player5.changeAssists(42);
    cout << "\nPlayer number "<< player5.getNumber() <<" has scored " << player5.getGoals() <<" goals\n" << endl;
	player5.printPlayer();
	
	//Setting Player 6
	cout << "The sixth Player Object"<< endl;
	player6.setName("Ryan Hartman");
	player6.setNumber(38);
	player6.changeGoals(18);
	player6.changeAssists(11);
	cout << "\nPlayer number "<< player6.getNumber() <<" has scored " << player6.getAssists() <<" assists\n" << endl;
	player6.printPlayer();
	
	
	
	

return 0;
}



/*********************************************************
Access Method 1:This is a method that essntially prints the 
out put of the program
*********************************************************/
void Player::printPlayer()
{
	// variabels
	int points;
	points = assists + goals;
	//This is used to display the infomation
	cout << name << "\t#" << number << endl;
	
	cout << "Goals: " << goals << "\t" << "Assissts: " << assists << "\t" << "Points: " << points;
	cout << "\n\n";
}

/*********************************************************
Access Method 2: This method take the array inputed and copies
it to the array used in outputting
*********************************************************/
void Player::setName(const char playerName[])
{
	strcpy(name, playerName);
}

/*********************************************************
Access Method 3: This helps set the number in the program
*********************************************************/
void Player::setNumber(int newNumber)
{
	number = newNumber;
}

/*********************************************************
Access Method 4: This helps set the goals scored and also
checks for errors or incorrect input
*********************************************************/
void Player::changeGoals(int goalsScored)
{
	if (goalsScored < 0)
	{
		cout << "Error in changeGoals. The # of goals scored cannot be negative" << endl;
	}
	else if (goalsScored > 0)
	{
		goals = goalsScored;
	}
}

/*********************************************************
Access Method 5:This inputs the assist and also has erro checking
it makes sure all inputed variables are correct
*********************************************************/
void Player::changeAssists(int assistsEarned)
{
		if (assistsEarned < 0)
	{
		cout << "Error in changeAssists. The # of assists earned cannot be negative\n" << endl;
	}
	else if (assistsEarned > 0)
	{
		assists = assistsEarned;
	}
}

/*********************************************************
Access Method 6:Thie gets the number and returns it to be used 
above in the main int
*********************************************************/
int Player::getNumber()
{
	return number;
}

/*********************************************************
Access Method 7:Thie gets the goals and returns it to be used above
*********************************************************/
int Player::getGoals()
{
	return goals;
}

/*********************************************************
Access Method 8:Thie gets assists and reuturns it to be used above
*********************************************************/
int Player::getAssists()
{
	return assists;
}


//Constructor no arguments; sets the data to be blank if nothing is written
Player::Player()
{
	name[0] = {'\0'};
	number = 0;
	goals = 0;
	assists = 0;
	
	
}


//Constructor that takes arguments
Player::Player( const char name[], int number, int goals, int assists)
{
	//intializing the varibales being used
	number = 0;
	goals = 0;
	assists = 0;
}


