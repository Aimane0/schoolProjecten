**Jullie namen: Aimane Chakiri, Lisa Beetz, Lia Engelchor

# Voorbereiding

Zorg voordat je aan de practica begint, dat je:

1. de bijbehorende theorie (reader en sheets) goed hebt doorgenomen

2. de benodigde materialen en gereedschappen voor alle opdrachten
   gereed hebt

## Benodigdheden

Voor deze practica heb je (als team) nodig:

- Een breadboard

- Een multimeter

- Twee 1k weerstanden (1k is een verkorte schrijfwijze voor 1k Ω,
  ofwel 1000 ohm)

- Wat geisoleerd, stug draad (geschikt om in breadboard te prikken)

- Wat breadboard wires

- Een striptang

- Een spanningsbron van rond de 5V.  
  Mogelijkheden: een adapter van 5V, een USB-adapter, een
  arduino-nano, een 4,5V batterij.

Als je van een van deze dingen niet weet wat het is, google er dan even
op.

# Wat wordt er van je verwacht?

- Voor de opdrachten uit samen met een andere student.

- Het is niet erg als je in overleg met andere teams een antwoord
  uitvogelt.  
  Zorg er wel voor dat je het 100% begrijpt, anders schiet je jezelf
  in je voet: op het tentamen zal worden verondersteld dat je de
  practicum opgaven gemaakt hebt en 100% begrijpt.

- Maak een copie van dit word-document, en voeg daarin je antwoorden
  toe. Als je iets moet invullen, wordt dat aangekondigd met
  **vetgedrukte** letters.

- Vermeld bij het inleveren helemaal bovenaan zowel je eigen naam als
  die van je teamgenoot.

# Breadboard

## Benodigd

- Een breadboard

- Een multimeter

## Opdracht
1.	Neem een breadboard.\
    - Die hebben wij alle drie
      
2.	Zet de multimeter in “contact detectie” stand.
Vaak wordt die stand weergegeven als een .))) symbool, omdat er een pieptoon ontstaat als de meetpennen van de multimeter contact maken.\
Gedaan, alle drie onze multimeter werkt
    - Alle drie onze multimeters gingen af, dat betekent dus dat onze multimeters werken
  	
4.	Maak met behulp van de multimeter in “contact detectie” stand een tekening die weergeeft hoe de connectors van het breadboard met elkaar verbonden zijn.
Zet die tekening (of evt een foto ervan) hieronder:
    - ![breadboard_tekening](https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/assets/144332649/a42bfa6f-a113-48cf-982a-ea795107b8f8)
      De gele lijnen lopen al goed, de rode en blauwe lijnen zijn toegevoegd als extra connectie die gevonden is.

# De wet van Ohm, Spanning, Stroom, Vermogen

## Benodigd

- Een breadboard

- Een multimeter

- Een 1k weerstand

- Breadboard wires of draad+striptang

## Opdracht

### Spanning

1. Sluit een 5V spanningsbron aan op de (horizontale-) voedingslijnen
   van je breadboard.\
   Het is aangesloten

2. Zet de multimeter in de modus “DC spanning meten”.

3. Controleer de gelijkspanning die tussen je voedingslijnen staat met
   de multimeter in “dc spanning meet modus” (aangegeven met DCV of
   V=)  
   **Welke spanning meet je (in 3 decimalen nauwkeurig)?**\
   We meten 5.09 V

### Weerstand

1. **Leg uit hoe je de 1k weerstand herkent (google evt op
   kleurcodes).**\
   Hij is bruin zwart zwart bruin bruin dus 100 * 10 = 1000

2. Controleer de weerstand met de multimeter in “weerstand meet modus”
   (aangegeven met Ω).  
   **Welke weerstand meet je (in 3 decimalen nauwkeurig)?**
   We kregen afwisselend 966 en 965 ohm te zien

### Stroom

1. Zet de multimeter in “stroom meet modus” (aangegeven met DCA of mA)

2. Bekijk de onderstaande schakeling met de weerstand, voedingsspanning
   en multimeter:  
   
   <img title="" src="./media/media/image2.png" alt="" width="576">

3. **Geef een berekening van de stroomgrootte die de multimeter naar
   verwachting in die situatie weergeeft. Welke wet heb je daarbij
   gebruikt?**\
   Wet van ohm: I = U/R\
   I = 5V/1000ohm = 0.005A = 5mA 
   
   Bouw en test de schakeling.  
   Houdt rekening met de richtlijnen voor het bouwen en testen van
   schakelingen (zie de bijlages “testen van een schakeling” en
   “bedraden van een schakeling” in de reader).  
   **Welke stroom geeft de multimeter aan (in 3 decimalen
   nauwkeurig)?**\
   5.04mA

### Lading

1. **Hoeveel lading (in Coulomb) aan electronen stroomt er per seconden
   door de weerstand?**\
   0.005C , want coulomb staat gelijk aan ampere per seconde.

