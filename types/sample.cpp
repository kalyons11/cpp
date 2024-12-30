#include <iostream>
#include <string_view>

#include "sample.hpp"

float return_float()
{
    return 3;  // Implicit conversion
}

// We can use type deduction for functions as well
auto return_int()
{
    return 3;
}

auto someFcn(bool b)
{
    if (b)
        return 5;  // return type int
    else
        // return 6.7; // return type double - not allowed to mix types
        return 6;  // return type int
}

// auto is also needed for the trailing return type syntax
auto add2(int a, int b) -> int
{
    return a + b;
}

void sample_function()
{
    [[maybe_unused]] float f{
        3};  // 3 is an integer, but it is implicitly converted to a float
    std::cout << f << '\n';
    [[maybe_unused]] double d{3};
    d = 6;
    [[maybe_unused]] float f2 = return_float();
    [[maybe_unused]] double division = 3 / 2;
    if (5)
    {  // Implicit conversion to bool
        std::cout << "5 is true\n";
    }

    // Brace-initialization prevents narrowing conversions
    // int i{3.14}; // Error: narrowing conversion

    // if a narrowing conversion is required, the compiler will issue an error
    // use static_cast to force a conversion
    [[maybe_unused]] int i = static_cast<int>(3.14);
    [[maybe_unused]] int j{static_cast<int>(3.14)};

    // Arithmetic conversions
    [[maybe_unused]] int i1 = 3;
    [[maybe_unused]] double d1 = 3.14;
    [[maybe_unused]] double result = i1 + d1;  // i1 is promoted to a double
    std::cout << result << '\n';

    // Integral promotions
    [[maybe_unused]] char c = 'A';
    [[maybe_unused]] int i2 = c;  // c is promoted to an int
    std::cout << i2 << '\n';

    // Integral conversions
    [[maybe_unused]] int i3 = 3;
    // char c2 = i3; // i3 is converted to a char
    // std::cout << c2 << '\n';

    // Floating-point conversions
    [[maybe_unused]] double d2 = 3.14;
    // float f3 = d2; // d2 is converted to a float
    // std::cout << f3 << '\n';

    // We can use typeid to get the type of a variable
    std::cout << "f: " << typeid(f).name() << '\n';
    std::cout << "d: " << typeid(d).name() << '\n';
    std::cout << "f2: " << typeid(f2).name() << '\n';
    std::cout << "division: " << typeid(division).name() << '\n';
    std::cout << "i: " << typeid(i).name() << '\n';

    // We can use type aliases to make our code more readable
    using MyFloat = float;
    [[maybe_unused]] MyFloat f4 = 3.14f;
    std::cout << "f4: " << typeid(f4).name() << '\n';

    using VectPairSI = std::vector<std::pair<std::string, int>>;
    [[maybe_unused]] VectPairSI v;
    v.push_back(std::make_pair("one", 1));

    // We can use auto to let the compiler deduce the type of a variable
    [[maybe_unused]] auto i4 = 3;
    std::cout << "i4: " << typeid(i4).name() << '\n';
    [[maybe_unused]] auto d3 = 3.14;
    std::cout << "d3: " << typeid(d3).name() << '\n';

    // auto works with const and constexpr
    [[maybe_unused]] const auto i5 = 3;
    std::cout << "i5: " << typeid(i5).name() << '\n';
    [[maybe_unused]] constexpr auto i6 = 3;
    std::cout << "i6: " << typeid(i6).name() << '\n';

    // auto drops const
    [[maybe_unused]] const int i7 = 3;
    [[maybe_unused]] auto i8 = i7;
    i8 = 4;  // OK
    std::cout << "i8: " << typeid(i8).name() << '\n';

    // Use const auto to keep const
    [[maybe_unused]] const auto i9{i7};

    // For strings, need to use the s and sv suffixes
    using namespace std::string_literals;
    using namespace std::string_view_literals;
    [[maybe_unused]] auto s{"Hello"};     // const char*
    [[maybe_unused]] auto s2{"Hello"s};   // std::string
    [[maybe_unused]] auto s3{"Hello"sv};  // std::string_view
}
