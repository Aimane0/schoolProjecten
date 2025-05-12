// OPDRACHGT 1.3C en D
// AIMANE CHAKIRI 
// x = 8.2 // Het antwoord is 8 want er staat INT voor, dus 8.2 wordt een INT
// y = 3
// z = 3.6 // Zelfde fout hier, het antwoord is 3 want er staat INT voor 
// f = 0 // Fout, blijkbaar is 1 haakje een char, en chars kun je tellen en aftrekken
// e = 1

// t = 3
// s = 3.6

// a = a
// b = e
// d = e
// c = 0 // Het antwoord is b want er wordt met ASCII gerekend
// Z - z is -32, want Z == 90 en z = 122, vervolgens tel je daar 98 bij op
// dan kom je op 66 want in ASCII gelijk staat aan B

// r = 0 // UITLEG VRAGEN AAN DOCENTEN
// u = 0

// string p = Utereg Me Stadsie!
// string station = Heidel // Je kunt ook strings aan elkaar plakken zonder ze als string aan te geven
// string plaats = ??????????????? // UITLEG VRAGEN DOCENT
                    // Besproken met Gera, begrijp nu hoe de erase functie werkt
                    // Je geeft een begin en eind index aan van wat je verwijderd wilt hebben

#include <string>
#include <iostream>
using namespace std;

int main(){

    int x = 8.2;
    int y = 18 / 5;
    int z = 18 / 5.0; 
    int f = '8' - '0';
    int e = 10 % 3;
    
    float t = 18 / 5;
    float s = 18 / 5.0;

    char a = 'a';
    char b = 'e';
    char d = b;
    char c = 'b' + ('Z'- 'z');

    bool r = true && (false || true);
    bool u = 8 >= 10;

    string p = "Utereg";
    p.append(" Me Stadsie!");
    string station = string("Heidel") + "berglaan";
    string plaats = station.erase(10, station.size()-10);

    cout << x << "\n" << y << "\n" << z << "\n" << f << "\n" << e << "\n" << t << "\n" << s << "\n" << a << "\n" << b << "\n" << d << "\n" << c << "\n" << r << "\n" 
    << u << "\n" << p << "\n" << station << "\n" << plaats;
}

