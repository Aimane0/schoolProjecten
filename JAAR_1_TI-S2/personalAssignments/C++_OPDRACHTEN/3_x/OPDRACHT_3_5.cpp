// Opdracht 3.5 Gemiddelde 1

// Schrijf een functie die van een gegeven vector<int> het gemiddelde berekent en teruggeeft.

#include <iostream>
#include <vector>

using namespace std;

float averageNumb(vector<int> v)
{
    float vectorSize = v.size(); // Vraagt om de grote van de vector, nodig om het gemiddelde te berekenen
    float totalNumb;             // Maak een variabel aan om total getal te verkrijgen
    for (unsigned int i = 0; i < v.size(); i++)
    {
        totalNumb += v[i]; // For loop om alle indexen van de vector bij elkaar op te tellen
    }                      // Zo hebben we een maximaal getal wat gedeeld kan worden door de size van de vector
    float average = totalNumb / vectorSize;
    return average; // Return het antwoord!
}

vector<int> vect = {2, 7, 9, 14, 22, 32, 44};

int main()
{
    float answer = averageNumb(vect);
    cout << "The average number = " << answer;
}