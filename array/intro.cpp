#include <array>
#include <iostream>
#include <vector>

#include "intro.hpp"

// We must specify both type and length when passing by const reference
void pass_array(const std::array<int, 5>& arr)
{
    std::cout << "Last element: " << std::get<2>(arr) << '\n';
}

// We can parameterize the type and length to enable more arrays
template <typename T, std::size_t N>
void pass_generic_array(const std::array<T, N>& arr)
{
    static_assert(N != 0);

    std::cout << "First element: " << arr[0] << '\n';
}

// We can have an array of structs
struct House
{
    int price;
    // std::string address1;
    int footage;
    // ...
};

// Let's practice with pointers again
struct Student
{
    int id{};
    std::string_view name{};
};

template <typename std::size_t N>
const Student* get_by_id(const std::array<Student, N>& arr, const int id)
{
    for (auto& s : arr)
    {
        if (s.id == id)
        {
            return &s;
        }
    }
    return nullptr;
};

void demo_array()
{
    // We can compare creating an array and vector
    [[maybe_unused]] std::array<int, 5>
        a{};  // The size of the array is fixed an known at compile-time

    [[maybe_unused]] std::vector<int> b(5);

    // The length of a std::array must be constexpr
    [[maybe_unused]] std::array<int, 3> nums{
        1, 2, 3};  // list initialization (preferred)

    // Prefer zero-initialization with braces to avoid elements being undefined
    [[maybe_unused]] std::array<int, 1> init{};
    [[maybe_unused]] std::vector<int> other(1);
    // Members are value initializated (ints would be 0)

    // More elements are not allowed, but fewer are
    // Remaining are value initialized
    // std::array<int, 4> x { 1, 2, 3, 4, 5 }; // compile error: too many
    // initializers
    [[maybe_unused]] std::array<int, 4> y{
        1, 2};  // b[2] and b[3] are value initialized

    // We really want to make our std::arrays constexpr to take advantage
    [[maybe_unused]] constexpr std::array<int, 5> prime{2, 3, 5, 7, 11};

    // We can use CTAD to avoid type annotations
    constexpr std::array test{0.5, 0.6, 0.7};
    // This will be determined to be std::array<double, 3>

    // We can get the length of an array with size(), not length()
    constexpr std::size_t len{test.size()};
    std::cout << "The size of test is: " << len << '\n';

    // We can use [] and at, but even better is get which does compile time
    // bounds checking
    constexpr auto first = std::get<0>(test);  // 0.5
    std::cout << "First is: " << first << '\n';
    std::cout << "First is: " << test[0] << '\n';
    std::cout << "First is: " << test.at(0) << '\n';
    // std::cout << std::get<4>(test>) << '\n'; // Compile error

    pass_array(prime);
    pass_generic_array(test);

    constexpr std::array houses{House{140000, 1000}, House{270000, 2500}};

    // We can loop over houses just like we did with vectors
    for (const auto& house : houses)
    {
        std::cout << "House: $" << house.price << ", " << house.footage
                  << "sq ft" << '\n';
    }

    constexpr std::array<Student, 3> students{
        Student{1, "Alice"}, Student{2, "Bob"}, Student{3, "Charlie"}};

    if (const Student* student = get_by_id(students, 2))
    {
        std::cout << "Found student: " << student->name << '\n';
    }
    else
    {
        std::cout << "Student not found\n";
    }
}
