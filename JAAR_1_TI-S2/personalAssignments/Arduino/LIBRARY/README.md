CODE CAN BE FOUND IN BME280_library_CPP/BME280_LIBRARY

LIBRARY FOR THE BME280\
DIGITAL HUMIDITY, PRESSURE AND TEMPERATURE SENSOR\
WRITEN BY AIMANE CHAKIRI\
LIBRARY BASED ON BOSCH BME280 DATASHEET\
LINK TO THE DATASHEET: https://www.mouser.com/datasheet/2/783/BST-BME280-DS002-1509607.pdf\

## FEEDBACK Hagen:

Oppassen met te veel code het zelfde hebben:
- Duplicatie vermijden
- Neemt ruimte op in microcontroller
- Als iemand code wilt aanpassen moet die dat op meerdere plekken doen en kan dat over het hoofd zien

Niet te veel print statements forceren in je geschreven functies:
- Print statements schrijven in je functies kunnen kut zijn
  Als iemand bijvoorbeeld op een LCD scherm iets wilt tonen heb je niks aan een Serial.print!
  Zorg er dus voor dat je functies zo min mogelijk printen en gewoon iets returnen
  
## FEEDBACK Tobias:

- Struct met een hoofdletter, geeft duidelijk aan dat het een datatype is in plaats van variabel
- Functie namen aanpassen, gebruik bijvoorbeeld get of read request etc in plaats van writeTemperature, denk vanuit de gebruiker en niet vanuit het programma
- Als je wat returned, zorg er voor dat de functie naam past bij wat je returned dus bijvoorbeeld getCalibratedTemperature of CalculateCalibratedTemperature
  Een draw is een command en heeft geen get of request nodig, als je wat returned gebruik dus termen zoals get om te tonen dat er iets gereturned wordt

- Maak een Struct die temperatuur, humidity en pressure ontvangt van een functie die een struct returned
  Zo kunnen de ''write'' functies die ik naar get ga vernoemen de nodige data opvragen van de struct
  WAnt een functie die temp humi en press opvraagt kan alle 3 indiviudeel returnen

- begintransmission maak daar een  functie van waarin je een variabel kunt mee geven, die variabel is de register waarnaar je schrijft

- select and write functie voor bijvoorbeeld de setSettings functie, want daar hoef ik niks te requesten

- zoveel mogelijk code duplication voorkomen, want dan is het meer leesbaar en de kans dat dingen fout gaan is dan ook kleiner
