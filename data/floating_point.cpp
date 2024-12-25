#include <iomanip>  // for output manipulator std::setprecision()
#include <iostream>

#include "floating_point.h"

// Function to describe and print various floating point values
void describe_floats()
{
    // Declare and initialize floating point variables
    [[maybe_unused]] float f = 4.2f;
    [[maybe_unused]] double d = 3.2;
    [[maybe_unused]] long double x = 23.2242;

    // Declare and initialize variables with different types
    [[maybe_unused]] int a{5};       // 5 means integer
    [[maybe_unused]] double b{5.0};  // 5.0 is a floating point literal (no
                                     // suffix means double type by default)
    [[maybe_unused]] float c{
        5.0f};  // 5.0 is a floating point literal, f suffix means float type

    [[maybe_unused]] int z{0};       // 0 is an integer
    [[maybe_unused]] double e{0.0};  // 0.0 is a double

    // Print some floating point values
    std::cout << "Let's print some floating values." << '\n';
    std::cout << 5.0 << '\n';
    std::cout << 6.7f << '\n';
    std::cout << 9876543.21 << '\n';

    std::cout << 1.23e4 << '\n';   // Scientific notation
    std::cout << 0.00123 << '\n';  // Small floating point number
    std::cout << -3.14 << '\n';    // Negative floating point number
    std::cout << 2.71827 << '\n';  // Another floating point number

    // std::cout truncates to 6 decimal places by default
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';

    // Use an output manipulator to print more decimal places
    std::cout << std::setprecision(17);  // show 17 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f
              << '\n';  // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333
              << '\n';  // no suffix means double
}
