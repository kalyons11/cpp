#include <iostream>

#include "pointer.hpp"

void run_pointer_arithmetic()
{
    // Allocate a zero-initialized integer
    int x{};

    // Get a pointer to it, assuming ints are 4 bytes (32 bits)
    const int* ptr{&x};

    // We can print the next N memory addresses after this one
    const int N = 10;
    for (int i = 0; i < N; ++i)
    {
        std::cout << "Address " << (ptr + i) << " contains " << *(ptr + i)
                  << '\n';
    }

    // We can apply this with pointers in subscripting
    const int arr[]{1, 2, 3, 4, 5};
    const int* q{arr};
    std::cout << q[2] << '\n';  // Should print 3

    const int vals[]{3, 2, 1};

    // First, let's use subscripting to get the address and values of our array
    // elements
    std::cout << &vals[0] << ' ' << &vals[1] << ' ' << &vals[2] << '\n';
    std::cout << vals[0] << ' ' << vals[1] << ' ' << vals[2] << '\n';

    // Now let's do the equivalent using pointer arithmetic
    std::cout << vals << ' ' << (vals + 1) << ' ' << (vals + 2) << '\n';
    std::cout << *vals << ' ' << *(vals + 1) << ' ' << *(vals + 2) << '\n';

    // We can use pointer arithmetic for array traversal
    constexpr int test[]{5, 6, 7, 8, 9, 10};
    const int* current{test};
    const int* end{test + std::size(test)};

    for (; current != end; ++current)
    {
        std::cout << *current << ' ';
    }
    std::cout << '\n';

    // This is how a range-based for loop is implemented
    for (const auto t : test)
    {
        std::cout << t << ' ';
    }
    std::cout << '\n';
}
