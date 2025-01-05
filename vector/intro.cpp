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

// We want to pass vectors by reference to avoid copying
// We also want to modify the vector, so we pass it by non-const reference
// We can use a template to make the function more generic
template <typename T>
void test_vector_ref(std::vector<T>& vec)
{
    std::cout << "Size of vector in test_vector_ref: " << vec.size() << '\n';
}

template <typename T>
void print_element(std::vector<T>& vec, const std::size_t index)
{
    if (index < vec.size())
    {
        std::cout << "Element at index " << index << ": " << vec[index] << '\n';
    }
    else
    {
        std::cout << "Index out of range\n";
    }
}

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

    // Save the size as a variable
    [[maybe_unused]] const std::size_t size =
        values.size();  // size_t is an unsigned integer type

    // if we want the size as an int we can use static_cast
    [[maybe_unused]] const int int_size{static_cast<int>(values.size())};

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

    // We can also use the insert function to insert elements at a specific
    // position
    std::vector<int> insert_vector{1, 2, 3, 4, 5};
    insert_vector.insert(insert_vector.begin() + 2, 10);
    // The vector will now be {1, 2, 10, 3, 4, 5}

    // We can also insert elements from another vector
    std::vector<int> insert_values{6, 7, 8, 9};
    insert_vector.insert(insert_vector.begin() + 3, insert_values.begin(),
                         insert_values.end());
    // The vector will now be {1, 2, 10, 6, 7, 8, 9, 3, 4, 5}

    // We can also use the erase function to remove elements from a vector
    insert_vector.erase(insert_vector.begin() + 2);
    // The vector will now be {1, 2, 6, 7, 8, 9, 3, 4, 5}

    // We can also remove a range of elements
    insert_vector.erase(insert_vector.begin() + 2, insert_vector.begin() + 5);
    // The vector will now be {1, 2, 9, 3, 4, 5}

    // We can also use the pop_back function to remove the last element
    insert_vector.pop_back();
    // The vector will now be {1, 2, 9, 3, 4}

    // We can also use the resize function to change the size of the vector
    insert_vector.resize(10);
    // The vector will now be {1, 2, 9, 3, 4, 0, 0, 0, 0, 0}

    // We can also use the swap function to swap the contents of two vectors
    std::vector<int> swap_vector{10, 20, 30};
    insert_vector.swap(swap_vector);
    // insert_vector will now be {10, 20, 30} and swap_vector will be {1, 2, 9,
    // 3, 4, 0, 0, 0, 0, 0}

    // We can also use the assign function to assign new values to the vector
    insert_vector.assign(5, 100);
    // The vector will now be {100, 100, 100, 100, 100}

    // We can also use the assign function to assign values from another vector
    insert_vector.assign(values.begin(), values.end());
    // The vector will now be {1, 2, 3, 4, 5}

    // We can also use the assign function to assign values from an initializer
    // list
    insert_vector.assign({10, 20, 30, 40, 50});
    // The vector will now be {10, 20, 30, 40, 50}

    // We can also use the reserve function to reserve memory for the vector
    insert_vector.reserve(100);
    // The vector will now have enough memory to store 100 elements

    // We can also use the shrink_to_fit function to reduce the capacity of the
    // vector to its size
    insert_vector.shrink_to_fit();
    // The vector will now have a capacity equal to its size

    // We can also use the max_size function to get the maximum number of
    // elements the vector can hold
    std::cout << "Max size of insert_vector: " << insert_vector.max_size()
              << '\n';

    // We can also use the capacity function to get the current capacity of the
    // vector
    std::cout << "Capacity of insert_vector: " << insert_vector.capacity()
              << '\n';  // Output: 5

    // Let's invoke our test_vector_ref function
    test_vector_ref(insert_vector);
    test_vector_ref(strings);

    // Let's invoke our print_element function
    print_element(insert_vector, 2);   // Output: Element at index 2: 30
    print_element(insert_vector, 10);  // Output: Index out of range
}
