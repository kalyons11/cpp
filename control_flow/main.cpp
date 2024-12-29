#include <iostream>

int main()
{
    std::cout << "Let's talk about control flow." << '\n';

    std::cout << "Enter a number: ";
    int number{};
    std::cin >> number;
    std::cout << "You entered: " << number << '\n';
    if (number >= 10)
        std::cout << "The number is greater than or equal to 10." << '\n';
    else
        std::cout << "The number is less than 10." << '\n';
}
