#include <iostream>

#include "multi.hpp"

void show_multi_d()
{
    [[maybe_unused]] int board[3][3]{};  // We can have 2D arrays
    board[0][0] = 1;

    // We can initialize using nested braces
    // We can omit the row count but not the column count
    int example[][2]{
        {0, 1},  // first row
        {2, 3},  // second row
    };

    // We can use regular index-based loops, as well as range-based loops
    for (std::size_t row{0}; row < std::size(example); ++row)
    {
        for (std::size_t col{0}; col < std::size(example[0]); ++col)
        {
            std::cout << example[row][col] << ' ';
        }
        std::cout << '\n';
    }

    // We can use a double range-based for loop
    for (const auto& row : example)
    {
        for (const auto& val : row)
        {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }
}
