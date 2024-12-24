#include <iostream>

int add(int x, int y)
{
    // clang-format off
std::cerr << "We are in add." << '\n';
    // clang-format on
    return x + y;
}

int main()
{
    std::cout << add(2, 3) << '\n';
}
