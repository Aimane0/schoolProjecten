// Opdracht 3.6 Gemiddelde 2

// Schrijf een functie die van een gegeven vector<vector<int>> het gemiddelde berekent van de gehele vector<vector<int>> en deze teruggeeft.
// Tip: maak gebruik van je code uit opdracht 3.5.

// TIP VAN GERA: Schrijf functies die niet crashen, zoals wanneer de MATRIX leeg is!
// Als er delingen zijn, probeer altijd te checken of er geen 0 zitten in delingen.

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vect = {
    {10, 10, 10},
    {20, 20, 20},
    {1, 1, 1}};

float averageNumbVect(vector<vector<int>> v)
{
    int totalAmountOfVectors = 0;               // Variabel aanmaken om totale aantal vectoren op te tellen, nodig om het gemiddelde te verkrijgen
    int totalAmountOfNumbs = 0;                 // Variabel om totale ints bij elkaar op te tellen
    for (unsigned int i = 0; i < v.size(); i++) // For loop om elke vect in de grote matrix te zien
    {
        totalAmountOfVectors += 1;                        // Optellen van aantal vectoren door dit per i aan totalAmountOfVectors toe te voegen.
        for (unsigned int j = 0; j < vect[i].size(); j++) // For loop om de individuele getallen per vect te zien
        {
            totalAmountOfNumbs += vect[i][j]; // Optellen van elk getal in de variabel
        }
    }

    float average = totalAmountOfNumbs / totalAmountOfVectors; // Rekenen met beide variabelen om het gemiddelde te returnen
    return average;
}

int main()
{
    int vects = averageNumbVect(vect);
    cout << vects;
}