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
}
