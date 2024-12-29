#include <iostream>

#include "switch.hpp"

int calculate(int x, int y, char operation)
{
    switch (operation)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        std::cout << "Invalid operation." << '\n';
        return 0;
    }
}

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
        // We can use a fallthrough attribute to go to the next case
        std::cout << "You entered 2, and I'm falling through to the next case."
                  << '\n';
        [[fallthrough]];
    case 3:
        std::cout << "You entered 3." << '\n';
        break;
    case 4:
    case 5:
    default:
        std::cout << "You entered a number that is not 1, 2, or 3." << '\n';
        break;
    }

    std::cout << "Enter two numbers and an operation (+, -, *, /): ";
    int x{}, y{};
    char operation{};
    std::cin >> x >> y >> operation;
    std::cout << "Result: " << calculate(x, y, operation) << '\n';
}
