# LED

## Benodigd

- Een breadboard
- Een multimeter
- Een LED
- Een 100 Ω weerstand
- Een 1k weerstand
- Een 10k potmeter
- Breadboard wires of draad+striptang

# PRACTICUM GEMAAKT DOOR AIMANE CHAKIRI

## Opdracht

De LED (Light emitting diode) is zoals de naam zegt, een diode die licht
geeft als hij geleidt (in voorwaarts staat). Ze diode staat in
voorwaarts als het ene pootje, de anode een voldoende hoge spanning
heeft vergeleken het andere pootje, de kathode.

Bouw de volgende schakeling, met P1=10k potmeter, R1=100 Ω weerstand\
   *Hier is een foto van het fysieke bouwwerk:*
   https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/blob/main/elektronica/Led_Kirchoff/led_kirchoff_foto_1.jpeg


<img title="" src="./media/media/image1.png" alt="" width="345">

1. **Kun je de potentiometer zo instellen dat de led licht geeft?
   Waarom wel/niet?**  
   
   Nee dat kan NIET!\
   De uitgang van het LED lampje is aangesloten op waar de stroom vanaf komt.\
   Het LED lampje laat stroom vanaf 1 kant naar de andere kant lopen, andersom kan niet.\
   Dit is waarom het LED lampje geen licht geeft, de stroom komt binnen bij de uitgang, niet de ingang.

2. Draai nu de LED om:  
   <img src="./media/media/image2.png" alt="" width="345"/>  
   Door de weerstand van de potentiometer te veranderen, kun je de
   stroom veranderen.  
   Stel de potentiometer zo in, dat je de led nog net een klein beetje
   ziet branden.  
   **Welke spanning staat er dan over de LED?**

   Hiervoor gebruik ik de multimeter, ik haal de uitgang van het LED lampje er uit en hou daar mijn rode draad tegen aan.\
   Het zwarte draadje hou ik vervolgens tegen een kabel aan die naar de GND toe gaat.\
   De meting die hier uit komt volgens de multimeter = 3.15 Volt

   Ik heb dit ook gedaan door 2 draden extra toe te voegen tussen de uitgang van het LED lampje en een andere serieel met de GND kabel.\
   Vervolgens heb ik de andere uiteindens van deze kabels niet in het breadboard gestoken en gebruikt om weer te meten met de multimeter.\
   Op die manier maakt de multimeter het seriele circuit af, daar uit kwam 3.23 Volt.

3. **Welke stroom I1 loopt er dan door
 de LED (bereken I1 door het
   spanningsverschil tussen V1 en V2 te meten en met R1 de wet van Ohm
   toe te passen)?**

   V1 = 3.23 Volt\
   V2 = 3.43 Volt\
   V2 - V1 = 0.20 Volt 

   I = U/R = 0,2 / 100 = 0,002 A = 2mA

4. Draai de potentiometer nu helemaal naar een kant, zodanig dat de LED
   maximaal hard brandt.  
   **Welke spanning staat er dan over de LED?**

   Volgens de multimeter 2.08 Volt

5. **Welke stroom I1 loopt er dan door de LED?**\
    I = U / R\
    2.08 / 100 = 0.0208 ampere

6. **Gehoorzaamt een LED de wet van Ohm? Beargumenteer je antwoord.**\
   Een LED is niet lineaire en daarom gehoorzaamt het niet de wet van Ohm.

7. **Wat zou er zijn gebeurd als je bij bovenstaande experimenten R1
   zou hebben vervangen door een draadverbinding?**\
   Er zou dan te weinig weerstand zijn, waardoor het LED lampje kapot gaat

8. **Bekijk onderstaande schakeling, met R1=1k**  
   **<img title="" src="./media/media/image3.png" alt="" width="294">**  
   **Geef zonder de schakeling te bouwen een gefundeerde schatting van
   stroom I1.**\
   De voltage op I1 is 5 - 2, dus 3 Volt.
   De weerstand R1 is 1000.
   I = U/R = 3 / 1000 = 0,003 ampere
   
9. **Bouw de schakeling en bepaal ter controle I1 door R1 als
   meetweerstand te gebruiken.**
   Uit mijn meeting met de multimeter komt 3.03 V
   Dan is het aantal ampere 0.00303

### Logisch niveau meter
<img title="" src="./media/media/logisch-niveau-meter.png" alt="" width="206">     

Voor de bovenstaande schakeling geldt:

- Vsup = 5V
- R1 = 1kOhm
- R2 = 1kOhm
- De junctiespanning van de Rode LED noem ik even VjRood
- De junctiespanning van de Groene LED noem ik even VjGroen

Deze schakeling is een handig circuit voor het testen van logische niveaus.
Probeer eerst onderstaande vragen te beantwoorden door te redeneren. Controleer vervolgens of het klopt door het circuit te bouwen en te testen:   
**Vraag a: Welke LED brandt als de meetklem wordt verbonden met een (digitale output-) pin die een spanning van 5V heeft? En welke stroom loopt er dan door?**\
Wanneer je de meetklem aansluit op 5 volt dan brandt alleen het groene lampje.\
Vervolgens gebruiken we de multimeter om de voltage te meten in het led lampje.\
2.53 V
I = U/R = 2.53 / 1000 Ohm = 0.00253 Ampere

**Vraag b: Welke LED brandt als de meetklem wordt verbonden met een (digitale output-) pin die een spanning van 0V heeft? En welke stroom loopt er dan door?** 
Het rode lampje gaat branden wanneer de klem op 0V zit.    
Ik meet hier 1.88 V
I = U/R = 1.88 / 1000 Ohm = 0.00188 Ampere  

**Vraag c: Hoe herken je het als de meetklem wordt verbonden met een punt dat hoogohmig (niet aangesloten) is? Welke stroom loopt dan door de leds?**    

**Vraag d: Bouw het circuit en controleer je voorspellingen. Gedraagt het zich zoals je had verwacht? Wat zijn de waarden van VjRood en VjGroen?**

# Uitsmijter

De uitsmijter kan theoretisch berekend worden. Je kunt het eventueel ook controleren door na te bouwen en te meten

### Opgave 3

<img title="" src="./media/media/image9.png" alt="" width="326">

Voor de bovenstaande schakeling geldt:

- Vsup = 5V
- R1 = 1kOhm
- R2 = 1kOhm

**Vraag a: Wat is de stroom door R2?**

### Opgave 4

<img title="" src="./media/media/image10.png" alt="" width="348">    
Voor de bovenstaande schakeling geldt:

- Vsup = 5V
- R1 = 1kOhm
- R2 = 1kOhm

**Vraag a: Wat is de stroom door D1?**
