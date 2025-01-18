#include <iostream>

#include "cexpr.hpp"
#include "default.hpp"
#include "overload.hpp"
#include "templates.hpp"

int main(int argc, char* argv[])
{
    show_overload();
    show_default_args();
    do_templates();
    show_cexpr_funcs();

    // argc is the number of arguments, while argv is an array of char pointers
    // to each argument as a C-style string

    std::cout << "There are " << argc << " arguments:\n";

    // Loop through each argument and print its number and value
    for (int count{0}; count < argc; ++count)
    {
        std::cout << count << ' ' << argv[count] << '\n';
    }

    return 0;
}
