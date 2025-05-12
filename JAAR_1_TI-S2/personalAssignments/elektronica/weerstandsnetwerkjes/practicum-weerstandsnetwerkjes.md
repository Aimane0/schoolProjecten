# Weerstandsnetwerkjes

Jullie namen: Aimane Chakiri, Lisa Beetz, Lia Engelchor

# Voorbereiding

Zorg voordat je aan de practica begint, dat je:

1. de bijbehorende theorie (reader en sheets) goed hebt doorgenomen

2. de benodigde materialen en gereedschappen voor alle opdrachten
   gereed hebt

## Benodigdheden

Voor deze practica heb je (als team) nodig:

- Een breadboard

- Een multimeter

- Een 10 Ω weerstand

- Twee 1k weerstanden (1k is een verkorte schrijfwijze voor 1k Ω,
  ofwel 1000 ohm)

- Een 2,2k weerstand

- Een 10k potmeter

- Wat geisoleerd, stug draad (geschikt om in breadboard te prikken)

- Wat breadboard wires

- Een striptang

- Een spanningsbron van rond de 5V.  
  Mogelijkheden: een adapter van 5V, een USB-adapter, een
  arduino-nano, een 4,5V batterij.

Als je van een van deze dingen niet weet wat het is, google er dan even
op.

# Wat wordt er van je verwacht?

- Voer de opdrachten uit samen met een andere student.

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

# Serieweerstand en Spanningsdeler

## Benodigd

- Een breadboard

- Een multimeter

- Een 1k weerstand

- Een 2,2k weerstand

- Breadboard wires of draad+striptang

## Opdracht

1. Zet op je breadboard een weerstand van 1k in serie met een weerstand
   van 2,2k:  
   
   <img title="" src="./media/media/image4.png" alt="" width="532">

2. **Geef de berekening van de de vervangingsweerstand van deze
   aaneenschakeling van weerstanden (ook wel “serieweerstand” genaamd).
   Tip: Gebruik de spanningswet van Kirchoff (Vtotaal = VR1+VR2) en de
   wet van ohm.**\
   Het antwoord is 3.2K, want in serie tel je de weerstanden bij elkaar op. 2.2k + 1k = 3.2K

3. Controleer het nu via een meting: zet de multimeter in “weerstand
   meet modus” en meet de serieweerstand.  
   **Welke weerstand meet je?**\
   **De meeting geeft ons 3.11k, omgerekend 3110**

4. Bouw de volgende schakeling:  
   
   <img title="" src="./media/media/image5.png" alt="" width="496">

5. **Geef een berekening van de grootte van de stroom I1 (door R1) en
   van stroom I2 (door R2).**
   I1 en I2 zijn allebei U / R1+R2\
   Want de stroom is altijd gelijk en daarom deel je de spanning door beiden weerstanden om de stroom te krijgen/
   5 / 3200 = 0.0015625 ampere = 1.5625 mA

6. **Geef een berekening van knooppunts-spanning V2.** 
   U = I * R1\
   0.0015625 * 1000 = 1.5625 verliezen we vanwege de weerstand\
   3.4375 V loopt er door V2

7. **Leidt een formule af voor de verhouding tussen V2 en V1. (geef een
   formule van V2/V1, uitgedrukt in R1 en R2)**
   Hoe druk je V2/V1 uit in R1 en R2\
   V2/V1 = (I * R1) / (I * (R1 + R2)) dus\
   V2/V1 = R1 / (R1 + R2) 

8. **Controle-meting. Welke spanning meet je op V2?**
   3.43 V hebben we gemeten met de multimeter.

9. Stel dat je twee chips met elkaar wilt verbinden.  
   De ene chip heeft een digitale uitgang die tussen 0 en 5V
   schakelt.  
   De andere chip heeft een digitale ingang die signalen tussen de 0 en
   3,3V verwacht.  
   **Hoe kun je beide chips goed-werkend op elkaar aansluiten?**
   De chip van 0 tot en met 5 V kan op V1 staan en de andere op V2

# Potentiometer

## Benodigd

