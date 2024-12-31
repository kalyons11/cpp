#include <iostream>

#include "in_out.hpp"

// Parameters that only receive input values from the caller are "in" parameters
void print(int x)
{
    std::cout << x << '\n';
}

// Parameters that only return output values to the caller are "out" parameters
void update(int& x)
{
    x = 42;
}

void run_in_out_params()
{
    int x = 0;
    print(x);
    update(x);
    print(x);
}
