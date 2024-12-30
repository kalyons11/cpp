#include <chrono>
#include <iostream>
#include <random>

#include "random.hpp"

void run_random_numbers()
{
    // Create a 32-bit Mersenne Twister random number engine
    std::mt19937 mt{};

    // Print 40 random numbers
    for (int i = 0; i < 40; ++i)
    {
        std::cout << mt() << '\t';

        // Start a new line every 5 numbers
        if ((i + 1) % 5 == 0)
        {
            std::cout << '\n';
        }
    }

    // Seed the random number engine with the current time
    std::mt19937 mt2{static_cast<std::mt19937::result_type>(
        std::chrono::system_clock::now().time_since_epoch().count())};

    // Create a distribution in the range [1, 6]
    std::uniform_int_distribution<int> dist(1, 6);

    // Print 40 rolls of a 6-sided die
    std::cout << "Printing 40 rolls of a 6-sided die:" << '\n';
    for (int i = 0; i < 40; ++i)
    {
        std::cout << dist(mt2) << '\t';

        // Start a new line every 10 numbers
        if ((i + 1) % 10 == 0)
        {
            std::cout << '\n';
        }
    }

    // Use a seed sequence with random_device to seed the mt
    std::random_device rd{};
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt3{seed};
    // Use this to generate random cards from a deck
    std::uniform_int_distribution<int> dist3(0, 51);
    std::cout << "Printing 10 random cards from a deck:" << '\n';
    for (int i = 0; i < 10; ++i)
    {
        // Map the random number to a card
        int card = dist3(mt3);
        int suit = card / 13;
        int rank = card % 13;
        // Hearts, Diamonds, Clubs, Spades
        std::string symbols[] = {"\u2665", "\u2666", "\u2663", "\u2660"};
        std::string ranks[] = {"Ace", "2", "3",  "4",    "5",     "6",   "7",
                               "8",   "9", "10", "Jack", "Queen", "King"};
        std::cout << ranks[rank] << " of " << symbols[suit] << '\n';
    }
}
