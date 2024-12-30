#include <iostream>

void run_loops()
{
    int count{1};
    while (count <= 10)
    {
        std::cout << count << " ";
        count++;
    }

    std::cout << '\n';
    std::cout << "Done with the while loop" << '\n';

    char current{'a'};
    while (current <= 'z')
    {
        std::cout << current << " " << static_cast<int>(current) << '\n';
        current++;
    }

    // We can do the same with a for loop
    for (int i{1}; i <= 10; i++)
    {
        std::cout << i << " ";
    }

    std::cout << '\n';
    std::cout << "Done with the for loop" << '\n';
    for (char c{'a'}; c <= 'z'; c++)
    {
        std::cout << c << " " << static_cast<int>(c) << '\n';
    }

    // We can also use a range-based for loop
    int scores[]{100, 90, 97};
    for (int score : scores)
    {
        std::cout << score << " ";
    }

    // We can decrement the loop variable as well
    for (int i{10}; i > 0; i--)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';

    // We can define multiple variables in the for loop
    for (int i{1}, j{5}; i <= 5; i++, j--)
    {
        std::cout << i << " + " << j << " = " << i + j << '\n';
    }

    // Keep the scope of the loop variable as small as possible
    for (int i{1}; i <= 10; i++)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';

    // We can use break and continue in loops to control the flow
    for (int i{1}; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        std::cout << i << " ";
        if (i == 5)
        {
            std::cout << "Breaking out of the loop" << '\n';
            break;
        }
    }
    std::cout << "Done." << '\n';
}