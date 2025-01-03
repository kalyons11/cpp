#include <iostream>
#include "friend.hpp"

#include "construct.hpp"
#include "oo.hpp"

int main()
{
    std::cout << "Hello, this is a sample message from project: " << "class"
              << '\n';
    show_oo();
    run_constructors();
    show_friends();
    return 0;
}
