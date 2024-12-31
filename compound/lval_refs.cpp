#include <iostream>

#include "lval_refs.hpp"

void run_lval_refs()
{
    // A reference is an alias to an existing object
    // An lvalue reference is a reference that binds to an lvalue
    // An lvalue is an object that occupies some identifiable location in memory
    // int& is a reference type that binds to an int lvalue
    // int is the referenced type here
    // non-const vs const lvalue references
    int x{42};
    int& ref_x{x};  // & means "reference to", not "address of"

    std::cout << "x: " << x << '\n';
    std::cout << "ref_x: " << ref_x << '\n';

    // We can update the value of x through ref_x
    ref_x = 43;
    std::cout << "x: " << x << '\n';          // 43
    std::cout << "ref_x: " << ref_x << '\n';  // 43
    // if we update x, ref_x will reflect the change
    x = 44;
    std::cout << "x: " << x << '\n';          // 44
    std::cout << "ref_x: " << ref_x << '\n';  // 44

    // References must be initialized
    // int& ref_x2; // error: reference must be initialized
    // Non-const lvalue references cannot bind to rvalues or const lvalues
    // int& ref_x3{42}; // error: cannot bind non-const lvalue reference of type
    // 'int&' to an rvalue of type 'int' int& ref_x4{42}; // error: cannot bind
    // non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    // const lvalue references can bind to rvalues
    [[maybe_unused]] const int& ref_x5{42};

    int t{5};
    [[maybe_unused]] int& ref_t{
        t};  // okay: non-const lvalue reference bound to a modifiable lvalue

    [[maybe_unused]] const int y{5};
    // int& invalidRef { y };  // invalid: non-const lvalue reference can't bind
    // to a non-modifiable lvalue int& invalidRef2 { 0 }; // invalid: non-const
    // lvalue reference can't bind to an rvalue

    // Mismatched types between reference and referenced type can cause issues
    // int& ref_x6{3.14}; // error: cannot bind non-const lvalue reference of
    // type 'int&' to an rvalue of type 'double' int& ref_x7{y}; // error:
    // cannot bind non-const lvalue reference of type 'int&' to an rvalue of
    // type 'const int'

    // References cannot be re-seated
    int z{42};
    int& ref_z{z};
    int w{43};
    ref_z = w;  // this updates the value of z, not the reference itself
    std::cout << "z: " << z << '\n';          // 43
    std::cout << "ref_z: " << ref_z << '\n';  // 43
    std::cout << "w: " << w << '\n';          // 43

    // References are not objects
    // sizeof(ref_x); // error: 'ref_x' declared as reference but not
    // initialized int& ref_x8{ref_x}; // error: 'ref_x' declared as reference
    // but not initialized
    int var{42};
    int& ref_var{var};
    int& ref_ref_var{ref_var};  // ref_var becomes l-value here
    // ref_ref_var references var
    std::cout << "var: " << var << '\n';                  // 42
    std::cout << "ref_var: " << ref_var << '\n';          // 42
    std::cout << "ref_ref_var: " << ref_ref_var << '\n';  // 42
}
