#include <iostream>

#include "oo.hpp"

class Employee
{
    int m_id{};
    int m_age{};
    double m_wage{};
    std::string m_name{};

   public:
    // This constructor will be called when an object is created
    Employee(int id, int age, double wage, const std::string& name)
    {
        m_id = id;
        m_age = age;
        m_wage = wage;
        m_name = name;
    }

    // This function can be called on objects
    void print() const
    {
        std::cout << "ID: " << m_id << " Name: " << m_name << " Age: " << m_age
                  << " Wage: $" << m_wage << '\n';
    }

    void updateWage(double wage)
    {
        // Validate wage before setting
        m_wage = wage;
    }

    // We can use a getter to return the name string by reference
    const std::string& getName() const { return m_name; }
};

struct Date
{
    int day{};
    int month{};
    int year{};

    void print() const
    {
        std::cout << day << '/' << month << '/' << year << '\n';

        // This will not compile
        // day = 20;
    }
};

void show_oo()
{
    // We can create instances of the Employee class
    Employee alex{1, 25, 25.00, "Alex"};
    Employee joe{2, 30, 30.00, "Joe"};

    // and access their data
    // std::cout << alex.m_name << " is " << alex.m_age << " years old and makes
    // $" << alex.m_wage << " per hour.\n"; std::cout << joe.m_name << " is " <<
    // joe.m_age << " years old and makes $" << joe.m_wage << " per hour.\n";
    alex.print();
    joe.print();

    // We can create instances of the Date struct
    const Date date{25, 12, 2014};
    // and call its member function
    date.print();

    alex.updateWage(30.00);

    // We can use a getter to access the name data member
    auto name = alex.getName();
}
