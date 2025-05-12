// Opdracht 3.3 Print doolhof

// Een doolhof is gepresenteerd als een matrix (een vector van integer vectoren), waarbij

//    0 een veilige plek aangeeft,
//    1 het einddoel aangeeft en
//    -1 muren en boze eekhoorns aangeeft.

// Schrijf een functie die de matrix met de waarden 1, 0 en -1 afdrukt. Waarbij de -1 wordt afgedrukt als een ’x’.

// Voorbeeld van een matrix mat:

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mat = {
     {-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1},
     {-1, 0,-1, 0, 0, 0,-1,-1, 0,-1,-1},
     {-1, 0,-1, 0,-1,-1,-1, 0, 0, 1,-1},
     {-1, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1},
     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} }; // Aanmaken van de matrix

string turnMinusOneIntoX(vector<vector<int>> vect) // functie maken voor een matrix
{
    string newMaze; // Willen de nieuwe dolholf returnen als een string
    for(unsigned int i=0; i < vect.size(); i++) // For loop om de vects in de vector te zien
    {
        for(unsigned int j=0; j < vect[i].size(); j++) // For loop om de individuele getallen per vect te zien
        {
            if(vect[i][j] != -1) // In het geval dat wij iets anders dan -1 tegen komen willen we het getal direct opschrijven
            {
                newMaze += to_string(vect[i][j]);
            }
            else // als we een -1 tegen komen willen we deze apart nemen, deze zit aan de buitenkant van de dolhof als muur
            {                     // Dus we willen mogelijk linebreaks toevoegen na een -1
                if (vect[i][j] % 11 == 0)  // De -1's aan de buitenkant staan op index 11, 22, 33, 44 en 55 dus we gebruiken modulo om te zien of we die hebben bereikt
                {
                    newMaze += "X"; // Indien we index 11 of tafel van 11 bereiken willen we de X toevoegen en een linebreak
                } else {
                    newMaze += "X"; // Indien we niet te maken hebben met een tafel van 11 index kan de -1 als X toegevoegd worden aan de string
                }
            }
        }
        newMaze += "\n"; // Voegt een linebreak toe na elke vect
    }
    return newMaze;
}

int main()
{
    string nieuwDolhof = turnMinusOneIntoX(mat);
    cout << nieuwDolhof;
}