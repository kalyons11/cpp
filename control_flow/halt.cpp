#include <iostream>

void cleanup()
{
    std::cout << "2. Cleaning up resources." << '\n';
}

void another_cleanup()
{
    std::cout << "1. Cleaning up more resources." << '\n';
}

void show_halting()
{
    std::cout << "Halting the program." << '\n';
    std::cout << "Goodbye!" << '\n';
    std::atexit(cleanup);
    std::atexit(another_cleanup);
    std::exit(0);  // Normal program termination

    std::cout << "This code is not executed." << '\n';

    // We can also have abnormal program termination
    // std::abort();
    // std::terminate();
}
