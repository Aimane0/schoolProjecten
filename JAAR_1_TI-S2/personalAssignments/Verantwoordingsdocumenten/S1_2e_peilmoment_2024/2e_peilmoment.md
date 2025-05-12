### Leer uitkomst analyseren
https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/tree/main/use_cases
Hier maken we gezamelijk een use case, waarin we analyseren wat we voor de kas kunnen doen!
Eerst hebben we de use cases gebrainstormed en in een markdown genoteerd, vervolgens een diagram gemaakt en daarna een tabel met de use cases
Dit hebben we ook nog eens gezamelijk als groep naar gekeken en aan gewerkt!
FEEDBACK: Nog geen feedback

https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/tree/main/Aantekeningen
Aantekeningen die ik gebruik om te leren, denk bijvoorbeeld aan mijn GIT.txt aantekening die ik gebruik om te leren hoe ik heel simpel via de commandline met git kan pushen en pullen.
Dit heb ik toevallig recent ook gedaan en is later in het peilmoment terug te vinden.
De git aantekeningen waren een opstapje om git te gebruiken via de commandline, zo ben ik tegen problemen aangelopen die ik heb moeten analyseren om te begrijpen wat er aan de hand is. 
Gelukkig is git heel duidelijk in de fouten die je maakt en hoe je die moet verhelpen.
Dit is terug te zien in de volgende link: https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/blob/main/git/Eerste_merg_en_push/foto_bewijs_1.jpg

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/tree/main/portfolio/UART
Practicum heeft geholpen met leren wat en hoe UART werkt, hierdoor hebben wij als groep de analyse kunnen maken dat dit een benodigheid is voor het project.
UART zorgt namelijk voor data uitwisseling tussen onze Arduinos die sensoren aansturen en de Raspberry Pi die de data van deze sensoren gebruikt voor bijvoorbeeld flask
Uit onze analyse komt de conclusie dat UART nodig is om de data van de sensoren te versturen naar de Raspberry Pi
Ook concluderen wij dat dit nodig is voor de Pi om de Arduinos aan te sturen, dat de Pi bijvoorbeeld de temperatuur van 1 arduino ontvangt en die doorstuurt naar een arduino die de ventilatie doet, die moet de temperatuur weten om te weten of de ventilatie aan moet of niet.


### leer uitkomst ontwerpen
Vanuit mijzelf de BMP280 en one wire gekoppeld op het breadboard!
https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/tree/main/Arduino/BMP280%2BDS18B20_mogelijk
Dit was voor mij een vorm van ontwerpen, omdat ik de voorbeeld codes gecombineerd heb en redudante lijnen aan code verwijderd heb. Ook heb ik een kleine aanpassing gemaakt aan de code, namelijk het verwisselen van bepaalde pins in de code, zodat ik zo min mogelijk hoefte te veranderen tijdens het bouwen van de fysieke opstelling.
Dit ontwerp heb ik uit eigen interesse uitgeprobeerd, omdat ik wilde zien of er een verschil was tussen de metingen van beide warmte sensoren.

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/tree/main/use_cases
Naast het analyseren van de mogelijke use cases moeten we ook een ontwerp creëeren die logisch lijkt. Dit ontwerp beeld zich uit in een use case diagram en bijhorende tabellen waarin bijvoorbeeld stap voor stap beschreven staat hoe een use case gebruikt wordt.
FEEDBACK: gekregen van marius https://github.com/TICT-TV1SE2-2324/personal-progress-lbeetz0/blob/main/Documentatie/Images/Whatsapp-1.png

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/tree/main/portfolio/raspberry_pi_uart
Bewuste keuze gemaakt om MQTT te gebruiken en dat te koppelen met flask om zo de temperatuur te tonen.
Dit in JSON format gedaan op verzoek van Harm zodat het universeel is!


