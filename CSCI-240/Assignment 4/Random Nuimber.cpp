/***************************************************************
CSCI 240         Program 4     Spring 2017

Programmer: Joe Meyer

Section: 1

Date Due: 1/18/17

Purpose: 
***************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
	//variables/random number generator
	float amountrand, num1, num2, num3, num4, num5, num6, num7, num8, num9, num10 ,output;
	
	float w1,w2,n;
	string proc;
	bool b1 = true;
	
	while (b1 == true)
	{
		//random variables
		srand(time(0));
		amountrand = 2 +(rand() % (10 - 3 +1));  
		cout << "This program will generate " << amountrand << " numbers."<< endl;
		
		//if statements and outputs
		if (amountrand == 2)
		{
			srand(time(0));
			num1 = 10 + (rand() % (50 - 10 +1));
			num2 = 10 + (rand() % (50 - 10 +1));
			
			//deviation math
			w1 = (num1*num1)+ (num2*num2);
			w2 = (num1 + num2) * (num1 + num2);
			
			output = (w1-(w2/amountrand))/(amountrand -1);
			output = sqrt(output);
			
			cout << "\nThe numbers are "<< num1 << " " << num2 << endl;
			if (num1 > num2)
			{
				cout << "Smallest:" << num2 << endl;
				cout << "Largest" << num1 << endl;
			}
			else
			{
				cout << "Smallest:" << num1 << endl;
				cout << "Largest" << num2 << endl;
			}
			cout << "Sum:" << num1+num2 << endl;
			cout << "Average:" << (num1+num2)/amountrand << endl;
			cout << "Standard Deviation:"<< output <<endl;

		}
		else if (amountrand == 3)
		{
			srand(time(0));
			num1 = 10 + (rand() % (50 - 10 +1));
			num2 = 10 + (rand() % (50 - 10 +1));
			num3 = 10 + (rand() % (50 - 10 +1));
			
			//deviation math
			w1 = (num1*num1)+ (num2*num2) * (num3 + num3);
			w2 = (num1 + num2 + num3) * (num1 + num2 + num3);
			
			output = (w1-(w2/amountrand))/(amountrand -1);
			output = sqrt(output);
			
			cout << "\nThe numbers are "<< num1 << " " << num2 << " " << num3 << endl;
			//largest
			if (num2 > num1 && num2 > num3)
			{
				cout << "Largest:" << num2 << endl;
			}
			else if(num1>num2 && num1>num3)
			{
				cout << "Largest:" << num1 << endl;
			}
			else if (num3 > num1 && num3 > num2)
			{
				cout << "Largest:" << num3 << endl;
			}
			
			//smallest
			if (num2 < num1 && num2 < num3)
			{
				cout << "Smallest:" << num2 << endl;
			}
			else if(num1<num2 && num1<num3)
			{
				cout << "Smallest:" << num1 << endl;
			}
			else if (num3 < num1 && num3 < num2)
			{
				cout << "Smallest:" << num3 << endl;
			}
			cout << "Sum:" << num1+num2+num3 << endl;
			cout << "Average:" << (num1+num2+num3)/amountrand << endl;
			cout << "Standard Deviation:"<< output <<endl;
		}
		else if (amountrand == 4)
		{
			srand(time(0));
			num1 = 10 + (rand() % (50 - 10 +1));
			num2 = 10 + (rand() % (50 - 10 +1)); 
			num3 = 10 + (rand() % (50 - 10 +1));
			num4 = 10 + (rand() % (50 - 10 +1));
			
			//deviation math
			w1 = (num1*num1)+ (num2*num2) * (num3 + num3) * (num4 + num4);
			w2 = (num1 + num2 + num3 +num4) * (num1 + num2 + num3 +num4) ;
			
			output = (w1-(w2/amountrand))/(amountrand -1);
			output = sqrt(output);
			
			cout << "\nThe numbers are "<< num1 << " " << num2 << " " << num3 << " " << num4 << endl;
			//largest
			if(num1>num2 && num1>num3 && num1 > num4)
			{
				cout << "Largest:" << num1 << endl;
			}
			else if(num2 > num1 && num2 > num3 && num2 >num4)
			{
				cout << "Largest:" << num2 << endl;
			}
			else if (num3 > num1 && num3 > num2 && num3 > num4)
			{
				cout << "Largest:" << num3 << endl;
			}
			else if(num4 > num1 && num4 > num2 && num4 > num3)
			{
				cout << "Largest:" << num4 << endl;
			}
			
			//smallest
			if (num1<num2 && num1<num3 && num1< num4)
			{
				cout << "Smallest:" << num1 << endl;
			}
			else if(num2<num2 && num2<num3 && num2 < num4)
			{
				cout << "Smallest:" << num2 << endl;
			}
			else if (num3 < num1 && num3 < num2 && num3 < num4)
			{
				cout << "Smallest:" << num3 << endl;
			}
			else if (num4 < num1 && num4 < num2 && num4 < num3)
			{
				cout << "Smallest:" << num4 << endl;
			}
			cout << "Sum:" << num1+num2+num3+num4 << endl;
			cout << "Average:" << (num1+num2+num3+num4)/amountrand << endl;
			cout << "Standard Deviation:"<< output <<endl;
		}
		else if (amountrand == 5)
		{
			srand(time(0));
			num1 = 10 + (rand() % (50 - 10 +1));
			num2 = 10 + (rand() % (50 - 10 +1));
			num3 = 10 + (rand() % (50 - 10 +1));
			num4 = 10 + (rand() % (50 - 10 +1));
			num5 = 10 + (rand() % (50 - 10 +1));
			
			//deviation math
			w1 = (num1*num1)+ (num2*num2) * (num3 + num3) * (num4 + num4) * (num5 +num5);
			w2 = (num1 + num2 + num3 +num4+num5) * (num1 + num2 + num3 +num4+num5) ;
			
			output = (w1-(w2/amountrand))/(amountrand -1);
			output = sqrt(output);
			
			cout << "\nThe numbers are "<< num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << endl;
			//largest
			if(num1>num2 && num1>num3 && num1 > num4 && num1 > num5)
			{
				cout << "Largest:" << num1 << endl;
			}
			else if(num2 > num1 && num2 > num3 && num2 >num4 && num2 > num5)
			{
				cout << "Largest:" << num2 << endl;
			}
			else if (num3 > num1 && num3 > num2 && num3 > num4 && num3 > num5)
			{
				cout << "Largest:" << num3 << endl;
			}
			else if(num4 > num1 && num4 > num2 && num4 > num3 && num4 > num5)
			{
				cout << "Largest:" << num4 << endl;
			}
			else if(num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4)
			{
				cout << "Largest:" << num5 << endl;
			}
			
			//smallest
			if (num1<num2 && num1<num3 && num1< num4 && num1 <num5)
			{
				cout << "Smallest:" << num1 << endl;
			}
			else if(num2<num2 && num2<num3 && num2 < num4 && num2 <num5)
			{
				cout << "Smallest:" << num2 << endl;
			}
			else if (num3 < num1 && num3 < num2 && num3 < num4 && num3 <num5)
			{
				cout << "Smallest:" << num3 << endl;
			}
			else if (num4 < num1 && num4 < num2 && num4 < num3 && num4 <num5)
			{
				cout << "Smallest:" << num4 << endl;
			}
			else if (num5 < num1 && num5 < num2 && num5 < num3 && num5< num4)
			{
				cout << "Smallest:" << num5 << endl;
			}
			cout << "Sum:" << num1+num2+num3+num4+num5 << endl;
			cout << "Average:" << (num1+num2+num3+num4+num5)/amountrand << endl;
			cout << "Standard Deviation:"<< output <<endl;
		}
		else if (amountrand == 6)
		{
			srand(time(0));
			num1 = 10 + (rand() % (50 - 10 +1));
			num2 = 10 + (rand() % (50 - 10 +1));
			num3 = 10 + (rand() % (50 - 10 +1));
			num4 = 10 + (rand() % (50 - 10 +1));
			num5 = 10 + (rand() % (50 - 10 +1));
			num6 = 10 + (rand() % (50 - 10 +1));
			
			//deviation math
			w1 = (num1*num1)+ (num2*num2) * (num3 + num3) * (num4 + num4) * (num5 +num5) * (num6+num6);
			w2 = (num1 + num2 + num3 +num4+num5+num6) * (num1 + num2 + num3 +num4+num5+num6);
			
			output = (w1-(w2/amountrand))/(amountrand -1);
			output = sqrt(output);
			
			cout << "\nThe numbers are "<< num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << " " << num6 << endl;
			//largest
			if(num1>num2 && num1>num3 && num1 > num4 && num1 > num4 && num5> num6)
			{
				cout << "Largest:" << num1 << endl;
			}
			else if(num2 > num1 && num2 > num3 && num2 >num4 && num2 > num4 && num2> num6)
			{
				cout << "Largest:" << num2 << endl;
			}
			else if (num3 > num1 && num3 > num2 && num3 > num4 && num3 > num5 && num4> num6)
			{
				cout << "Largest:" << num3 << endl;
			}
			else if(num4 > num1 && num4 > num2 && num4 > num3 && num4 > num4 && num4> num6)
			{
				cout << "Largest:" << num4 << endl;
			}
			else if(num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4 && num5> num6)
			{
				cout << "Largest:" << num5 << endl;
			}
			else if(num6 > num1 && num6 > num2 && num6 > num3 && num6 > num4 && num6> num5)
			{
				cout << "Largest:" << num6 << endl;
			}
			
			//smallest
			if (num1<num2 && num1<num3 && num1< num4 && num1 <num5  &&num1 <num6)
			{
				cout << "Smallest:" << num1 << endl;
			}
			else if(num2<num2 && num2<num3 && num2 < num4 && num2 <num5  &&num2 <num6)
			{
				cout << "Smallest:" << num2 << endl;
			}
			else if (num3 < num1 && num3 < num2 && num3 < num4 && num3 <num5  &&num3 <num6)
			{
				cout << "Smallest:" << num3 << endl;
			}
			else if (num4 < num1 && num4 < num2 && num4 < num3 && num4 <num5 &&num4 <num6)
			{
				cout << "Smallest:" << num4 << endl;
			}
			else if (num5 < num1 && num5 < num2 && num5 < num3 && num5< num4 &&num5 <num6)
			{
				cout << "Smallest:" << num5 << endl;
			}
			else if (num6 < num1 && num6 < num2 && num6 < num3 && num6< num4 && num6 <num5)
			{
				cout << "Smallest:" << num6 << endl;
			}
			cout << "Sum:" << num1+num2+num3+num4+num5+num6 << endl;
			cout << "Average:" << (num1+num2+num3+num4+num5+num6)/amountrand << endl;
			cout << "Standard Deviation:"<< output <<endl;
		}
		else if (amountrand == 7)
		{
			srand(time(0));
			num1 = 10 + (rand() % (50 - 10 +1));
			num2 = 10 + (rand() % (50 - 10 +1));
			num3 = 10 + (rand() % (50 - 10 +1));
			num4 = 10 + (rand() % (50 - 10 +1));
			num5 = 10 + (rand() % (50 - 10 +1));
			num6 = 10 + (rand() % (50 - 10 +1));
			num7 = 10 + (rand() % (50 - 10 +1));
			
			//deviation math
			w1 = (num1*num1)+ (num2*num2) * (num3 + num3) * (num4 + num4) * (num5 +num5) * (num6+num6) *(num7+num7);
			w2 = (num1 + num2 + num3 +num4+num5+num6+num7) * (num1 + num2 + num3 +num4+num5+num6+num7);
			
			output = (w1-(w2/amountrand))/(amountrand -1);
			output = sqrt(output);
			
			cout << "\nThe numbers are "<< num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << " " << num6 << " " << num7 << endl;
			//largest
			if(num1>num2 && num1>num3 && num1 > num4 && num1 > num4 && num5> num6 && num1 > num7)
			{
				cout << "Largest:" << num1 << endl;
			}
			else if(num2 > num1 && num2 > num3 && num2 >num4 && num2 > num4 && num2> num6 && num2 > num7)
			{
				cout << "Largest:" << num2 << endl;
			}
			else if (num3 > num1 && num3 > num2 && num3 > num4 && num3 > num5 && num4> num6 && num3 > num7)
			{
				cout << "Largest:" << num3 << endl;
			}
			else if(num4 > num1 && num4 > num2 && num4 > num3 && num4 > num4 && num4> num6 && num4 > num7)
			{
				cout << "Largest:" << num4 << endl;
			}
			else if(num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4 && num5> num6 && num5 > num7)
			{
				cout << "Largest:" << num5 << endl;
			}
			else if(num6 > num1 && num6 > num2 && num6 > num3 && num6 > num4 && num6> num5 && num6 > num7)
			{
				cout << "Largest:" << num6 << endl;
			}
			else if(num7 > num1 && num7 > num2 && num7 > num3 && num7 > num4 && num7> num5 && num7 > num6)
			{
				cout << "Largest:" << num7 << endl;
			}
			
			//smallest
			if (num1<num2 && num1<num3 && num1< num4 && num1 <num5  &&num1 <num6 &&num1 < num7)
			{
				cout << "Smallest:" << num1 << endl;
			}
			else if(num2<num2 && num2<num3 && num2 < num4 && num2 <num5  &&num2 <num6 &&num2 < num7)
			{
				cout << "Smallest:" << num2 << endl;
			}
			else if (num3 < num1 && num3 < num2 && num3 < num4 && num3 <num5  &&num3 <num6 &&num3 < num7)
			{
				cout << "Smallest:" << num3 << endl;
			}
			else if (num4 < num1 && num4 < num2 && num4 < num3 && num4 <num5 &&num4 <num6 &&num4 < num7)
			{
				cout << "Smallest:" << num4 << endl;
			}
			else if (num5 < num1 && num5 < num2 && num5 < num3 && num5< num4 &&num5 <num6 &&num5 < num7)
			{
				cout << "Smallest:" << num5 << endl;
			}
			else if (num6 < num1 && num6 < num2 && num6 < num3 && num6< num4 && num6 <num5 &&num6 < num7)
			{
				cout << "Smallest:" << num6 << endl;
			}
			else if (num7 < num1 && num7 < num2 && num7 < num3 && num7< num4 && num7 <num5 && num7< num6)
			{
				cout << "Smallest:" << num7 << endl;
			}
			cout << "Sum:" << num1+num2+num3+num4+num5+num6+num7 << endl;
			cout << "Average:" << (num1+num2+num3+num4+num5+num6+num7)/amountrand << endl;
			cout << "Standard Deviation:"<< output <<endl;
		}
		else if (amountrand == 8)
		{
			srand(time(0));
			num1 = 10 + (rand() % (50 - 10 +1));
			num2 = 10 + (rand() % (50 - 10 +1));
			num3 = 10 + (rand() % (50 - 10 +1));
			num4 = 10 + (rand() % (50 - 10 +1));
			num5 = 10 + (rand() % (50 - 10 +1));
			num6 = 10 + (rand() % (50 - 10 +1));
			num7 = 10 + (rand() % (50 - 10 +1));
			num8 = 10 + (rand() % (50 - 10 +1));
			
			//deviation math
			w1 = (num1*num1)+ (num2*num2) * (num3 + num3) * (num4 + num4) * (num5 +num5) * (num6+num6) *(num7+num7) *(num8+num8);
			w2 = (num1 + num2 + num3 +num4+num5+num6+num7 +num8) * (num1 + num2 + num3 +num4+num5+num6+num7 +num8);
			
			output = (w1-(w2/amountrand))/(amountrand -1);
			output = sqrt(output);
			
			
			cout << "\nThe numbers are "<< num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << " " << num6 << " " << num7 << " " << num8 << endl;
			//largest
			if(num1>num2 && num1>num3 && num1 > num4 && num1 > num4 && num5> num6 && num1 > num7 && num1 > num8)
			{
				cout << "Largest:" << num1 << endl;
			}
			else if(num2 > num1 && num2 > num3 && num2 >num4 && num2 > num4 && num2> num6 && num2 > num7 && num2 > num8)
			{
				cout << "Largest:" << num2 << endl;
			}
			else if (num3 > num1 && num3 > num2 && num3 > num4 && num3 > num5 && num4> num6 && num3 > num7 && num3 > num8)
			{
				cout << "Largest:" << num3 << endl;
			}
			else if(num4 > num1 && num4 > num2 && num4 > num3 && num4 > num4 && num4> num6 && num4 > num7 && num4 > num8)
			{
				cout << "Largest:" << num4 << endl;
			}
			else if(num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4 && num5> num6 && num5 > num7 && num5 > num8)
			{
				cout << "Largest:" << num5 << endl;
			}
			else if(num6 > num1 && num6 > num2 && num6 > num3 && num6 > num4 && num6> num5 && num6 > num7 && num6 > num8)
			{
				cout << "Largest:" << num6 << endl;
			}
			else if(num7 > num1 && num7 > num2 && num7 > num3 && num7 > num4 && num7> num5 && num7 > num6 && num7 > num8)
			{
				cout << "Largest:" << num7 << endl;
			}
			else if(num8 > num1 && num8 > num2 && num8 > num3 && num8 > num4 && num8> num5 && num8 > num6 && num8 > num7)
			{
				cout << "Largest:" << num8 << endl;
			}
			
			//smallest
			if (num1<num2 && num1<num3 && num1< num4 && num1 <num5  &&num1 <num6 &&num1 < num7 && num1 <num8)
			{
				cout << "Smallest:" << num1 << endl;
			}
			else if(num2<num2 && num2<num3 && num2 < num4 && num2 <num5  &&num2 <num6 &&num2 < num7 && num2 <num8)
			{
				cout << "Smallest:" << num2 << endl;
			}
			else if (num3 < num1 && num3 < num2 && num3 < num4 && num3 <num5  &&num3 <num6 &&num3 < num7 && num3 <num8)
			{
				cout << "Smallest:" << num3 << endl;
			}
			else if (num4 < num1 && num4 < num2 && num4 < num3 && num4 <num5 &&num4 <num6 &&num4 < num7 && num4 <num8)
			{
				cout << "Smallest:" << num4 << endl;
			}
			else if (num5 < num1 && num5 < num2 && num5 < num3 && num5< num4 &&num5 <num6 &&num5 < num7 && num5 <num8)
			{
				cout << "Smallest:" << num5 << endl;
			}
			else if (num6 < num1 && num6 < num2 && num6 < num3 && num6< num4 && num6 <num5 &&num6 < num7 && num6 <num8)
			{
				cout << "Smallest:" << num6 << endl;
			}
			else if (num7 < num1 && num7 < num2 && num7 < num3 && num7< num4 && num7 <num5 && num7< num6 && num7 <num8)
			{
				cout << "Smallest:" << num7 << endl;
			}
			else if (num8 < num1 && num8 < num2 && num8 < num3 && num8< num4 && num8 <num5 && num8< num6&& num8 < num7)
			{
				cout << "Smallest:" << num8 << endl;
			}
			cout << "Sum:" << num1+num2+num3+num4+num5+num6+num7+num8 << endl;
			cout << "Average:" << (num1+num2+num3+num4+num5+num6+num7+num8)/amountrand << endl;
			cout << "Standard Deviation:"<< output <<endl;
		}
		else if (amountrand == 9)
		{
			srand(time(0));
			num1 = 10 + (rand() % (50 - 10 +1));
			num2 = 10 + (rand() % (50 - 10 +1)); 
			num3 = 10 + (rand() % (50 - 10 +1));
			num4 = 10 + (rand() % (50 - 10 +1)); 
			num5 = 10 + (rand() % (50 - 10 +1));
			num6 = 10 + (rand() % (50 - 10 +1));
			num7 = 10 + (rand() % (50 - 10 +1));
			num8 = 10 + (rand() % (50 - 10 +1));
			num9 = 10 + (rand() % (50 - 10 +1));
			
			//deviation math
			w1 = (num1*num1)+ (num2*num2) * (num3 + num3) * (num4 + num4) * (num5 +num5) * (num6+num6) *(num7+num7) *(num8+num8)* (num9+num9);
			w2 = (num1 + num2 + num3 +num4+num5+num6+num7 +num8+num9) * (num1 + num2 + num3 +num4+num5+num6+num7 +num8+num9);
			
			output = (w1-(w2/amountrand))/(amountrand -1);
			output = sqrt(output);
			
			cout << "\nThe numbers are "<< num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << " " << num6 << " " << num7 << " " << num8 << " " << num9 << endl;
			//largest
			if(num1>num2 && num1>num3 && num1 > num4 && num1 > num4 && num5> num6 && num1 > num7 && num1 > num8 && num1 > num9)
			{
				cout << "Largest:" << num1 << endl;
			}
			else if(num2 > num1 && num2 > num3 && num2 >num4 && num2 > num4 && num2> num6 && num2 > num7 && num2 > num8 && num2 > num9)
			{
				cout << "Largest:" << num2 << endl;
			}
			else if (num3 > num1 && num3 > num2 && num3 > num4 && num3 > num5 && num4> num6 && num3 > num7 && num3 > num8 && num3 > num9)
			{
				cout << "Largest:" << num3 << endl;
			}
			else if(num4 > num1 && num4 > num2 && num4 > num3 && num4 > num4 && num4> num6 && num4 > num7 && num4 > num8 && num4 > num9)
			{
				cout << "Largest:" << num4 << endl;
			}
			else if(num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4 && num5> num6 && num5 > num7 && num5 > num8 && num5 > num9)
			{
				cout << "Largest:" << num5 << endl;
			}
			else if(num6 > num1 && num6 > num2 && num6 > num3 && num6 > num4 && num6> num5 && num6 > num7 && num6 > num8 && num6 > num9)
			{
				cout << "Largest:" << num6 << endl;
			}
			else if(num7 > num1 && num7 > num2 && num7 > num3 && num7 > num4 && num7> num5 && num7 > num6 && num7 > num8 && num7 > num9)
			{
				cout << "Largest:" << num7 << endl;
			}
			else if(num8 > num1 && num8 > num2 && num8 > num3 && num8 > num4 && num8> num5 && num8 > num6 && num8 > num7 && num8 > num9)
			{
				cout << "Largest:" << num8 << endl;
			}
			else if(num9 > num1 && num9 > num2 && num9 > num3 && num9 > num4 && num9> num5 && num9 > num6 && num9 > num7 && num9 > num8)
			{
				cout << "Largest:" << num9 << endl;
			}
			
			//smallest
			if (num1<num2 && num1<num3 && num1< num4 && num1 <num5  &&num1 <num6 &&num1 < num7 && num1 <num8 && num1 <num9)
			{
				cout << "Smallest:" << num1 << endl;
			}
			else if(num2<num2 && num2<num3 && num2 < num4 && num2 <num5  &&num2 <num6 &&num2 < num7 && num2 <num8 && num2 <num9)
			{
				cout << "Smallest:" << num2 << endl;
			}
			else if (num3 < num1 && num3 < num2 && num3 < num4 && num3 <num5  &&num3 <num6 &&num3 < num7 && num3 <num8 && num3 <num9)
			{
				cout << "Smallest:" << num3 << endl;
			}
			else if (num4 < num1 && num4 < num2 && num4 < num3 && num4 <num5 &&num4 <num6 &&num4 < num7 && num4 <num8 && num4 <num9)
			{
				cout << "Smallest:" << num4 << endl;
			}
			else if (num5 < num1 && num5 < num2 && num5 < num3 && num5< num4 &&num5 <num6 &&num5 < num7 && num5 <num8 && num5 <num9)
			{
				cout << "Smallest:" << num5 << endl;
			}
			else if (num6 < num1 && num6 < num2 && num6 < num3 && num6< num4 && num6 <num5 &&num6 < num7 && num6 <num8 && num6 <num9)
			{
				cout << "Smallest:" << num6 << endl;
			}
			else if (num7 < num1 && num7 < num2 && num7 < num3 && num7< num4 && num7 <num5 && num7< num6 && num7 <num8 && num7 <num9)
			{
				cout << "Smallest:" << num7 << endl;
			}
			else if (num8 < num1 && num8 < num2 && num8 < num3 && num8< num4 && num8 <num5 && num8< num6&& num8 < num7 && num8 <num9)
			{
				cout << "Smallest:" << num8 << endl;
			}
			else if (num9 < num1 && num9 < num2 && num9 < num3 && num9< num4 && num9 <num5 && num9< num6&& num9 < num7 && num9 <num8)
			{
				cout << "Smallest:" << num9 << endl;
			}
			cout << "Sum:" << num1+num2+num3+num4+num5+num6+num7+num8+num9 << endl;
			cout << "Average:" << (num1+num2+num3+num4+num5+num6+num7+num8+num9)/amountrand << endl;
			cout << "Standard Deviation:"<< output <<endl;
		}
		b1 = false;
	
	
	//Extra Credit
	cout << "\nWould you like to process another set of numbers ('Y' for yes)?"; 
	cin >> proc;
	if (proc == "Y")
	{
		b1 = true;
	}
	else if (proc == "N")
	{
		b1 = false;
		continue;
	}
	else
	{
		cout << "You did not enter a valid letter";
	}
}
	
}
