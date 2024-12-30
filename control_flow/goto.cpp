#include <iostream>

#include "goto.hpp"

// goto statements can also be used to jump forward
void show_jump_forward(bool skip)
{
    if (skip)
    {
        std::cout << "skip is true, so we're skipping ahead.\n";
        goto skipAhead;
    }
    std::cout << "This will only show if skip is false.\n";
skipAhead:;  // null statement
}

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

    show_jump_forward(true);
    show_jump_forward(false);
}