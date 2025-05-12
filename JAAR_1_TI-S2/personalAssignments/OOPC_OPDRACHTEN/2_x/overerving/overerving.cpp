#include "overerving.hpp"

// PERSON
void Person::setName(std::string name)
{
    Person::name = name;
}

void Person::setBirthDay(std::string day)
{
    Person::dayOfBirth = day;
}

void Person::setBirthMonth(std::string month)
{
    Person::monthOfBirth = month;
}

void Person::setBirthYear(int year)
{
    Person::yearOfBirth = year;
}

void Person::setAge()
{
    int currentYear = 2024;
    Person::age = currentYear - yearOfBirth;
}

std::string Person::getName()
{
    return name;
}

int Person::getAge()
{
    return age;
}

std::string Person::getBirthDay()
{
    return dayOfBirth;
}

std::string Person::getBirthMonth()
{
    return monthOfBirth;
}

int Person::getBirthYear()
{
    return yearOfBirth;
}

// STUDENT

Student::Student(const Person& person) : Person(person) {}

void Student::setSchoolName(std::string name)
{
    Student::schoolName = name;
}

void Student::setClassNumber(int number)
{
    Student::classNumber = number;
}

void Student::seteducationLevel(std::string level)
{
    Student::educationLevel = level;
}

std::string Student::getSchoolName()
{
    return schoolName;
}

int Student::getClassNumber()
{
    return classNumber;
}

std::string Student::getEducationLevel()
{
    return educationLevel;
}
