#include <array>
#include <iostream>
#include <vector>

#include "intro.hpp"

void demo_array()
{
    // We can compare creating an array and vector
    [[maybe_unused]] std::array<int, 5>
        a{};  // The size of the array is fixed an known at compile-time

    [[maybe_unused]] std::vector<int> b(5);

    // The length of a std::array must be constexpr
    [[maybe_unused]] std::array<int, 3> nums{
        1, 2, 3};  // list initialization (preferred)

    // Prefer zero-initialization with braces to avoid elements being undefined
    [[maybe_unused]] std::array<int, 1> init{};
    [[maybe_unused]] std::vector<int> other(1);
    // Members are value initializated (ints would be 0)

    // More elements are not allowed, but fewer are
    // Remaining are value initialized
    // std::array<int, 4> x { 1, 2, 3, 4, 5 }; // compile error: too many
    // initializers
    [[maybe_unused]] std::array<int, 4> y{
        1, 2};  // b[2] and b[3] are value initialized

    // We really want to make our std::arrays constexpr to take advantage
    [[maybe_unused]] constexpr std::array<int, 5> prime{2, 3, 5, 7, 11};
}
