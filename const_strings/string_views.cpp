#include <iostream>
#include <string>
#include <string_view>

#include "string_views.hpp"

void print_string_view(std::string_view sv)
{
    std::cout << sv << '\n';
}

void print_string(const std::string str)
{
    std::cout << str << '\n';
}

std::string get_name()
{
    return std::string{"John Doe"};
}

// Be careful when returning a string_view from a function, because the
// underlying string may be destroyed
std::string_view get_name_view(bool b)
{
    std::string temp{"John Doe"};
    std::string other{"Jane Doe"};

    if (b)
    {
        return std::string_view{temp};
    }
    else
    {
        return std::string_view{other};
    }
}

void expose_string_views()
{
    using namespace std::string_literals;
    using namespace std::string_view_literals;
    // std::string is expensive to create and copy around
    // std::string_view is a lightweight, non-owning reference to a string
    std::string_view sv{"Hello, World!"};
    print_string_view(sv);

    // string_view can be initialized from a literal, a string, or another
    // string_view
    std::string str{"Hello, World!"};
    std::string_view sv2{str};
    print_string_view(sv2);

    std::string_view sv3{sv2};
    print_string_view(sv3);

    // We can call print_string_view with a string literal, a string, or a
    // string_view
    print_string_view("Hello, World!");
    print_string_view(str);
    print_string_view(sv2);

    // We can call print_string with a string literal or a string
    print_string("Hello, World!");
    print_string(str);
    // We can't call print_string with a string_view
    // print_string(sv2);
    // But, we can convert a string_view to a string
    print_string(std::string{sv2});
    // We can also use static_cast
    print_string(static_cast<std::string>(sv2));

    // We can re-assing a string_view to point to a different string
    std::string str2{"Goodbye, World!"};
    sv2 = str2;
    print_string_view(sv2);
    sv2 = "Hello, World!";

    // We can use the sv suffix to create a string_view from a string literal
    std::cout << "foo" << '\n';
    std::cout << "foo"s << '\n';
    std::cout << "foo"sv << '\n';

    // string_view has full support for constexpr
    constexpr std::string_view sv4{"Hello, World!"};
    std::cout << sv4 << '\n';  // At compile-time, this will be replaced with
                               // "Hello, World!"

    // std::string is an owner, whereas std::string_view is a non-owner (viewer)
    // Undefined behavior can occur if the string_view outlives the string
    // it is viewing
    std::string_view sv5;
    {
        std::string str3{"Hello, World!"};
        sv5 = str3;
    }
    // This will print garbage
    print_string_view(sv5);

    std::string_view sv6{get_name()};  // initialize a string_view from a
                                       // temporary string
    // Return values are temporary objects that are destroyed at
    // the end of the full expression containing the function call.
    // Undefined behavior can occur if the string_view outlives the temporary
    std::cout << sv6 << '\n';  // This will print garbage

    // The same can occur with string-literal initialization which is temporary
    std::string_view sv7{"Hello, World!"s};
    std::cout << sv7 << '\n';  // This will print garbage

    // A view whose lifetime is tied to a temporary object is a dangling view

    // We can also get undefined behavior if the underlying string is modified
    // This is called invalidation
    std::string str4{"Hello, World!"};
    std::string_view sv8{str4};
    print_string_view(sv8);
    str4 = "Goodbye, World!";
    std::cout << sv8 << '\n';  // Undefined behavior

    // We can re-validate the string_view by re-assigning it to the new string
    sv8 = str4;
    print_string_view(sv8);  // This will print "Goodbye, World!"

    std::cout << get_name_view(true) << '\n';  // Undefined behavior

    // We can call view modifications on a string_view
    std::string_view sv9{"Hello, World!"};
    std::cout << sv9 << '\n';
    sv9.remove_prefix(7);
    std::cout << sv9 << '\n';  // This will print "World!"
    sv9.remove_suffix(1);
    std::cout << sv9 << '\n';  // This will print "World"
    // We can reset the view
    sv9 = "Hello, World!";
    std::cout << sv9 << '\n';

    // A C-style string literal and a std::string are always null-terminated
    // A string_view may or may not be null-terminated
    sv9.substr(
        7);  // This will create a string_view that is not null-terminated
    std::cout << sv9.substr(7) << '\n';  // This will print "World!"
    sv9 = "Hello, World!";
    sv9.substr(0, 2);
    std::cout << sv9 << '\n';
}
