#include <iostream>

#include "pointers.hpp"

void start_pointers()
{
    // We can use the & operator to get the memory address of a variable
    int number = 10;
    std::cout << "Memory address of number: " << &number << '\n';
    std::cout << "Value of number: " << number << '\n';

    // The dereference or indirection operator * is used to access the value
    // stored at a memory address as an lvalue
    std::cout << "Value at memory address: " << *&number << '\n';

    // A pointer is an object that stores the memory address of another object
    [[maybe_unused]] int* pointer = &number;
    // int; - type of the pointer
    // int&; - reference to the object
    // int*; - pointer to the object's memory address

    int x{5};
    [[maybe_unused]] int*
        ptr;  // Declare a pointer - uninitialized - points to garbage
    [[maybe_unused]] int* ptr2{};  // Declare a pointer - initialized to nullptr
    int* ptr3{&x};  // Declare a pointer - initialized to the address of x

    // Once we have a pointer we can use the dereference operator to access the
    // value stored at the memory address
    std::cout << "Value of x: " << *ptr3 << '\n';
    std::cout << "Memory address of x: " << ptr3 << '\n';
    std::cout << "x itself: " << x << '\n';

    int val{2};
    int* ptr_val{&val};
    std::cout << *ptr_val << '\n';  // 2
    int another{6};
    // Update ptr_val to point at another
    ptr_val = &another;
    std::cout << *ptr_val << '\n';  // 6

    // We can also use pointers to update the actual value stored at the memory
    // address
    *ptr_val = 10;
    std::cout << *ptr_val << '\n';  // 10
    std::cout << another << '\n';   // 10

    // Pointers and lvalue references are similar in that they both refer to
    // objects, but they are different in that pointers are objects themselves
    // that can be assigned, copied, and deleted
    int y{5};
    int& ref{y};
    int* ptr_y{&y};
    std::cout << ref << '\n';     // 5
    std::cout << *ptr_y << '\n';  // 5
    ref = 10;
    std::cout << y << '\n';       // 10
    std::cout << ref << '\n';     // 10
    std::cout << *ptr_y << '\n';  // 10
    *ptr_y = 15;
    std::cout << y << '\n';       // 15
    std::cout << ref << '\n';     // 15
    std::cout << *ptr_y << '\n';  // 15
}
