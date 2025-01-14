#include <iomanip>
#include <iostream>

#include "decay.hpp"

void print_first_element(
    const int arr[])  // Prefer over const int* array for clarity
{
    std::cout << arr[0] << '\n';
}

void show_decay()
{
    int arr[5]{9, 7, 5, 3, 1};  // our array has elements of type int

    // First, let's prove that arr decays into an int* pointer

    auto ptr{arr};  // evaluation causes arr to decay, type deduction should
                    // deduce type int*
    std::cout << std::boolalpha << (typeid(ptr) == typeid(int*))
              << '\n';  // Prints true if the type of ptr is int*

    // Now let's prove that the pointer holds the address of the first element
    // of the array
    std::cout << std::boolalpha << (&arr[0] == ptr) << '\n';

    // We can grab the value of the first element by destructuring the pointer
    std::cout << *ptr
              << '\n';  // Should print 9, the first element of the array

    // We can use the operator[] on the decayed pointer
    std::cout << ptr[1]
              << '\n';  // Should print 7, the second element of the array
    std::cout << ptr[2]
              << '\n';  // Should print 5, the third element of the array
    std::cout << ptr[3]
              << '\n';  // Should print 3, the fourth element of the array
    std::cout << ptr[4]
              << '\n';  // Should print 1, the fifth element of the array

    print_first_element(arr);
}
