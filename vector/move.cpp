#include <iostream>
#include <vector>

#include "move.hpp"

// We can return move-capable types by value and the temporary r value
// will be moved instead of copied and destroyed
// For move-capable types we pass by reference and return by value
template <typename T>
std::vector<T> demo_func(std::vector<T>& input)
{
    if (input.size() < 1)
    {
        std::cout << "Input vector is empty" << '\n';
        return input;
    }
    std::vector<T> output{input[0]};
    return output;
}

void describe_move()
{
    // We can copy one vector into another
    std::vector<int> a{1, 2, 3};
    std::vector b{a};

    a[0] = 1;
    b[0] = 2;

    // Each array has different values now at index 0, due to copy semantics
    std::cout << "a[0] = " << a[0] << '\n';
    std::cout << "b[0] = " << b[0] << '\n';

    std::vector<int> result = demo_func(a);
    std::cout << "New result size: " << result.size() << '\n';
}
