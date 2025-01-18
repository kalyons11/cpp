#include <cstddef>    // for std::size_t
#include <exception>  // for std::exception
#include <iostream>
#include <limits>
#include <string>  // for this example

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

    try
    {
        // Your code using standard library goes here
        // We'll trigger one of these exceptions intentionally for the sake of
        // the example
        std::string s;
        s.resize(
            std::numeric_limits<std::size_t>::max());  // will trigger a
                                                       // std::length_error or
                                                       // allocation exception
    }
    // This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception& exception)
    {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }

    throw std::runtime_error("Random error");
}
