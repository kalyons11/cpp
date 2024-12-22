#include <iostream>

int main()
{
    std::cout << "Hello, world!\n";

    [[maybe_unused]] int x; // Definition then default-initialization
    [[maybe_unused]] int
        y{}; // Definition then value-initialization (zero-initialization)
    [[maybe_unused]] int z{
        5}; // Definition then direct-list-initialization - preferred
    [[maybe_unused]] int a = 2; // Definition then copy-initialization
    [[maybe_unused]] int b = 3, c = 5;
    // [[maybe_unused]] int d (); // Function definition of d returning int
    [[maybe_unused]] int e(7); // Definition then direct-initialization

    // [[maybe_unused]] int bad { 4.5 };

    // Using the insertion operator
    std::cout << "The number 4: " << 4 << std::endl;
    // Prefer \n over std::endl when outputting text to the console.
    // This avoid unnecessary flushing

    // Using the extraction operator
    std::cout << "Enter two numbers separated by spaces: ";
    int number{};
    int other{};
    std::cin >> number >> other;

    std::cout << "You entered: " << number << "\n";
    std::cout << "You also entered: " << other << "\n";

    // Both std::cout and std::cin are buffered with a FIFO queue

    // Let's not initialize a variable, print it out, then see what we get
    int un;
    std::cout << un << "\n";

    return 0;
}
