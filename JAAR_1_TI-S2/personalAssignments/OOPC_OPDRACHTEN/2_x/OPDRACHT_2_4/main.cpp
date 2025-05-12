#include <ostream>
#include "ADTVector.hpp"

int main()
{
    ADTVector a(4, 6);
    ADTVector b(5, 7);

    ADTVector c = a + b;

    std::cout << c << "\n";
    // out hoef je niet te gebruiken, je kunt gwn std::cout gebruiken
    // out is geen print functie, cout wel
    // gebruik het om vector te printen, want vector kun je niet couten

    ADTVector d = 5 * b;
    std::cout << d << "\n";

    ADTVector e = a * 5;
    std::cout << e << "\n";
    
}