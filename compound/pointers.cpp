#include <cassert>
#include <iostream>

#include "pointers.hpp"

void print_by_address(const int* ptr)
{
    std::cout << "Value at memory address: " << *ptr << '\n';
}

// Passing by address allows the function to modify the value of the argument
void increment_by_address(int* ptr)
{
    // Add null check
    assert(ptr && "Null pointer passed to increment_by_address");
    if (!ptr)
    {
        return;
    }
    *ptr += 1;
}

// We can take in a reference to a pointer to be able to update where the
// pointer points
void update_pointer([[maybe_unused]] int*& ptr)
{
    // static int value{10};
    // ptr = &value;
}

// We can use std::nullptr_t to require a null pointer
void operate_null_pointer([[maybe_unused]] std::nullptr_t ptr)
{
    std::cout << "Null pointer passed to operate_null_pointer" << '\n';
}

// We can return by reference to avoid an expensive copy back to the caller
std::string& get_string()
{
    static std::string str{"Hello, World!"};
    // it's critical that str is not destroyed when the function ends, hence the
    // static keyword
    return str;
}

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

    char* chPtr{};         // chars are 1 byte
    int* iPtr{};           // ints are usually 4 bytes
    long double* ldPtr{};  // long doubles are usually 8 or 12 bytes

    std::cout << sizeof(chPtr) << '\n';  // prints 4
    std::cout << sizeof(iPtr) << '\n';   // prints 4
    std::cout << sizeof(ldPtr) << '\n';  // prints 4

    // Dangling pointers occur when a pointer points to a memory address that
    // has been deallocated
    // int z{5};
    // int* ptr_z{&z};
    // std::cout << *ptr_z << '\n';  // 5
    // {
    //     int another_z{10};
    //     ptr_z = &another_z;
    //     std::cout << *ptr_z << '\n';  // 10
    // }
    // ptr_z is now a dangling pointer because it points to a memory address
    // that has been deallocated (another_z)
    // std::cout << *ptr_z << '\n';  // Undefined behavior

    // We can create a null pointer with empty value initialization
    int* nullPtr{};
    int test{5};
    nullPtr = &test;
    std::cout << *nullPtr << '\n';  // 5

    // We can use nullptr to create a null pointer
    int* nullPtr2{nullptr};
    std::cout << nullPtr2 << '\n';  // 0
    // Dereferencing a null pointer is undefined behavior
    // std::cout << *nullPtr2 << '\n';  // Undefined behavior - segmentation
    // fault

    // We can check to see if a pointer is null before dereferencing it
    // if (nullPtr2 != nullptr)
    if (nullPtr2)  // We can use implicit conversion to bool
    {
        std::cout << *nullPtr2 << '\n';  // 0
    }

    // We need to use const to declare a pointer to a constant value
    const int value{5};
    const int* ptr_value{&value};
    std::cout << *ptr_value << '\n';  // 5
    // *ptr_value = 10;  // Error - cannot modify a const value
    int another_value{10};
    ptr_value = &another_value;       // OK - pointer is not const itself
    std::cout << *ptr_value << '\n';  // 10

    // We can make the pointer itself const by using const after the *
    int value2{5};
    int* const ptr_value2{&value2};
    *ptr_value2 = 10;  // OK - can modify the value
    // ptr_value2 = &another_value;  // Error - cannot modify a const pointer
    std::cout << *ptr_value2 << '\n';  // 10

    // We can make both the pointer and the value const
    const int value3{5};
    const int* const ptr_value3{&value3};
    // *ptr_value3 = 10;  // Error - cannot modify a const value
    // ptr_value3 = &another_value;  // Error - cannot modify a const pointer
    std::cout << *ptr_value3 << '\n';  // 5

    // We can use pointers to pass arguments by reference
    const int number2{5};
    const int* ptr_number2{&number2};
    const int& ref_number2{number2};
    print_by_address(ptr_number2);  // Value at memory address: 5
    std::cout << "Value of number2: " << ref_number2 << '\n';  // 5

    int number3{5};
    int* ptr_number3{&number3};
    increment_by_address(ptr_number3);  // Increment by address
    std::cout << "Value of number3: " << number3 << '\n';  // 6

    // increment_by_address(nullptr);  // Null check should prevent incrementing
    // and a segmentation fault

    // Prefer pass by reference to pointers when possible
    // This is because references are safer and more readable
    // Use pointers when you need to reassign the pointer to point to a
    // different object Use pointers when you need to pass a null value Use
    // pointers when you need to pass an array

    // We can use references to pointers to update the pointer itself
    int value4{5};
    int* ptr_value4{&value4};
    std::cout << *ptr_value4 << '\n';  // 5
    update_pointer(ptr_value4);
    std::cout << *ptr_value4 << '\n';  // 10
    std::cout << value4 << '\n';       // Still 5

    operate_null_pointer(
        nullptr);  // Null pointer passed to operate_null_pointer
    // operate_null_pointer(ptr_value4);  // Error - cannot convert int* to
    // nullptr_t

    std::string& str{get_string()};
    std::cout << str << '\n';  // Hello, World!
}
