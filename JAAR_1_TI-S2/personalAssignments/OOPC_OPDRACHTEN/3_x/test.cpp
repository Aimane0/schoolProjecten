#include <iostream>
#include <string>

// Eigen geschreven code om te testen of ik references begrijp!

void plusOneRef(int &number)
{
    number += 1;
}

void plusTwoRef(int &number)
{
    number += 2;
}

void plusOne(int number)
{
    number += 1;
}

void plusTwo(int number)
{
    number += 2;
}

int main(){

    int numOne = 1;
    int numTwo = 2;

    plusOne(numOne);
    plusTwo(numTwo);

    std::cout << "USING FUNCTION WITHOUT REFERENCE" << "\n";
    std::cout << numOne << "\n";
    std::cout << numTwo << "\n";

    plusOneRef(numOne);
    plusTwoRef(numTwo);

    std::cout << "USING FUNCTION WITH REFERENCE" << "\n";
    std::cout << numOne << "\n";
    std::cout << numTwo << "\n";

    return 0;
}