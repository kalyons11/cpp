#include <bitset>
#include <iostream>

#include "numerals.hpp"

void print_numeral_systems()
{
    std::cout << "Decimal: " << 10 << '\n';
    std::cout << "Octal: " << 010 << '\n';
    std::cout << "Hexadecimal: " << 0x10 << '\n';
    std::cout << "Binary: " << 0b10 << '\n';

    int x{12};
    std::cout << "Decimal: " << x << '\n';
    std::cout << "Octal: " << std::oct << x << '\n';
    std::cout << "Hexadecimal: " << std::hex << x << '\n';

    // Let's use std::bitset to print binary numbers
    std::bitset<8> b1{0b1010'1010};
    // We can also initialize with hexadecimal
    std::bitset<8> b2{0xAA};
    std::cout << "Binary: " << b1 << '\n';
    std::cout << "Binary: " << b2 << '\n';

    // We can use the format and print libraries to print in different bases
    // std::cout << "Decimal: " << std::format("{:d}", x) << '\n';
    // std::cout << "Octal: " << std::format("{:o}", x) << '\n';
    // std::cout << "Hexadecimal: " << std::format("{:x}", x) << '\n';
    // std::cout << "Binary: " << std::format("{:b}", x) << '\n';

    // Reset to decimal
    std::cout << std::dec;
}
