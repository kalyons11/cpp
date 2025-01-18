#include <iostream>

#include "decay.hpp"
#include "intro.hpp"
#include "multi.hpp"
#include "old.hpp"
#include "pointer.hpp"
#include "string.hpp"

int main()
{
    std::cout << "Hello, this is a sample message from project: " << "array"
              << '\n';
    demo_array();
    show_c_style();
    show_decay();
    run_pointer_arithmetic();
    show_c_strings();
    show_multi_d();
    return 0;
}
