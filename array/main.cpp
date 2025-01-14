#include <iostream>

#include "decay.hpp"
#include "intro.hpp"
#include "old.hpp"

int main()
{
    std::cout << "Hello, this is a sample message from project: " << "array"
              << '\n';
    demo_array();
    show_c_style();
    show_decay();
    return 0;
}
