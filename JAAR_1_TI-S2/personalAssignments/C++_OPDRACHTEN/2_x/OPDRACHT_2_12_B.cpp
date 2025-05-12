// CODE KAN KORTER! STAPPEN KUN JE REDUCEREN VOLGENS DE FEEDBACK VAN GERA!

#include <iostream>
#include <string.h>
using namespace std;

bool isPalindroom(const string &word)
{
    string palindroom = ""; // Je kunt de palindroom functie maken zonder het woord te herschrijven in een nieuwe string
                            // Je kunt het woord gelijk vergelijken in de for loop in plaats van eerst het woord te herschrijven en dan te vergelijken.
    for (int i = word.size() - 1; i >= 0; i--)
    {
        palindroom += word[i];
    }
    if (palindroom == word)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isPalindroom2(const string &word)
{
    int i = 0;
    int j = word.size() - 1; // Deze twee getallen bepalen de indexen die we willen vergelijken!

    while (i < j) // Een while loop die er voor zorgt dat tot in het midden van het woord de volgende if loop loopt.
    {             // De while loop kan stoppen in het midden van het woord, want als de eerste 3 en laatste 3 bijvoorbeeld de zelfde letters zijn dan hoeven de indexen niet elkaar te kruizen!
        if (word[i] != word[j])
        {
            return false;
        }
        i++; // Tijdens de while loop voegen we aan de index toe of halen we van de index af, want we willen letter voor letter langs gaan
        j--;
    }
    return true; // Als de while loop afgelopen is dan returnen we true, want als de while loop niet afloopt dan heeft het false gereturned!
}

int main()
{
    bool word1 = isPalindroom("lepel");
    bool word2 = isPalindroom("testen");

    bool word3 = isPalindroom2("lepel");
    bool word4 = isPalindroom2("testen");
    bool word5 = isPalindroom2("teeseeet");

    cout << word1 << "\n";
    cout << word2 << "\n";
    cout << word3 << "\n";
    cout << word4 << "\n";
    cout << word5 << "\n";
}