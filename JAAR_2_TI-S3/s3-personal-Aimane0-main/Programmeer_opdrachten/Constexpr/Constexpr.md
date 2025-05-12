# Oefenopdracht constexpr

## A. Eerste test
Opdracht:
- Test deze cpp code: [constexpr_sin.cpp](constexpr_sin.cpp)
- Vervang de functiebody van constexprSin tijdelijk door: return sin(x); en run opnieuw.
- Zet de functiebody met de Taylor-reeks implementatie terug. 

Vraag:
- Waarom gebruikten we een Taylor-reeks implementatie?
  - **-> [Hierdoor kunnen we constexpr gebruiken, dit zorgt er voor dat de berekeningen tijdens compile time gedaan kunnen worden. Dit maakt het programma sneller. Constexpr kan namelijk alleen gedaan worden voor simpele berekeningen.]**

## B. Nauwkeurigheidstest
Opdracht:
- Voeg code toe die de maximale fout weergeeft tussen sin(x) en sinDegrees(x) voor integer hoeken in het bereik van 0..259 graden.
```
De code staat in de CPP file als: 

double calculateMaxError() {
    double maxError = 0.0;
    for (int i = 0; i < 360; ++i) {
        double error = std::abs(std::sin(degreesToRadians(i)) - sinDegrees(i));
        maxError = std::max(maxError, error);
    }
    return maxError;
}
```

Vraag:
- Welke fout meet je? 
  - **-> [Die tussen sin(x) en sinDegrees(x) voor volgens mij elke graad tussen 0 en 360]**

Opdracht:
- Verklein die maximale fout eens met tenminste factor miljard. 
```
Geen idee hoe dit moet, vraag stellen
```

Vraag:
- Daarvoor hoefts slechts 1 getal aangepast te worden, welk getal en hoeveel?
  - **-> [-]**

## C. Snelheidstest
Opdracht:
- Voeg code toe die het snelheidsverschil laat zien tussen sin() en sinDegrees(x).
```
  auto startSinDegrees = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 1'000'000; ++i) {
      sinDegrees(i % 360);
  }
  auto endSinDegrees = std::chrono::high_resolution_clock::now();
  auto durationSinDegrees = std::chrono::duration_cast<std::chrono::microseconds>(endSinDegrees - startSinDegrees).count();
  std::cout << "Tijd voor sinDegrees(): " << durationSinDegrees << " microseconden\n";

  auto startStdSin = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 1'000'000; ++i) {
      std::sin(degreesToRadians(i % 360));
  }
  auto endStdSin = std::chrono::high_resolution_clock::now();
  auto durationStdSin = std::chrono::duration_cast<std::chrono::microseconds>(endStdSin - startStdSin).count();
  std::cout << "Tijd voor std::sin(): " << durationStdSin << " microseconden\n";

  if (durationSinDegrees < durationStdSin) {
      std::cout << "sinDegrees() is sneller dan std::sin()\n";
  } else {
      std::cout << "std::sin() is sneller dan sinDegrees()\n";
  }
```

Vragen:
- Verklaar het snelheidsverschil.
  - **-> [sinDegrees is sneller, omdat de waarden al vooraf tijdens compile time worden berekend en opgeslagen worden in een tabel. sin(x) moet elke keer alles opnieuw complex berekenen.]**

- Verlaagt de eerder genoemde extra nauwkeurigheid de gemeten snelheid?
  - **-> [Ja het kan het verlagen, omdat de extra nauwkeurigheid meer complexe berekeningen toevoegd!]**
- Waarom wel/niet?

## D. Cosdegrees
- Voeg ook een functie cosDegrees(x) toe, op dezelfde leest geschoeid.
- Voeg die ook toe aan de tests.
- Voeg onderstaand een link toe naar je resulterende cpp code:
  - **-> [https://github.com/2024-TICT-TV2SE3-24/s3-personal-Aimane0/blob/main/Programmeer_opdrachten/Constexpr/constexpr_sin.cpp]**

## E. const
Je zou het ook kunnen oplossen zonder constexpr, door direct na start van het programma de tabellen uit te rekenen. Je kunt dan zelfs sin() en cos() gebruiken voor het invullen van de tabellen. Dus eenvoudiger code. Vervolgens heb je met sinDegrees en cosDegrees weer vergelijkbare performance. 

Vraag:
- Is het altijd het best om constexpr te gebruiken? Licht je antwoord toe. 
- **-> [Nee, want je kunt constexpr niet letterlijk altijd gebruiken zoals wanneer sommige waardes pas tijdens runtime bekend zijn of waardes die tijdens runtime veranderen!]**
