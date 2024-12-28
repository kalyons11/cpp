#include <iostream>

#include "name.hpp"

[[maybe_unused]] int globalVariable{5};  // define a global variable

// Global variables can be constants
[[maybe_unused]] const int globalConstant{5};
[[maybe_unused]] constexpr int globalConstantExpression{globalConstant};

// We can also define doSomething in the global namespace
int doSomething(int x, int y)
{
    return x * y;
}

void print()
{
    std::cout << "Hello, World!" << '\n';
}

namespace Foo  // define a namespace named Foo
{
// This doSomething() belongs to namespace Foo
int doSomething(int x, int y)
{
    return x + y;
}

void print()
{
    std::cout << "Hello, Foo!" << '\n';
}

void print_all()
{
    print();    // call the print() that exists in namespace Foo
    ::print();  // call the print() that exists in the global namespace
}
}  // namespace Foo

namespace Goo  // define a namespace named Goo
{
// This doSomething() belongs to namespace Goo
int doSomething(int x, int y)
{
    return x - y;
}
}  // namespace Goo

int main()
{
    std::cout << Foo::doSomething(4, 3)
              << '\n';  // use the doSomething() that exists in namespace Foo
    std::cout << Goo::doSomething(4, 3)
              << '\n';  // use the doSomething() that exists in namespace Goo
    std::cout
        << doSomething(4, 3)
        << '\n';  // use the doSomething() that exists in the global namespace

    Foo::print_all();

    MyNamespace::my_function();  // use the my_function() that exists in
                                 // namespace MyNamespace

    namespace inner =
        MyNamespace::InnerNamespace;  // create an alias for InnerNamespace
    inner::inner_function();          // use the inner_function() that exists in
                                      // namespace MyNamespace::InnerNamespace

    std::cout << globalVariable << '\n';  // use the global variable
    std::cout << MyNamespace::globalVariable
              << '\n';  // use the global variable that exists in namespace
                        // MyNamespace

    return 0;
}
