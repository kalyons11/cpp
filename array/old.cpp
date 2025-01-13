#include <array>
#include <iostream>

#include "old.hpp"

void show_c_style()
{
    [[maybe_unused]] int scores[30]{};
    // in comparison
    [[maybe_unused]] std::array<int, 30> scores2{};

    // We can use [] to get and set values in a C-style array
    scores[0] = 10;
    std::cout << "C-style array first element: " << scores[0] << '\n';

    scores2[0] = 20;
    std::cout << "std::array first element: " << scores2[0] << '\n';

    // We can use aggregate initialization with a list of elements
    int scores3[5] = {1, 2, 3, 4, 5};
    std::array<int, 5> scores4 = {6, 7, 8, 9, 10};

    std::cout << "C-style array elements: ";
    for (int score : scores3)
    {
        std::cout << score << " ";
    }
    std::cout << '\n';

    std::cout << "std::array elements: ";
    for (int score : scores4)
    {
        std::cout << score << " ";
    }
    std::cout << '\n';

    // We can omit the length during initialization and it will be inferred
    int scores5[] = {11, 12, 13, 14, 15};
    std::array<int, 5> scores6 = {16, 17, 18, 19, 20};

    std::cout << "C-style array with inferred length elements: ";
    for (int score : scores5)
    {
        std::cout << score << " ";
    }
    std::cout << '\n';

    std::cout << "std::array with inferred length elements: ";
    for (int score : scores6)
    {
        std::cout << score << " ";
    }
    std::cout << '\n';

    // We can use std::size and std::ssize to get the length
    std::cout << "Length of C-style array scores3: " << std::size(scores3)
              << '\n';
    std::cout << "Length of std::array scores4: " << std::size(scores4) << '\n';

    std::cout << "Length of C-style array scores5: " << std::size(scores5)
              << '\n';
    std::cout << "Length of std::array scores6: " << std::size(scores6) << '\n';

    // C-style arrays are not modifiable l-values so we can't assign to them
    // directly after they've been initialized scores3 = {21, 22, 23, 24, 25};
    // // This will cause a compilation error scores4 = {26, 27, 28, 29, 30}; //
    // This is valid for std::array
    scores4 = {26, 27, 28, 29, 30};
    std::cout << "Modified std::array elements: ";
    for (int score : scores4)
    {
        std::cout << score << " ";
    }
    std::cout << '\n';
}
