#include <iostream>

#include "intro.hpp"

int return_5()
{
    return 5;
}

void show_basics()
{
    // l-values and r-values
    int x = 42;     // x is an l-value
    int y = x;      // x is an l-value, y is an l-value
    int z = x + y;  // x is an l-value, y is an l-value, z is an l-value

    int a{5};              // a is an l-value, 5 is an r-value
    int b{a};              // a is an l-value, b is an l-value
    const double d{3.14};  // d is an l-value, 3.14 is an r-value
    const double e{d};     // d is an l-value, e is an l-value
    // d is non-modifiable

    int five = return_5();  // return_5() is an r-value, five is an l-value
    int six{five + 1};      // five + 1 is an r-value, six is an l-value
    int q{static_cast<int>(
        d)};  // static_cast<int>(d) is an r-value, q is an l-value

    // l-values will implicitly convert to r-values when needed
    int r{5};  // 5 is an r-value
    int s{r};  // r is an l-value, s is an l-value

    // Print all the values defined above
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
    std::cout << "z: " << z << '\n';
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    std::cout << "d: " << d << '\n';
    std::cout << "e: " << e << '\n';
    std::cout << "five: " << five << '\n';
    std::cout << "six: " << six << '\n';
    std::cout << "q: " << q << '\n';
    std::cout << "r: " << r << '\n';
    std::cout << "s: " << s << '\n';
}
