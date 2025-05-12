## Object Model

Hier te vinden:
[link](https://github.com/2024-TICT-TV2SE3-24/s3-personal-Aimane0/blob/main/Programmeer_opdrachten/Broodrooster/ObjectModel/ObjectModel.svg)

## Objecten lijst
| Object Naam | Stereotype | Beschrijving |
| --- | --- | --- |
| BruinteInstellen | Control | "Dirigent" van use case bruinte instellen |
| BroodRoosteren | Control | "Dirigent" van use case brood roosteren |
| Display | Boundary | Huidige gewenste bruinte wordt hier op getoond |
| UpKnop | Boundary | Verhogen van de gewenste bruinte |
| DownKnop | Boundary | Verlagen van de gewenste bruinte |
| Handel | Boundary | Wordt naar beneden getrokken om het brood te verlagen |
| Solenoid | Boundary | Blokkeert de gespannen veer |
| Lichtsensor | Boundary | Detecteerd het brood en de bruinte van het brood |
| VerwarmingsElement | Boundary | Verwarmt het brood |
| Speaker | Boundary | Maakt een ping geluid wanneer het proces voorbij is |

## Taakstructurering

| Object | Taaksoort | Periode | Deadline | Prioriteit
| --- | --- | --- | --- | --- |
| BruinteInstellen | Intern, Demand Driven | - | 30ms | 1 |
| BroodRoosteren | Intern Demand Driven | - | 30ms | 2 |
| Display | IO, Demand Driven | - | 100ms | 7 |
| UpKnop | IO, Periodical | 60ms | 60ms | 3 |
| DownKnop | IO, Periodical | 60ms | 60ms | 4 |
| Handel | IO, Periodical | 150ms | 150ms | 8 | 
| Lichtsensor | IO, Periodical | 100ms | 100ms | 5 |
| Solenoid | IO, Demand Driven | - | 200ms | 9 |
| Speaker | IO, Demand Driven | - | 200ms | 10 |
| VerwarmingsElement | IO, Demand Driven | - | 100ms | 6 |


## Taken samenvoegen

| Taak | Objecten | Taaksoort | Periode | Deadline | Prioriteit |
| --- | --- | --- | --- | --- | --- |
| BruinteTaak | BruinteInstellen | Intern, Demand Driven | - | 30ms | 1 |
| RoosterTaak | BroodRoosteren | Intern, Demand Driven | - | 30ms | 2 |
| KnopTaak | ButtonHandler, UpKnop, DownKnop | IO, Periodical | 60ms | 60ms | 3 |
| DisplayTaak | Display | IO, Demand Driven | - | 100ms | 6 | 
| HandelTaak | Handel | IO, Periodical |150ms | 150ms | 7 | 
| LichtsensorTaak | Lichtsensor | IO, Periodical | 100ms | 100ms | 5 |
| UitschietTaak | Solenoid | IO, Demand Driven | - | 200ms | 8 |
| GeluidsTaak | Speaker | IO, Demand Driven | - | 200ms | 9 |
| VerwarmingsTaak | Verwarmingselement | IO, Demand Driven | - | 100ms | 4 |

