#include <iostream>

#include "intro.hpp"

int foo()
{
    return 5;
}

int bar()
{
    return 6;
}

// We can use function pointers to pass functions as arguments
// to other functions, i.e. a callback
void print_result(const int input, int (*func)(const int))
{
    if (!func)
    {
        return;
    }

    std::cout << (*func)(input) << '\n';
}

int increment(const int input)
{
    return input + 1;
}

void show_func_pointers()
{
    int (*ptr)(){&foo};
    ptr = &bar;

    // Once we have a function pointer, we can dereference to call it
    // Check to see if it's a nullptr first
    if (ptr)
    {
        std::cout << (*ptr)() << '\n';
    }

    const int input = 10;
    print_result(input, &increment);
}