2. **Hoeveel lading (in Coulomb) aan electronen stroomt er gedurende 1
   uur in totaal door de weerstand?**\
   3600s * 0.005C = 18C

3. **Hoeveel is die lading, als je het uitdrukt in mAh (milli ampere
   uur) in plaats van Coulomb?**\
   18 * 1000 = 18000mAh

4. **Hoe groot is knooppuntsspanning V1? (tip: een knooppuntsspanning
   is de spanning tussen dat knooppunt en de ground
   (**<img src="./media/media/image3.png"/>)\
   5V (hetzelfde als de batterij)

5. **Hoe groot is knooppuntsspanning V2?**\
    Iets minder dan 5V, aangezien de amperemeter een insignificante weerstand heeft waar een beetje volt
   over heen gaat.
    
6. **Hoeveel spanning staat er over de weerstand (tip: leen even een
   extra multimeter om dat te meten)?**\
   4.90V wanneer we 2 multimeters gebruiken.

7. **Hoeveel spanning staat er over de stroom metende multimeter (tip:
   leen even een extra multimeter om dat te meten)?**\
   5.06mA , dus nog steeds het zelfde

8. **Bereken hoe groot de weerstand van de (nog als stroommeter
   geschakelde-) multimeter is.**\
   R = U/I\
   0.16 / 0.00506 = 31.6205 .. ohm

### Vermogen en energie

1. **Hoeveel electrisch vermogen (in Watt) wordt er gedissipeerd in de
   weerstand (laat de berekening zien. Gebruik de gemeten stroom en
   spanning)?**\
   P = U x I
   4.90 * 0.00506 = 0.0247 Watt = 24.7 mWatt
   
2. **Geef een afleiding van de formule die het in de weerstand
   gedisspeerde vermogen uitdrukt in alleen de spanning en de weerstand
   (tip: substitueer de stroom in bovenstaande formule met de stroom
   die volgt uit de wet van Ohm).**\

   P = U * I\
   R = U/I (Wet van Ohm)\
   I = U/R\
   P = U * U/R\
   P = U²/R

3. **Controleer de formule door hem in te vullen.**\
   4.90² V / 1000 Ohm = 0.02401 Watt = 24.01 mWatt
   
4. **Geef een afleiding van de formule die het in de weerstand
   gedisspeerde vermogen uitdrukt in alleen de stroom en de weerstand
   (tip: als voorgaande, maar substitueer nu de spanning (in plaats van
   de stroom) die volgt uit de wet van Ohm).**\
   P = U * I\
   R = U / I\
   U = I * R\
   P = I * R * I\
   P = I² * R 

5. **Controleer de formule door hem in te vullen.**\
   0.00506² * 1000 = 0.0256 Watt = 25.6 mWatt

6. **Als de spanning over een weerstand verdubbelt, hoeveel neemt het
   in de weerstand gedissipeerde vermogen dan toe? Beargumenteer waarom**\
   Er heerst een kwadratisch verband, dus het wordt 4x zo groot.

7. **Als de stroom door een weerstand verdubbelt, hoeveel neemt het in
   de weerstand gedissipeerde vermogen dan toe?**\
   Er heerst een kwadratisch verband, dus het wordt 4x zo groot.

8. **Hoeveel electrische energie (in Joules) wordt er in de weerstand
   gedurende 10 seconden in totaal omgezet naar warmte-energie?**\
   E = P * t\
   0.02401 Watt * 10 seconde = 0.2401 Joules

9. **Als je de weerstand zou vervangen door een weerstand van 10 Ω, wat
   zou dan het in de weerstand gedissipeerde vermogen zijn?**\
   P = I² * R\
   0.00506² * 10 = 0.000256 Watt = 0.0256 mWatt

10. **Hoeveel vermogensdissipatie kan een “normaal, qua afmetingen klein
    weerstandje”, zoals je 1k weerstand aan (in plaats van 1kΩ wordt
    vaak kortweg 1k geschreven)?**\
    P_max = U² / R 
    4.90² V / 1000 Ohm = 0.02401 Watt = 24.01 mWatt

11. Stel dat je over een 3,7V LiPo (Lithium Polymer) batterij beschikt
    met een (ladings-) capaciteit van 100mAh.  
    **Hoeveel energie (in Joules) bevat de volledig opgeladen
    batterij?**\
    E = U * Q\
    Q = 100 mAh = 100 * 3600 =  360 C\
    3,7 * 360 = 1332 J

12. Stel dat je een 1k weerstand tussen de plus en min van de batterij
    zet. 
    **Hoeveel uur duurt het dan voordat de batterij leeg is?**\
    I = U/R = 3.7V/1000ohm = 0.0037A
    Capaciteit = 100mAh = 0.1Ah
    t = 0.1Ah / 0.0037A = 27uur
