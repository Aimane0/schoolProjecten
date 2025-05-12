# Opdracht Sfinae
## Inleiding
De voorbeeld casus is dat we in onze code van een bepaald object willen controleren of het een bepaalde memberfunctie heeft.

Dat kan compiletime, met SFINAE. Er zijn ook eenvoudiger runtime alternatieven.

Bij deze opdracht ga je SFINAE vergelijken met 2 runtime alternatieven.

## A: Snelheidsmeting van Sfinae
Neem als uitgangspunt de code [sfinae.cpp](./sfinae.cpp).
Ga voor jezelf na hoe de code werkt.
Test de code even, en pas het als volgt aan:

- Commentarieer de couts uit in foo() en callFooIfExists() (we zijn nu immers niet geinteresseerd in de snelheid van couting)
- Meet hoe lang het duurt om de volgende combi 100000 keer aan te roepen:
```c++
callFooIfExists(a);
callFooIfExists(b);
```
-> **[Gemeten tijd 0.001118]**

## B: Snelheidsmeting van Sfinae alternatief 1
Doe hetzelfde voor [runtime_nosfinae](./runtime_nosfinae.cpp).

-> **[Gemeten tijd 0.0056191]**

## C: Snelheidsmeting van Sfinae alternatief 2
Doe hetzelfde voor [runtime_nosfinae_2](./runtime_nosfinae_2.cpp).

-> **[Gemeten tijd 0.0018893]**

## D: Vergelijking
Geef voor elk van de methoden aan wat het voordeel is ten opzichte van de andere methoden.

- -> **Voordeel van sfinae:** [Run time is sneller en je hebt flexibiliteit in je datatype vanwege template gebruik]
- -> **Voordeel van alternatief 1:** [?]
- -> **Voordeel van alternatief 2:** [De code is meer leesbaar]