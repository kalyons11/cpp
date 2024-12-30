#include <iostream>

#include "overload.hpp"

int add(int a, int b)
{
    return a + b;
}

// We can overload add for double as well
double add(double a, double b)
{
    return a + b;
}

// We can also overload by adding a third parameter
int add(int a, int b, int c)
{
    return a + b + c;
}

// Return types are not part of the function signature
// So we can't overload by return type alone

// We can use delete to remove a function from the overload set
void printInt(int a)
{
    std::cout << "printInt: " << a << '\n';
}
void printInt(double a) = delete;

// We can use a template to delete all non-matching overloads
template <typename T>
void printInt(T a) = delete;

void show_overload()
{
    std::cout << "Overloading functions" << '\n';
    std::cout << "add(1, 2) = " << add(1, 2) << '\n';
    std::cout << "add(1.1, 2.2) = " << add(1.1, 2.2) << '\n';
    std::cout << "add(1, 2, 3) = " << add(1, 2, 3) << '\n';

    std::cout << "printInt(1) = ";
    printInt(1);
    // These will cause a compile error
    // printInt(1.1);
    // printInt("Hello");
    // printInt(false);
}
