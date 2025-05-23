**Jouw naam: Aimane C, Lia, Lisa
Naam van jouw teamgenoot:**

# Practicum Servo Controller

# Servo Aansturing

Servos zijn motoren waarvan je de as op een bepaalde vaste hoek kunt
instellen. Een servo heeft 3 pinnen: een ground pin, een voedingspin, en een stuuringangs-pin. De servo wordt aangestuurd door op zijn
stuuringangs-pin een PWM (pulse width modulated) signaal van een vaste
frequentie zet zetten. De breedte van de puls wordt gebruikt om de hoek
van de servo in te stellen:  
<img src="./media/media/image4.png"
width="700px" />

Het circuit in dit practicum is multi-functioneel: het kan als
servo-controller gebruikt worden, maar ook als “gewone” multi-purpose
pwm controller met een groot instelbaar pulsbreedte modulatie bereik.
Eenhandig circuitje om in de kast te hebben liggen.

## Voorbereiding

Zorg voordat je aan dit practicum begint, dat je:

1.  de bijbehorende theorie (reader en sheets t.a.v. bouwtechnieken,
    solderen, comparator, transistor, diode, weerstand en condensator)
    goed hebt doorgenomen

2.  de benodigde materialen en gereedschappen voor alle opdrachten
    gereed hebt

## Benodigdheden

Voor deze practica heb je (als team) nodig:

-   Een breadboard
-   Een multimeter
-   Wat geisoleerd, stug draad (geschikt om in breadboard te prikken)
-   Wat breadboard wires
-   Een striptang
-   Een spanningsbron van rond de 5V.  
    Mogelijkheden: een adapter van 5V, een USB-adapter, een
    arduino-nano, een 4,5V batterij.
-   Nog wat meer electronica-onderdelen – zie de “Benodigd” kopjes onder
    elke opdracht.

Als je van een van deze dingen niet weet wat het is, google er dan even
op.

# Wat wordt er van je verwacht?

-   Voor de opdrachten uit samen met een andere student.
-   Het is niet erg als je in overleg met andere teams een antwoord
    uitvogelt.  
    Zorg er wel voor dat je het 100% begrijpt, anders schiet je jezelf
    in je voet: op het tentamen zal worden verondersteld dat je de
    practicum opgaven gemaakt hebt en 100% begrijpt.
-   Maak een copie van dit word-document, en voeg daarin je antwoorden
    toe. Als je iets moet invullen, wordt dat aangekondigd met
    **vetgedrukte** letters.
-   Vermeld bij het inleveren helemaal bovenaan zowel je eigen naam als
    die van je teamgenoot.

# Servo Controller

## Benodigd

-   Een breadboard
-   Een multimeter
-   Alle electronische onderdelen in het onderstaande schema;
-   Een ne555
-   <u>Een capaciteit van 47nF</u>
-   <u>Een capaciteit van 470uF</u>
-   Een 5V voeding. Bijvoorbeeld een arduino.
-   Een 470 ohm weerstand
-   Een 50 Kpotmeter
-   Een 500K potmeter

<img src="./media/media/image1.png"
width="800px"  />

## Opdracht

1.  Bovenstaand schema is gebaseerd op een NE555 timer.

2.  In zijn datasheet vind je het bijbehorende “Simplified Schematic”:

<img src="./media/media/image2.png"
width="800px" />

> De driehoekjes aan de linkerkant zijn comparators Comp1 en Comp2. Hun
> ingangen met circeltje zijn hun negatieve ingangen. Het driehoekje aan
> de rechterkant met circeltje ervoor symboliseert een inverter Inv1 met
> relatief sterke (eentje die wat meer stroom kan leveren)
> spanningsuitgang. De overige circeltjes (bij de Resettable SR-flipflop
> SR1) symboliseren inverters.

