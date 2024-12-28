#include <iostream>
#include <string>

void do_strings()
{
    using namespace std::string_literals;

    // Create an empty string
    std::string str{};
    std::string name{"John"};
    name = "Jane";

    std::cout << "Name: " << name << '\n';

    // Empty strings will print nothing
    std::cout << "Empty string: " << str << '\n';

    // Use std::getline to read a line of text
    std::string line{};
    std::cout << "Enter a line of text: ";
    std::getline(std::cin >> std::ws, line);
    std::cout << "You entered: " << line << '\n';

    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name2{};
    std::getline(std::cin >> std::ws, name2);
    std::cout << "You picked " << choice << " and your name is " << name2
              << '\n';

    // Print the number of characters in a string
    std::string str2{"Hello"};
    std::cout << "The string Hello has " << str2.length() << " characters\n";
    [[maybe_unused]] int length{static_cast<int>(std::ssize(str2))};
    [[maybe_unused]] int len{static_cast<int>(str2.length())};

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "bar\n"s;  // the 's' suffix creates a std::string

    std::cout << "Enter your full name: ";
    std::string full_name{};
    std::getline(std::cin >> std::ws, full_name);
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;
    std::cout << "Your age + length of name is: "
              << age + static_cast<int>(std::ssize(full_name)) << '\n';
}