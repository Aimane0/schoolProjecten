// AIMANE CHAKIRI
// Opdracht 4.6 Verschuif Cyclisch

// Schrijf een functie met twee parameters. De eerste parameter, ch, is een uint8_t.
// De tweede parameter, n, geeft aan hoeveel posities de bitjes van ch opgeschoven moeten worden.
// Als n > 0 is dan worden de bitjes naar links geschoven. Als n < 0 is dan worden de bitjes naar rechts geschoven.
// De bitjes die wegvallen worden aan de andere kant van de byte weer teruggeplaatst.

// Voorbeeld 1
// ch met bitwaarde 10110001 en n is gelijk aan 3 resulteert in een ch met de bitwaarde: 10001101.
// 10110001
// 01100011
// 11000110
// 10001101

// Voorbeeld 2
// ch met bitwaarde 10111000 en n is gelijk aan -5 resulteert in een ch met de bitwaarde: 11000101.
// 10111000
// 01011100
// 00101110
// 00010111
// 10001011
// 11000101

#include <iostream>
#include <stdint.h>
#include <bitset>

using namespace std;

uint8_t shiftBit(uint8_t ch, int n)
{
    uint8_t newBit; // Nieuwe bit die gereturned wordt
    // uint8_t heeft altijd 8 bits, dus [7] is de laatste index!

    if (n > 0) // Checked of N groter is dan 0, dan worden de bits naar links geschoven.
    {
        newBit = (ch << n) | (ch >> (8 - n));
    }
    if (n < 0) // Checked of N kleiner is dan 0, dan worden de bits naar rechts geschoven.
    {
        n = -n;
        newBit = (ch >> n) | (ch << (8 - n));
    }

    return newBit;
}

int main()
{
    uint8_t ch1 = 0b10110001;
    int n1 = 3;
    cout << "Voorbeeld 1: " << bitset<8>(ch1) << " shift met " << n1 << " geeft als resultaat: " << bitset<8>(shiftBit(ch1, n1)) << endl;

    uint8_t ch2 = 0b10110001;
    int n2 = -4;
    cout << "Voorbeeld 2: " << bitset<8>(ch2) << " shift met " << n2 << " geeft als resultaat: " << bitset<8>(shiftBit(ch2, n2)) << endl;

    return 0;
}