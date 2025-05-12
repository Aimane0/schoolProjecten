// Een groep wiskundigen besluit mee te doen aan een 9-tegen-9-voetbaltoernooi. Na analyse van eerdere wedstrijden wordt besloten dat de beste opstelling drie rijen van drie is.

// Om de tegenstanders te verwarren en omdat hun teamnaam ‘the Transposers’ is, besluiten de wiskundigen om tijdens de wedstrijden af en toe de opstelling te transponeren.

// Schrijf een functie die de getransponeerde matrix van de opstelling kan berekenen.

//    Een getransponeerde matrix is een matrix die gespiegeld is over zijn hoofddiagonaal. Met andere woorden, de functie moet van matrix m het element m[i][ j] verwisselen met het element m[ j][i].
//    De functie moet ook werken voor andere matrixen. - Je mag aannemen dat de kolommen even lang zijn als de rijen.
//    Laat het programma de getransponeerde matrix afdrukken.

// Eisen:

//    Je mag in de functie geen nieuwe matrix aanmaken. - Je mag wel gebruik maken van een tijdelijke variabele.
//    De aanpak is vergelijkbaar met de functie van opdracht 2.12 Palindroom.
//    Je mag geen gebruik maken van de std::swap functie.

#include <vector>
#include <iostream>

using namespace std;

void transpose(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int tempMatrix = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tempMatrix;
        }
    }
}
