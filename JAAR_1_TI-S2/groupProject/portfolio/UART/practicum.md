# Practicum Uart gemaakt door Aimane Lia en Lisa!

## Voorbereiding

- Neem een arduino mee.
- Neem een geinstalleerde raspberry pi mee.
- Neem je electronica spullen (breadboard, weerstanden etc) mee.
- Neem je logic analyser mee (als je die al hebt)
- Lees alvast de lesstof door: [uart](./README.md)
- Kijk de volgende video [Salae Logic Analyser Tutorial](https://www.youtube.com/watch?v=rR5cEFRO9_s)
- Een indruk voor de plaats van deze opdracht in het geheel vind je [in dit overzicht](./img/overzicht1.png) en [in dit overzicht](./img/overzicht2.png).

## Opdracht 1
Laat je arduino via uart (rx,tx) communiceren met de arduino van je buurman.    
- ![Foto van de serial monitor die afleest van de andere Arduino](https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/portfolio/UART/UART_1.png)

### Vraag a
Noteer je bevindingen / persoonlijke lessen.\
*We hebben geleerd dat we niet pin 1 en 0 moeten gebruiken waar TX en RX staat op de arduino. We moeten andere pins zoals 10 en 11 gebruiken zoals in de code!\
Nadat we arduinos aangesloten waren en daadwerkelijk functioneerde kreeg de ontvangende Arduino 12345 binnen.\
Vervolgens hebben we de print statement aangepast om te zien of dit ter plekken, live, te veranderen was.\
Dat is het geval, dat is te zien aan het feit dat de monitor 66666 ontving, nadat de verzendende arduino de nieuwe print statement heeft geupload.*

### Vraag b
Voeg een foto toe van een screenshot van de logic analyser met daarop een gecommuniceerde byte. Leg uit hoe uit de bits volgt dat de waarde van de gecommuniceerde byte het getal is dat de logic analyser erbij weergeeft.\
[Foto van onze opstelling met de logic analyser](https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/tree/main/portfolio/UART)

Foto van de bytes!
![Foto van wat gecommuniceerde bytes](https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/portfolio/UART/UART_3.png)
*Hoge punten geven een 1 aan en lage punten geven een 0 aan, als wij dit optellen komen wij op getallen zoals 49, 50, 51, want dit is ascii als wij dit dan van ascii naar normaal omrekenen komen wij uit op 12345*\
*Ook hebben we geleerd dat je de logic analyser het beste kunt gebruiken door het te laten 'af te tappen'. Je connect de RX en TX van beide arduinos via het breadboard, op die manier kun je gemakkelijk de logic analyser met draadjes tussen de connectie laten aftappen!*

## Opdracht 2
Laat je arduino via seriele verbinding (rx,tx pinnen) communiceren met je raspberri-pi.   
### Vraag a
Noteer je bevindingen / persoonlijke lessen.\
*Het werkte niet met de RX en TX GPIO pins, wel hebben we met de USB port de Pi en arduino kunnen verbinden met elkaar!\
Het werkt in principe het zelfde, het enige verschil is dat je in de command line van de raspberry pi naar de juiste map moet cd'en en daar je py document moet aanmaken omdat de Pi het zelfde functioneert als een computer*\
*Ook hebben we een foto van het geslaagde proces*\
![Raspberry Pi en Arduino UART](https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/portfolio/UART/UART_4.png)


## Bonus Opdracht 1
Communiceer vanuit een python of c++ programma op je windows laptop via uart met je raspberri pi ([gebruik python op VSCode](../../../software/python/python-op-vscode.md)).
Leen daarvoor een USB to serial converter.
Check even welk type je gebruikt. Als het gebruik maakt van een CP210x chip, kun je hier de driver downloaden:  [driver voor CP210x](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads))   
<img src="./img/bonus-opdracht.png" width="350px" />

### Vraag a
Welke code heb je gebruikt op de pc kant?
### Vraag b
Noteer je bevindingen / persoonlijke lessen.

## Bonus Opdracht 2
Zelfde als de vorige Bonus Opdracht, maar nu twee laptops die (zonder arduinos) via USB-naar-Serial converters met elkaar communiceren.
