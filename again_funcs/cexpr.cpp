#include <iostream>

#include "cexpr.hpp"

constexpr double get_circumference(double radius)
{
    return 2 * 3.14159 * radius;
}

// constexpr functions can also be evaluated at runtime
constexpr int max(int a, int b)
{
    return a > b ? a : b;
}

// We can use consteval to enforce compile-time evaluation
consteval int max(int a, int b, int c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

void show_cexpr_funcs()
{
    constexpr double radius = 5.0;
    constexpr double circumference = get_circumference(radius);
    std::cout << "Circumference of a circle with radius " << radius << " is "
              << circumference << \n;

    int a = 10;
    int b = 20;
    int max_val = max(a, b);
    std::cout << "Max value between " << a << " and " << b << " is " << max_val
              << \n;

    constexpr int x = 30;
    constexpr int y = 40;
    constexpr int z = 50;
    int max_val_3 = max(x, y, z);
    std::cout << "Max value between " << x << ", " << y << " and " << z
              << " is " << max_val_3 << \n;
}
