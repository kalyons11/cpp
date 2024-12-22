#include <iostream>  // for std::cout

/*
 * Notes:
 * Nested functions are not supported
 * Functions should do one and only one task
 * Forward declarations avoid the need for complex checking of dependency order
 */

void doPrint()
{
  std::cout << "In doPrint()\n";
}

int getValueFromUser()
{
  std::cout << "Enter an integer: ";
  int input{};
  std::cin >> input;

  return input;  // return the value the user entered back to the caller
}

// This function has two integer parameters, one named x, and one named y
// The values of x and y are passed in by the caller
// Pass by value - values are copied in
void printValues(int x, int y)
{
  std::cout << x << '\n';
  std::cout << y << '\n';
}

void doSomething(int /*count*/)
{
}

int doubleNumber(int num)
{
  return num * 2;
}

// Function declaration
int add(int x, int y);

// Definition of function main()
int main()
{
  std::cout << "Starting main()\n";
  doPrint();  // doPrint() called for the first time
  doPrint();  // doPrint() called for the second time
  std::cout << "Ending main()\n";

  int num{getValueFromUser()};

  std::cout << num << " doubled is: " << num * 2 << '\n';

  printValues(2, 3);
  doSomething(2);

  std::cout << doubleNumber(100) << "\n";

  std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';

  return 0;
}

int add(int x, int y)  // even though the body of add() isn't defined until here
{
  return x + y;
}
