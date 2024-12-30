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
}