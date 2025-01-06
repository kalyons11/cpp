#include <iostream>
#include <vector>

#include "loop.hpp"

// We can use unscoped enumerations to document the meaning of
// array indices
namespace Test
{
    enum Names
    {
        first,
        second,
        third,
    };
};

void run_loop()
{
    // We can create a vector and then loop over its values
    const std::vector<char> vec{'a', 'b', 'c'};
    std::cout << "Here are the contents of vec: ";
    const std::size_t s = vec.size();
    for (std::size_t i{0}; i < s; ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';

    // We can use a range-based for-loop to avoid indexing issues
    for (char c : vec)
    {
        std::cout << c << ' ';
    }
    std::cout << '\n';

    // We can use const auto& as the loop variable type when
    // we don't need to modify elements and we want to avoid
    // expensive copies
    for (const auto& c : vec)
    {
        std::cout << c << ' ';
    }
    std::cout << '\n';

    const std::vector<std::string> names{"Kevin", "Bob", "Tim"};
    std::cout << names[Test::Names::third] << '\n';
}
