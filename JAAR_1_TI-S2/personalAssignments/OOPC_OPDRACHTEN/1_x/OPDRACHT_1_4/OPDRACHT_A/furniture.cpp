#include <iostream>
#include "furniture.hpp"
#include <vector>

// Maken van Stool print functie
void Stool::print_stool()
{
    print_legs();
    print_seats();
};

// Maken van de functies die in de print functies zitten
void Stool::print_legs()
{
    std::cout << "Amount of legs: " << n_legs << "\n";
};

void Stool::print_seats()
{
    std::cout << "Amount of seats: " << n_seats << "\n";
};

// Maken van makeMoreHipster onderdeel
void Stool::remove_legs()
{
    n_legs = n_legs - 1;
};

// Maken van Table print functie
void Table::print_table()
{
    print_legs();
    print_length();
    print_width();
};

void Table::print_legs()
{
    std::cout << "Amount of legs: " << n_legs << "\n";
};

void Table::print_length()
{
    std::cout << "Length of the table:  " << length << "\n";
};

void Table::print_width()
{
    std::cout << "Width of the table: " << n_legs << "\n";
};

// Maken van makeMoreHipster onderdeel
void Table::receive_legs(int received_legs) {
    n_legs = n_legs + received_legs;
};

// Basis waarde geven aan de furnitures van stoelen en de tafel
Furniture::Furniture() : stool1(4, 1),
                         stool2(4, 1),
                         stool3(4, 1),
                         stool4(4, 1),
                         table1(4, 200, 100){};

// Maken van Furniture functies
void Furniture::makeMoreHipster()
{
    stool1.remove_legs();
    stool2.remove_legs();
    stool3.remove_legs();
    stool4.remove_legs();
    table1.receive_legs(4);
};

// De print functie kan gedaan worden door de print functies van de vorige klassen te gebruiken!
void Furniture::print_furniture() {
    stool1.print_stool();
    stool2.print_stool();
    stool3.print_stool();
    stool4.print_stool();
    table1.print_table();
};
