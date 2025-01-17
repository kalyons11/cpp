#include <iostream>

#include "goto.hpp"
#include "halt.hpp"
#include "loops.hpp"
#include "random.hpp"
#include "switch.hpp"

int main()
{
    std::cout << "Let's talk about control flow." << '\n';

    std::cout << "Enter a number: ";
    int number{};
    std::cin >> number;
    std::cout << "You entered: " << number << '\n';
    const int target{10};
    if (number >= target)
    {
        std::cout << "The number is greater than or equal to " << target << "."
                  << '\n';
    }
    else
    {
        std::cout << "The number is less than " << target << "." << '\n';
    }

    // We can use constexpr with conditionals
    constexpr double gravity{9.8};
    if constexpr (gravity > 9.0)
    {
        std::cout << "The gravity is greater than 9.0." << '\n';
    }
    else
    {
        // This block is not compiled because gravity is greater than 9.0
        std::cout << "The gravity is less than or equal to 9.0." << '\n';
    }

    show_switch();
    show_goto();
    run_loops();
    run_random_numbers();
    show_halting();  // Must be the last function called since it halts the
                     // program

    return 0;
}
