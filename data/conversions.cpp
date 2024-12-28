#include <iostream>

#include "conversions.hpp"

void print(int x)
{
    std::cout << x << '\n';
}

void run_type_conversions()
{
    print(42);
    print(static_cast<int>(3.14));  // explicit conversion

    char c{'a'};
    std::cout << c << '\n';
    print(static_cast<int>(c));

    unsigned int u{42};
    int i{static_cast<int>(u)};
    std::cout << i << '\n';

    int j{100};
    unsigned int v{static_cast<unsigned int>(j)};
    std::cout << v << '\n';

    // Let's see how this works with modulo arithmetic
    int s{-1};
    unsigned int t{static_cast<unsigned int>(s)};
    std::cout << t << '\n';

    unsigned int a{4294967295};
    int b{static_cast<int>(a)};
    std::cout << b << '\n';

    // Fixed size integers can behave strangely
    std::int8_t x{65};
    std::cout << static_cast<int>(x) << '\n';  // 65

    std::cout << "Enter a single character: ";
    char ch{};
    std::cin >> ch;
    std::cout << "You entered: '" << ch << "', which has ASCII code "
              << static_cast<int>(ch) << "." << '\n';
}