### leer uitkomst Realisatie
https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/tree/main/Arduino/BMP280%2BDS18B20_mogelijk
Heb uiteindelijk het hele simpele ontwerp wat ik gemaakt heb gerealiseerd door te bouwen en uit te voeren.

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/tree/main/portfolio/temp_sensor
We hebben gewerkt met de voorbeeld die 1 sensor gebruikt, vervolgens heeft Harm ons uitgedaagd en gezegd dat we eens moeten proberen om er 2 aan de praat te krijgen in serie.
Als groep hebben we dit gerealiseerd door de sensor te solderen en de voorbeeld code aan te passen zodat er 2 sensoren af te lezen zijn 
FEEDBACK: Voor 1 van de drie kabels had ik geen tin gebruikt, ik dacht dat je de kabels kon vast klemmen aan de pinnen waarin je de kabels kon doen. Harm heeft aangemerkt dat het toch wel verstandig is om met tin te solderen en niet alleen gebruik te maken van de krimp kousen.

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/portfolio/UART/practicum.md
UART Practicum gemaakt! Hiervoor hebben we UART gerealiseerd door 2 arduinos met elkaar te laten communiceren! Ook hebben we een Arduino en Raspberry Pi 4 laten communiceren met elkaar! Het realiseren van UART heeft ons geholpen met begrijpen hoe deze seriele communicatie gebeurt. We hebben dit project samen gemaakt als groepje, dus dit item is ook terug te zien bij samenwerken.

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/tree/main/portfolio/raspberry_pi_uart
We hebben één Arduino die een one wire warmte sensor gebruikt gekoppelt met een raspberry pi. De raspberry pi ontvangt van de Arduino hoeveel graden de one wire warmte sensor meet.
Vervolgens verstuurt de raspberry pi de temperatuur naar onze postgresql database en MQTT. Ook hebben we een flask app die uit MQTT de temperatuur opvraagt.
MQTT slaat de gegevens op als JSON, op die manier is de data universeel te bereiken


### Leer uitkomst samenwerken
https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/tree/main/use_cases
Zoals eerder benoemd, samen met team genoten gewerkt aan de use case!
FEEDBACK: https://github.com/TICT-TV1SE2-2324/personal-progress-lbeetz0/blob/main/Documentatie/Images/Whatsapp-1.png

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/portfolio/UART/practicum.md
Voor dit practicum hebben we samen gewerkt en alle drie tijd en moeite gestoken in onderdelen van het practicum. Met zijn drieeen hebben we ons bekommerd om het begrijpen van de voorbeeld code waarmee de arduinos en pi konden communiceren. Ook hebben we ons gezamelijk bekommerd om het gebruiken van de logic analyser.
Om voorbeeld te geven van hoe we samengewerkt hebben; voor het uitlezen van de logic analyser hebben we de software logic2 gebruikt. Alle drie wisten we niet hoe we het moesten gebruiken dus zaten we met zijn drieeen om de laptop heen en gaven we alle drie suggesties hoe we de software moesten gebruiken om het resultaat te verkrijgen die wij wilden hebben. Zo had Lisa nadat wij het programma werkende kregen gelijk door dat de bytes ascii waren en dat we ze van ascii naar decimaal moesten berekenen.
Lia heeft mij en Lisa geholpen met het navigeren van de Pi, omdat zij geweldige ervaring heeft met het gebruiken van Linux commands.
Ik heb veel werk gestoken in het bouwen van de RX en TX opstellingen. Zo bracht ik met hulp van Marius op dat we de logic analyser konden gebruiken door middel van een breadboard. Zo stak de logic analyser tussen de UART connectie in en konden we de bytes aftappen!

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/tree/main/portfolio/oscilloscope
Samen aan dit practicum gewerkt

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/tree/main/portfolio/raspberry_pi_uart
Samen gewerkt aan flask mqtt postgresql en docker


### Leer uitkomst communiceren
https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/sprint_retro_review/sprint_verslag_3.md
We zijn op basis van feedback van Teun gestart met het noteren van onze daily standups. 
Als groepje deden we al aan daily standups, maar we noteerde deze niet in een markdown.
Vanaf nu proberen we onze daily standups te noteren.
Dit is niet alleen een vorm van communiceren, maar ook samenwerken en plannen.

- 
https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/blob/main/Verantwoordingsdocumenten/communicatie_bewijs/communicatie_7.jpg

https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/blob/main/Verantwoordingsdocumenten/communicatie_bewijs/communicatie_8.jpg

https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/blob/main/Verantwoordingsdocumenten/communicatie_bewijs/communicatie_9.jpg

