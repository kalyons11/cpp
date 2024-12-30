#include <iostream>

#include "goto.h"

void show_goto()
{
    double x{};
tryAgain:
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
    {
        std::cout << "Negative number, try again.\n";
        goto tryAgain;
    }

    std::cout << "You entered " << x << ".\n";
}