#include <iostream>

#include "arithmetic.hpp"

void show_arithmetic_operators()
{
    // Unary arithmetic operators
    int x{5};
    int y = -x;  // y is -5
    std::cout << "Unary minus: " << y << '\n';
    int z = +x;  // z is 5
    std::cout << "Unary plus: " << z << '\n';

    // Binary arithmetic operators
    int a{5};
    int b{4};
    int c = a + b;  // c is 9
    std::cout << "Addition: " << c << '\n';
    int d = a - b;  // d is 1
    std::cout << "Subtraction: " << d << '\n';
    int e = a * b;  // e is 20
    std::cout << "Multiplication: " << e << '\n';
    int f = a / b;  // f is 1
    std::cout << "Division: " << f << '\n';
    int g = a % b;  // g is 1
    std::cout << "Modulus: " << g << '\n';

    // Floating point vs integer division
    double h = 5.0 / 4;  // h is 1.25
    std::cout << "Floating point division: " << h << '\n';
    double i = 5 / 4;  // i is 1.0
    std::cout << "Integer division: " << i << '\n';

    // We can use static_cast to force the division to be floating point
    constexpr int one{7};
    constexpr int two{4};
    std::cout << "int / int = " << one / two << '\n';  // prints 1
    std::cout << "double / int = " << static_cast<double>(one) / two
              << '\n';  // prints 1.75
    std::cout << "int / double = " << one / static_cast<double>(two)
              << '\n';  // prints 1.75
    std::cout << "double / double = "
              << static_cast<double>(one) / static_cast<double>(two)
              << '\n';  // prints 1.75

    // Arithmetic assignment operators
    int j{5};
    j += 3;  // equivalent to j = j + 3, j is now 8
    std::cout << "Addition assignment: " << j << '\n';
    j -= 4;  // equivalent to j = j - 4, j is now 4
    std::cout << "Subtraction assignment: " << j << '\n';
    j *= 2;  // equivalent to j = j * 2, j is now 8
    std::cout << "Multiplication assignment: " << j << '\n';
    j /= 2;  // equivalent to j = j / 2, j is now 4
    std::cout << "Division assignment: " << j << '\n';
    j %= 3;  // equivalent to j = j % 3, j is now 1
    std::cout << "Modulus assignment: " << j << '\n';
}
