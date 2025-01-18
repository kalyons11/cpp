#include <iostream>

#include "intro.hpp"

// The stack gets unwound when exceptions are thrown deep within
void deep_function()
{
    std::cout << "Entering deep_function" << '\n';
    throw std::runtime_error("Exception thrown in deep_function");
    std::cout << "Exiting deep_function" << '\n';  // This will not be executed
}

void middle_function()
{
    std::cout << "Entering middle_function" << '\n';
    deep_function();
    std::cout << "Exiting middle_function"
              << '\n';  // This will not be executed
}

void top_function()
{
    std::cout << "Entering top_function" << '\n';
    try
    {
        middle_function();
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
    std::cout << "Exiting top_function" << '\n';
}

void show_try_catch()
{
    try
    {
        throw -1;
    }
    catch (int x)
    {
        std::cout << x << " was thrown" << '\n';
    }

    top_function();
}
