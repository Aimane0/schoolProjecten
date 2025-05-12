

# Ontwikkeldocument Project ``Snelheidsmeter`` 

Versie ``0.1``
Team ``Flitsmeister``

## Inhoudsopgave

- [Inleiding](#inleiding)
- [Leeswijzer](#leeswijzer)
- [Uitgangspunten](#uitgangspunten)
  - [Systeem Context](#systeem-context)
  - [Identificatie en prioritering van Key Drivers](#identificatie-en-prioritering-van-key-drivers)
- [Requirements](#requirements)
  - [Functionele Requirements](#functionele-requirements)
  - [Niet-Functionele Requirements](#niet-functionele-requirements)
  - [Constraints](#constraints)
  - [Use Cases](#use-cases)
  - [Activity Diagrammen](#activity-diagrammen)
  - [Requirements Traceability Diagrammen](#requirements-traceability-diagrammen)
- [Ontwerp](#ontwerp)
  - [Functionele Decompositie](#functionele-decompositie)
  - [Object Modellen](#objectmodellen)
  - [Lijst met Objecten](#lijst-met-objecten)
  - [Taakstructurering](#taakstructurering)
    - [Taaksoort en deadline](#taaksoort-en-deadline)
    - [Taken samenvoegen](#taken-samenvoegen)
  - [Klassediagrammen](#klassediagrammen)
  - [STD's](#stds)
- [Realisatie](#realisatie)
  - [Code](#code)
  - [Unit-Tests](#unit-tests)
  - [Integratie-Tests](#integratie-tests)
  - [Eindresultaat](#eindresultaat)
- [Conclusie en Advies](#conclusie-en-advies)
- [Appendices](#appendices)

## Inleiding

Dit document dient als ontwikkel- en referentiedocument voor het project Speeddetector, uitgevoerd in opdracht van SilverFit. Het doel van dit document is om het werkproces zowel tijdens als na het project overzichtelijk vast te leggen. Hierdoor kunnen zowel het team als de opdrachtgever op een gestructureerde manier inzicht krijgen in de voortgang, keuzes en resultaten van het project.

## Leeswijzer

- Uitgangspunten
  - Systeem context:\
  Dit onderdeel geeft een schematische weergave van hoe wij het systeem voor ons zien en in welke context het functioneert.

  - Identificatie en prioritering van Key Drivers:\
  De geïdentificeerde key drivers vertegenwoordigen de belangrijkste belangen die invloed hebben op het product. Deze belangen spelen vervolgens een cruciale rol bij het opstellen en prioriteren van de requirements.

- Requirements
  - Functionele requirements:\
  Dit zijn beschrijvingen van wat een systeem of product moet doen. Ze zijn gebaseerd op de behoeften en verwachtingen van gebruikers of stakeholders.

  - Niet-functionele requirements:\
  Dit zijn beschrijvingen van hoe een systeem of product moet werken. Ze leggen de kwaliteitseisen en prestatiecriteria vast. Als een functionele requirement bijvoorbeeld stelt dat het systeem een snelheid moet meten, dan bepaalt een niet-functionele requirement in welke eenheid deze meting wordt uitgevoerd (bijvoorbeeld kilometers per uur of meters per seconde).

  - Use Cases:\
  Een use case beschrijft een scenario of reeks stappen die een gebruiker doorloopt om een bepaalde taak uit te voeren met behulp van het systeem. Het definieert de wie, wat en hoe van van deze scenarios. Ze zijn gebaseerd op functionele requirements en vormen een brug tussen abstracte requirements en een echt ontwerp.

  - Requirements Traceability Diagrammen:\
  Een requirements traceability diagram is een hulpmiddel om de implementatie en verificatie van de requirements te volgen gedurende het project.

  - Functionele decompositie:\
  In een functionele decompositie wordt een systeem beschreven in functies en taken die opeenvolgend zijn, met actoren die interacties hebben met het systeem.

  - Object modellen:\
  Object modellen helpen bij het ontwerpen van "objectgeoriënteerde software", Het is een diagram met objecten die gebaseerd zijn op de functionele decompositie. Deze zijn ingedeeld in boundaries, controls en entities.

  - Lijst met objecten:\
  De lijst met objecten is een overzicht van de objecten die opgesteld zijn in het object model.

  - Taakstructurering:
    - Taaksoort en deadline
    Een tabel waarin alle taken die uitgevoerd worden door de objecten. Deze geven aan wat voor soort taken het zijn en hoe lang deze taken horen te duren. Dit is handig om de threads te plannen.
    
    - Taken samenvoegen
    Taken die nauw verbonden met elkaar zijn of afhankelijk van elkaar zijn kunnen gecombineerd worden. Dit optimaliseert het programma. Wanneer de taken samengevoegd zijn kun je dit terug zien in de klassen die hier uit komen.

  - Klassediagram: \
  Een klassediagram is gemaakt met UML, het toont de relaties en eigenschappen van klassen. Het helpt bij het begrijpen van hoe verschillende interacties tussen componenten verlopen.\
  Vervolgens moet je voor controle klassen STD's ontwikkelen.

  - STD's:\
  STD staat voor State Transition Diagram, dit beschrijft hoe een object of systeem van de ene naar de andere toestand gaat in verband met voorgaande acties, STD's worden gemaakt voor controle klassen.

- Realisatie:
  - Fysieke view:\
  ?

  - Code:\
  Gebaseerd op de STD's en klassendiagram wordt er code gemaakt, deze code wordt hier getoond.

  - Unit-tests:\
  Hier staan testplannen en de uitgevoerde resultaten van de testen. Deze testen zijn er om te testen hoe afzonderlijke onderdelen hardware en code werken.

  - Integratie-tests:\
  Hier staan testplannen en de uitgevoerde resultaten van de testen. Deze testen zijn er om te testen hoe het gehele project werkt.

  - Eindresultaat:\
  Hier in bespreken we het volledige geteste en werkende systeem dat voldoet naar alle eerder benoemde hoofdstukken.

## Uitgangspunten

``Leg uit dat dit hoofdstuk de uitgangspunten voor de requirements inventariseert. Verwijs naar een appendix met genoteerde input (verslag van speech, gespreksverslagen) van de opdrachtgever - (de echte, tijdens de kickoff-meeting of diens vervanger (Marius,Bart) erna) ``

### Systeem Context

![SysteemContext](https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Business%20documentatie/SysteemContext/SysteemContext.svg)

### Identificatie en prioritering van Key Drivers

#### Keydrivers omtrent snelheidsdetector

Functionaliteit van het product: Het moet de snelheid van een persoon meten, door het tijdverschil tussen twee punten te berekenen, ook moet de persoon te herkennen zijn via IR. De snelheid wordt vervolgens getoond op een scherm en opgeslagen in een database.

Keydriver | Stakeholders | Beschrijving van de keydriver
--- | --- | ---
Veiligheid | Opdrachtgever, klant, bejaarde, verzorger | De opdrachtgever heeft ons gevraagd de benodigde apparatuur te installeren op zodanige plekken dat bejaarden er niet over heen kunnen struikelen.
Stimuleren van beweging | Opdrachtgever, klant, gebruiker | Het hoofddoel is het stimuleren van beweging bij ouderen met behulp van gamificatie, omdat dit de gezondheid van ouderen bevorderd en de sociale contacten verbetert.
Winst | Opdrachtgever | De opdrachtgever wilt geld verdienen aan het product en een groter marktaandeel vergaren. Zo hoopt de opdrachtgever een nieuwe markt aan te spreken.
10 meter loop test | Opdrachtgever, bejaarde, klant, verzorger, bewegingswetenschapper | Bij de 10 meter loop test wordt de comfortabele snelheid van een gebruiker gemeten. Dit is door de opdrachtgever aan ons gevraagd.
Dataverzameling | Verzorger, bewegingswetenschapper | Het is cruciaal om verzamelde informatie op te slaan, zodat bewegingswetenschappers en/of verzorgers onderzoek kunnen doen of interventies plegen met hulp van de data.
Gebruiksgemak | Bejaarde, verzorger, bewegingswetenschapper | Het is van belang dat het product makkelijk te gebruiken is. De bejaarden zijn minder bekend met technologie en moeten zo min mogelijk hoeven te interacteren. De verzorgers moeten zo snel en makkelijk mogelijk hun werk kunnen doen.

## Requirements

De requiremnts zijn opgesteld op basis van wat het product moet doen. De beschrijving van wat het product moet doen helpt te bedenken wat er gedaan moet worden door het product.

#### Functionele Requirements

##### Functionele requirements, ingedeeld in systemen van ons product.

- Snelheidsdetectiesysteem
- Scorebordsysteem
- Databasesysteem
- Snelheidsdisplaysysteem

#### Snelheidsdetectiesysteem

F01 | Snelheidsdetector
--- | ---
Omschrijving | De snelheid van de gebruiker die langs de detector/detectoren loopt moet gemeten worden.
Rationale | De gemeten snelheid is nodig om lopen en bewegen te gamificeren. De gebruikers moeten gemotiveerd worden als zij hun eigen snelheid gemeten zien.
Business priority | Must have

F02 | Connectie met andere systemen
--- | ---
Omschrijving | Het product bestaat uit meerdere onderdelen die in verbinding staan met elkaar
Rationale | Dit is nodig om data en informatie aan elkaar uit te wisselen. De systemen zijn afhankelijk van elkaar.
Business priority | Must have

F03 | Makkelijk gebruik
---|---
Omschrijving | Het systeem moet makkelijk te gebruiken zijn voor bejaarden en verzorgers
Rationale | Omdat wij met bejaarden werken is het belangrijk het systeem zo begrijpelijk mogelijk te maken. Ook moet er zo min mogelijk moeite gedaan worden om het systeem op te starten.
Business priority | Should have

#### Scorebordsysteem

F04 | Een scherm
--- | ---
Omschrijving | Een scherm met het scorebord
Rationale | Een scorebord moet je kunnen zien, daarom hebben we een scherm nodig.
Business priority | Must have

F02 | Connectie met andere systemen
--- | ---
Omschrijving | Het product bestaat uit meerdere onderdelen die in verbinding staan met elkaar
Rationale | Dit is nodig om data en informatie aan elkaar uit te wisselen. De systemen zijn afhankelijk van elkaar.
Business priority | Must have

F05 | Front end
--- | ---
Omschrijving | Een UI met de scores
Rationale | Vanuit de Hogeschool Utrecht is opgelegd dat wij een onderdeel front end hebben.
Business priority | Must have

F03 | Makkelijk gebruik
---|---
Omschrijving | Het systeem moet makkelijk te gebruiken zijn voor bejaarden en verzorgers
Rationale | Omdat wij met bejaarden werken is het belangrijk het systeem zo begrijpelijk mogelijk te maken. Ook moet er zo min mogelijk moeite gedaan worden om het systeem op te starten.
Business priority | Should have

#### Databasesysteem

F02 | Connectie met andere systemen
--- | ---
Omschrijving | Het product bestaat uit meerdere onderdelen die in verbinding staan met elkaar
Rationale | Dit is nodig om data en informatie aan elkaar uit te wisselen. De systemen zijn afhankelijk van elkaar.
Business priority | Must have

F05 | Front end
--- | ---
Omschrijving | Een front end om de data uit de database in te zien
Rationale | Verzorgers en bewegingswetenschappers kunnen hoogstwaarschijnlijk geen SQL, met een front end systeem maken wij data opvragen gemakkelijk.
Business priority | Must have

#### Snelheidsdisplay 

F04 | Een scherm
--- | ---
Omschrijving | Een scherm met het scorebord
Rationale | Een scorebord moet je kunnen zien, daarom hebben we een scherm nodig.
Business priority | Must have

F06 | Feedback
--- | ---
Omschrijving | Op basis van de gelopen snelheid van de bejaarden is er visuele/auditieve feedback
Rationale | Het geven van signalen verhoogt de motivatie van bejaarden gebruikers. Daardoor gaan ze meer en sneller lopen.
Business priority | Must have

F02 | Connectie met andere systemen
--- | ---
Omschrijving | Het product bestaat uit meerdere onderdelen die in verbinding staan met elkaar
Rationale | Dit is nodig om data en informatie aan elkaar uit te wisselen. De systemen zijn afhankelijk van elkaar.
Business priority | Must have

F03 | Makkelijk gebruik
---|---
Omschrijving | Het systeem moet makkelijk te gebruiken zijn voor bejaarden en verzorgers
Rationale | Omdat wij met bejaarden werken is het belangrijk het systeem zo begrijpelijk mogelijk te maken. Ook moet er zo min mogelijk moeite gedaan worden om het systeem op te starten.
Business priority | Should have

#### Herkenningsysteem
F07 | Herkenning
--- | ---
Omschrijving | Het systeem moet bejaarden die het product gebruiken kunnen herkennen.
Rationale | Omdat het voor verzorgers handig is om te weten wie wat loopt.
Business priority | Should have

F08 | Uitsluiting
--- | ---
Omschrijving | Het systeem herkent alleen bejaarden die te herkennen zijn en sluit de rest uit.
Rationale | SilverFit deed het verzoek om iedereen die niet een bejaarden is uit te sluiten.
Business priority | Should have

### Niet-Functionele Requirements

#### Snelheidsdetectiesysteem

Requirement ID | Requirement | Rationale 
--- | --- | ---
NF01 | Snelheid eenheid | Snelheid moet uitgedrukt worden in een eenheid, één die goed te begrijpen is.
NF02 | Nauwkeurigheid | Dit moet gevraagd worden aan Lucy, want dat is een eis vanuit de opdrachtgever.
NF03 | Standby | We willen stroombesparen en daarom een standby mode ontwikkelen.
NF04 | Wireless connectie | Dit is opgelegd vanuit de HU als leerdoel en ook van belang ivm de veiligheid.
NF05 | Makkelijk gebruik | Bejaarden en verzorgers moeten zich zo min mogelijk inspannen voor het gebruiken van het product, vanwege de werkdruk van verzorgers en omdat de meeste bejaarden digibeet zijn.

#### Scorebordsysteem

Requirement ID | Requirement | Rationale 
--- | --- | ---
NF06 | Style keuzes | Het scorebord moet leesbaar zijn want ouderen moeten het goed kunnen lezen, ook moet de style plezant zijn om naar te kijken en het scorebord opvallen. Dit is te baseren op online bronnen die wij kunnen onderzoeken.
NF07 | Real-time | We willen niet dat je lang moet wachten op feedback, dit zou de ervaring kunnen verpesten.
NF08 | Capaciteit | Het scorebord is niet oneindig en daarom moet er een limiet op het aantal snelheden die getoond worden.
NF09 | Logo | Op het scorebord willen we een logo gebruiken van ons ter naam bekendheid.
NF10 | IR | Het scorebord haar style moet aangepast kunnen worden van het ene template naar het andere met gebruik van een afstandsbediening. Dit is opgelegd vanuit de HU als leerdoel.
NF04 | Wireless connectie | Dit is opgelegd vanuit de HU als leerdoel en ook van belang ivm de veiligheid.
NF05 | Makkelijk gebruik | Bejaarden en verzorgers moeten zich zo min mogelijk inspannen voor het gebruiken van het product, vanwege de werkdruk van verzorgers en omdat de meeste bejaarden digibeet zijn.
NF11| Flask | Dit is een eis van de HU voor het behalen van leerdoelen.

#### Databasesysteem

Requirement ID | Requirement | Rationale 
--- | --- | ---
NF12 | Ubuntu 22.04 | Dit is opgelegd vanuit de HU. Op Ubuntu zullen wij een database draaien.
NF13 | Lokaal gebruik | Dit is voor de veiligheid van opgeslagen data.
NF14 | Docker | Dit is een eis van de HU.

#### Snelheidsdisplay

Requirement ID | Requirement | Rationale 
--- | --- | ---
NF04 | Wireless connectie | Dit is opgelegd vanuit de HU als leerdoel en ook van belang ivm de veiligheid.
NF15 | Positieve feedback only | Op verzoek van Lucy mogen we alleen positieve feedback geven aan gebruikers.
NF05 | Makkelijk gebruik | Bejaarden en verzorgers moeten zich zo min mogelijk inspannen voor het gebruiken van het product, vanwege de werkdruk van verzorgers en omdat de meeste bejaarden digibeet zijn.
NF07 | Real-time | We willen niet dat je lang moet wachten op feedback, dit zou de ervaring kunnen verpesten.

#### Herkenningsysteem
Requirement ID | Requirement | Rationale
--- | --- | ---
NF16 | IR Beacon | Dit  is opgelegd vanuit de HU als leerdoel.

### Constraints

``Beschrijf de relevante Constraints``

| Naam         | ``C02 - Jaarlijkse onderhoudskosten``                     |
| ------------ | --------------------------------------------------------- |
| Omschrijving | ``quantificeerbare of anderszins meetbare omschrijving `` |
| Rationale    | ``reden: waarom kan het niet anders?``                    |

### Use Cases

#### Use Case 01: Snelheid Meten

| **Naam** | UC01 - Snelheid Meten |
| --- | --- |
| **Actor** | Bejaarden |
| **Samenvatting** | Het systeem meet de loopsnelheid van de bejaarden. |
| **Preconditie** | Een bejaarde wordt door het systeem geregistreerd, waardoor de meting kan beginnen. |
| **Scenario** | 1. Een bejaarde begint met lopen. <br> 2. Het systeem meet de snelheid.<br> 3. Na de meting stopt het systeem met meten. |
| **Invariant** | Het systeem blijft de snelheid meten zolang de bejaarde beweegt. |
| **Postconditie** | - |
| **Uitzonderingen** | Het systeem kan een foutmelding weergeven als het apparaat de gegevens niet goed kan registreren. |

#### Use case 02: Snelheid door versturen

| **Naam** | UC02 - Snelheid door versturen |
| --- | --- |
| **Actor** | - |
| **Samenvatting** | De snelheidsdetector verstuurt de snelheden door naar andere systemen. |
| **Preconditie** | - |
| **Scenario** | 1. Er is een snelheid gemeten.<br> 2.Deze snelheid wordt tijdelijk opgeslagen in het systeem.<br> 3. De opgeslagen snelheden worden doorgestuurd naar twee andere systemen. |
| **Invariant** | De snelheden blijven verstuurd worden, zolang er snelheden gemeten worden. |
| **Postconditie** | - |
| **Uitzonderingen** | Als de verbinding defect is kan er niks doorgestuurd worden. |

#### Use case 03: Snelheid tonen

| **Naam** | UC03 - Snelheid tonen |
| --- | --- |
| **Actor** | Bejaarden, verzorger |
| **Samenvatting** | Het systeem toont de live gemeten snelheid |
| **Preconditie** | - |
| **Scenario** | 1.Er komt een live gemeten snelheid binnen.<br> 2. Het systeem toont deze live gemeten snelheid.<br> 3. Het systeem toont positieve feedback. |
| **Invariant** | - |
| **Postconditie** | Het scherm verandert terug naar standaard weergave. |
| **Uitzonderingen** | Als er geen snelheden gemeten zijn dan wordt er niks weergegeven. |

#### Use case 04: Opslaan van de snelheden

| **Naam** | UC04 - Opslaan van de snelheden |
| --- | --- |
| **Actor** | - |
| **Samenvatting** | De verstuurde snelheden worden opgeslagen in een database. |
| **Preconditie** | - |
| **Scenario** | 1: De database ontvangt data van de snelheidsdetector<br>2: Vervolgens wordt de ontvangen data opgeslagen in de database. |
| **Invariant** | - |
| **Postconditie** | - |
| **Uitzonderingen** | - |

#### Use case 05: Toont beste snelheden

| **Naam** | UC05 - Toont beste snelheden |
| --- | --- |
| **Actor** | Bejaarden, verzorger |
| **Samenvatting** | Een leaderbord met de beste snelheden. |
| **Preconditie** | - |
| **Scenario** | 1. Het systeem vraagt snelheden op uit de database.<br> 2.De opgevraagde snelheden worden getoond op rang. |
| **Invariant** | - |
| **Postconditie** | - |
| **Uitzonderingen** | - |

#### Use case : 06 Toont snelheden op UI

| **Naam** | UC06 - Toont snelheden op UI |
| --- | --- |
| **Actor** | Bewegingswetenschapper, verzorger |
| **Samenvatting** | Een UI om snelheden op te vragen. |
| **Preconditie** | Een gebruiker die bewegingswetenschapper of verzorger is moet de nodige rechten hebben. |
| **Scenario** | 1. Een gebruiker opent de UI.<br> 2. De gebruiker vraagt de relevante snelheden op.<br> 3. De UI vraagt de snelheden op uit de database. <br> 4. De UI ontvangt deze data uit de database. <br> 5. De UI maakt een leesbare vertaling van de opgevraagde data.<br> 6. De snelheden zijn op een visuele plezante manier te zien. |
| **Invariant** | - |
| **Postconditie** | - |
| **Uitzonderingen** | Als een bewegingswetenschapper of verzorger geen toegang heeft tot de UI, moet deze de nodige rechten vekrijgen. |

#### Use case 07: Snelheden exporteren

| **Naam** | UC07 Snelheden exporteren |
| --- | --- |
| **Actor** | Bewegingswetenschapper, verzorger |
| **Samenvatting** | De bewegingswetenschapper en of verzorger kan de relevante snelheden uit de database exporteren. |
| **Preconditie** | - |
| **Scenario** | 1. De bewegingswetenschapper of verzorger opent de UI.<br> 2. Via een optie te selecteren kunnen ze kiezen de data te exporteren.<br> 3. De data wordt geëxporteerd in een document.|
| **Invariant** | - |
| **Postconditie** | - |
| **Uitzonderingen** | Als een bewegingswetenschapper of verzorger geen toegang heeft tot de UI, moet deze toestemming vragen aan de eigenaar van het product. |

![Use_cases_diagram](https://github.com/user-attachments/assets/8d52b589-f376-42cc-b304-14f4c0fb05df)

### Activity Diagrammen

![ActivityDiagramSpeeddetector](https://github.com/user-attachments/assets/5dbcd9e5-960c-4a86-9f78-8394112d2864)

### Key Driver Chart

![KeyDriverChart](https://github.com/user-attachments/assets/fa5239ca-ff68-46ac-ac0e-6277561ca9a0)

### Requirements Traceability Diagrammen

![TraceabilityDiagram](https://github.com/user-attachments/assets/087c177b-c5ab-4922-822d-9cb27a97373d)


## Ontwerp

leg uit hoe het ontwerp volgt door het volgen van de stappen die in de sub-hoofdstukken worden behandeld en hoe deze onderwerpen met elkaar in verband staan

### Functionele decompositie

De functionele decompositie is te vinden op deze Github-link:

![Functionele decompositie](https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Business%20documentatie/functionele_decompositie/FunctioneleDecompositie.svg)

### Objectmodellen

Het objectmodel is te vinden op deze Github-link:

![Objectmodel](https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Business%20documentatie/ObjectModel3/ObjectModel.svg)

#### Lijst met Objecten

In deze lijst is elk object uit de objectmodellen toegevoegd:

| Object Naam         | Stereotype  | Beschrijving                                                           |
| -------------       | ----------- | ---------------------------------------------------------------------- |
| ToFSensor           | Boundary    | Een afstandmeter die gebruikt wordt als "tripwire"                     |
| IRBeacaon           | Boundary    | Infrarood systeem dat gebruikt wordt voor de herkenning van personen   |
| ESP32Start          | Control     | Bestuurt de ToFSensor en IRBeacon aan het begin van het systeem        |
| ESP32End            | Control     | Bestuurt de ToFSensor en IRBeacon aan het einde van het systeem        |
| RaspberryPiDatabase | Boundary    | Een minicomputer waarop een lokale MongoDB database staat              |


### Taakstructurering

In dit hoofdstuk wordt uigelegd wat het doel is van taakstructurering en hoe de deelstappen (sub-hoofdstukken) samen dat doel reliseren

#### Taaksoort en deadline

Tabel die per object taaksoort, deadline, periode en prioriteit weergeeft:

| Object Naam   | Taaksoort     | Periode | Deadline | Prioriteit |
| ------------- | ------------- | ------- | -------- | ---------- |
| TripwireDetectie | Periodiek | 100ms | 100ms | 1 |
| IRHerkenning | Periodiek | 100ms | 100ms | 2 |
| SnelheidBerekening | Demand driven | - | 200ms | 3 |
| VersturenNaarDatabase | Demand driven | - | 1000ms | 4 |

#### Taken samenvoegen

Tabel waarin we laten zien welke objecten een eigen taak hebben en van welke de taken worden samenvoegd in een enkele.


| Taak Naam  | Object Naam                            | Taaksoort     | Periode | Deadline | Prioriteit |
| ---------- | -------------------------------------- | ------------- | ------- | -------- | ---------- |
| HerkenningTaak | TripwireDetectie, IRHerkenning | Periodiek | 100ms | 100ms | 1 |
| SnelheidBerekening | Snelheidberekening | Demand driven | - | 200ms | 2 |
| VersturenNaarDatabase | VersturenNaarDatabase | Demand driven | - | 1000ms | 3 |

### Klassediagrammen

Het klassediagram is te vinden op deze Github-link:

![Klassediagram](https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Business%20documentatie/Klassediagram3/KlasseDiagram.svg)

### STD's

De STD's zijn te vinden op deze Github-link:

![STD EPSStart](https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Business%20documentatie/STD3/STDStartESP3.svg)

![STD ESPEnd](https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Business%20documentatie/STD3/STDEndESP2.svg)

## Realisatie

In dit hoofdstuk wordt uitgelegd waarin de realisatie zich onderscheidt van het ontwerp.

### Code

- Projectcode Dashboard: https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/tree/main/Dashboard
- Projectcode UART: https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/tree/main/UARTVerbinding
- Projectcode TOFSensor: https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/tree/main/ToFSensor


### Unit Tests

- ToFSensor test; https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Tests/MeasurementTests/MeasurementTest.md
- Plan B ToFSensor test; https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Tests/TOF_PlanB_Sensor_Test/TOF_PlanB.md
- Wifi test; https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Tests/WifiTests/WifiTest.md
- API test; https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Tests/APITests/ApiTest.md

### Integratie Tests

- TOFSensor 10-meter-test; https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Tests/Integratietest_TOF/TOF_Integratietest.md

### Eindresultaat

Het project heeft met succes een systeem ontwikkeld waarmee de loopsnelheid van bejaarden over een afstand van 10 meter kan worden gemeten. Door gebruik te maken van twee ESP-microcontrollers die via een WiFi-meshnetwerk communiceren, kan een nauwkeurige meting worden uitgevoerd. De eerste ESP detecteert de aanwezigheid van een persoon met een TOF-sensor en valideert de meting met een IR-zender, die door de bejaarde wordt gedragen, om interferentie van andere voorbijgangers te voorkomen. Zodra een persoon wordt gedetecteerd, start de tijdmeting en wordt een signaal naar de tweede ESP gestuurd.Om de veiligheid van de ouderen te waarborgen, zijn de sensoren op de muur geplaatst, zodat er geen obstakels op de grond staan waarover men kan struikelen of tegenaan kan stoten. 

De tweede ESP registreert wanneer de persoon de eindpositie bereikt en berekent op basis van de verstreken tijd de snelheid in km/h. Deze gegevens, samen met een unieke IR-code die correspondeert met een geregistreerde gebruiker, worden via een UART-verbinding naar een database gestuurd. Hierdoor kunnen individuele metingen worden gekoppeld aan specifieke bewoners, wat de mogelijkheid biedt om persoonlijke voortgang bij te houden.

De actuele snelheid wordt direct weergegeven op een scherm, en er is tevens een leaderboard beschikbaar met de hoogste snelheden. Daarnaast kunnen verzorgers van het bejaardentehuis inloggen om inzicht te krijgen in de prestaties en gezondheidstrends van de bewoners. Dit biedt waardevolle informatie om veranderingen in mobiliteit en gezondheid tijdig te signaleren.

In conclusie biedt dit systeem een efficiënte en gebruiksvriendelijke manier om de mobiliteit van ouderen te monitoren, wat kan bijdragen aan hun welzijn en gezondheid.

## Conclusie en Advies

Over het algemeen zijn de meeste functionele en niet-functionele requirements succesvol geïmplementeerd. De snelheid wordt nauwkeurig gemeten, de connectie tussen de systemen werkt zoals verwacht, en de gebruikersinterface functioneert naar behoren. De belangrijkste doelen, zoals het motiveren van ouderen door gamificatie en het verzamelen van nuttige bewegingsdata, zijn behaald. Echter, enkele functionaliteiten zijn nog niet volledig geïmplementeerd en behoeven verdere ontwikkeling.

### **Niet-behaalde requirements:**
- **Standby-modus (NF03):** Er is nog geen energiebesparende modus ontwikkeld om het verbruik te optimaliseren.
- **UI-wissel met afstandsbediening (NF10):** De mogelijkheid om het scorebord uiterlijk te wisselen via een afstandsbediening is nog niet geïmplementeerd.
- **Auditieve feedback (F06):** Momenteel is alleen visuele feedback aanwezig, terwijl ook auditieve signalen gewenst zijn.

## **Aanbevelingen voor Toekomstige Doorontwikkeling**

- Adviezen van Lucy:

- Feedback systeem te implementeren. Zo zou elke loper positieve feedback krijgen zowel in audio als visueel. Lucy vond het leaderbord een leuke andere manier om mensen te motiveren. Het voegt een competief randje toe aan ons product.

- Het zou mooi zijn geweest als bejaarden die lopen hun vorige tijden kunnen zien. Denk bijvoorbeeld aan dat je loopt en herkend wordt door de IR en dat na het lopen je de gelopen tijd ziet en tevens de twee vorige tijden!

- Op het leaderbord mag er meer witte ruimte tussen de gebruikers. 

- Het zou handig zijn als de staafdiagram waar de gelopen tijden van een bejaarden op af te lezen zijn ook duidelijk aangeeft wanneer er NIET is gelopen. Lucy gaf aan dat het zo makkelijk mogelijk te zien moet zijn voor een fysiotherapeut.

## Appendices

### Appendix : Gespreksfeedback

- Feedback show and tell 1: We kregen tijdens het eerste sprint-gesprek te horen dat we vaker het planbord bij moeten houden en taken op DONE kunnen zetten. Ik heb mijn planning bijgehouden en deze zo volledig mogelijk ingevuld inclusief links naar commits van de betreffende taken.

- Feedback show and tell 2: Scrum bord moet echt beter. De taken moeten echt aan het einde van de sprint naar Done.  Gebruik het scrum bord als iets wat jullie helpt. Per persoon maar 1 taak in TODO. Deze taken moeten tussen de 2 en 3 uur zijn. Dit helpt om niet in tijdsnood te komen en vroeg erachter te komen of iemand vastloopt of niet.

- Feedback show and tell 3: Scrum bord ziet er al veel beter uit, lekker leeg aan het einde van de sprint. Hierin zijn we als team gegroeid.

- Feedback show and tell 4: Er moet meer gelet worden op de deadline van het project omdat deze al snel nadert. We hebben samen met de opdrachtgevers een planning gemaakt om zo een goede workflow te krijgen in de laatste paar weken voor de deadline het project.

- Feedback show and tell 5: Er moeten meer kloppende STDs gemaakt worden voor het project, dit is belangrijk want STD's geven de toestanden en overgangen weer binnen onze software, hardware en processen. Daarnaast waren de opdrachtgevers positief over de hoeveelheid taken die in het SCRUM-board op DONE stonden.

- Feedback show and tell 6: Login op navbar moet weg na ingelogd te zijn. Snelheidsgrafiek moet met meeteenheden. Staafgrafieken met verschillende datums per meting. Keuze maken over hoe we de dagen van de week laten zien op de grafiek. Uitzonderingssituaties voor het meetsysteem tonen via tekeningen.

### Appendix : Upgradeonderzoeksverslagen

Lijst met links naar de upgradeonderzoeksverslagen:

- Mesh onderzoek (Niels Bosboom) : https://github.com/2024-TICT-TV2SE3-24/s3-personal-Kaasschaver/blob/main/Persoonlijke_project_opdrachten/Persoonlijk_onderzoek_meshes.md
- Leesbaarheid onderzoek (Aimane Chakiri) : https://github.com/2024-TICT-TV2SE3-24/s3-project-flitsmeister/blob/main/Standups_en_verslagen/onderzoek/LeesbaarheidOnderzoek/Leesbaarheid2.md
- Encryptie onderzoek (Ingmar van de Sande) : https://github.com/2024-TICT-TV2SE3-24/s3-personal-ingmarvdsande/blob/main/Opdrachten/Onderzoek/Onderzoek_Encryptie.md
- Authenticator onderzoek (Sem Holema) : https://github.com/2024-TICT-TV2SE3-24/s3-personal-creartgaming/blob/main/personal%20log/onderzoek/Onderzoeks_opdracht.md
- onderzoek

