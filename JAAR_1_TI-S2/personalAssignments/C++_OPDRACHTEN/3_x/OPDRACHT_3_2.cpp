// AIMANE CHAKIRI
// Beschrijf in maximaal twee zinnen wat de onderstaande functie upperAndLower() doet. Probeer dit te doen zonder de code op een computer uit te voeren. Je mag aannemen in je beschrijving dat de parameter van de functie enkel letters bevat.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void upperAndLower(vector<string> &text)
{ // Functie vraagt om een vector gemaakt van strings, bewaard in variabel text
    for (unsigned int i = 0; i < text.size(); i++)
    { // Deze loop gaat langs elke string in de vector
        for (unsigned int j = 0; j < text[i].size(); j++)
        { // Deze loop gaat langs elke letter in de string in de vector, maakt het een char?
            if (i % 2 == 0)
            {                           // Slaat elke keer 1 string over in de vector indien index even is of gelijk staat aan 0
                text[i][j] |= (1 << 5); // Voert deze expressie uit wanneer de string index even of 0 is.
            }
            else
            {
                text[i][j] &= ~(1 << 5); // Indien de index niet even is of 0 is deze expressie uitvoeren
            }
        }
    }
}

// ANTWOORD:
// upperAndLower zet even indexen naar hoofdletters en oneven indexen naar kleine letters
