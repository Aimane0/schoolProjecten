#Vraagt naar naam van NS klant

while True:
    naam = input('Welkom! Wat is uw naam? ')
    naam = naam.strip()
    naam = naam.title()

    # If statement die geen antwoord veranderd naar naar anoniem
    if naam == '':
        naam = 'Anoniem'
        print('Hallo en welkom!')

    # Mogelijkheid om de zuil te stoppen
    elif naam == 'Stop':
        break
    else:
        print('Hallo' + ' ' + (naam) + ' en welkom!')

    # Vraagt naar opmerking
    bericht = input('Wat wilt u delen over de NS? Dit kan een compliment zijn of feedback! ')
    bericht = bericht.strip()

    # While loop die een foutmelding geeft en opnieuw vraagt naar input
    while len(bericht) == 0 or len(bericht) >= 140:
        print('U heeft geen antwoord ingevoerd, of uw antwoord is te lang. Voer alstublieft een nieuw antwoord in!')
        bericht = input('Wat wilt u delen over de NS? Dit kan een compliment zijn of feedback! ')

    # Random stad kiezen
    import random
    stad_lijst = ['Utrecht', 'Oss', 'Nijmegen', 'Gouda', 'Groningen', 'Zwolle', 'Hilversum', 'Den Haag', 'Den Bosch', 'Maastricht', 'Amsterdam']
    stad = random.choice(stad_lijst)

    # Station_id dictonary, om het station_ID in te voeren
    id_per_stad = {
        'Utrecht': 1,
        'Oss': 2,
        'Nijmegen': 3,
        'Gouda': 4,
        'Groningen': 5,
        'Zwolle': 6,
        'Hilversum': 7,
        'Den Haag': 8,
        'Den Bosch': 9,
        'Maastricht': 10,
        'Amsterdam': 11
    }
    station_id = id_per_stad[stad]

    # Live datum en tijd van het bericht
    from datetime import datetime
    tijd = datetime.now()
    tijd = tijd.replace(microsecond=0)

    # Schrijft de informatie op in een txt
    file = open("opmerkingen.txt","a")
    file.write(naam + ' / ' + bericht + ' ' + str(tijd) + ' ' + '/ ' + stad + 'Niet gecontroleerd' + "\n")
    file.close()

    # CSV uitvoering
    import csv
    header = ['Naam' , 'Bericht' , 'Stad' , 'Tijd', 'Status', 'Station ID', 'Tijd en datum moderatie', 'Moderator ID']
    data = [naam, bericht, tijd, stad, 'Niet gecontroleerd', station_id, 'Not set', 'Not set']
    with open('database_opmerkingen.csv', mode='a', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(data)
        file.close()

    print('Bedankt voor uw bericht! Wij wensen u nog een hele fijne dag!\n')