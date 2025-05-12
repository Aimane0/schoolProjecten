// AIMANE CHAKIRI 

// 2.3A
// De vector returned alle getallen kleiner dan 0 * -1 , dus om ze positief te maken

// 2.3B
// Deze functie geeft haar resultaat terug door het direct in de vector aan te passen
// Dat zie je aan het feit dat er geen const staat en geen &

// 2.3C
// De eerste returned het resultaat en kan gekoppeld worden aan een nieuwe variabel
// De tweede past het direct aan in de vector
// De derde returned het in een hele nieuwe variabel die aangemaakt wordt binnen de functie

// 2.3D
// De laatste versie, het returnen maakt het mogelijk om het resultaat te koppelen aan een variabel wanneer je de functie aanroept
// Ook vind ik het fijn dat er binnen de functie een nieuwe variabel wordt aangemaakt, zodat er geen conflict ontstaat met de al bestaande versie van numbers

#include <iostream>
#include <vector>
using namespace std;

vector<int> positive1(vector<int> numbers){
    for(unsigned int i=0; i<numbers.size(); i++){
        if(numbers[i] < 0){
            numbers[i] *= -1;
        }
    }
    return numbers;
}

void positive2(vector<int> & numbers){
    for(unsigned int i=0; i<numbers.size(); i++){
        if(numbers[i] < 0){
            numbers[i] *= -1;
        }
    }
}

vector<int> positive3(const vector<int> & numbers){
    vector<int> newNumbers = numbers;

    for(unsigned int i=0; i<newNumbers.size(); i++){
        if(newNumbers[i] < 0){
            newNumbers[i] *= -1;
        }
    }
    return newNumbers;
}