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

// Data hiding is a key concept in object-oriented programming. It means that
// the data is hidden from the outside world and only the class itself can
// access it. This is done by making the data private. The class can then
// provide public member functions to access the data. This is called
// encapsulation.

class Person
{
    std::string m_name;
    char first_initial{};

   public:
    Person(const std::string& name)
    {
        m_name = name;
        first_initial = m_name.front();
    }

    const std::string& getName() const { return m_name; }
    void setName(const std::string& name)
    {
        // Ensure name is non-empty
        if (name.empty()) return;
        m_name = name;
        first_initial = m_name.front();
    }
    void print() const
    {
        std::cout << "Name: " << m_name << " First initial: " << first_initial
                  << '\n';
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

    Person person{"Alex"};
    std::cout << person.getName() << '\n';
    person.setName("Joe");
    person.print();
}
