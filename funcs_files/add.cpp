#include <iostream>

// This is to be avoided as it can create surprising conflicts down the road
using namespace std;

#define KEY "value"
#define ADD_DEF "here"

int subtract(int x, int y)
{
    cout << "This is a log via the `using` directive." << '\n';
#ifdef KEY
    cout << "We do have a KEY: " << KEY << '\n';
#endif
#if defined(KEY)
    cout << "We do have a KEY: " << KEY << '\n';
#endif
#ifndef NOT_KEY
    cout << "We don't have NOT_KEY." << '\n';
#endif
    return x - y;
}