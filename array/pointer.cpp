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
}
