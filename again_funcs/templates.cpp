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

// We can have template functions with non-template parameters
template <typename T>
void print_with_precision(T value, int precision = 10)
{
    std::cout.precision(precision);
    std::cout << value << '\n';
}

// We can use template specialization to delete specific template functions
template <>
void print_with_precision(std::string value, int precision) = delete;

// To forward delcare min we can use std::common_type_t
template <typename T, typename U>
auto min(T a, U b) -> std::common_type_t<T, U>;

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

    print_with_precision(1.23456789, 5);
    print_with_precision(1.23456789f, 5);
    print_with_precision(1.23456789, 10);
    print_with_precision(1.23456789f);
    // print_with_precision("Hello", 5);  // This will not compile

    std::cout << min(1, 2.2) << '\n';
    std::cout << min(1.1, 2) << '\n';
    std::cout << min(1, 2) << '\n';
    std::cout << min(1.1, 2.2) << '\n';
}

// We can use multiple types in a template
template <typename T, typename U>
// We need to use auto to return the correct type
auto min(T a, U b) -> std::common_type_t<T, U>
{
    return (a < b) ? a : b;
}