- Een multimeter

- Een 10k potmeter (potentiometer of regelbare weerstand)

## Opdracht

Neem de potentiometer:

<img title="" src="./media/media/image6.png" alt="" width="174">

1. Meet met de multimeter de weerstand tussen pootje 1 en 3 (de
   buitenste pootjes), terwijl je de potentiometer naar links en naar
   rechts draait.  
   **Welke weerstandswaarde(n) lees je af:  
   \* Als hij helemaal naar links staat?\
     10,20k Ohm\
   \* Als hij in het midden staat?\
   10,20k Ohm\
   \* Als hij helemaal naar rechts staat?**\
   10,20k Ohm

2. Meet met de multimeter de weerstand tussen pootje 1 en 2, terwijl je
   de potentiometer naar links en naar rechts draait.  
   **Welke weerstandswaarde(n) lees je af:  
   \* Als hij helemaal naar links staat?  
   15.7 Ohm\
   \* Als hij in het midden staat?  
   5.1k Ohm\
   \* Als hij helemaal naar rechts staat?** 
   10.2k Ohm

3. Meet met de multimeter de weerstand tussen pootje 2 en 3, terwijl je
   de potentiometer naar links en naar rechts draait.  
   **Welke weerstandswaarde(n) lees je af:  
   \* Als hij helemaal naar links staat?  
   10.2k Ohm\
   \* Als hij in het midden staat?  
   5.1k Ohm\
   \* Als hij helemaal naar rechts staat?**
   10.7 Ohm

4. **Beschrijf hoe een potmeter werkt.**
   De potmeter veranderd de hoeveelheid Ohm als je aan de potmeter draait.
   Dit kan van links hoog naar rechts laag of andersom, dit hangt af van hoe je de potmeter hebt staan.

# Parallelweerstand en stroomdeler

## Benodigd

- Een breadboard

- Een multimeter

- Een 10 Ω weerstand

- Een 1k weerstand

- Een 2,2k weerstand

- Breadboard wires of draad+striptang

## Opdracht

1. Zet op je breadboard een weerstand van 1k parallel met een weerstand
   van 2,2k:  
   
   <img title="" src="./media/media/image7.png" alt="" width="232">

2. **Geef de berekening van de vervangingsweerstand van deze
   aaneenschakeling van weerstanden (ook wel “parallelweerstand”
   genaamd).**\

   $\frac{1}{1/1000 + 1/2200} = 687.5 Ohm$

3. Controleer het nu via een meting: zet de multimeter in “weerstand
   meet modus” en meet de parallelweerstand.  
   **Welke weerstand meet je?**
   Als we meten komen we uit op 660 Ohm

4. Bouw de volgende schakeling, met Vsup=5V, R1 = 1k en R2 = 2,2k:  
   
   <img title="" src="./media/media/image8.png" alt="" width="462">

5. - **Geef een berekening van de grootte van de stroom I1 (door R1) en
     van stroom I2 (door R2).**** 
     5 / 1000 = 5 mA
     5 / 2200 = 2.3 mA
   
   - **Hoe groot is de verhouding tussen de stromen? (geef een formule voor I1/I2 uitgedrukt in R1 en R2)**  
      I1/I2 = (U/R1) / (U/R2)

6. **Hoe groot is de som van I1 en I2?**
     I = U / R
     5 U / 687.5 Ohm = 0.0072727 ampere = 7.3 mA

7. We willen ter controle nu de stroom meten die uit voeding Vsup
   komt.  
   Dit keer meten we die stroom indirect, door een klein
   meetweerstandje R3=10 Ω in het stroompad te zetten:  
   <img src="./media/media/image9.png"/>  
   
   **Meet de spanningsval over dat meetweerstandje R3, en leidt daaruit
   met behulp van de wet van Ohm af hoe groot stroom I3 is.**
   Uit de mening kwam 0.07 volt\
   I = U / R , 0.07 / 10 = 0.007 ampere