https://github.com/TICT-TV1SE2-2324/personal-progress-lbeetz0/blob/main/Documentatie/Images/Whatsapp-1.png
We blijven nogsteeds goed communiceren via medium zoals whatsapp en discord, daar delen we relevante fotos met elkaar en houden we elkaar up to date!
Zo had ik laatst bijvoorbeeld perongeluk onze eerste sprint verwijderd en dit aangegeven via whatsapp, Lia had mij toen via whatsapp gebeld en dit hebben we vervolgens samen gefixt!
Ook houden we elkaar up to date wanneer iemand niet kan komen vanwege ziek zijn.
Dit zijn een paar voorbeelden om een beeld te vormen van hoe onze communicatie buiten school om nog steeds goed verloopt en dat we buiten school om elkaar kunnen appen en dergelijke indien dat nodig is!


### Leer uitkomst Reflecteren / Verbeteren / Evalueren
https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/blob/main/Aantekeningen/meerdere_files_compilen.png
Samen met docent, Nick(?), gekeken naar hoe de tasks.json file ingevuld moest worden!
Vervolgens ook een issue verstuurd naar de repo van het semester. 
Issue: https://github.com/HU-TI-DEV/TI-S2/issues/89
FEEDBACK: Van Gera verteld gekregen om issues te maken van problemen in de Git Repo, van Nick verteld gekregen dat de oplossing die ik nu heb voor multiple files niet van toepassing is zou ik meerdere mapjes met meerdere CPP files hebben.

https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/tree/main/solderen/solderen_3
Makkelijker voorwerp gesoldeerd op basis van feedback van Hagen om wat makkelijkers dan de muziekbox te solderen als oefening.
FEEDBACK: Vervolgens nog meer feedback gekregen van Hagen over mijn soldeer werk, mag minder zuinig zijn met het gebruiken van tin, zodat de gaten echt goed dicht zitten en het koper niet te zien is.


https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/blob/main/C%2B%2B_OPDRACHTEN/FEEDBACK/FEEDBACK_GERA_2.jpg
C++ Opdracht 2.12 A en B, Opdracht 3.6 feedback ontvangen van Gera!
Ik heb feedback ontvangen van Gera omtrent mijn gemaakte C++ opdrachten.
Deze feedback heb ik als comments verwerkt in mijn C++ code op github!
In het vorige peilmoment ben ik volgens mij vergeten een screenshot te maken van wat Gera op canvas heeft achtergelaten, daarom heb ik dus nu ook een nieuw mapje aangemaakt bij mijn C++ opdrachten genaamd feedback, waar ik screenshots zal delen van Gera's feedback!
Van deze feedback heb ik zo snel mogelijk werk gemaakt, dit is terug te zien in mijn C++ opdrachten folder:
https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/tree/main/C%2B%2B_OPDRACHTEN
In 2_x zit opdracht 2.12b waar ik de code heb gereduceerd.

https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/tree/main/C%2B%2B_OPDRACHTEN/4_x
Feedback C++ opdrachten gekregen van Gera.
Hier is een screenshot te zien van de feedback die ze heeft achtergelaten!
https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/blob/main/C%2B%2B_OPDRACHTEN/FEEDBACK/FEEDBACK_GERA_3.jpg
Hier wil ik alle feedback 1 voor 1 even doornemen.
Voor 4.2 kreeg ik feedback die ik eerder heb ontvangen, namelijk voortaan mijn code zo proberen te schrijven dat het delen door 0 nooit mogelijk is, anders crashed het programma!
Voor 4.3 heb ik met Gera besproken dat ik met de kennis van nu zoveel mogelijk code in functies zou werken, zodat de main() zo weinig mogelijk code bevat.
En 4.6 zag er goed uit maar zowel Gera als ik vonden het allebei beter om n = -n; in iets anders te veranderen.
Op die manier maak ik van een negatief getal een positief getal.
Er staat dus bijvoorbeeld -1 = -1; waardoor er 1 uit komt.
Ik had beter n = n * -1 kunnen gebruiken of de functie abs, omdat ik dat makkelijker had kunnen begrijpen want tijdens het bespreken van de opdracht merkte ik op dat ik vergeten was waar ik n = -n voor gebruikt heb.
Ik ben hier zeer tevreden mee, want dit feedback moment was zeer positief en er was weinig fouts aan mijn code.
Het is wel weer een bevestiging dat ik moet letten op delen door 0! Maar voor deze en vorige opdracht mocht ik aannemen dat ik niet door 0 hoef te delen.

