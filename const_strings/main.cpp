#include <iostream>

#include "constexpr.hpp"
#include "numerals.hpp"
#include "quiz.hpp"
#include "string.hpp"
#include "string_views.hpp"

// Best practice: Don’t use const for value parameters, since it doesn’t provide
// any benefit Also, don’t use const for return values, since it doesn’t provide
// any benefit
void printInt(const int value)
{
    std::cout << value << '\n';
}

int main()
{
    // Make variables constant whenever possible
    // Prefer constant variables over object-like macros with substitution text
    const char* str = "Hello, World!";
    std::cout << str << '\n';

    [[maybe_unused]] const double gravity{9.8};

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    const int constAge{age};
    std::cout << "Your age is: " << constAge << '\n';
    // age = 30;  // This is allowed
    // constAge = 40; // This is not allowed

    printInt(5);
    printInt(12);

    print_numeral_systems();
    output_constexpr();
    do_strings();
    expose_string_views();
    run_quiz();

    return 0;
}