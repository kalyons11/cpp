#include <iostream>

int main()
{
  std::cout << "Enter an integer: ";
  int x{};
  std::cin >> x;
  // Evaluate the expression x * 2 rather than saving to some intermediate
  // variable
  std::cout << x << " * 2 = " << x * 2 << "\n";
  std::cout << x << " * 3 = " << x * 3 << "\n";
  return 0;
}
