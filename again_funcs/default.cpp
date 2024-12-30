#include <iostream>

#include "default.hpp"

// We can provide default arguments to functions
void printInt(int a, int b = 0)
{
    std::cout << "printInt: " << a << ", " << b << '\n';
}

// Multiple default arguments are allowed
void printOther(int a, int b = 1, int c = 2, int d = 3)
{
    std::cout << "printOther: " << a << ", " << b << ", " << c << ", " << d
              << '\n';
}

void show_default_args()
{
    std::cout << "Default arguments" << '\n';
    printInt(1);
    printInt(1, 2);
    // We can't skip an argument
    // printInt();

    printOther(1, 2, 3, 4);
    printOther(1, 2, 3);
    printOther(1, 2);
    printOther(1);
}
