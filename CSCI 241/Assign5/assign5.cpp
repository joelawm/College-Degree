/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 5
 PROGRAMMER: your name
 LOGON ID:   your z-ID
 DUE DATE:   due date of assignment
 
 FUNCTION:   This program tests the functionality of the Stack class.
**********************************************************************/

#include <iostream>
#include "Stack.h"

using std::cout;
using std::endl;

int main()
   {
   cout << "Testing default constructor\n\n";
    
   Stack s1;
    
   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "Testing push()\n\n";
    
   for (int i = 10; i < 80; i+= 10)
      s1.push(i);
    
   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   for (int i = 15; i < 85; i+= 10)
      s1.push(i);
    
   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "Testing copy constructor()\n\n";
    
   Stack s2 = s1;
    
   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "Testing top()\n\n";
    
   cout << "Top item of s1: " << s1.top() << endl << endl;
    
   cout << "Testing pop()\n\nTop item of s1: ";
    
   while (!s1.empty())
      {
      cout << s1.top() << ' ';
      s1.pop();
      }
    
   cout << endl << endl;
   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "Testing assignment operator\n\n";
    
   Stack s3;
    
   s3 = s2;
    
   cout << "s2 (size " << s2.size() << "): " << s2 << endl;
   cout << "s3 (size " << s3.size() << "): " << s3 << endl << endl;
    
   cout << "Testing clear()\n\n";
    
   s2.clear();
    
   cout << "s2: " << s2 << endl;
   cout << "s2 size: " << s2.size() << ", capacity: " << s2.capacity() << endl;
   cout << "s2 is " << ((s2.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "s3: " << s3 << endl;
   cout << "s3 size: " << s3.size() << ", capacity: " << s3.capacity() << endl;
   cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "Testing assignment to self and swap\n\n";
    
   s3 = s3;
   s2 = s3;
   s3.clear();
    
   cout << "s2 (size " << s2.size() << "): " << s2 << endl;
   cout << "s3 (size " << s3.size() << "): " << s3 << endl << endl;
    
   cout << "Testing chained assignment\n\n";
    
   Stack s4;
    
   s4 = s3 = s2;
    
   cout << "s2 (size " << s2.size() << "): " << s2 << endl;
   cout << "s3 (size " << s3.size() << "): " << s3 << endl;
   cout << "s4 (size " << s4.size() << "): " << s4 << endl << endl;
    
   Stack s5 = s4;
    
   cout << "s5 (size " << s5.size() << "): " << s5 << endl << endl;
    
   cout << "Testing write version of subscript operator\n\n";
    
   for (size_t i = 0; i < s5.size(); ++i)
      s5[i] += 5;
    
   cout << "s5 (size " << s5.size() << "): " << s5 << endl << endl;
    
   cout << "Testing read version of subscript operator\n\nv5: ";
    
   for (size_t i = 0; i < s5.size(); ++i)
      cout << s5[i] << ' ';
   cout << endl << endl;
    
   cout << "Testing const correctness\n\n";
    
   const Stack& r4 = s4;
    
   cout << "s4: " << r4 << endl;
   cout << "s4 size: " << r4.size() << ", capacity: " << r4.capacity() << endl;
   cout << "s4 is " << ((r4.empty()) ? "empty\n" : "not empty\n");
   cout << "Top item of s4: " << r4.top() << endl;
   cout << "Element 2 of s4: " << r4[2] << endl << endl;
    
   s1 = r4;
    
   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    

   cout << "Testing equality operator\n\n";

   cout << "s1 and s4 are " << ((s1 == s4) ? "equal\n" : "not equal\n");
   cout << "s5 and s4 are " << ((s5 == s4) ? "equal\n" : "not equal\n"); 
   s1.pop();
   cout << "s1 and s4 are now " << ((s1 == s4) ? "equal\n" : "not equal\n");
   cout << endl;
   
   s1.clear();

   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
    
   return 0;
   }
