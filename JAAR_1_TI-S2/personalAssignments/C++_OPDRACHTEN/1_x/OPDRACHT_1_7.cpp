// AIMANE CHAKIRI 

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Geef een string om te vertalen naar 1337: ";
    string x;
    getline(cin, x);
    cout << x << "\n";

    string z;
    for (unsigned int i=0; i < x.size(); i++){
        if (x[i] == 'e'|| x[i] == 'E') {
            z += '3';
        } else if (x[i] == 'l'|| x[i] == 'L') {
            z += '1';
        } else if (x[i] == 't'|| x[i] == 'T') {
            z += '7';
        } else if (x[i] == 'o'|| x[i] == 'O') {
            z += '0';
        } else if (isupper(x[i])) {
            z += x[i];
        } else if (x[i] == '.') {
            z += x[i];
        } else if (x[i] == ' ') {
            z += x[i];
        } else {
            char newLetter = x[i] - 32;
            z += newLetter;
        }
    }
    cout << "1337 speak:\n" << z;
    return 0;
}