#include <iostream>

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
}
