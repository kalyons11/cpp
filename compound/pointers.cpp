#include <iostream>

#include "pointers.hpp"

void start_pointers()
{
    // We can use the & operator to get the memory address of a variable
    int number = 10;
    std::cout << "Memory address of number: " << &number << '\n';
    std::cout << "Value of number: " << number << '\n';
}
