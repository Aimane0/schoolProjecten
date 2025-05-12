import json
import time

class Kleur: # fancy kleurtjes binnen de code zelf
    Waarschuwing = "\033[93m"
    Standaard = "\033[0m"
    Fout = "\033[91m"
    Goed = "\033[32m"
    Waardes = "\033[96m"
    Dikgedrukt = "\033[1m"
    
def zoek_spel_op_deel_naam(json_bestandsnaam, deel_naam):
    start_tijd = time.time()  # Start de timer 

    # JSON-bestand laden
    with open(json_bestandsnaam, 'r') as json_bestand:
        alle_spellen = json.load(json_bestand)
    
    # Zoek spellen op basis van het deel van de naam in de JSON-alle_spellen
    gevonden_spellen = [spel for spel in alle_spellen if deel_naam.lower() in spel['name'].lower()]
    
    # Controleer of spellen zijn gevonden (ook overzichtelijk gemaakt binnen deze code)
    if gevonden_spellen:
        print("")
        print(f"Spellen met deel van naam '{deel_naam}' gevonden:")
        print("")
        for spel in gevonden_spellen:
            print(f"App ID:{spel['appid']}")
            print(f"Naam:{spel['name']}")
            print(f"Ontwikkelaar:{spel['developer']}")
            print(f"Uitgever:{spel['publisher']}")
            print(f"Prijs:{spel['price']}")
            print(f"Release date:{spel['release_date']}")            
            print("")

        eind_tijd = time.time()  # Stop de timer

        doorlooptijd = eind_tijd - start_tijd # (hoe lang het duurt om de restultaten te weergeven)
        
        print("")
        print(f"{Kleur.Goed}Doorlooptijd: {doorlooptijd:.6f} seconden{Kleur.Standaard}") # De tijd dat het duurt de json file te doorzoeken
        print("")
    else:
        print("")
        print(f"{Kleur.Fout}Geen spellen gevonden met deel van naam '{deel_naam}'. Doorlooptijd: {doorlooptijd:.6f} seconden{Kleur.Standaard}") # Als het gezochte spel niet gevonden kan worden en de tijd dat het duurde
        print("")

while True:
    # De waardes benoemen
    json_bestandsnaam = "steam.json"  # De bestandsnaam
    # deel_naam = "counter-strike: global offensive" # (non input)
    deel_naam = input("Zoek hier uw Game: ") # De input van gebruiker
    zoek_spel_op_deel_naam(json_bestandsnaam, deel_naam) # De gegevens die ingevuld worden in de functie

