#include <iostream>

#include "intro.hpp"
#include "lval_refs.hpp"

int main()
{
    std::cout << "Hello, this is a sample message from project: " << "compound"
              << '\n';
    show_basics();
    run_lval_refs();
    return 0;
}
