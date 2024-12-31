#include <iostream>
#include <optional>

#include "optional.hpp"

// We can use std::optional from the C++17 standard to represent an optional
// value that may or may not be present.
std::optional<int> divide(int a, int b)
{
    if (b == 0)
    {
        return std::nullopt;
    }
    return a / b;
}

// We can also use std::optional for optional arguments to a function
void print_optional(std::optional<const int> value = std::nullopt)
{
    if (value)
    {
        std::cout << "Value: " << value.value() << '\n';
    }
    else
    {
        std::cout << "No value" << '\n';
    }
}

void show_optional()
{
    std::optional<int> result = divide(10, 2);
    if (result.has_value())
    {
        std::cout << "Result: " << result.value() << '\n';
    }
    else
    {
        std::cout << "Error: Division by zero" << '\n';
    }

    result = divide(10, 0);
    if (result)
    {
        std::cout << "Result: " << result.value() << '\n';
    }
    else
    {
        std::cout << "Error: Division by zero" << '\n';
    }

    print_optional(42);
    print_optional();
}
