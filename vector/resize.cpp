#include <iostream>
#include <vector>

#include "resize.hpp"

template <typename T>
void print_properties(std::vector<T>& vec)
{
    std::cout << "Size: " << vec.size() << '\n';
    std::cout << "Capacity: " << vec.capacity() << '\n';
}

void adjust_size()
{
    // We can use resize to dynamically allocate more or less
    // memory for vector elements at runtime
    // This is expensive though
    // capacity() shows how many elements the vector can hold
    // size() shows how many elements it is currently holding
    std::vector<int> numbers{1, 2, 3};
    print_properties(numbers);

    numbers.resize(5);
    print_properties(numbers);
}
