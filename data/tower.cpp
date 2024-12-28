#include <iostream>

#include "tower.hpp"

double get_height()
{
    double d{};
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> d;
    return d;
}

void compute_height(double initialHeight, int seconds)
{
    // Constants
    const double gravity{9.8};

    // Compute the distance fallen after a certain amount of time
    double distanceFallen = (gravity * seconds * seconds) / 2;

    // Compute the height of the object above the ground
    double height = initialHeight - distanceFallen;

    // Check whether the object has already hit the ground
    if (height > 0.0)
    {
        std::cout << "At " << seconds
                  << " seconds, the ball is at height: " << height
                  << " meters\n";
    }
    else
    {
        std::cout << "At " << seconds
                  << " seconds, the ball is on the ground.\n";
    }
}

void simulate_ball_fall()
{
    // Get the initial height from the user
    double initialHeight = get_height();

    // Simulate the ball falling for 5 seconds
    for (int i = 0; i <= 5; ++i)
    {
        compute_height(initialHeight, i);
    }
}