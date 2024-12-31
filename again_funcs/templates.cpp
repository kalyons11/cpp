#include <cmath>
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

// We can also use an abbreviated syntax
auto equals(auto a, auto b)  // a and b can be different types
{
    return a == b;
}

template <typename T, typename U>
auto min_new(T a, U b) -> std::common_type_t<T, U>
{
    return (a < b) ? a : b;
}

template <typename T, typename U, typename V>
T min_new(T a, U b, V c)
{
    return min_new(min_new(a, b), c);
}

// We can use non-type template parameters
template <int N>
void print_n_times(const std::string& str)
{
    for (int i = 0; i < N; ++i)
    {
        std::cout << str << '\n';
    }
}

// We can provide constexpr to the template function
// template <double D>
// double get_sqrt()
// {
//     static_assert(D >= 0, "D must be greater than or equal to 0");
//     if constexpr (D >= 0)
//         return std::sqrt(D);
//     return 0.0;
// }

template <int N>
int factorial()
{
    static_assert(N >= 0, "N must be greater than or equal to 0");
    if constexpr (N == 0)
        return 1;
    else
        return N * factorial<N - 1>();
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

    print_with_precision(1.23456789, 5);
    print_with_precision(1.23456789f, 5);
    print_with_precision(1.23456789, 10);
    print_with_precision(1.23456789f);
    // print_with_precision("Hello", 5);  // This will not compile

    std::cout << min(1, 2.2) << '\n';
    std::cout << min(1.1, 2) << '\n';
    std::cout << min(1, 2) << '\n';
    std::cout << min(1.1, 2.2) << '\n';

    std::cout << equals(1, 1) << '\n';
    std::cout << equals(1.1, 1.1) << '\n';
    std::cout << equals(1, 1.1) << '\n';

    std::cout << min_new(1, 2) << '\n';
    std::cout << min_new(1.1, 2) << '\n';
    std::cout << min_new(1, 2.2) << '\n';
    std::cout << min_new(1, 2, 3) << '\n';

    print_n_times<5>("Hello");
    print_n_times<3>("World");

    // std::cout << get_sqrt<4.0>() << '\n';
    // std::cout << get_sqrt<-1>() << '\n';  // This will not compile

    std::cout << factorial<5>() << '\n';  // 120
    // std::cout << factorial<-1>() << '\n';  // This will not compile
    std::cout << factorial<0>() << '\n';  // 1
}

// We can use multiple types in a template
template <typename T, typename U>
// We need to use auto to return the correct type
auto min(T a, U b) -> std::common_type_t<T, U>
{
    return (a < b) ? a : b;
}
