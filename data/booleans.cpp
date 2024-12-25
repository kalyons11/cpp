#include "booleans.h"
#include <iostream>

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
}
