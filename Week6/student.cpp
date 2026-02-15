#include "student.h"
#include <iostream>



Student::Student(std::string n, int a) : name(n), age(a)
{

}

void Student::setAge(int a)
{
    age = a;
}

void Student::setName(std::string n)
{
    name = n;
}

std::string Student::getName() const
{
    return name;
}

int Student::getAge() const
{
    return age;
}

void Student::printStudentInfo() const
{
    std::cout << "Student " << name << " Age " << age << std::endl;
}
