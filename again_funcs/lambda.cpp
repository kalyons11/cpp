#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

#include "lambda.hpp"

void show_lambdas()
{
    constexpr std::array<std::string_view, 4> arr{"apple", "banana", "wal",
                                                  "lemon"};

    // Find a value
    std::string value{"app"};
    auto found{
        std::find_if(arr.begin(), arr.end(), [value](std::string_view str)
                     { return str.find(value) != std::string_view::npos; })};

    if (found != arr.end())
    {
        std::cout << *found << '\n';
    }
    else
    {
        std::cout << "Could not find nut." << '\n';
    }

    auto isEven{[](int i) { return (i % 2) == 0; }};
    std::array<int, 5> numbers{1, 2, 3, 4, 5};
    auto allEven = std::all_of(numbers.begin(), numbers.end(), isEven);
    std::cout << "All in numbers are even? " << std::boolalpha << allEven
              << '\n';
    std::cout << std::noboolalpha;
}