1.  Door je voor te stellen dat het onderste van bovenstaande diagrammen
    de invulling vormt van het NE555 blok in het bovenste van
    bovenstaande twee diagrammen krijg je een totaaloverzicht van de
    schakeling.  
      
    Werkings-modus 1:  
    Potentiometer P2 is zodanig ingesteld dat ze een kortsluiting vormt
    tussen de knooppunten met spanningen VD1 en Vmid.  
      
    **Leg uit hoe de schakeling werkt. Benoem daarbij de rol van elk van
    de componenten R1, R2, R3, R4, P1, P2, D1, D2, Comp1, Comp2, SR1,
    T1, Inv1, C1 en C2.  
    - en – beschrijf wat er in dat geval zal gebeuren als je P1 van
    helemaal links naar helemaal rechts draait. Leg uit waarom!**  
      
    Als dit nog wat lastig voor je is om te doorgronden, discussieer
    er dan over met andere studenten of stel het beantwoorden van deze
    vraag uit tot na de metingen met de oscilloscope/picoscope.

    - R1 staat altijd op 0, want die wordt direct gevoed en is inverted zoals aan het bolletje te zien is.

    - De R2 t/m 4 zitten in de NE555 in serie en daardoor verdelen die als weerstandjes de spanning in het circuit.

    - P1 en P2 bepalen of er spanning vanaf NE555 naar de condensator toe gaat of andersom.

    - D1 en D2 diodes die bepalen welke kant de spanning en stroom gaat. Als de spanning op Vdis bijvoorbeeld hoger is laat D1 spanning door.

    - Comp1 en Comp2 bepalen of er spanning stroomt naar reset of set.

    - SR1 geeft een 1 of 0 uit en deze wordt geinvert.

    - T1 een mosfet die gebaseerd op of die een 1 of 0 binnen krijgt open of dicht springt en dan of naar GND of DISCH connect.

    - Inv1 is een inverter die speelt een belangrijke rol ivm met T1 en SR1
    SR1 stuurt namelijk inverted een 0 of 1 door voor de mosfet en die moet dan weer terug geinvert worden.

    - C1 en C2 ?
    

2.  Werkings-modus 2:  
    Potentiometer P1 is zodanig ingesteld dat zijn slider (onderste
    pootje met pijltje, het knooppunt met Vc) contact maakt met zijn
    linker pootje (het knooppunt met Vmid).  
    **Wat zal er in dat geval gebeuren als je P2 van helemaal links naar helmaal rechts draait?  
    Leg uit waarom!*P2 is er om nauwkeurig de weerstand in te stellen samen met P1, dit is nodig om de condensator op te laden. Met P2 kun je nauwkeurig de snelheid bepalen waarmee je de condensator wilt opladen. Dit willen we namelijk in miliseconde doen*  
    Als dit nog wat lastig voor je is om te doorgronden, discussieer er
    dan over met andere studenten of stel het beantwoorden van deze
    vraag uit tot na de metingen met de oscilloscope/picoscope.

3.  **Welke frequentie schat je dat het uitgangssignaal zal hebben? Geef een gefundeerde schatting!** Dit doen we via de RC berekening.
550K Ohm * 47 nF = 0.023 seconde, vervolgens doen we 1 / 0,02585 = 39 Hz ongeveer

4.  Bouw de schakeling op je breadboard.  
    **Voeg hieronder een screenshot toe van een periode van het
    uitgangssignaal onder de conditie dat het systeem in Werkings-modus
    1 staat, en P1 in het midden staat ingesteld.**  
      
    **Welke frequentie heeft het uitgangssignaal?**
    Uit de meting die we hebben gedaan met de picoscope kiezen we 1 moment uit de meting; 422.1 ms - 399.4 = 22.7 ms
    Vervolgens doen we 1/0.0227 = 44 Hz

5.  **Demonstreer aan de docent de goede werking van de schakeling.**
    Marius heeft gekeken naar onze schakeling en bevestigd dat die er goed uit zag.
