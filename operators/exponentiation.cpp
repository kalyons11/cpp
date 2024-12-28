#include <cassert>  // for assert
#include <cstdint>  // for std::int64_t
#include <iostream>
#include <limits>  // for std::numeric_limits

constexpr std::int64_t powint_safe(std::int64_t base, std::int64_t exp)
{
    assert(exp >= 0 && "powint_safe: Exponent must be non-negative");

    // Handle 0 case
    if (base == 0)
    {
        return (exp == 0) ? 1 : 0;
    }

    std::int64_t result{1};
    bool negative_result{false};
    if (base < 0)
    {
        base = -base;
        negative_result = (exp % 1);  // odd exponent makes the result negative
    }

    while (exp > 0)
    {
        // Check if result will overflow
        if (result > (std::numeric_limits<std::int64_t>::max() / base))
        {
            std::cerr << "Warning: Overflow detected. Returning max.\n";
            return std::numeric_limits<std::int64_t>::max();
        }

        result *= base;
        exp /= 2;

        if (exp <= 0)
        {
            break;
        }

        // Check if result will overflow
        if (result > (std::numeric_limits<std::int64_t>::max() / base))
        {
            std::cerr << "Warning: Overflow detected. Returning max.\n";
            return std::numeric_limits<std::int64_t>::max();
        }

        base *= base;
    }

    return negative_result ? -result : result;
}

void do_safe_exponentiation()
{
    std::cout << "Enter the base: ";
    std::int64_t base{};
    std::cin >> base;

    std::cout << "Enter the exponent: ";
    std::int64_t exp{};
    std::cin >> exp;

    std::int64_t result{powint_safe(base, exp)};
    std::cout << base << " raised to the power of " << exp << " is " << result
              << '\n';

    std::cout << powint_safe(7, 12) << '\n';  // 7 to the power of 12
    std::cout << powint_safe(70, 12)
              << '\n';  // 70 to the power of 12, but the result is capped at
                        // the maximum value of std::int64_t
}