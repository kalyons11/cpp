#include <climits>  // for CHAR_BIT
#include <iomanip>  // for std::setw (which sets the width of the subsequent output)
#include <iostream>

#include "booleans.h"
#include "fixed_ints.h"
#include "floating_point.h"
#include "signed_ints.h"

int main()
{
    // Fundamental data types
    [[maybe_unused]] float f = 3.14159f;
    [[maybe_unused]] double d = 4.56;
    [[maybe_unused]] long double dd = 2.233;

    [[maybe_unused]] bool b = true;

    [[maybe_unused]] char c = 'c';
    [[maybe_unused]] wchar_t cOther = 'd';
    [[maybe_unused]] char8_t cX = 'e';

    [[maybe_unused]] short int i = 65;
    [[maybe_unused]] int another = 677;
    [[maybe_unused]] long int extra = 1232113;

    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left;  // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long)
              << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double)
              << " bytes\n";

    int x{};
    std::cout << "x is " << sizeof(x) << " bytes\n";

    print_int_info();
    print_fixed_ints();
    describe_floats();
    dig_booleans();

    return 0;
}
