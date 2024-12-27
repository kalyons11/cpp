#include <iostream>

int five()
{
    return 5;
}

void output_constexpr()
{
    [[maybe_unused]] constexpr double gravity{9.8};
    [[maybe_unused]] constexpr int sum{4 + 5};
    [[maybe_unused]] constexpr int something{sum};

    std::cout << "Enter your age: ";
    [[maybe_unused]] int age{};
    std::cin >> age;

    // constexpr int constAge{age}; // Error: the value of ‘age’ is not usable
    // in a constant expression constexpr int f{five()}; // Error: the value of
    // ‘five()’ is not usable in a constant expression

    std::cout << "Gravity: " << gravity << std::endl;

    [[maybe_unused]] constexpr double d{
        1.2};  // d can be used in constant expressions!
}