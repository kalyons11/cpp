#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <string_view>

#include "enum.hpp"

enum Color
{
    RED,
    GREEN,
    BLUE
};

constexpr std::string_view to_string(Color color)
{
    switch (color)
    {
    case RED:
        return "Red";
    case GREEN:
        return "Green";
    case BLUE:
        return "Blue";
    }
    return "Unknown";
}

// We can overload << operator to print the enum values
std::ostream& operator<<(std::ostream& os, Color color)
{
    os << to_string(color);
    return os;
}

// We can also overload operator>> to read the enum values from input
#include <algorithm>
#include <cctype>

constexpr std::optional<Color> from_string(std::string_view str)
{
    auto to_lower = [](unsigned char c) { return std::tolower(c); };
    std::string lower_str(str.begin(), str.end());
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                   to_lower);

    if (lower_str == "red")
    {
        return RED;
    }
    else if (lower_str == "green")
    {
        return GREEN;
    }
    else if (lower_str == "blue")
    {
        return BLUE;
    }
    return std::nullopt;
}

std::istream& operator>>(std::istream& is, Color& color)
{
    std::string str{};
    is >> str;
    std::optional<Color> color_opt{from_string(str)};
    if (color_opt.has_value())
    {
        color = *color_opt;
        return is;
    }

    // Set the input stream to a failed state
    is.setstate(std::ios_base::failbit);
    // We can also do zero-initialization
    color = Color{};
    return is;
}

enum SortOrder
{
    ASCENDING,
    DESCENDING,
    RANDOM
};

// These are unscoped enums and their values live in the same namespace as the
// enum itself This means that the values are accessible without the enum prefix
// For example, RED, GREEN, and BLUE are accessible without the Color prefix
// This can lead to naming conflicts if the values are not unique
// For example, if there is another enum with a RED value, there will be a
// naming conflict To avoid this, use scoped enums

// Scoped enums are defined by adding the class or struct keyword after the enum
// keyword This makes the enum scoped to the class or struct and the values are
// not accessible without the enum prefix For example, Color::RED, Color::GREEN,
// and Color::BLUE are accessible with the Color prefix This makes the values
// unique and avoids naming conflicts

enum class ColorScoped
{
    RED,
    GREEN,
    BLUE
};

// We can also put an enum inside a namespace
namespace Flavor
{
    enum IceCream
    {
        VANILLA,
        CHOCOLATE,
        STRAWBERRY
    };
}

// it's important to define the first value in the enum, otherwise the default,
// as a sort of fallback
enum PacketType
{
    PACKET_TYPE_DEFAULT,
    PACKET_TYPE_DATA,
    PACKET_TYPE_ACK,
    PACKET_TYPE_NACK
};

// We can define the base type of the enum
enum OrderStatus : int
{
    ORDER_PENDING,
    ORDER_PROCESSING,
    ORDER_SHIPPED,
    ORDER_DELIVERED
};

void sort_data(SortOrder order)
{
    switch (order)
    {
    case ASCENDING:
        std::cout << "Sorting data in ascending order" << '\n';
        break;
    case DESCENDING:
        std::cout << "Sorting data in descending order" << '\n';
        break;
    case RANDOM:
        std::cout << "Sorting data in random order" << '\n';
        break;
    }
}

void run_enum()
{
    Color color = RED;
    std::cout << color << '\n';
    color = GREEN;
    std::cout << color << '\n';
    color = BLUE;
    std::cout << color << '\n';

    Color shirt{GREEN};

    // This will not compile
    // if (shirt == 1) {
    //     std::cout << "The shirt is green" << '\n';
    // }

    if (shirt == GREEN)
    {
        std::cout << "The shirt is green" << '\n';
    }

    SortOrder order = ASCENDING;
    sort_data(order);

    ColorScoped color_scoped = ColorScoped::RED;
    // This will not compile
    // if (color_scoped == RED) {
    //     std::cout << "The color is red" << '\n';
    // }

    if (color_scoped == ColorScoped::RED)
    {
        std::cout << "The color is red" << '\n';
    }

    Flavor::IceCream ice_cream = Flavor::IceCream::VANILLA;
    // This will not compile
    // if (ice_cream == VANILLA) {
    //     std::cout << "The ice cream is vanilla" << '\n';
    // }

    if (ice_cream == Flavor::IceCream::VANILLA)
    {
        std::cout << "The ice cream is vanilla" << '\n';
    }

    // Since IceCream is unscoped, we can access the values without the IceCream
    // prefix
    Flavor::IceCream ice_cream2 = Flavor::CHOCOLATE;
    if (ice_cream2 == Flavor::IceCream::CHOCOLATE)
    {
        std::cout << "The ice cream is chocolate" << '\n';
    }

    PacketType packet{};          // default value of PACKET_TYPE_DEFAULT
    std::cout << packet << '\n';  // 0

    // if we define a base type for the enum, we can use implicit conversion
    OrderStatus status = ORDER_PENDING;
    std::cout << status << '\n';   // 0
    OrderStatus status2{1};        // ORDER_PROCESSING
    std::cout << status2 << '\n';  // 1

    // We can always use static_cast to convert between enum types
    OrderStatus status3 = static_cast<OrderStatus>(2);  // ORDER_SHIPPED
    std::cout << status3 << '\n';                       // 2

    // Now that we've overloaded operator<<, we can print the enum values
    Color my_color = RED;
    std::cout << my_color << '\n';  // Red
    my_color = GREEN;
    std::cout << my_color << '\n';  // Green
    my_color = BLUE;
    std::cout << my_color << '\n';  // Blue

    // Now that we've overloaded operator>>, we can read the enum values from
    // input
    Color input_color{};
readInput:
    std::cout << "Enter a color: ";
    std::cin >> input_color;
    if (std::cin.fail())
    {
        // Reset the input stream to a good state
        std::cin.clear();
        // Ignore the rest of the line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Error reading color" << '\n';
        goto readInput;
    }
    else
    {
        std::cout << "You entered: " << input_color << '\n';
    }
}
