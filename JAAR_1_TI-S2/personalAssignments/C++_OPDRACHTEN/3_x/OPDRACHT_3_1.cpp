// AIMANE


// In onderstaande code heeft de variabele b steeds een andere byte-waarde. Schrijf elke keer dat de waarde van b verandert zijn nieuwe byte-waarde op.
#include <iostream>
#include <stdint.h>
#include <bitset>
using namespace std;

int main(){
    uint8_t mask = 0x6b;
    cout << "uint8_t mask = 0x6b; =" << bitset<8>(mask) << "\n";
    uint8_t b = 15;
    cout << "uint8_t b = 15;" << bitset<8>(b) << "\n";
    b = b | (1 << 6);
    cout << "b = b | (1 << 6); = " << bitset<8>(b) << "\n";
    b = ~b;
    cout << "b = ~b; =" << bitset<8>(b) << "\n";
    b = b << 1;
    cout << "b = b << 1; = " << bitset<8>(b) << "\n";
    b |= 7;
    cout << "b |= 7; = " << bitset<8>(b) << "\n";
    b &= ~(1 << 1);
    cout << "b &= ~(1 << 1); = " << bitset<8>(b) << "\n";
    b ^= mask;
    cout << " b ^= mask; = " << bitset<8>(b) << "\n";
}

// unit8_t mask = 0x6b = 01101011 , dit was te lezen in de theorie

// uint8_t b = 15 = 00001111 , want 00010000 is 16, dus 15 is 00001111


// Bij | (1 << 6) 01001111 is het antwoord. Eerst kijken we naar 1 << 6 , die geeft 01000000, vervolgens kijken we naar de or operator de | 
// De | voegt beide aan elkaar, eerst b van rechts naar links en dan 1 << 6 van waar b is gestopt naar het einde van 1 << 6
// Het schrijft dus eerst van rechts naar links 1111 en dan 0100 waardoor je op 01001111 komt


// Vervolgens doet ~b een inversie, alle 0'en worden een 1, alle 1'en worden een 0
// Het verandert hier dus in 10110000


// Ne moeten we vanwege b << 1 naar links shiften
// dus 10110000 wordt 01100000


// Hier moeten we b en 7 in bits combineren eerst rekenen we wat 7 in bits is namelijk 00000111
// en we hebben 01100000 dus we hebben 01100000 | 00000111 en dit wordt samen 01100111


// omg b &= ~(1 << 1); 
// We beginnen bij de & operator en de 1 << 1, de 1 << 1 geeft ons 00000010
// Vervolgens moeten we die inversen waardoor het 11111101
// Dan vergelijken we b en 11111101 vanwege de & operator
// de b is 01100111
//de ander 11111101
//         --------
//         01100101


// Vervolgens moeten we 01100101 en mask 01101011 XOR'en
// 01100101
// 01101011
// --------
// 00001110

// Na het COUT printen om het te vergelijken met de antwoorden die ik heb gegeven blijkt het allemaal te kloppen! :)