8. **Bereken met behulp van alleen I3 en V2 de vervangingsweerstand R1
   en R2. (Tip: de vervangingsweerstand als geheel gehoorzaamt ook de
   wet van Ohm).**\
   R = U/I, 4.93 U / 0.007 = 704.29 Ohm
   
9. Door het invoegen van het meetweerstandje is de stroom die door de
   parallelweerstand R1 en R2 loopt, ietsje veranderd.  
   **Hoe komt dat?**\
   Er is meer weerstand toegevoegd aan het circuit

10. **Wat is het voordeel van het stroom meten door middel van het meten
    van spanningen over meetweerstandjes in plaats van het meten van
    stromen door direct stromen te meten met de multimeter?**\
    Dan hoef je niet het circuit uit elkaar te halen.

# Combi

## Benodigd

- Een breadboard

- Een multimeter

- Twee 1k weerstanden

- Een 2,2k weerstand

- Breadboard wires of draad+striptang

## Opdracht

1. Bouw de volgende schakeling:  
   
   <img title="" src="./media/media/image10.png" alt="" width="354">

2. **Geef de berekening van de vervangingsweerstand van deze
   serieschakeling van weerstand R3 met de parallelweerstand bestaande
   uit R1 en R2.\
   $\frac{1}{1/1000 + 1/2200} + 1000 = 1687.5 Ohm$

3. Controleer het nu via een meting: zet de multimeter in “weerstand
   meet modus” en meet de vervangingsweerstand.  
   **Welke weerstand meet je?**\
   We hebben 1640 Ohm gemeten

4. Bouw de volgende schakeling, met Vsup=5V, R1 = 1k, R2 = 2,2k en R3 =
   1k:  
   
   <img title="" src="./media/media/image11.png" alt="" width="667">

5. **Meet de spanning over R3, bereken daaruit de stroom I3.**
   De meeting geeft ons 2.97U\
   2.97U / 1000Ohn = 0.00297 ampere, 2.97mA

6. **Bereken mbv alleen I3 en V1 de vervangingsweerstand van het geheel
   dat bestaat uit R3, R1 en R2. (Tip: de vervangingsweerstand als
   geheel gehoorzaamt ook de wet van Ohm).**\
   R = U/I\  
   5U / 0.00297I = 1683.50 Ohm

# Pull-up
Stel je wilt met een drukschakelaar een logisch signaal maken voor een ingangspin van een microcontroller.

1. Stel je gebruikt daarvoor een schakelaar met **pull-up** weerstand, wat is dan het gedrag van het circuit? Waarom werkt het niet als je de pull-up weerstand weglaat?
Het circuit is afgebroken en er is geen connectie vanaf + naar -, wanneer de schakelaar niet gebruikt wordt.\
Als je geen pull up weerstand gebruikt krijg je een short circuit

# Pull-down

Stel je wilt met een drukschakelaar een logisch signaal maken voor een ingangspin van een microcontroller.
Ok nice :)

# Uitsmijter (theorie)

<img title="" src="./media/media/groter-netwerkje-1.png" alt="" width="220">   

1. **Bereken de vervangingsweerstand (die je tussen de klemmen meet) van het bovenstaande netwerk**
   (Tip: gebruik alleen de formules voor serie en parallelweerstand)

   R1 + R2 = 2K Ohm\
   1/(1/2000+1/1000) = 666.667 Ohm
   666.667 Ohm + R5 = 1166.667
   1/(1/1166.667+1/1000) = 625 Ohm

# Bonus: Laddernetwerk

<img title="" src="./media/media/ladder1.gif" alt="" width="667">   

<img title="" src="./media/media/ladder2.gif" alt="" width="667">   

<img title="" src="./media/media/ladder3.gif" alt="" width="667">   

1. **Probeer uit te leggen waar de bovenstaande plaatjes over gaan.**

Tips: 

- Kijk eens naar [ladder-networks](https://www.sciencedirect.com/topics/engineering/ladder-networks)).
- De opamp-weerstandscombinatie rechtsonder regelt zijn ingang op 0Volt, en converteert de binnenkomende stroom naar de uitgangs-spanning: -Iin * Rt.
