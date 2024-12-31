#include <iostream>
#include "cexpr.hpp"
#include "templates.hpp"

#include "default.hpp"
#include "overload.hpp"

int main()
{
    show_overload();
    show_default_args();
    do_templates();
    show_cexpr_funcs();
    return 0;
}
