## Lijst van objecten
| Object Naam   | Stereotype | Beschrijving                                                    |
| ------------- | ---------- | --------------------------------------------------------------- |
| ToFSensor | Boundary    | Een afstandmeter die gebruikt wordt als "tripwire" |
| IRBeacaon | Boundary | Infrarood systeem dat gebruikt wordt voor de herkenning van personen |
| ESP32Start       | Control   | Bestuurt de ToFSensor en IRBeacon aan het begin van het systeem |
| ESP32End | Control | Bestuurt de ToFSensor en IRBeacon aan het einde van het systeem |
| RaspberryPiDatabase | Boundary | Een minicomputer waarop een lokale MongoDB database staat |

## Taaksoorten en deadlines
| Object Naam   | Taaksoort     | Periode | Deadline | Prioriteit |
| ------------- | ------------- | ------- | -------- | ---------- |
| TripwireDetectie | Periodiek | 100ms | 100ms | 1 |
| IRHerkenning | Periodiek | 100ms | 100ms | 2 |
| SnelheidBerekening | Demand driven | - | 200ms | 3 |
| VersturenNaarDatabase | Demand driven | - | 1000ms | 4 |

## Taken samenvoegen
| Taak Naam  | Object Naam                            | Taaksoort     | Periode | Deadline | Prioriteit |
| ---------- | -------------------------------------- | ------------- | ------- | -------- | ---------- |
| HerkenningTaak | TripwireDetectie, IRHerkenning | Periodiek | 100ms | 100ms | 1 |
| SnelheidBerekening | Snelheidberekening | Demand driven | - | 200ms | 2 |
| VersturenNaarDatabase | VersturenNaarDatabase | Demand driven | - | 1000ms | 3 |
