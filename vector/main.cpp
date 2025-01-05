#include <iostream>

#include "intro.hpp"
#include "loop.hpp"
#include "move.hpp"

int main()
{
    std::cout << "Hello, this is a sample message from project: " << "vector"
              << '\n';
    show_vector();
    describe_move();
    run_loop();
    return 0;
}
