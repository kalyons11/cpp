#include <iostream>

#include "friend.hpp"

// We can use friend functions to access private members of a class
// without having to use getters and setters
// This is useful when we want to keep the class interface clean
// and we don't want to expose the internal implementation details
// to the outside world

class Friend;  // Forward declaration of the Friend class is needed

class Accumulator
{
   private:
    int m_value{};

   public:
    Accumulator() : m_value(0) {}
    void add(int value) { m_value += value; }
    int get_value() const { return m_value; }

    // Make the function show_value a friend of this class
    friend void show_value(const Accumulator& accumulator);

    // Friend functions defined inside the class are non-member functions
    // and they are inline functions
    friend void print(const Accumulator& accumulator)
    {
        std::cout << "Accumulator { m_value: " << accumulator.get_value()
                  << " }" << '\n';
    }

    // Declare the Friend class as a friend of this class
    friend class Friend;
};

// Prefer to use get_value() instead of accessing m_value directly
// in the friend functions to avoid breaking encapsulation

void show_value(const Accumulator& accumulator)
{
    // Since show_value is a friend of Accumulator, it can access
    // the private members of Accumulator
    std::cout << "The value is: " << accumulator.get_value() << '\n';
}

// We can also have entire classes as friends
class Friend
{
   public:
    void run_value(const Accumulator& accumulator)
    {
        std::cout << "The value is: " << accumulator.get_value() << '\n';
    }
};

void show_friends()
{
    Accumulator acc{};
    show_value(acc);
    acc.add(5);
    show_value(acc);
    print(acc);

    Friend friend_;
    friend_.run_value(acc);
}
