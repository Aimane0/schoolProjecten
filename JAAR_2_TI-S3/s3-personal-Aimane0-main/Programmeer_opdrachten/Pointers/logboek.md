## POINTERS

    - Pointers verwijzen naar geheugen adres op de HEAP

    - Waarom zou je pointers gebruiken die de HEAP gebruikt? Is flexibeler! 

    - Nadeel pointers als het object verdwijnt uit de HEAP dan verwijst die nog steeds naar het zelfde memory adres

    - Een smartpointer houdt bij hoeveel smartpointers naar het zelfde object op de HEAP. Deze houdt een counter bij, als die op 0 raakt dan pas wordt de destruct van het HEAP object aangeroepen door de LAATSTE smartpointer die weet dat dan

