#ifndef overerving_HPP
#define overerving_HPP

#include <iostream>
#include <string>

// Onderdelen voor persoon
class Person
{
private:
    std::string name;
    int age;
    std::string dayOfBirth;
    std::string monthOfBirth;
    int yearOfBirth;
  
public:
    // Maak een constructor voor person, gebruik deze binnen constructor student
    void setName(std::string name);
    void setBirthDay(std::string day);
    void setBirthMonth(std::string month);
    void setBirthYear(int year);
    void setAge();
    std::string getName();
    int getAge();
    std::string getBirthDay();
    std::string getBirthMonth();
    int getBirthYear();
};

// student erft van class persoon
class Student : public Person
{
private:
    std::string schoolName;
    int classNumber;
    std::string educationLevel;

public:
    Student() = default;           // DEFAULT ZORGT ER VOOR DAT DE CONSTRUCTOR DEFAULT OP EEN LEGE CONSTRUCTOR
    Student(const Person &person); // DEZE CONSTRUCTOR, SAMEN MET EEN REFERENCE, ZORGT ER VOOR DAT WE EEN AL BESTAAND PERSOON KUNNEN GEBRUIKEN VOOR 
                            // Hoeft person niet in de constructor te verwerken
                            // check de README.md van overerving en kijk hoe ball en circle worden gedaan
    void setSchoolName(std::string name);
    void setClassNumber(int number);
    void seteducationLevel(std::string level);
    std::string getSchoolName();
    int getClassNumber();
    std::string getEducationLevel();
};

class Employee
{
};

#endif
