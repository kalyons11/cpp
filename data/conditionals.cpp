#include "conditionals.hpp"
#include <iostream>

// Returns the absolute value of a number
int abs(int x)
{
    // Example of an early return
    if (x < 0)
    {
        return -x;
    }
    return x;
}

void do_conditionals()
{
    int num{};
    std::cout << "Enter an integer: ";
    std::cin >> num;

    if (num > 0)
    {
        std::cout << "You entered a positive number.\n";
    }
    else if (num < 0)
    {
        std::cout << "You entered a negative number.\n";
    }
    else
    {
        std::cout << "You entered zero.\n";
    }

    if (num % 2 == 0)
    {
        std::cout << "The given number is even.\n";
    }
    else
    {
        std::cout << "The given number is odd.\n";
    }

    std::cout << "The absolute value of " << num << " is " << abs(num) << '\n';
}
