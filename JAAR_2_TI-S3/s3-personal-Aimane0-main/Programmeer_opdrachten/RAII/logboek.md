## Logboek over RAII

Ik vond de reader op; https://www.geeksforgeeks.org/resource-acquisition-is-initialization/?ref=gcse_ind een beetje onduidelijk dus heb ik een YouTube video er bij genomen die ik duidelijker vond; https://www.youtube.com/watch?v=q6dVKMgeEkk&t=500s&ab_channel=pencilflip

Dit zijn aantekeningen die ik heb gemaakt om mij te helpen bij het begrijpen van RAII

- Wat is RAII? ;  Resourceverwerving is initialisatie
Dit betekent dat het object zijn resources zal verwerven bij initialisatie en deze vrijgeeft bij vernietiging. 

## Wat voor problemen kun je oplossen door RAII te gebruiken volgens de video?

- Handmatig vrijgeven van geheugen is foutgevoelig!

- Deadlocks die kunnen ontstaan door mutexen, je moet overal handigmatig locken en unlocken wat kan leiden tot fouten in je code, omdat je het handmatig doet! Wat nou als je ergens een unlock vergeet?!

- Oppassen met threads die out of scope raken

