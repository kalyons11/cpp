#include <iostream>

#include "templates.hpp"

// We can use function templates to create a function that can work with many
// different types
int sub(int a, int b)
{
    return a - b;
}

double sub(double a, double b)
{
    return a - b;
}

template <typename T>
T sub(T a, T b)
{
    return a - b;
}

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
void print(T value)
{
    std::cout << value << '\n';
}

void print(bool value)
{
    std::cout << std::boolalpha << value << '\n';
}

void do_templates()
{
    // We can call the function with different types
    std::cout << sub(1, 2) << '\n';
    std::cout << sub(1.1, 2.2) << '\n';
    std::cout << sub(1.1f, 2.2f) << '\n';

    print(1);
    print(1.1);
    print(1.1f);
    print(true);       // This will call the overloaded function for bool
    print<int>(true);  // This will call the template function for int
}
