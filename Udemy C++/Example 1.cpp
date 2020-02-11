#include <iostream>
#include <vector>

int main() {
  //declaring setup
  std::vector<int> vector1;
  std::vector<int> vector2;

  //dynamically adding 10 and 20 to vector1
  vector1.push_back(10);
  vector1.push_back(20);

  //dynamically adding 100 and 200 to vector2
  vector2.push_back(100);
  vector2.push_back(200);

  //declare a 2d vector
  std::vector<std::vector<int>> vector_2d;

  //dynamically pushback the vectors
  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  //display the vector_2d
  std::cout << vector_2d.at(0).at(0) << vector_2d.at(0).at(1) << std::endl;
  std::cout << vector_2d.at(1).at(0) << vector_2d.at(1).at(1) << std::endl;  

  //change vector1 at 0 to 1000
  vector1.at(0) = 1000;

  //display the vector_2d
  std::cout << vector_2d.at(0).at(0) << vector_2d.at(0).at(1) << std::endl;
  std::cout << vector_2d.at(1).at(0) << vector_2d.at(1).at(1) << std::endl;  
}
