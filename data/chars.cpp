#include <iostream>

#include "chars.h"

void work_with_chars()
{
    std::cout << "Working with chars" << std::endl;

    char c = 'A';
    std::cout << "c: " << c << std::endl;

    [[maybe_unused]] char ch2{'a'};  // initialize with code point for 'a'
                                     // (stored as integer 97) (preferred)

    [[maybe_unused]] char ch3 =
        97;  // initialize with code point for 'a' (stored as integer 97)

    std::cout
        << "Input a keyboard character: (a b) ";  // assume the user enters "a
                                                  // b" (without quotes)

    char ch{};
    std::cin.get(ch);  // extracts a, leaves " b\n" in stream
    std::cout << "You entered: " << ch << '\n';

    std::cin.get(ch);  // extracts space, leaves "b\n" in stream
    std::cout << "You entered: " << ch << '\n';
}
