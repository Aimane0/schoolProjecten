#include "book.hpp"
#include <string>

using namespace std;

int main()
{
    book book1{"Text?", "Fréderike Geerdink", "Dit vuur dooft nooit: Een jaar bij de PKK"};

book1.print(); // mogelijk het antwoord gebaseerd op de repo van Lia
               // Dit is zo omdat in de book.cpp file een functie aangemaakt wordt genaamd void book::print()
               // Deze functie voert de functies print_title(), print_author() en print_text() uit
               // Vervolgens wordt er onder de void book::print() de functies binnen deze functie gedefineerd.
               // void book::print_text() heeft namelijk de definitie std::cout << text << "\n"
    return 0;
}