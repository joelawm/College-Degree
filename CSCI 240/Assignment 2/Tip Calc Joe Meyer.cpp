/***************************************************************
CSCI 240         Program 1     Spring 2017

Programmer: Joe Meyer

Section: 1

Date Due: 1/18/17

Purpose: This program takes a input from the user and will give back the percentage
			of the tip needed to be given.
***************************************************************/
 #include <iostream>
 #include <iomanip>
 
 using namespace std;
 
 int main()
{
	float tipam; //sets the amount of the sip in a interger
 	cout << "What is the amount of the bill?: "; //outputs the qestion
 	cin >> tipam; //receives input
 	
 	//this section does the math
 	float tenpercent = tipam * .1;
 	float fifteenpercent = tipam * .15;
 	float twentypercent = tipam * .2;
 	float twentyfivepercent = tipam * .25;
 	
 	//this section shows that math afterwards
 	cout << "\n\nThe recommended tip amounts are:";
 	cout << "\n10% = $" <<fixed << setprecision(2) << tenpercent;
 	cout << "\n15% = $" << fifteenpercent;
 	cout << "\n20% = $" << twentypercent;
 	cout << "\n25% = $" << twentyfivepercent;
 	
 	//extra credit part
 	//math section to get the total for extra credit
 	float tentotal = tenpercent + tipam;
 	float fifteentotal = fifteenpercent + tipam;
 	float twentytotal = twentypercent + tipam;
 	float twentyfivetotal = twentyfivepercent + tipam;
 	//this section will basically dipslay the total paid, tip and amount
 	cout << "\n\n The total bill with the recommended tips:";
 	cout << "\n 10% = $" << tentotal;
 	cout << "\n 15% = $" << fifteentotal;
 	cout << "\n 20% = $" << twentytotal;
 	cout << "\n 25% = $" << twentyfivetotal;
 	
 	return 0; // return a positive code
}


