class vehicle {
  ...
};

class car : public vehicle {
  ...
};

class train : public vehicle {
  ...
};

class intercity : public train {
  ...
};

void travel(vehicle& v);
void ovchipkaart(train& t);
void file(car& c);
car batmobiel;
intercity utr_amst;
train ICE;

file(batmobiel);              // 1
ovchipkaart(utr_amst);        // 2
file(ICE)                     // 3
ovchipkaart(batmobiel)        // 4
travel(utr_amst)              // 5
travel(batmobiel)             // 6
intercity& ref7 = utr_amst;   // 7
car& ref8 = utr_amst;         // 8
train& ref9 = utr_amst;       // 9
train& ref10 = batmobiel;     // 10
intercity& ref11 = batmobiel; // 11
intercity& ref12 = ICE;       // 12

1: Geen fout melding:
Batmobiel is van de klasse car, en de functie file accepteert car, dit is te zien aan car&

2: Geen fout melding:
utr_amst is een intercity, de intercity wordt gemaakt door de klasse train
de functie ovchipkaart accepteert train door train& en omdat de intercity gemaakt wordt door de klasse train werkt utr_amst

3: Fout melding:
file accepteert alleen car, ICE is geen car maar een train ook is er geen associatie of dergelijke tussen ICE en car

4: Fout melding:
batmobiel is een car, niet een train wat nodig is voor de functie ovchipkaart

5: Geen fout melding:
Travel accepteert alle vehicles, intercity is een vehicle, omdat het een trein is en treinen zijn vehicles. 

6: Geen fout melding:
Batmobiel is een vehicle want cars zijn gemaakt door klasse vehicles, klasse vehicles worden geaccepteerd door de functie travel

7: Geen fout melding:
De referentie en utr_amst zijn allebei intercities, dus dit zou goed horen te komen

8: Fout melding:
utr_amst is een intercity, een intercity is geen car en heeft ook geen associatie met car

9: Geen fout melding:
Er is hier geen fout melding want utr_amst is van het type intercity, intercity is afgeleid van train dus het kan!

10: Fout melding:
batmobiel is een car, die is op geen enkele manier afgeleid van train

11: Fout melding:
batmobiel is een car, die is op geen enkele manier afgeleid van intercity

12: Fout melding:
Intercities zijn afgeleid van train, maar andersom niet! Daarom is hier een foutmelding!