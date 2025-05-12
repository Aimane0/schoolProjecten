# REQUIREMENTS - PLANT AARDVOCHTIGHEID REGULATIE

In dit document worden de user en functionele requirements van de plant aardvochtigheid regulatie in de planten kas beschreven.

## User requirements
- **Geautomatiseerd plant aardvochtigheid regulatie:** De gebruikers moeten in staat zijn om de temperatuur op gewenst niveau in te stellen in de kas.

- **Aanpasbare instellingen:** De gebruiker moet de instellingen van het systeem kunnen aanpassen.

- **Gebruikersvriendelijk:** Het systeem moet een duidelijke en makkelijk te gebruiken dashboard hebben.

- **Constante functioneren van het systeem:** Het systeem moet nadat de instellingen gekozen zijn door de gebruiker ten alle tijden draaiende zijn.

## Functionele requirements
### **Geautomatiseerd plant aardvochtigheid regulatie:**
F01 | Geautomatiseerd plant aardvochtigheid regulatie
--- | ---
Omschrijving | Het systeem moet de gebruiker in staat stellen om de plant aardvochtigheid regulatie op te zetten.
Rationale | De gebruiker moet met minimale inspanning de aardvochtigheid van de plant kunnen reguleren om het naar wensen van de plant te kunnen vormen.
Business priority | Must have

F02 | Aardvochtigheid regulatie component
--- | ---
Omschrijving | Het systeem maakt gebruik van één component, een moisture sensor V2.0.
Rationale | De moisture sensor is nodig om de vochtigheid van de plant te meten.
Business priority | Must have

F03 | Watertoevoer melding
--- | ---
Omschrijving | Het systeem meldt aan de gebruiker wanneer de plant water moet krijgen.
Rationale | De gebruiker ziet op het dashboard wanneer de plant water nodig heeft zodat de plant water kan krijgen van de gebruiker.
Business priority | Must have

F04 | Geautomatiseerd watertoevoer systeem.
--- | ---
Omschrijving | Het systeem geeft de plant automatisch water wanneer de plant water nodig heeft.
Rationale | Op basis van de door de gebruiker ingevulde gegevens en de moisture sensor V2.0 krijgt de plant water toegediend. Zo hoeft de gebruiker zich niet fysiek in te spannen om de plant te bewateren.
Business priority | Should have

--- 

### **Aanpasbare instellingen:**
F05 | Aanpasbare instellingen
--- | ---
Omschrijving | De aardvochtigheid regulatie moet aanpasbaar zijn via een dashboard. De instellingen zijn: De maximale aardvochtigheid en de minimale aardvochtigheid.
Rationale | De gebruiker moet een dashboard kunnen gebruiken waarin de benodigde waardes ivm vochtigheid van de aarde in te stellen zijn op basis van de gewenste aardvochtigheid van de plant/planten. 
Business priority | Must have

---

### **Gebruikersvriendelijk:**
F06 | Makkelijke navigatie van het dashboard
--- | ---
Omschrijving | Het aardvochtigheid regulatiesysteem moet een dashboard hebben dat eenvoudig en duidelijk te navigeren is.
Rationale | De gebruiker moet gevoelsmatig en eenvoudig het dashboard kunnen gebruiken en begrijpen. Zo moet de navigatie niet te complex zijn. Een paar opties om de instellingen aan te passen en gegevens op te vragen van de kas zou genoeg moeten zijn. Zo blijft het dashboard eenvoudig en minimaal.
Business priority | Should have

F07 | Aardvochtigheid regulatie gemakkelijk instellen
--- | ---
Omschrijving | Het aardvochtigheid regulatiesysteem moet makkelijk in te stellen zijn voor de gebruiker.
Rationale | De gebruiker moet via het dashboard makkelijk de aardvochtigheid regulatiesysteem instellen en aanpassen. Dit zou gelieve moeten kunnen met één of twee muiskliks en het invoeren van een getal.
Business priority | Must have

F08 | Aardvochtigheid in de kas
--- | ---
Omschrijving | Het systeem moet op het dashboard kunnen tonen wat de aardvochtigheid van de plant is.
Rationale | De gebruiker moet via het dashboard kunnen zien wat de aardvochtigheid van de plant in de kas is, zo kan de gebruiker ingrijpen als er toch wat mankeert aan de kas.
Business priority | Should have

---

### **Constante functioneren van het systeem**

F09 | Functioneren van componenten
--- | ---
Omschrijving | Het systeem moet nadat de gebruiker de instellingen heeft ingevoerd draaiende blijven. Componenten moeten ten alle tijden werken.
Rationale | De gebruiker moet kunnen vertrouwen en weten dat na het invoeren van instellingen dat de componenten zich zelf aansturen op basis van de instellingen van de gebruiker. 
Business priority | Must have

F10 | Waarschuwingen en meldingen
--- | ---
Omschrijving | Het systeem moet de gebruiker meldingen geven als componenten niet functioneren zoals die horen te functioneren of wanneer de aardvochtigheid van de plant te hoog of te laag is.
Rationale | De gebruiker moet kunnen zien wanneer componenten niet functioneren zoals die horen te functioneren of wanneer de aarde van de plant te droog of vochtig is. Dit is van belang zodat de gebruiker kan aangeven dat er wat mankeert aan het systeem.
Business priority | Should have
