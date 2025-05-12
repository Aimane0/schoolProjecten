// Opdracht 4.5 Compression

// Schrijf een compress-programma, dat uit een gegeven bestand een nieuwe bestand maakt, waarbij

//    van iedere regel alle spaties en tabs aan het begin van de regel zijn verwijderd.
//    Verder zijn alle lege regels verwijderd (een lege regel bevat \n , eventueel voorafgegaan door spaties en tabs(\t)).

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void compress(string src_filename, string dest_filename)
{
    string line; // Maken van nieuwe string die geschreven wordt in nieuw txt document
    ifstream myfile(src_filename); // openen van txt document met spaties en tabs
    ofstream outputFile(dest_filename); // openen van txt document met de nieuwe versie

    while (getline(myfile, line)) // while loop voor het schrijven
    {
        line.erase(remove(line.begin(), line.end(), '\t'), line.end()); // verwijderen van tabs
        line.erase(remove(line.begin(), line.end(), ' '), line.end()); // verwijderen van spaties

        if (!line.empty()) // als de regel niet leeg is schrijf naar outputfile
        {
            outputFile << line << "\n";
        }
    }

    outputFile << line; // schrijven van de string

    outputFile.close();
    myfile.close(); // sluiten van de documenten
}

int main()
{
    compress("opdracht.txt", "opdracht2.txt");
    return 0;
}