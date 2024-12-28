#include <iostream>

int add(int x, int y)
{
    return x + y;
}

void show_increment_decrement()
{
    // Prefix increment and decrement
    int x{5};
    int y{++x};  // x is incremented to 6, then assigned to y
    std::cout << "x: " << x << " y: " << y << '\n';  // x: 6 y: 6

    int a{5};
    int b{--a};  // a is decremented to 4, then assigned to b
    std::cout << "a: " << a << " b: " << b << '\n';  // a: 4 b: 4

    // Postfix increment and decrement
    int m{5};
    int n{m++};  // m is assigned to n, then incremented to 6
    std::cout << "m: " << m << " n: " << n << '\n';  // m: 6 n: 5

    int p{5};
    int q{p--};  // p is assigned to q, then decremented to 4
    std::cout << "p: " << p << " q: " << q << '\n';  // p: 4 q: 5

    // Favor the prefix versions, as they are more performant and less likely to
    // cause surprises

    // Side effects can lead to undefined behavior
    // int i{5};
    // std::cout << add(i, ++i) << '\n';  // undefined behavior

    // C++ does not define the order of evaluation for function arguments or the
    // operands of operators Don’t use a variable that has a side effect applied
    // to it more than once in a given statement. If you do, the result may be
    // undefined
}
