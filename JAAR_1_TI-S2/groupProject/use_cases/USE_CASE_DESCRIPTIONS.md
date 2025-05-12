# USE CASE BESCHRIJVINGEN
<br>

### UC01 Temperatuur systeem

NAAM: | Temperatuur reguleren
--- | ---
*Doel* |  De temperatuur in de kas meten en reguleren |
*Pre-condities* | - Het systeem moet temperatuur waardes binnen krijgen<br>- Een maximum temperatuur<br>- Een minimum temperatuur<br> |
*Scenario* |SCENARIO 1: Temperatuur bereikt maximum<br>1: De sensor meet hoger dan de maximale temperatuur<br>2: De ventilator gaat om de kas af te koelen<br>3: De temperatuur blijf zakken naar de minimum temperatuur<br><br>SCENARIO 2: Minimum temperatuur<br>1: De temperatuur zakt naar de minimum temperatuur<br>2: De ventilator gaat uit|
*Post-condities* | - De kas wordt afgekoeld met de ventilator en bereikt de minimum temperatuur<br> - De ventilator gaat uit<br> - De kas warmt vanwege de zon weer op| 
*Uitzonderingen* | - | 
---
<br>

### UC02 Luchtvochtigheid systeem

NAAM: | Luchtvochtigheid reguleren
--- | ---
*Doel* |  De luchtvochtigheid in de kas meten en reguleren |
*Pre-condities* | - Het systeem moet luchtvochtigheid waardes binnen krijgen<br>- Een maximum relatieve luchtvochtigheid<br>- Een minimum relatieve luchtvochtigheid<br> |
*Scenario* |SCENARIO 1: Relatieve luchtvochtigheid bereikt maximum<br>1: De sensor meet hoger dan de maximale relatieve luchtvochtigheid<br>2: De kas ramen gaan open om de relatieve luchtvochtigheid te verlagen<br>3: De relatieve luchtvochtigheid blijf zakken naar de minimum relatieve luchtvochtigheid<br><br>SCENARIO 2: Minimum relatieve luchtvochtigheid<br>1: De relatieve luchtvochtigheid zakt naar de minimum relatieve luchtvochtigheid<br>2: De kas ramen gaan dicht|
*Post-condities* | - De kas wordt gelucht door de kas ramen open te doen en bereikt de minimum relatieve luchtvochtigheid<br> - De kas ramen gaan dicht<br> - De relatieve luchtvochtigheid gaat weer omhoog| 
*Uitzonderingen* | - | 
---
<br>

### UC03

NAAM: | Aardvochtigheid reguleren
--- | ---
*Doel* | De vochtigheid van de aarde meten en reguleren |
*Pre-condities* | - Het systeem moet aardvochtigheid waardes binnen krijgen<br>- Een maximum aardvochtigheid<br>- Een minimum aardvochtigheid<br> |
*Scenario* | SCENARIO 1: Aardvochtigheid te laag<br>1: De aardvochtigheid van de plant is te laag<br>2: Het systeem geeft een  waarschuwing zodat de gebruiker weet dat de plant water nodig heeft.|
*Post-condities* | 1: De gebruiker van de kas weet dat de plant water moet krijgen | 
*Uitzonderingen* | - | 
<br>

### UC04

NAAM: | Geluidssysteem
--- | ---
*Doel* | Het vermaken van de kas medewerkers |
*Pre-condities* | 1: De radio moet aangesloten zijn op stroom<br>2: Er moet een muziek box zijn die een AUX aansluiting heeft |
*Scenario* | 1: Medewerkers stellen de radio in om muziek te luistern<br>2: De radio gaat aan en speelt muziek<br>3: Via een aux aansluiting kan de muziek via een box afgespeeld worden |
*Post-condities* | 1: De medewerkers kunnen muziek horen<br>2: De medewerkers kunnen tevreden aan het werk en muziek luisteren | 
*Uitzonderingen* | - | 
<br>

### UC05

NAAM: | Systeem beheer
--- | ---
*Doel* | Geeft beheerder van de kas de mogelijkheid waardes te bepalen voor de eerder benoemde systemen. |
*Pre-condities* | 1: Een beeldscherm ter gebruik van het systeem beheer<br>2: Een flask applicatie ter dashboard |
*Scenario* | SCENARIO 1: Gebruiker wilt nieuwe waardes invullen<br>1: De gebruiker opent het dashboard<br>2: De gebruiker zoekt het menu om nieuwe waardes in te vullen<br>3: De gebruiker vult nieuwe waardes in<br>4: Het systeem slaat deze nieuwe waardes op en vervangen de oude met de nieuwe<br>SCENARIO 2: Gebruiker wilt de gemeten waardes aflezen<br>1: De gebruiker opent het dashboard<br>2: De gebruiker zoekt het menu om de gemeten waardes af te lezen<br>3: De gebruiker krijgt een dashboard te zien met de gemeten waardes in de kas|
*Post-condities* | 1: De minimale en maximale waardes in de kas zijn aangepast door de gebruiker<br>2: De gemeten waardes van de kas worden getoond op het dashboard | 
*Uitzonderingen* | - | 
