#include <iostream>
#include <vector>

#include "intro.hpp"

struct Foo
{
    std::vector<int> data{std::vector<int>(
        10, 0)};  // Vector with 10 elements, all initialized to 0
    // use an explicit constructor to initialize the vector with 10 elements,
    // all initialized to 0
};

void show_vector()
{
    // Create an empty vector
    std::vector<int> empty{};

    // Create a vector with some values
    std::vector<int> values{1, 2, 3, 4, 5};
    std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    std::vector vowels{'a', 'e', 'i', 'o',
                       'u'};  // CTAD infers the type as std::vector<char>

    // Print the size of the vectors
    std::cout << "Size of empty vector: " << empty.size() << '\n';
    std::cout << "Size of values vector: " << values.size() << '\n';
    std::cout << "Size of primes vector: " << primes.size() << '\n';
    std::cout << "Size of vowels vector: " << vowels.size() << '\n';

    // Print the elements of the vectors
    std::cout << "Elements of values vector: ";
    for (const auto& value : values)
    {
        std::cout << value << ' ';
    }

    // Get the first element of the vector
    std::cout << "\nFirst element of values vector: " << values.front() << '\n';

    // Get the last element of the vector
    std::cout << "Last element of values vector: " << values.back() << '\n';

    // Get the element at a specific index
    std::cout << "Element at index 2 of values vector: " << values.at(2)
              << '\n';
    // We can also use the subscript operator to get the element at a specific
    // index
    std::cout << "Element at index 2 of values vector: " << values[2] << '\n';

    // Check if the vector is empty
    std::cout << "Is empty vector empty? " << (empty.empty() ? "Yes" : "No")
              << '\n';

    // Clear the vector
    empty.clear();

    // Check if the vector is empty
    std::cout << "Is empty vector empty after clear? "
              << (empty.empty() ? "Yes" : "No") << '\n';

    // Add elements to the empty vector
    empty.push_back(10);
    empty.push_back(20);
    empty.push_back(30);

    // Arrays are contiguous in memory, so we can access elements using pointers
    int* ptr = empty.data();
    std::cout << "First element of empty vector: " << *ptr << '\n';

    // We can view the memory location of the vector's data
    std::cout << "Memory location of empty vector's data: " << ptr << '\n';

    // We can get the memory location of each element in the primes vector
    for (const auto& prime : primes)
    {
        std::cout << "Memory location of prime " << prime << ": " << &prime
                  << '\n';
    }

    // We can construct a vector of a particular size
    std::vector<int> size_vector(5);

    // We can also construct a vector of a particular size with a default value
    std::vector<int> size_default_vector(5, 10);
    // The vector will have 5 elements, all initialized to 10

    // We can also construct a vector using iterators
    std::vector<int> iterator_vector(values.begin(), values.end());
    // The vector will have the same elements as the values vector

    const Foo foo;
    std::cout << "Size of data vector in Foo: " << foo.data.size() << '\n';

    // A vector can be made const, but not constexpr
    const std::vector<int> const_vector{1, 2, 3, 4, 5};
    // const_vector.push_back(6);  // Error: const object cannot be modified

    // constexpr std::vector<int> constexpr_vector{1, 2, 3, 4, 5};  // Error:
    // constexpr vector cannot be initialized with a non-constexpr value

    // We can also use the emplace_back function to construct elements in place
    std::vector<std::string> strings;
    strings.emplace_back("Hello");
    strings.emplace_back("World");
    strings.emplace_back("from");
    strings.emplace_back("vectors!");

    // Print the elements of the strings vector
    std::cout << "Elements of strings vector: ";
    for (const auto& str : strings)
    {
        std::cout << str << ' ';
    }  // Output: Hello World from vectors!
    std::cout << '\n';
}
