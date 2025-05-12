// 010-TestCase.cpp

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "Catch2.hpp"

// ORGINELE FACTORIAL FUNCTIE
// unsigned int Factorial(unsigned int number) {
//    return number <= 1 ? number : Factorial(number-1) * number;
//}
// UITLEG VAN DE FUNCTIE
// 1: Als number gelijk staat aan 1 of kleiner is wordt de voorwaarde als true gezien want aan de linker kant
// van de ternary operator staat de return waarde als de condition true is
// 2: Als het getal groter is dan 1 is de return Factorial(number-1) * number
// 3: Als je dus bijvoorbeeld 5 mee geeft aan de functie dan wordt 4 * 5 gereturned
// 4: een 1 of 0 returned 1

unsigned int Factorial(unsigned int number)
{
    return number > 1 ? Factorial(number - 1) * number : 1; // DE FUNCTIE GEBRUIK RECURSION!
                                                            // DAAROM DOET DIE CONSTANT EEN LAGER GETAL * ORGINELE GETAL
                                                            // ROEPT NAMELIJK ZICH ZELF TERUG IN DE RETURN STATEMENT!
} // ? stelt een voorwaarde, het is een voorwaardelijke expressie genaamd ternary
  // Als number groter is dan 1 dan wordt Factorial(number-1)*number gereturned
  // dus bijvoorbeeld 5 zal als true gezien worden en geeft 4*5 terug
  // kleiner of gelijk aan 1 zal een 1 terug geven

// De tests checken of het resultaat van de functie gelijk staat aan wat er achter de == staat

// mijn eigen voorbeeld:

TEST_CASE("Factorials tests1", "[factorial]") // 1 en 2 genoemd, want mag niet de zelfde naam hebben
{
    REQUIRE(Factorial(0) == 1);
    REQUIRE(Factorial(4) == 7); // FAILED hier komt 24 uit in plaats van 7 volgens de test!
}
TEST_CASE("Factorials tests2", "[factorial]")
{
    REQUIRE(Factorial(22) == 866); // FAILED! hier komt 3772252160 getal in hex:(0xe0d80000) uit
    REQUIRE(Factorial(9) == 644); // FAILED 362880 (0x58980) is het juiste antwoord
    REQUIRE(Factorial(10) == 3628800);
}
// De tests checken of het resultaat van de functie gelijk staat aan wat er achter de == staat

// mijn eigen voorbeeld:

// Compile & run:
// - g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 010-TestCase 010-TestCase.cpp && 010-TestCase --success
// - cl -EHsc -I%CATCH_SINGLE_INCLUDE% 010-TestCase.cpp && 010-TestCase --success
