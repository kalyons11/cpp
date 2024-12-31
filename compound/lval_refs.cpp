#include <iostream>

#include "lval_refs.hpp"

// str is bound to the object passed to print_value as a reference
// This avoids copying the object
void print_value(std::string& str)
{
    std::cout << str << '\n';
}

void add_one(int& x)  // x must be modifiable
{
    x += 1;  // This will modify the value of the object passed to add_one
}

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

    // We can have a const reference to a const lvalue
    const int const_x{42};
    const int& ref_const_x{const_x};
    // ref_const_x = 43; // error: assignment of read-only reference
    // 'ref_const_x' const_x = 43; // error: assignment of read-only variable
    // 'const_x'
    std::cout << "const_x: " << const_x << '\n';          // 42
    std::cout << "ref_const_x: " << ref_const_x << '\n';  // 42

    // We can have a const reference to a non-const lvalue
    int x2{44};
    const int& ref_const_x2{x2};
    // ref_const_x2 = 43; // error: assignment of read-only reference
    x2 = 43;                            // okay: x2 is not const
    std::cout << "x2: " << x2 << '\n';  // 43
    std::cout << "ref_const_x2: " << ref_const_x2 << '\n';  // 43

    // lvalue references to const can be initialized with rvalues
    const int& ref_const_x3{51};
    std::cout << "ref_const_x3: " << ref_const_x3 << '\n';  // 51

    // We can have a reference of one type to an object of another type
    const double& r1{5};
    std::cout << "r1: " << r1 << '\n';  // 5.0
    // But, the referenced object must be implicitly convertible to the
    // reference

    // When this type conversion takes place from a temporary object, the
    // value can be modified
    short test{1};
    const int& ref_test{test};
    --test;
    std::cout << "ref_test: " << ref_test << '\n';  // Accessing ref_test will
                                                    // print the value of test
                                                    // at the time of
                                                    // initialization
    std::cout << "test: " << test << '\n';          // 0

    // We can pass by reference to avoid copying large objects
    // We can also use references to modify the value of an object in a function
    int a{5};
    int b{6};
    std::cout << "a: " << a << '\n';  // 5
    std::cout << "b: " << b << '\n';  // 6
    std::swap(a, b);                  // a and b are passed by reference
    std::cout << "a: " << a << '\n';  // 6
    std::cout << "b: " << b << '\n';  // 5

    // We can pass a reference to a std::string to print_value
    std::string str{"Hello, World!"};
    print_value(str);  // Hello, World!

    // We can pass a reference to an int to add_one
    int num{5};
    add_one(num);
    std::cout << "num: " << num << '\n';  // 6

    // Reference parameters must be modifiable
    const int const_num{5};
    // add_one(const_num); // error: cannot bind non-const lvalue reference
}
