#include <iostream>
#include <vector>

#include "intro.hpp"

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

    /// Get the element at a specific index
    std::cout << "Element at index 2 of values vector: " << values.at(2)
              << '\n';

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
}
