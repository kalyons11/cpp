#include <iostream>

#include "decay.hpp"
#include "intro.hpp"
#include "old.hpp"
#include "pointer.hpp"

int main()
{
    std::cout << "Hello, this is a sample message from project: " << "array"
              << '\n';
    demo_array();
    show_c_style();
    show_decay();
    run_pointer_arithmetic();
    return 0;
}
