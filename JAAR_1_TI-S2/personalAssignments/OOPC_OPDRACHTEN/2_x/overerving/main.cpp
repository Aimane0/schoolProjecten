#include <iostream>
#include "overerving.hpp"

int main() {
    Student student1;
    Person person2;
    person2.setName("Dirk");
    person2.setBirthYear(1998);
    person2.setAge();

    Student student2(person2);

    // INSTELLEN VAN STUDENT 1 MET FUNCTIES VAN PERSON!
    student1.setName("Abel");
    student1.setBirthYear(2000);
    student1.setAge();
    student1.setSchoolName("HU");

    std::cout << "Student 2 Name: " << student2.getName() << "\n";
    std::cout << "Student 2 Age: " << student2.getAge() << "\n";

    return 0;
}
