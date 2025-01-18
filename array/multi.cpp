#include <iostream>

#include "multi.hpp"

// We can have funcs take these in
template <typename T, std::size_t Row, std::size_t Col>
void printArray(const std::array<std::array<T, Col>, Row>& arr)
{
    for (const auto& arow : arr)  // get each array row
    {
        for (const auto& e : arow)  // get each element of the row
            std::cout << e << ' ';

        std::cout << '\n';
    }
}

// An alias template makes this a lot less verbose
template <typename T, std::size_t Row, std::size_t Col>
using Array2D = std::array<std::array<T, Col>, Row>;

template <typename T, std::size_t Row, std::size_t Col>
void printAnother(const Array2D<T, Row, Col>& arr)
{
    for (const auto& row : arr)
    {
        for (const auto& val : row)
        {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }
}

// We can use constexpr to get the row and col sizes of an
// Array2D at compile time
template <typename T, std::size_t Row, std::size_t Col>
constexpr std::size_t getRowCount(const Array2D<T, Row, Col>&)
{
    return Row;
}

template <typename T, std::size_t Row, std::size_t Col>
constexpr std::size_t getColCount(const Array2D<T, Row, Col>&)
{
    return Col;
}

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

    // We can have a 2+D std::array
    std::array<std::array<int, 4>, 3> arr{{// note double braces
                                           {1, 2, 3, 4},
                                           {5, 6, 7, 8},
                                           {9, 10, 11, 12}}};
    printArray(arr);

    Array2D<int, 2, 2> another{{{1, 2}, {3, 4}}};
    printAnother(another);

    Array2D<double, 3, 3> doubleArray{
        {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}}};
    printAnother(doubleArray);

    // Let's get the row and col count of doubleArray using our func
    std::cout << "Row count: " << getRowCount(doubleArray) << '\n';
    std::cout << "Col count: " << getColCount(doubleArray) << '\n';
}
