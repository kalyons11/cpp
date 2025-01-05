#include <iostream>
#include <vector>

#include "loop.hpp"

void run_loop()
{
    // We can create a vector and then loop over its values
    const std::vector<char> vec{'a', 'b', 'c'};
    std::cout << "Here are the contents of vec: ";
    const std::size_t s = vec.size();
    for (std::size_t i{0}; i < s; ++i)
    {
        std::cout << vec[i];
    }
    std::cout << '\n';
}