Van Teun heb ik de volgende feedback ontvangen omtrent documenteren "Dat je niet alles noteert is logisch, maar je wil wel zorgen dat je niets mist natuurlijk. Misschien wel een idee om eens na te denken over hoe je bijvoorbeeld goede ideeën kan vastleggen. Of opmerkingen die je graag nog eens terug wil zien"
Hierom heb ik in mijn persoonlijke repo voor het tweede peilmoment een markdown aangemaakt om te documenteren wat ik later in mijn peilmoment wil verwerken. Als ik bijvoorbeeld in een les iets nieuws heb gedaan of feedback ontvang kan ik dit in de markdown bewaren en later verwerken in het peilmoment.
Een linkje naar de markdown: https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/tree/main/Verantwoordingsdocumenten/S1_2e_peilmoment_2024

https://github.com/TICT-TV1SE2-2324/personal-progress-lbeetz0/blob/main/Documentatie/Images/Whatsapp-1.png
Verkregen van feedback omtrent use case van marius, moet het alleen nog verwerken! al wel een idee wat er beter kan en beter moet.
We hebben alle acties die sensoren uitvoeren als use cases opgeschreven en de controllers zoals arduinos als actors aangemerkt.
Maar de use cases moeten systemen zijn. Warmte meten is geen use case, maar bijvoorbeeld onderdeel van de use case 'temperatuur regulatie'
Het was nog niet helemaal duidelijk, dus willen we even met marius zitten voor duidelijkere feedback.
We hebben een moment gepland om de acties die sensoren uitvoeren samen te voegen in relevante 'systemen'

### Leer uitkomst Testen / Evalueren


### Leer uitkomst plannen
SPRINT 3:
https://github.com/orgs/TICT-TV1SE2-2324/projects/18/views/5
Onze planning van sprint 3 is te zien in deze link.
We hebben het dashboard dit keer anders gemaakt dan we normaal deden.
Na de sprint oefening die we hebben gedaan met Alexander hebben we dit keer de sprint backlog gebruikt om algemene taken te beschrijven zoals 'use cases opstellen' en 'elektronica practica'
Dit zijn de algemene taken die vervolgens in de rest van het dashboard uitgewerkt zijn in kleinere taken.
Elektronica practica bestaat namelijk bijvoorbeeld uit de taken practicum T&S en C&M

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/sprint_retro_review/sprint_verslag_3.md
We zijn op basis van feedback van Teun gestart met het noteren van onze daily standups. 
Als groepje deden we al aan daily standups, maar we noteerde deze niet in een markdown.
Vanaf nu proberen we onze daily standups te noteren.
De daily standup die wij noteren voegt toe aan onze planning. 
Zo plannen wij nieuwe dingen in om te doen op basis van moeilijkheden of problemen die wij tijdens onze daily standup opmerken.

https://github.com/orgs/TICT-TV1SE2-2324/projects/18/views/11
We zijn nog steeds goed op weg met plannen, we beginnen nu ook meer groepsgerelateerde opdrachten te plaatsen en blijven dingen plannen die we nog niet helemaal af hebben. Dit toont dat we nog steeds goed op weg zijn als het gaat om plannen en dat dit niet iets is wat we in de eerste weken gedaan hebben omdat het moest als opdracht van Teun

https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/sprint_retro_review/sprint_verslag_4.md
Niet regelmatig, maar nog steeds bezig met het maken van daily standups, na het inleveren van het peilmoment een verslag schrijven met het groep


### Leer uitkomst Opleveren / Documenteren

- https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/tree/main/git
Oefenen met het opleveren van documenten via de bash van raspberry pi 4

- Deel m'n commit history om aan te geven dat ik actief documenteer en niet maar eens in de zoveel tijd bezig ben met mijn repo.

https://github.com/TICT-TV1SE2-2324/personal-progress-Aimane0/tree/main/Verantwoordingsdocumenten/S1_2e_peilmoment_2024