#include <iostream>

#include "goto.hpp"

// goto should really only be used in very specific cases,
// like jumping out of a nested loop
void show_goto_nested_loop()
{
    for (int i{0}; i < 10; ++i)
    {
        for (int j{0}; j < 10; ++j)
        {
            if (i == 5 && j == 5)
            {
                std::cout << "Jumping out of the nested loop.\n";
                goto exitLoop;
            }
        }
    }
exitLoop:;
    std::cout << "Exited the nested loop.\n";
}

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
    show_goto_nested_loop();
}