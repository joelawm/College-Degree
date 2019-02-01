#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
#include <shapes.cpp>

using namespace std;

class Shape
  {
  		//Data Memebers
  		string name;
		//Method Prototypes
		public:
           	Shape(const string&);
			Shape();
			void print();
			double getArea() const;
  };

#endif
