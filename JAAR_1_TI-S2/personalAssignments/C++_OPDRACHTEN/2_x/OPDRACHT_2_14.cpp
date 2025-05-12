#include <iostream>
// AIMANE CHAKIRI 

#include <vector>
#include <algorithm>
using namespace std;

string ifSorted(vector<int> v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {                        // Maken van een for loop om door de vector heen te kijken
        if (v[i] > v[i + 1]) // vergelijken van 2 elementen in de vector
        {                    // Wanneer de linker groter is dan de rechter is het niet gesorteerd
            return "De reeks is niet gesorteerd.";
        }
    }
    return "De reeks is gesorteerd.";
}

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

int minimumNumb(std::vector<int> v)
{
    auto minIter = std::min_element(v.begin(), v.end()); // Opslaan van de iteratie die zoekt naar min getal, moet auto gebruiken volgens chatGPT
    int minNumb = *minIter;                              // Van de opgeslagen iteratie een int maken die opgeslagen wordt
    return minNumb;
}

int amountNumbs(vector<int> v)
{
    int vectorSize = v.size(); // Vraagt om de grote van de vector.
    return vectorSize;
}

int main()
{
    while (true)
    {
        vector<int> vect{};            // aanmaken van vect
        int x;                         // aanmaken van variabel die
        cout << "Voer een getal in: "; // vraag naar getal
        while (cin >> x)               // while loop die gebeurt
        {
            vect.push_back(x); // Verwerkt variabel X in de vector
            if (0 > x)         // Checked of x kleiner is dan 0
            {
                vect.pop_back(); // Indien x kleiner is dan 0 en het laatste getal is in de vector wordt die verwijderd met pop_back
                break;           // Stopt de while loop wanneer een negatief getal gegeven wordt
            }
            cout << "Voer een getal in: "; // Herhaalt het voer een getal in bericht
        }
        for (unsigned int i = 0; i < vect.size(); i++)
        { // een for loop en cout om te checken of de vector goed ingevuld is!
            cout << vect[i] << "\n";
        }

        string sorted = ifSorted(vect); // gebruiken van functie om te checken of de vector gesorteerd is
        cout << sorted << "\n";

        int totalAmount = amountNumbs(vect); // gebruiken van functie om aan te geven hvl elementen in de vector staan
        cout << "De reeks bevat " << totalAmount << " getallen.\n";

        int minNumb = minimumNumb(vect); // gebruiken van functie om het laagste getal te vinden
        cout << "De minimum waarde is: " << minNumb << "\n";

        float average = averageNumb(vect); // Gebruiken van functie om het gemiddelde te tonen
        cout << "De gemiddelde waarde is: " << average << "\n";
        return 0;
    }
}