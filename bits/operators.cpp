#include <iostream>

#include "operators.hpp"

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
    // // Get the most significant bit
    // bool msb{bits.test(3)};
    // // Left shift by 1
    // bits <<= 1;
    // // Set the least significant bit to the previous most significant bit
    // bits.set(0, msb);
    // return bits;

    // Let's do this only using bitwise operators
    return (bits << 1) | (bits >> 3);
}

void run_bitwise_operators()
{
    // Left shift
    std::bitset<4> x{0b0001};
    std::cout << "0b0001 << 1 = " << (x << 1) << '\n';  // 0b0010
    // Right shift
    std::bitset<4> y{0b1000};
    std::cout << "0b1000 >> 1 = " << (y >> 1) << '\n';  // 0b0100

    // Bitwise NOT
    std::bitset<4> z{0b0101};
    std::cout << "~0b0101 = " << (~z) << '\n';  // 0b1010
    // The size of the bitset matters
    std::bitset<8> z8{0b0101};
    std::cout << "~0b0101 = " << (~z8) << '\n';  // 0b11111010

    // Bitwise AND
    std::bitset<4> a{0b1100};
    std::bitset<4> b{0b1010};
    std::cout << "0b1100 & 0b1010 = " << (a & b) << '\n';  // 0b1000

    // Bitwise OR
    std::bitset<4> c{0b1100};
    std::bitset<4> d{0b1010};
    std::cout << "0b1100 | 0b1010 = " << (c | d) << '\n';  // 0b1110

    // Bitwise XOR
    std::bitset<4> e{0b1100};
    std::bitset<4> f{0b1010};
    std::cout << "0b1100 ^ 0b1010 = " << (e ^ f) << '\n';  // 0b0110

    // Assignment operators
    std::bitset<4> g{0b1100};
    std::bitset<4> h{0b1010};
    g &= h;
    std::cout << "0b1100 &= 0b1010: " << g << '\n';  // 0b1000
    // Left shift assignment
    std::bitset<4> i{0b0001};
    i <<= 1;
    std::cout << "0b0001 <<= 1: " << i << '\n';  // 0b0010
    // Right shift assignment
    std::bitset<4> j{0b1000};
    j >>= 1;
    std::cout << "0b1000 >>= 1: " << j << '\n';  // 0b0100
    // Bitwise OR assignment
    std::bitset<4> k{0b1100};
    std::bitset<4> l{0b1010};
    k |= l;
    std::cout << "0b1100 |= 0b1010: " << k << '\n';  // 0b1110
    // Bitwise XOR assignment
    std::bitset<4> m{0b1100};
    std::bitset<4> n{0b1010};
    m ^= n;
    std::cout << "0b1100 ^= 0b1010: " << m << '\n';  // 0b0110
    // Bitwise AND assignment
    std::bitset<4> o{0b1100};
    std::bitset<4> p{0b1010};
    o &= p;
    std::cout << "0b1100 &= 0b1010: " << o << '\n';  // 0b1000
    // Bitwise NOT assignment
    std::bitset<4> q{0b0101};
    q = ~q;  // Since NOT is unary, it doesn't have an assignment operator

    // Be careful of integral promotion and type conversion
    std::uint8_t r{0b00001111};
    // std::cout << std::bitset<32>{ ~r } << '\n'; // incorrect: prints
    // 11111111111111111111111111110000 std::cout << std::bitset<32>{r << 6} <<
    // '\n'; // incorrect: prints 0000000000000000001111000000 std::uint8_t cneg
    // { ~c };

    // static_cast to the rescue
    std::cout << std::bitset<32>{static_cast<std::uint32_t>(~r)}
              << '\n';  // correct: prints 00000000000000000000000011110000
    std::cout << std::bitset<32>{static_cast<std::uint32_t>(r << 6)}
              << '\n';  // correct: prints 0000000000000000000011000000

    std::bitset<4> bits1{0b0001};
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{0b1001};
    std::cout << rotl(bits2) << '\n';
}
