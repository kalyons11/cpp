#include "fixed_ints.h"
#include <iostream>

void print_fixed_ints()
{
    [[maybe_unused]] std::int8_t a = 127;
    [[maybe_unused]] std::uint8_t b = 255;
    [[maybe_unused]] std::int16_t c = 32'767;
}
