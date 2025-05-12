// Opdracht 1.3 A en B, data-types

/////////// 1.3A 
// x = 8
// y = 3
// e = 3.429
// f = 3.6 // FOUT; Er komt geen float terug, omdat de som gedaan is zonder floats

// a = 'a'
// b = 'e'
// c = error?  // FOUT; blijkbaar neem C de char over van de vorige variabel

// r = true // True == 1
// u = 1 ? // De uitkomst is False, dus 1, want een bool is altijd True of False

// p = "Klaar?"
// s = "Nee, nog niet"

// AIMANE CHAKIRI 

/////////// 1.3B
#include <string>
#include <iostream>
using namespace std;

int main(){

    int x = 8.2;
    int y = 18 / 5;
    
    float e = 3.429;
    float f = 18 / 5;

    char a = 'a';
    char b = 'e';
    char c = b;

    bool r = true;
    bool u = (1 & 0);

    string p = "Klaar?";
    string s = string("Nee, nog") + string(" niet");

    cout << x << '\n' << y << "\n" << e << "\n"
    << f << "\n" << a << "\n" << b << "\n"
    << c << "\n" << r << "\n" << u << "\n"
    << p << "\n" << s;

}