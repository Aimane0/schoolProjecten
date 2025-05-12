#include "winners.hpp"

float nearestScore2Average(const vector<float> &scores)
{
    float total_score = 0.0;                // Aanmaken van een variabel waarin we de totale score optellen
    float amount_of_scores = scores.size(); // Aanmaken van variabel met hoeveel scores er in de vector staan

    for (unsigned int i = 0; i < scores.size(); i++) // For loop om alle scores in de vector op te tellen
    {
        total_score += scores[i]; // Optellen van alle scores zodat we de totale score hebben
    }
    float average_score = total_score / amount_of_scores; // Uitrekenen van gemiddelde scoren met de eerder verkregen
                                                          // totale score en aantal scores in de vector

    float tempDifference = abs(scores[0] - average_score); // Aanmaken van een variabel vanaf waar we beginnen met tellen
    float winner = scores[0];                              // Aanmaken van de winnaar variabel waarvan we beginnen met tellen
                                                           // Deze beginnen allebei vanaf index 0, zodat we met een for loop de floats kunnen aanpassen indien het verschil volgens de for loop kleiner blijkt te zijn
    for (unsigned int i = 0; i < scores.size(); i++)       // De for loop om alle vector scores te checken
    {
        float scoreDifference = abs(scores[i] - average_score); // Checken van het verschil tussen de score en de gemiddelde score, abs wordt gebruikt om altijd een ABSOLUUT getal te verkrijgen.
                                                                // Dit heb ik gedaan omdat er soms min getallen voor kwamen, -40 geeft een verschil van 40 aan maar wordt door C++ natuurlijk als kleiner gezien dan
                                                                // bijvoorbeeld 1 want 1 is inderdaad groter dan -40, na google gebruikt te hebben kwam ik op de functie abs terecht!
        if (scoreDifference < tempDifference)                   // In het geval dat de gemiddelde score van de loop groter is dan de placeholder of nieuwe score gaan we in een if statement wat uitvoeren
        {
            tempDifference = scoreDifference; // De tempDifference die begon met [0] of nu het verschil tussen een score en gemiddelde van een andere index toont wordt veranderd met de nieuwe, want
                                              // we hebben volgens de if statement een nog kleiner verschil gevonden!
            winner = scores[i];               // Het getal dat nu met de for loop gechecked wordt zit dichterbij het gemiddelde en wordt nu gekoppeld aan het variabel winner
        }
    }
    return winner;
}

float furthestScoreFromWinner(const vector<float> &scores)
{
    float total_score = 0.0;                // Aanmaken van een variabel waarin we de totale score optellen
    float amount_of_scores = scores.size(); // Aanmaken van variabel met hoeveel scores er in de vector staan

    for (unsigned int i = 0; i < scores.size(); i++) // For loop om alle scores in de vector op te tellen
    {
        {
            total_score += scores[i]; // Optellen van alle scores zodat we de totale score hebben
        }
    }
    float average_score = total_score / amount_of_scores; // Uitrekenen van gemiddelde scoren met de eerder verkregen
                                                          // totale score en aantal scores in de vector

    float winner = nearestScore2Average(scores);     // We kunnen met de vorige functie bepalen wie de winnaar is, dit is nodig om uiteindelijk het getal te vinden met het grootste verschil ten opzichte van de winnaar
    float tempDifference = abs(scores[0] - winner);  // Net als de vorige functie moeten we een start punt hebben waarmee we elke index kunnen vergelijken en indien nodig deze te veranderen met een groter getal
    float mol = scores[0];                           // Zelfde logica als vorige functie, we beginnen bij index 0, maar de mol veranderd natuurlijk als we een getal vinden met een GROTERE afstand ten opzichte van de winnaar!
    for (unsigned int i = 0; i < scores.size(); i++) // For loop om weer alle getallen in de vector te vergelijken met de tempDifference en mol!
    {
        float scoreDiffrence = abs(scores[i] - winner);

        if (scoreDiffrence > tempDifference)         // HIER ZIT DE ZELFDE LOGICA ACHTER ALS DE VORIGE FUNCTIE!
        {
            tempDifference = scoreDiffrence;
            mol = scores[i];
        }
    }
    return mol;
}