#include <iostream>
#include "intro.hpp"

int main()
{
    try
    {
        std::cout << "Hello, this is a sample message from project: "
                  << "exceptions" << '\n';
        show_try_catch();
    }
    catch (...)
    {
        std::cout << "Undetermined exception type caught." << '\n';
    }

    return 0;
}
