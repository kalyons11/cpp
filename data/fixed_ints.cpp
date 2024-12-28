#include <cstddef>
#include <iostream>

#include "fixed_ints.hpp"

void print_fixed_ints()
{
    [[maybe_unused]] std::int8_t a = 127;
    [[maybe_unused]] std::uint8_t b = 255;
    [[maybe_unused]] std::int16_t c = 32'767;
    [[maybe_unused]] std::uint16_t d = 65'535;
    [[maybe_unused]] std::int32_t e = 2'147'483'647;
    [[maybe_unused]] std::uint32_t f = 4'294'967'295;
    [[maybe_unused]] std::int64_t g = 9'223'372'036'854'775'807;
    [[maybe_unused]] std::uint64_t h = 18'446'744'073'709'551'615ull;

    // Be careful though because singe-byte sized integers can be expressed as a
    // char
    std::int8_t x{65};
    std::cout << x << '\n';

    // Least and fast types can have varying sizes depending on the compiling
    // machine
    std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << '\n';
    std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
    std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
    std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";

    // Let's experiment with std::size_t
    int temp{5};
    std::size_t s{sizeof(temp)};
    std::cout << "Size of int with value 5 is: " << s << " bytes." << '\n';
}
