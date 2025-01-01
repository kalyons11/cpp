#include <iostream>
#include <numeric>

#include "construct.hpp"

class Foo
{
   private:
    int m_x{};
    int m_y{};
    int m_z{5};

   public:
    Foo(int x, int y) : m_x{x}, m_y{y}  // here's our member initialization list
    {
        std::cout << "Foo constructor" << '\n';
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }
};

class Fraction
{
   private:
    int m_numerator;
    int m_denominator;
    // Let's use a private constructor so we can write a factory function
    Fraction(int numerator, int denominator)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }

   public:
    // Allow this function to access private members
    friend std::optional<Fraction> createFraction(int numerator,
                                                  int denominator);

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

std::optional<Fraction> createFraction(int numerator, int denominator)
{
    if (denominator == 0) return {};  // invalid fraction

    // Simplify the fraction by dividing the numerator and denominator by the
    // greatest common divisor Find the greatest common divisor of the numerator
    // and the denominator
    int gcd{std::gcd(numerator, denominator)};
    return Fraction(numerator / gcd, denominator / gcd);
}

void run_constructors()
{
    Foo foo(1, 2);
    foo.print();

    auto f1 = createFraction(3, 5);
    if (f1.has_value())
        std::cout << "Fraction has been created.\n";
    else
        std::cout << "Fraction has not been created.\n";

    auto f2 = createFraction(3, 0);
    if (f2.has_value())
        std::cout << "Fraction has been created.\n";
    else
        std::cout << "Fraction has not been created.\n";

    auto f3 = createFraction(2, 4);
    if (f3.has_value())
        f3.value().print();  // 1/2
    else
        std::cout << "Fraction has not been created.\n";
}
