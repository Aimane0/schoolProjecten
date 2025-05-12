OBJECT MODEL: https://github.com/2024-TICT-TV2SE3-24/s3-personal-Aimane0/blob/main/Project_persoonlijke_werk/Business_documentatie/Object_model/NS_opdracht/NS_ObjectModel_1.svg

| Naam | Stereotype | Beschrijving
| --- | --- | ---
| **Trein** | Entity | Is het voertuig dat rijdt
| **SnelheidsRegulatie** | Control | Regelt de snelheid
| **Lampjes** | Boundary | Geeft een waarschuwing gebaseerd op de snelheid
| **RegionaleTreinVerkeersRegelCentrum** | Entity | Heeft de snelheden die per spoor gereden mogen worden
| **Schuif** | Boundary | Mechanisme waarmee de snelheid wordt bepaald
| **Machinist** | Boundary | Bestuurt de voertuig
| **MachinistDisplay** | Boundary | Toont de situatie op het spoor
| **Noodrem** | Boundary | Brengt het voertuig snelheid zsm naar 0
| **NoodremRegelaar** | Controle | Zorgt voor veiligheid en waarschuwingen
| **BlackBox** | Entity | Slaat op hoevaak en waar de noodrem is gebruikt
| **Obstakel-sensor** | Boundary | Scant wat er op het spoor zit
| **CentraleTreinVerkeersRegelStation** | Entity | Communiceert gevaarlijke situaties
