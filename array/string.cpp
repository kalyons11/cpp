#include <iostream>

#include "string.hpp"

void print_str(const char ptr[])
{
    // std::cout will continue printing until the null terminator character
    std::cout << ptr << '\n';
}

void show_c_strings()
{
    // C-style strings are just char[] or const char[]
    char one[]{6};  // String of length 5 because of null termination character
    const char hello[]{"hello"};  // length is 6

    print_str(one);  // random characters since non-initialized
    print_str(hello);

    // We can read in a C-style string as input but must specify the length
    char input[100]{};
    std::cout << "Enter rolls: ";
    std::cin.getline(input, std::size(input));
    std::cout << "You entered: " << input << '\n';
}
