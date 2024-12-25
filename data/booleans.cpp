#include "booleans.h"
#include <iostream>

// returns true if the given number is even, false otherwise
bool is_even(int num)
{
    return num % 2 == 0;
}

void dig_booleans()
{
    std::cout << "Booleans are " << sizeof(bool) << " byte(s) in size.\n";

    [[maybe_unused]] bool b1{true};
    [[maybe_unused]] bool b2{false};
    b1 = false;
    [[maybe_unused]] bool b3{};  // default initialize to false

    [[maybe_unused]] bool truey{
        !true};  // b1 will be initialized with the value false
    [[maybe_unused]] bool falsey{
        !false};  // b2 will be initialized with the value true

    // booleans store internally as 0 for false and 1 for true
    std::cout << true << '\n';   // true evaluates to 1
    std::cout << !true << '\n';  // !true evaluates to 0

    bool b{false};
    std::cout << b << '\n';   // b is false, which evaluates to 0
    std::cout << !b << '\n';  // !b is true, which evaluates to 1

    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::boolalpha;  // print bools as true or false

    std::cout << true << '\n';
    std::cout << false << '\n';

    // Copy initialization allows implicit conversion
    bool b4 = 42;   // b4 is true
    bool b5 = -42;  // b5 is true
    bool b6 = 0;    // b6 is false
    std::cout << b4 << '\n';
    std::cout << b5 << '\n';
    std::cout << b6 << '\n';

    // Let's take in a boolean value from std::cin the right way
    bool b7{};
    std::cout << "Enter a boolean value: ";
    std::cin >> std::boolalpha >> b7;
    std::cout << "You entered: " << b7 << '\n';

    // Reset the stream flags
    std::cin >> std::noboolalpha;
    std::cout << std::noboolalpha;

    // Check if a number is even
    int num{};
    std::cout << "Enter an integer: ";
    std::cin >> num;
    std::cout << std::boolalpha;
    std::cout << num << " is even?: " << is_even(num) << '\n';
}
