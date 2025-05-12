*Wat ga ik maken:*

Ik ga een library schrijven voor de BME280, we hebben al een warmte sensor maar deze gaan we gebruiken om de luchtvochtigheid te meten.

De toepassing van deze chip is als volgt: de chip zal aangeven wat de luchtvochtigheid is binnen de kas. Indien deze te hoog of te laag is zal er een melding weergeven worden op een dashboard.
Via deze dashboard kunnen instellingen aangepast worden en kan data over de kas gezien worden.
De instellingen die aangepast kunnen worden is de minimale en maximale luchtvochtigheid die je wilt hebben in de kas.
De data die de chip zal weergeven is wat de luchtvochtigheid is en of die niet onder het minimale of boven het maximale uit stijgt.

*Planning:*
1: Twee dagen om de datasheet door te nemen en nodige informatie voor de library te noteren.
2: Vijf dagen om een minimale versie van de library te schrijven in C++. Bij houden van gedachtegang en waar ik mijn werk op baseer vanuit de datasheet.
3: Vijf dagen om een minimale applicatie te schrijven om de instellingen via een dashboard aan te passen of data in te kunnen zien. Zo kan iemand de instellingen van de chip aanpassen zonder de code aan te passen.
4: Het schrijven van commentaar bij de library die ik heb gemaakt.
5: Huidige versie inleveren en de docenten vragen om de nodige feedback.
6: In de tussen tijd verbeteringen maken en de library en applicatie afstemmen op het werk van groepsgenoten.

*Fall back plan:*

1: Als dit misschien te weinig is overweeg ik het ook om een kleine library extra te schrijven voor de makkelijke lichtsensoren.
2: Als het niet lukt de datasheet goed door te nemen kan ik de hulp van klasgenoten inschakelen.
3: Als het schrijven van de library niet lukt kan ik altijd een makkelijkere chip kiezen om aan te werken.
4: Als het maken van een applicatie niet lukt kan ik de hulp van klasgenoten inschakelen. Op dit moment kan ik niet een andere chip gaan uitkiezen, want ik heb stap 2 al af. Het zou zonden zijn om dan weer helemaal opnieuw te beginnen.

*Benodigheden:*

Voor het werken aan deze library heb ik de BME280 nodig, want ik heb de BMP280.
Ik zou een si7021 kunnen gebruiken als backup. 
Mogelijk zou ik voor de applicatie een led schermpje kunnen gebruiken om samen met het dashboard te functioneren.

