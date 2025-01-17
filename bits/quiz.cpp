#include <bitset>
#include <cstdint>
#include <iostream>

#include "quiz.hpp"

void run_quiz()
{
    [[maybe_unused]] constexpr std::uint8_t option_viewed{0x01};
    [[maybe_unused]] constexpr std::uint8_t option_edited{0x02};
    [[maybe_unused]] constexpr std::uint8_t option_favorite{0x04};
    [[maybe_unused]] constexpr std::uint8_t option_shared{0x08};
    [[maybe_unused]] constexpr std::uint8_t option_deleted{0x10};

    std::uint8_t myArticleFlags{option_favorite};

    // Set article as viewed
    myArticleFlags |= option_viewed;

    // Check if article was deleted
    myArticleFlags& option_deleted ? std::cout << "Article deleted\n"
                                   : std::cout << "Article not deleted\n";

    // Toggle the favorite status
    myArticleFlags ^= option_favorite;

    std::cout << std::bitset<8>{myArticleFlags} << '\n';
}