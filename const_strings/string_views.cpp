#include <iostream>
#include <string>
#include <string_view>

#include "string_views.h"

void print_string_view(std::string_view sv)
{
    std::cout << sv << '\n';
}

void print_string(const std::string str)
{
    std::cout << str << '\n';
}

void expose_string_views()
{
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
}
