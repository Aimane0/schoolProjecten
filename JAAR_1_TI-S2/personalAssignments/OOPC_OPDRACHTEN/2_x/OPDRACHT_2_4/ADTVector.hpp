#ifndef ADTVector_HPP
#define ADTVector_HPP
#include <ostream>
#include <iostream>

class ADTVector{
private:
    int x; // Aangegeven attributen
    int y;

public:
    ADTVector(int x, int y); // Constructor
    
    // Operator +
    // Op stackoverflow gezien dat je iets een friend moet noemen als functie om te overloaden
    // Codevoorbeeld 06-04 - Vectoren bij elkaar optellen via publieke attributen gebruikt voor deze functie
    friend ADTVector operator+(ADTVector one, ADTVector two);

    // Als ik hier friend weg haal werkt de functie wel, anders werkt die niet
    // Hoezo? Vraag Gera
    ADTVector& operator+=(ADTVector &v);

    // Van Lia gezien dat er gebruik wordt gemaakt van 2x een * operator maken
    // maken we er 2 zodat de compiler kan kiezen tussen de twee afhangende op welke plek de int zit en welke de ADTVector?
    friend ADTVector operator*(const ADTVector lhs, const int rhs); // RHS = RIGHT HAND SIDE
    friend ADTVector operator*(const int lhs, const ADTVector rhs); // LHS = LEFT HAND SIDE
                                                                    // Maak gebruik van const want return iets nieuws in plaats van reference te gebruiken

    ADTVector &operator*=(const int rhs);
    
    friend std::ostream &operator<<(std::ostream &out, ADTVector rhs);
};

#endif