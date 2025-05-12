#include <ostream>
#include <iostream>
#include "ADTVector.hpp"

ADTVector::ADTVector(int x, int y) : x (x), y (y){}

// Codevoorbeeld 06-04 - Vectoren bij elkaar optellen via publieke attributen gebruikt
// https://github.com/HU-TI-DEV/TI-S2/tree/main/software/c%2B%2B/oop-concepten/ADTs
// Kan deze functie niet maken als ik ADTVector:: toevoeg voor operator+
// Hoezo kan het zonder ADTVector? Waarom moet += wel met?
ADTVector operator+(ADTVector one, ADTVector two)
{
    return ADTVector(one.x + two.x, one.y + two.y);
    // Voegt de X'en van zowel one als two bij elkaar
    // De komma er tussen geeft aan waar index 0 stopt
    // Voegt de Y'en van zowel one en two bij elkaar!
}
                                  // Voor ADTVector const schrijven
                                  // WANT we willen v niet aanpassen
                                  // we willen alleen de linker kant van
                                  // += aanpassen
                                  // &v gebruiken om geen kopie te maken
                                  // dit is effiecenter
                                  // EN DAAROM GEBRUIK CONST
                                  // Het risico is dat je v aanpast terwijl
                                  // we dat niet willen in dit geval
ADTVector& ADTVector::operator+=(ADTVector &v)
// ook deze & is er om de return type aan de linkerkant als referentie
// te lezen in plaats van een kopie te maken ter efficientie 
{
    x += v.x;

    y += v.y;

    return *this; // verwijst naar de left hand side van de += berekening
                  // v1 += v2, this verwijst naar v1
                  // * zorgt er voor dat je niet refereert naar het geheugen address
                  // * zorgt er voor dat we v1 vanuit het address opvragen
}

ADTVector operator*(const ADTVector lhs, const int rhs)
{
    return ADTVector(lhs.x * rhs, lhs.y * rhs);
}

ADTVector operator*(const int lhs, const ADTVector rhs)
{
   return ADTVector(lhs * rhs.x, lhs * rhs.y);
   // return rhs * lhs;
   // ^ Dit maakt gebruik van de functie hier boven
   // Hergebruik eerder gemaakte functies is handig voor als je grote operators schrijft die ook de andere kant
   // op moeten werken zoals deze * operator
}

//ADTVector is de return value, we gebruiken een reference om aan te geven dat we de lhs willen aanpassen
ADTVector &ADTVector::operator*=(const int rhs) // We maken een const van de rhs want die willen we NIET veranderen
{
    x *= rhs;
    y *= rhs;

    return *this; // this refereert naar een specifieke plek in de memory waar de lhs is opgeslagen
                  // * zorgt er voor dat we niet de memory returnen maar returnen naar wat er op de memory staat namelijk de variabel zelf
}
// GEBRUIKEN VAN LHS EN RHS om aan te geven om welk object rond om de operator het gaat

std::ostream &operator<<(std::ostream &out, ADTVector rhs)
{
    out << "(" << rhs.x << ", " << rhs.y << ")";
    return out;
}
// Wat gebeurt hier boven ?! 
// Vragen aan vera


// MAAK EEN VECTOR * VECTOR operator
