#include "signed_ints.h"
#include <iostream>

void print_int_info()
{
    [[maybe_unused]] short one = 16;
    [[maybe_unused]] int two = 16;
    [[maybe_unused]] long three = 32;
    [[maybe_unused]] long long four = 64;

    // assume 4 byte = 4 * 8 = 32 bit integers
    int x{2'147'483'647};
    std::cout << x << '\n';

    std::cout << "Let's overflow a 32 bit integer, which is undefined." << '\n';
    x = x + 1;
    std::cout << x << '\n';

    // Integer division truncation
    std::cout << 8 / 5 << '\n';
}
