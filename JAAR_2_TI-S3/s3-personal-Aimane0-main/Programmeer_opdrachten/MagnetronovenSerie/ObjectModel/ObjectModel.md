## Object Model

Hier te vinden:
https://github.com/2024-TICT-TV2SE3-24/s3-personal-Aimane0/blob/main/Programmeer_opdrachten/MagnetronovenSerie/ObjectModel/ObjectModel.svg

## Objecten lijst

| Object Naam | Stereotype | Beschrijving |
| --- | --- | --- |
| instelControl | Control | "Dirigent" van use case "Instellen" |
| kookControl | Control | "Dirigent" van use case "Koken" | 
| deurSensor | Boundary | Geeft aan of de deur open of dicht is |
| display | Boundary | Toont berichten en timers |
| minKnop | Boundary | Onderdeel van de tiptoetsen verlaagt een getal in een aangegeven eenheid |
| plusKnop | Boundary | Onderdeel van de tiptoetsen verhoogt een getal in een aangegeven eenheid |
| instelKnop | Boundary | Een knop om keuzes mee af te sluiten |
| magnetronStraler | Boundary | Straling waarmee eten wordt opgewarmd, voert een aantal wattage uit |
| speaker | Boundary | Maakt een geluid wanneer het koken klaar is |

## Taakstructurering

| Object | Taaksoort | Periode | Deadline | Prioriteit
| --- | --- | --- | --- | --- |
| instelControl | Demand Driven | - | 30ms | 1 |
| kookControl | Demand Driven | - | 30ms | 2 |
| deurSensor | Periodical | 80ms | 80ms | 7 |
| display | Demand Driven | - | 100ms | 9 |
| instelKnop | Periodical | 60ms | 60ms | 3 |
| plusKnop | Periodical | 60ms | 60ms | 4 |
| minKnop | Periodical | 60ms | 60ms | 5 |
| magnetronStraler | Periodical | 100ms | 100ms | 8 |
| speaker | Periodical | 70ms | 70ms | 6 |

## Taken samenvoegen

| Taak | Objecten | Taaksoort | Periode | Deadline | Prioriteit |
| --- | --- | --- | --- | --- | --- |
| InstelTaak | instelControl | Demand Driven | - | 30ms | 1 |
| KookTaak | kookControl | Demand Driven | - | 30ms | 2 |
| DeurTaak | deurSensor | Periodical | 80ms | 80ms | 5 |
| DisplayTaak | display | Demand Driven | - | 100ms | 7 |
| KnopTaak | buttonHandler<br>instelKnop<br>plusKnop<br>minKnop<br> | Periodical | 60ms | 60ms | 3 |
| StralerTaak | magnetronStraler | Periodical | 100ms | 100ms | 6 |
| SpeakerTaak | speaker | Periodical | 70ms | 70ms | 4 |
