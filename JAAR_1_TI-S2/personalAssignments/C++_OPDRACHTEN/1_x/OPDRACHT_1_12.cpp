// AIMANE CHAKIRI 

#include <iostream>
using namespace std;

int main(){
    int x;
    cout << "Geef een getal: ";
    cin >> x;
    
    cout << "Het gekozen getal is: " << x << "\n";

    for (int i = 1; i <= x; ++i){
        string z;
        for (int j = 0; j < i; ++j){
            z += "*";    
        }
        cout << z << "\n";
    }

    for (int i = x - 1; i >= 1; --i){
        string z;
        for (int j = 0; j < i; ++j){
            z += "*";    
        }
        cout << z << "\n";    
    }
}