#include <iostream>

int main() {
    std::cout << "Hello, world!\n";

    [[maybe_unused]] int x; // Definition then default-initialization
    [[maybe_unused]] int y {}; // Definition then value-initialization (zero-initialization)
    [[maybe_unused]] int z { 5 }; // Definition then direct-list-initialization - preferred
    [[maybe_unused]] int a = 2; // Definition then copy-initialization
    [[maybe_unused]] int b = 3, c = 5;
    // [[maybe_unused]] int d (); // Function definition of d returning int
    [[maybe_unused]] int e (7); // Definition then direct-initialization

    // [[maybe_unused]] int bad { 4.5 };

    return 0;
}
