#include "Stack.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
   {
   cout << "Testing default constructor\n\n";

   Stack<int> s1;

   cout << "s1 (size " << s1.size() << "): " << s1 << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "Testing push()\n\n";

   s1.push(17);

   cout << "s1 (size " << s1.size() << "): " << s1 << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   s1.push(2);
   s1.push(6);
   s1.push(4);

   cout << "s1 (size " << s1.size() << "): " << s1 << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "Testing copy constructor\n\n";
   Stack<int> s2(s1);

   cout << "s1 (size " << s1.size() << "): " << s1 << endl;
   cout << "s2 (size " << s2.size() << "): " << s2 << endl << endl;

   cout << "Testing clear()\n\n";
   s1.clear();

   cout << "s1 (size " << s1.size() << "): " << s1 << endl;
   cout << "s2 (size " << s2.size() << "): " << s2 << endl << endl;

   Stack<int> s3;

   s3.push(36);
   s3.push(41);
   s3.push(75);
   s3.push(28);

   cout << "s3 (size " << s3.size() << "): " << s3 << endl << endl;

   cout << "Testing assignment operator\n\n";

   Stack<int> s4;

   s4 = s3;

   cout << "s3 (size " << s3.size() << "): " << s3 << endl;
   cout << "s4 (size " << s4.size() << "): " << s4 << endl << endl;


   s3.clear();

   cout << "s3 (size " << s3.size() << "): " << s3 << endl;
   cout << "s4 (size " << s4.size() << "): " << s4 << endl << endl;

   cout << "Testing assignment to self\n\n";

   s4 = s4;
   s3 = s4;
   s4.clear();

   cout << "s3 (size " << s3.size() << "): " << s3 << endl;
   cout << "s4 (size " << s4.size() << "): " << s4 << endl << endl;

   cout << "Testing chained assignment\n\n";

   Stack<int> s5;

   s5 = s4 = s3;

   cout << "s3 (size " << s3.size() << "): " << s3 << endl;
   cout << "s4 (size " << s4.size() << "): " << s4 << endl;
   cout << "s5 (size " << s5.size() << "): " << s5 << endl << endl;

   cout << "Testing top(), push(), pop()\n\n";

   Stack<char> s6, s7;

   for(char c = 'a'; c < 'k'; c++)
      s6.push(c);

   cout << "s6 (size " << s6.size() << "): " << s6 << endl << endl;

   for(int i = 0; i < 10; i++)
      {
      int val;

      val = s6.top();
      s7.push(val);
      s6.pop();
      }

   cout << "s6 (size " << s6.size() << "): " << s6 << endl;
   cout << "s7 (size " << s7.size() << "): " << s7 << endl << endl;

   cout << "Testing top()\n";
   
   s6 = s7;

   int val1 = s6.top();
   int val2 = s7.top();
   val1 = s6.top();    // Make sure that top() doesn't remove a value.

   cout << ((val1 == val2) ? "top() works\n\n" : "top() failure\n\n");

   cout << "Testing const correctness\n\n";

   s7.clear();
   const Stack<char>& r6 = s6;

   cout << "s6 (size " << r6.size() << "): " << r6 << endl;
   cout << "s6 is " << ((r6.empty()) ? "empty\n" : "not empty\n");
   cout << "Top item of s6: " << r6.top() << endl << endl;

   s7 = r6;
   Stack<char> s8(r6);

   cout << "s7 (size " << s7.size() << "): " << s7 << endl;
   cout << "s8 (size " << s8.size() << "): " << s8 << endl << endl;

   return 0;
   }
