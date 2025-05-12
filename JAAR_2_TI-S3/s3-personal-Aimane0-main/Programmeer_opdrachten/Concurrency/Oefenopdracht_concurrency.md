# Opdracht 1:
``Voor alle code scriptjes (die in dezelfde folder staan als dit .md bestand) uit, speel ermee. Ga voor jezelf na wanneer er wel of geen deadlocks optreden (geen vragen bij deze opdracht).``

- testDeadlock.cpp: Er is hier een deadlock, omdat mtx_teller1 en 2 kruislinks gecodeerd zijn. Dit is te zien op line 12, 13, 23 en 24. Hierdoor zijn beide tellers tegelijk bezet waardoor beiden threads constant op elkaar wachten. Want omdat ze allebei bezet zijn kan de ene thread niet de andere teller gebruiken.

- testMutex.cpp: Hier vindt geen deadlock plaats. Deze script toont hoe een mutex goed gebruikt hoort te worden.

- testRace.cpp: Omdat hier geen mutex gebruikt wordt kunnen de threads door elkaar heen gebruikt worden. Omdat ze door elkaar heen gebruikt worden klopt de volgorde van de teller niet en komt er een compleet ander getal uit.

- testThreads.cpp: Hier heb ik werkelijk geen idee, ik moet hier hulp voor vragen

---

# Opdracht 2

``Verbeter het ASCII-poppetje: tijdens het langdurige couten van de afbeeld-functie zijn de mutexen gelockt. De periode waarin de mutexen gelockt zijn kan veel korter. Upload de link naar je verbeterde code naar de canvas opdracht "Concurrency, Mutex".``

De opdracht is gemaakt in het volgende documentL: https://github.com/2024-TICT-TV2SE3-24/s3-personal-Aimane0/blob/main/Programmeer_opdrachten/Concurrency/testASCII_poppetje.cpp
