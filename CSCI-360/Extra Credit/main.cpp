#include <iostream>
int main()
{
  int sum, i;
  for(i = 0; i < 5000; i++)
  {
    sum += i;
  }
  std::cout << sum << std::endl;
  return 0;
}
