#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student
{
public:
    Student (std::string, int);
    void setAge(int);
    void setName(std::string);
    std::string getName() const;
    int getAge() const;
    void printStudentInfo() const;

private:
    std::string name;
    int age;
};

#endif // STUDENT_H
