// AIMANE CHAKIRI 

// Het begint bij 65
// Dan wordt het nummer 70
// Als het nummer == 70 dan komt de else if statement
// Het nummer wordt 2x plus zichzelf gedaan
// Eindigd op 90?

// Ik heb het helemaal fout en moet dit misschien
// klassikaal bespreken met een docent

#include <iostream>
using namespace std;

int main(){
    int number = 65;
    cout << number << "\n";
    while( number < 90){
        cout << number << "\n";
        if(number < 70){
            cout << number << "\n";
            number = 70;
            cout << number << "\n";
        }else if( number < 80){
            cout << number << "\n";
            number++;
            cout << number << "\n";
        }
        number += 3;
        cout << number << "\n";
    }

}