#include <iostream>

#include "enum.hpp"

enum Color
{
    RED,
    GREEN,
    BLUE
};

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
}
