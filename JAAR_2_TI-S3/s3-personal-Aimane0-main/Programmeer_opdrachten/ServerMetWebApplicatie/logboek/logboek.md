## Opzetten van WSL en Ubuntu op mijn persoonlijke laptop

Tags:
[problemen]
[troubleshooting]

- Via MS store Ubuntu 24.04.5 LTS gedownload
- Vervolgens heb ik WSL gedownload via powershell door command "wsl --install"

- Wanneer ik de Ubuntu app probeer te openen krijg ik de volgende error:
![alt text](image.png) [problemen]

- Om dit te fixen moest ik volgens Lisa het volgende doen, windows subsystem for linux aanvinken bij "Turn Windows features on or off"
![alt text](image-1.png) [troubleshooting]

- Nu dat de Ubuntu app geopend is kan ik een UNIX username invoeren ik ben gegaan voor "aimane", want username AimaneLinux mocht niet en het wachtwoord "123456"

- Nu dat ik een user heb ga ik verder met het gebruik van WSL, ik voer "wsl --export Ubuntu-22.04 ubuntu-22_04.tar" uit
![alt text](image-2.png)

- Ik was vergeten de directory waarin ik in PowerShell aan het werken was aan te passen! Hierdoor heb ik de tar aangemaakt in system32. Note to self; cd naar de juiste dir toe!
![alt text](image-3.png) [problemen]

- Ik knip het tar document en verplaats het naar mijn C:\WSL folder

- Met PowerShell doe ik nu (wsl --import U2204_RollatorNavigatie "C:\WSL\Ubuntu-22_04" "C:\WSL\ubuntu-22_04.tar") ik heb besloten de naam RollatorNavigatie te behouden om deze installatie simpel te behouden.

- Het was succesvol! 
![alt text](image-4.png)
![alt text](image-5.png)

- De machine is correct toegevoegd!
![alt text](image-6.png)

- Ook is het gelukt een prompt te openen met wsl -d U2204_RollatorNavigatie
![alt text](image-7.png)
![alt text](image-8.png)

- Het is vervolgens gelukt docker te verkrijgen
![alt text](image-9.png)

- Vervolgens voer ik de volgende stap uit;
![alt text](image-10.png)

- ![alt text](image-11.png)

- Vervolgens voer ik het volgende uit 
![alt text](image-12.png)

- Vervolgens voer ik sudo apt update en sudo apt upgrade uit!
![alt text](image-13.png)

- Vervolgens installeren we Python op de Linux distru

- Vervolgens clone it WebApp Gomoku in docker/RollatorNavigatie ![alt text](image-14.png)

- Vervolgens voer ik docker-compose up --build -d uit
![alt text](image-15.png)

- Vervolgens kan ik met docker ps de status zien, zowel de mongo database als de gomoku zijn draaiende
![alt text](image-16.png)

- ook probeer ik docker logs uit 
![alt text](image-17.png)

- Ik ga de docker stoppen en het met een clean slate opnieuw opstarten
![alt text](image-18.png)

- Vervolgens check ik de localhost!
![alt text](image-19.png)

- Ik krijg het volgende probleem als ik probeer te connecten met de database via mongodb desktop [problemen]
![alt text](image-20.png)

- Ik zoek de foutcode op om het te fixen [troubleshooting]

- volgens docker ps blijkt de database aan te staan
![alt text](image-21.png)

- De fout is dat ik de localhost open via http://localhost:27017 en niet 27018
[troubleshooting]

- Ik krijg geen informatie binnen en heb de volgende foutmelding [problemen] ![alt text](image-22.png)

- Volgens het internet is dit te fixen door de connectie aan te maken met mongodb://username:password@localhost:27018 [troubleshooting]

- Het is gelukt! Ik kan de gegevens van de database inzien!
![alt text](image-23.png)
