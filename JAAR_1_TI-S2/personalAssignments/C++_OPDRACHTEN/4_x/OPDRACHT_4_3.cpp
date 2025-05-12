#include <iostream>
#include <string.h>

using namespace std;

struct furniture {
    int number = 0;
    string name = "";
    float weight = 0.0;
    float length = 0.0;
};

int main(void){
    cout << "Geef een nummer: ";
    int nummer;
    cin >> nummer;

    float gewicht;
    cout << "Geef een gewicht door in kilos: ";
    cin >> gewicht;

    cout << "Geef een lengte door in cm: ";
    float lengte;
    cin >> lengte;

    cout << "Geef de naam van het type meubel: ";
    string naam;
    cin >> naam;

    furniture meubel {nummer, naam, gewicht, lengte};

    cout << meubel.name << " heeft nummer " << meubel.number << ", weegt " <<
    meubel.weight << " kilo en is " << meubel.length << " cm." ;
}