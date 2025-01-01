#include <iostream>

#include "enum.hpp"
#include "in_out.hpp"
#include "intro.hpp"
#include "lval_refs.hpp"
#include "optional.hpp"
#include "pointers.hpp"
#include "struct.hpp"

int main()
{
    std::cout << "Hello, this is a sample message from project: " << "compound"
              << '\n';
    show_basics();
    run_lval_refs();
    start_pointers();
    run_in_out_params();
    show_optional();
    run_enum();
    demo_structs();
    return 0;
}
