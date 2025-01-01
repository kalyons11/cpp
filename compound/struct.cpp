#include <iostream>

#include "struct.hpp"

struct Employee
{
    int id;
    int age{26};
    float salary{56000};
};

// Just like for enums, we can overload operator<< for structs
std::ostream& operator<<(std::ostream& os, const Employee& emp)
{
    os << "Employee. ID: " << emp.id << ", Age: " << emp.age
       << ", Salary: " << emp.salary;
    return os;
}

struct Fraction
{
    int numerator{0};
    int denominator{1};
};

std::ostream& operator<<(std::ostream& os, const Fraction& frac)
{
    os << frac.numerator << "/" << frac.denominator;
    // Print the value of the fraction as a decimal
    os << " = " << static_cast<double>(frac.numerator) / frac.denominator;
    return os;
}

void demo_structs()
{
    Employee emp1{1, 25, 50000.0};
    Employee emp2{2, 30, 75000.0};

    emp1.age = 26;
    emp2.salary = 80000.0;

    std::cout << "Employee 1\n";
    std::cout << "ID: " << emp1.id << "\n";
    std::cout << "Age: " << emp1.age << "\n";
    std::cout << "Salary: " << emp1.salary << "\n";

    std::cout << "\nEmployee 2\n";
    std::cout << "ID: " << emp2.id << "\n";
    std::cout << "Age: " << emp2.age << "\n";
    std::cout << "Salary: " << emp2.salary << "\n";

    // if we skip some fields, they will be initialized to 0
    Employee emp3{3};
    std::cout << "\nEmployee 3\n";
    std::cout << "ID: " << emp3.id << "\n";          // 3
    std::cout << "Age: " << emp3.age << "\n";        // 0
    std::cout << "Salary: " << emp3.salary << "\n";  // 0.0

    // we can also use the overloaded operator<<
    std::cout << emp1 << "\n";

    // We can use designated initializers to initialize only some fields
    Employee emp4{.id = 4, .salary = 100000.0};
    emp4 = {.id = emp4.id,
            .age = 35,
            .salary = emp4.salary};  // update age but keep id and salary
    std::cout << emp4 << "\n";

    // We can make a struct const
    const Employee emp5{5, 35, 120000.0};
    // emp5.age = 36; // error: assignment of member 'Employee::age' in
    // read-only object
    std::cout << emp5 << "\n";

    const Fraction frac1{3, 4};
    std::cout << frac1 << "\n";  // 3/4 = 0.75
    const Fraction frac{};
    std::cout << frac << "\n";  // 0/1 = 0.0
    const Fraction one{1};
    std::cout << one << "\n";  // 1/1 = 1.0
    const Fraction empty;
    std::cout << empty << "\n";  // 0/1 = 0.0
}
