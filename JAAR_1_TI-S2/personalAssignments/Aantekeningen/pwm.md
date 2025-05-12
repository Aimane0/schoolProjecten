Voorbeeld van PWM

Als de PWM een 0% duty cycle heeft, dan staat bijvoorbeeld de ventilator van je PC uit.
Op 100% draait die volle toeren.

PWM stuurt namelijk signalen die gedeeltelijke hoog en laag zijn.

Elk signaal is even lang, hoeveel % hoog of laag is geeft aan hoe hard bijvoorbeeld een ventilator moet draaien.

Digitaal is beter als je lange kabels hebt over lange afstanden.
In het geval van analoog kun je namelijk spanning verliezen over een hele lange kabel. Kabels hebben een weerstand waar je weinig van merkt als die kabels kort zijn, maar bij lange kabels kan de weerstand zoveel worden dat de analoge verbinding spanning verliest.

ARDUINO!:

Als er een '~' voor het getal staat van een port in de arduino is dit een digitale port waarmee je PWM kunt gebruiken!

De arduino moet als je code schrijft voor de duty cycle vanaf 0 tot en met 255 gebruiken.
0 staat natuurlijk voor 0%
255 staat natuurlijk voor 100%
