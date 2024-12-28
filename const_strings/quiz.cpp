#include <iostream>
#include <string>

#include "quiz.hpp"

std::string get_name(int person_number)
{
    std::cout << "Enter the name of person #" << person_number << ": ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    return name;
}

int get_age(const std::string& name)
{
    std::cout << "Enter the age of " << name << ": ";
    int age{};
    std::cin >> age;
    return age;
}

void print_older_person(const std::string& name1, int age1,
                        const std::string& name2, int age2)
{
    if (age1 > age2)
    {
        std::cout << name1 << " is older than " << name2 << '\n';
    }
    else if (age1 < age2)
    {
        std::cout << name2 << " is older than " << name1 << '\n';
    }
    else
    {
        std::cout << name1 << " and " << name2 << " are the same age\n";
    }
    // Print the age difference as an absolute value
    std::cout << "The age difference is " << std::abs(age1 - age2)
              << " year(s)\n";
}

void run_quiz()
{
    std::string name1 = get_name(1);
    int age1 = get_age(name1);
    std::string name2 = get_name(2);
    int age2 = get_age(name2);

    print_older_person(name1, age1, name2, age2);
}