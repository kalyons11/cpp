#include <iostream>

#include "in_out.hpp"
#include "intro.hpp"
#include "lval_refs.hpp"
#include "optional.hpp"
#include "pointers.hpp"

int main()
{
    std::cout << "Hello, this is a sample message from project: " << "compound"
              << '\n';
    show_basics();
    run_lval_refs();
    start_pointers();
    run_in_out_params();
    show_optional();
    return 0;
}
