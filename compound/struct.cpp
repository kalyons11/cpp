#include <iostream>
#include <numeric>

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

Fraction multiply(const Fraction& frac1, const Fraction& frac2)
{
    const Fraction result{frac1.numerator * frac2.numerator,
                          frac1.denominator * frac2.denominator};
    // Simplify the fraction
    const int gcd = std::gcd(result.numerator, result.denominator);
    return {result.numerator / gcd, result.denominator / gcd};
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac)
{
    os << frac.numerator << "/" << frac.denominator;
    // Print the value of the fraction as a decimal
    os << " = " << static_cast<double>(frac.numerator) / frac.denominator;
    return os;
}

// We can pass a struct by reference to avoid copying
void print_employee(const Employee& emp)
{
    std::cout << emp << "\n";
}

// We can have a function return a struct
Employee get_employee(int id, int age, float salary)
{
    return {id, age, salary};
}

// We can create a Company struct that has an Employee CEO
struct Company
{
    Employee ceo;
    std::string name;
};

struct Point
{
    int x;
    int y;
};

struct Triangle
{
    const Point* a;
    const Point* b;
    const Point* c;
};

std::ostream& operator<<(std::ostream& os, const Triangle* triangle)
{
    os << "Triangle a: (" << triangle->a->x << ", " << triangle->a->y << ")\n";
    os << "Triangle b: (" << triangle->b->x << ", " << triangle->b->y << ")\n";
    os << "Triangle c: (" << triangle->c->x << ", " << triangle->c->y << ")\n";
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

    print_employee(emp1);
    const Employee& ref_emp1 = emp1;
    print_employee(ref_emp1);

    const Employee emp6 = get_employee(6, 40, 150000.0);
    std::cout << emp6 << "\n";

    const Fraction frac2{2, 3};
    const Fraction frac3{5, 7};
    const Fraction result = multiply(frac2, frac3);  // 10/21
    std::cout << result << "\n";

    const Fraction frac4{3, 4};
    const Fraction result2 = multiply(frac2, frac4);  // 1/2
    std::cout << result2 << "\n";

    const Company company{{7, 45, 200000.0}, "Acme Inc."};
    std::cout << "Company: " << company.name << "\n";
    std::cout << "CEO: " << company.ceo << "\n";

    // We can use the member selection operator to access the fields of a struct
    // from a pointer
    const Employee* emp_ptr{&emp1};
    std::cout << "Employee ID: " << emp_ptr->id << "\n";  // 1
    // This is equivalent to (*emp_ptr).id but more concise
    // We can also use the member selection operator to access the fields of a
    // struct from a reference
    const Employee& emp_ref{emp1};
    std::cout << "Employee Age: " << emp_ref.age << "\n";  // 26

    // We can do this in a nested way
    const Point a{0, 0};
    const Point b{3, 0};
    const Point c{0, 4};
    const Triangle triangle{&a, &b, &c};
    const Triangle* triangle_ptr{&triangle};
    std::cout << triangle_ptr;
}
