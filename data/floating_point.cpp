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
    [[maybe_unused]] int a { 5 };      // 5 means integer
    [[maybe_unused]] double b { 5.0 }; // 5.0 is a floating point literal (no suffix means double type by default)
    [[maybe_unused]] float c { 5.0f }; // 5.0 is a floating point literal, f suffix means float type

    [[maybe_unused]] int z { 0 };      // 0 is an integer
    [[maybe_unused]] double e { 0.0 }; // 0.0 is a double

    // Print some floating point values
    std::cout << "Let's print some floating values." << '\n';
    std::cout << 5.0 << '\n';
    std::cout << 6.7f << '\n';
    std::cout << 9876543.21 << '\n';

    std::cout << 1.23e4 << '\n';  // Scientific notation
    std::cout << 0.00123 << '\n'; // Small floating point number
    std::cout << -3.14 << '\n';   // Negative floating point number
    std::cout << 2.71828 << '\n'; // Another floating point number
}
