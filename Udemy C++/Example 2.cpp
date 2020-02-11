#include <iostream>

int main() {
  //intialize variabels
  const int dollar_value(100);
  const int quarter_value(25);
  const int dimes_value(10);
  const int nickles_value(5);
  const int pennies_value(1);
  int amount, dollars, quarters, dimes, nickles, pennies;
  int balance;

  std::cout << "Enter a amount in cents: " << std::endl;

  std::cin >> amount;

  balance = dollars = quarters = dimes = nickles = pennies = 0;

  dollars = amount / dollar_value;
  balance = amount % dollar_value;

  std::cout << balance << std::endl;

  quarters = balance / quarter_value;
  balance %= quarter_value;

  dimes = balance / dimes_value;
  balance %= dimes_value;

  nickles = balance /nickles_value;
  balance %= nickles_value;

  pennies = balance;

  //Final output
  std::cout << "Dollars: " << dollars << std::endl;
  std::cout << "Quarters: " << quarters << std::endl;
  std::cout << "Dimes: " << dimes << std::endl;
  std::cout << "Nikcles: " << nickles << std::endl;
  std::cout << "Pennies: " << pennies << std::endl;
}
