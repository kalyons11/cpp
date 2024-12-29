#include <iostream>

#include "switch.hpp"

void show_switch()
{
    std::cout << "Let's talk about switch statements." << '\n';

    std::cout << "Enter a number: ";
    int number{};
    std::cin >> number;

    switch (number)  // Must evaluate to an integer or an enumeration type
    {
    case 1:
        std::cout << "You entered 1." << '\n';
        break;
    case 2:
        std::cout << "You entered 2." << '\n';
        break;
    case 3:
        std::cout << "You entered 3." << '\n';
        break;
    default:
        std::cout << "You entered a number that is not 1, 2, or 3." << '\n';
        break;
    }
}
