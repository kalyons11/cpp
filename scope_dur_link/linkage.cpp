#include <iostream>

#include "linkage.hpp"

// Non-const global variables have external linkage by default
// This means they can be accessed (via a declaration) in other files
// Use static to give a global variable internal linkage
[[maybe_unused]] int g_globalVariable{5};  // define a global variable
[[maybe_unused]] static int g_globalVariable2{
    5};  // define a global variable with internal linkage

[[maybe_unused]] const int g_x{
    5};  // const variables have internal linkage by default
[[maybe_unused]] const int g_y{5};  // const variables with internal linkage
[[maybe_unused]] constexpr int g_z{
    5};  // constexpr variables have internal linkage by default

void show_linkage()
{
}
