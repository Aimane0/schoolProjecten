## TAAKSTRUCTURERING BLADZIJDE 23
    - Zodra je objecten hebt moet elk object een taaksoorten worden toegekend.
    
    1: IO = input output, taken van boundary objecten
        - periodical; met vaste intervallen
        - event driven; gedaan na hardware interrupt komt verder niet voor in deze cursus
        - demand driven: gaat pas iets doen als er bericht binnenkomt
    
    2: Intern = taken van overige objecten
        - Periodical; vaste intervallen
        - demand driven; doet pas als er een bericht binnenkomt

    3: Geen taak = Soms heeft een object geen eigen taak bijvoorbeeld als het gene wat het doet instantaan is. 

    - Taakstructurerings‐tabel
        - Periode = regelmaat in actie
        - Deadline = tijd die een object krijgt zijn ding te doen
        - Prioriteit = des te korter de deadline, des te hoger de prioriteit
    
    -Vuistregel: kies een periodetijd die gelijk is aan de deadline. Dan is de taak binnen een periode
    afgehandeld. NB: de worst case tijd van afhandeling is de som van periodetijd en deadline.  
    
## KLASSEDIAGRAMMEN BLADZIJDE 31
- Klassediagram wordt in de volgende stappen opgesteld
    - Maak een kopie van het object model, alle objecten worden klassen

    - Elk bericht dat ergens heen gaat wordt bij zijn ontvanger een publieke functie

    - Dubbele pijlen zijn dubbelop en mogen weg

    - Representeer gelijksoortige objecten door een enkele klasse

    - Je moet compositie pijlen gebruiken, om aan te geven wat een klasse bevat. Een class human heeft bijvoorbeeld members zoals klasse heart and lungs. De ene classe is onderdeel van de andere

    - Pijlen die geen compositie relatie tonen betekenen alleen nog "kennen" voeg voor elk object dat een klasse "kent" een private member reference toe

    - Markeer klassen met een taak <<isActive>>

    - extra Handler klassen 

## STDs 

### STD ontwerpen
    - STDs zijn toestandsdiagrammen

    - Dat zijn de control objecten, maar ook veel boundary objecten die periodieke taken verrichten

    - Hoe kom je vanuit een klassediagram tot de STDs?
        - Maak interface sectie 
        - Schrijf in woorden de reeks acties en beslissingen
        - Zet de beschrijving om in een STD

    - Ergens op wachten maak je een event van langs de uitgaande pijl
        - Bijvoorbeeld als je wacht tot de “aan‐knop” is ingedrukt, maak dan een __toestand__ met
        de naam “uit”, en verlaat die via een uitgaande pijl met de event “flagAanButton”.

    - Wanneer zijn er actions die plaats vinden? Uitvoering tijdens een overgang, verandering in het systeem of actie gekoppeld aan een gebeurtenis. Gebeurt in een split second kost geen tijd.

    - Verwerk beslissingen met guard en decision nodes.

    - Voorkom duplicate actions en guards

    - Samengestelde teostand (composite state) als het gedrag uit meerdere lagen bestaat

### Ontwerp van de STD interface
    - Vuistregels voor het maken van de STD interface 
        - Voeg elke publieke functie toe aan de STD onder te verdelen in;
            - Functies die even snel een waarde opvragen (Pool)

            - Functies zonder argument (Flag)

            - Functies met argument 
                - Als alleen laatste binnengekomen waarde ertoe doet (pool en of flag)
                - Als het belangrijk is dat geen voorgaande waarde misloopt (channel)