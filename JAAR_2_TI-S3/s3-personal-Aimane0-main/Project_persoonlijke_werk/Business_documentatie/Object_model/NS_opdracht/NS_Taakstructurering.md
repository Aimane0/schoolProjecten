## Taakstructurering


| Naam | Taaksoort | Periode | Deadline | Prioriteit
| --- | --- | --- | --- | ---
| **Trein** | Demand driven | - | 2500ms | 8
| **SnelheidsRegulatie** | Periodiek | 100ms | 100ms | 3
| **Lampjes** | Periodiek | 200ms | 200ms | 4
| **RegionaleTreinVerkeersRegelCentrum** | - | - | - | -
| **Schuif** | Demand driven | - | 200ms | 5
| **Machinist** | Demand driven | - | 2000ms | 7
| **MachinistDisplay** | Demand driven | - | 400ms | 6
| **Noodrem** | Demand driven | -
| **NoodremRegelaar** | Periodical | 100ms | 100ms | 1
| **BlackBox** | Demand driven | - | - | -
| **Obstakel-sensor** | Periodical | 100ms | 100ms | 2
| **CentraleTreinVerkeersRegelStation** | - | - | - | -

## Samenvoeging
- Lampjes, schuif en trein voegen we samen vanwege hun controle cohesie, dit noemen we __snelheidsTaak.__

- Ik voeg de Machinist en MachinistDisplay ook samen tot __MachinistenTaak.__

- Ik voeg de regelcentrums bij elkaar tot een __VerkeersRegelStationTaak.__