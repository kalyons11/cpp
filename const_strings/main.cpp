#include <iostream>

#include "constexpr.h"
#include "numerals.h"
#include "string.h"

// Best practice: Don’t use const for value parameters, since it doesn’t provide
// any benefit Also, don’t use const for return values, since it doesn’t provide
// any benefit
void printInt(const int value)
{
    std::cout << value << std::endl;
}

int main()
{
    // Make variables constant whenever possible
    // Prefer constant variables over object-like macros with substitution text
    const char* str = "Hello, World!";
    std::cout << str << std::endl;

    [[maybe_unused]] const double gravity{9.8};

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    const int constAge{age};
    std::cout << "Your age is: " << constAge << std::endl;
    // age = 30;  // This is allowed
    // constAge = 40; // This is not allowed

    printInt(5);
    printInt(12);

    print_numeral_systems();

    output_constexpr();

    do_strings();

    return 0;
}