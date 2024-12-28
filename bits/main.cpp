#include <bitset>
#include <iostream>

#include "manipulation.h"
#include "operators.h"
#include "quiz.h"

int main()
{
    // 8 bits in size
    [[maybe_unused]] std::bitset<8> bits{0b1100'0101};
    std::cout << bits << '\n';
    // We can use set, reset, and flip to change bits
    bits.set(3);  // set bit 3 to 1
    std::cout << bits << '\n';
    bits.reset(4);  // set bit 4 to 0
    std::cout << bits << '\n';
    bits.flip(5);  // flip bit 5
    std::cout << bits << '\n';

    // We can use test to check the value of a bit
    if (bits.test(3))
    {
        std::cout << "Bit 3 is set\n";
    }

    // There are other useful querying functions: size, count, any, none, all
    std::cout << "The size of bits is: " << bits.size() << '\n';
    std::cout << "The number of set bits is: " << bits.count() << '\n';
    std::cout << "Are any bits set? " << std::boolalpha << bits.any() << '\n';
    std::cout << "Are no bits set? " << std::boolalpha << bits.none() << '\n';
    std::cout << "Are all bits set? " << std::boolalpha << bits.all() << '\n';

    run_bitwise_operators();
    run_manipulation_and_masks();
    run_quiz();
}