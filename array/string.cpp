#include <cstring>
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

    // We can't re-assign an entire C-style string array after creation
    // But we can modify individual characters
    // wont' compile:
    // input = "new string";
    input[0] = 'R';
    std::cout << "Modified input: " << input << '\n';

    // std::size and std::ssize return the full array length and don't
    // work on decayed arrays
    std::cout << "Length of 'one': " << std::size(one) << '\n';
    std::cout << "Length of 'hello': " << std::size(hello) << '\n';
    std::cout << "Length of 'input': " << std::size(input) << '\n';

    // Instead we can use strlen from <cstring> to get the real length,
    // excluding the null terminator
    std::cout << "Real length of 'one': " << std::strlen(one) << '\n';
    std::cout << "Real length of 'hello': " << std::strlen(hello) << '\n';
    std::cout << "Real length of 'input': " << std::strlen(input) << '\n';

    // We can initialize in 2 different ways
    const char name[]{"Alex"};  // case 1: const C-style string initialized with
                                // C-style string literal
    const char* const color{
        "Orange"};  // case 2: const pointer to C-style string literal

    std::cout << name << ' ' << color << '\n';
}
