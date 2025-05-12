import psycopg2
from psycopg2 import sql
from datetime import datetime
import hashlib
import csv
from getpass import getpass

# Connecten met de postgresql database!
connection = psycopg2.connect(host='40.114.242.236', port='5432', database='project_zuil', user='admin', password='admin')
cursor = connection.cursor()

print('Welkom bij het moderatie systeem van de NS stationzuil!\n')

# Vraagt om een email en een wachtwoord
while True:
    mod_email = input('Let op hoofdletters! Voer uw email in: ')
    mod_wachtwoord = input('Voer uw wachtwoord in: ')
    mod_wachtwoord_bytes = mod_wachtwoord.encode('utf-8')
    hash_ww1 = hashlib.md5(mod_wachtwoord_bytes)
    hash_ww2 = hash_ww1.hexdigest()


# Checken of email en wachtworod(in hash) in database zit
    cursor.execute('SELECT * FROM moderator WHERE email = %s AND wachtwoord = %s', (mod_email, hash_ww2))

    result = cursor.fetchone()

# Klopt het email en wachtworod niet, wijst toegang af vraagt opnieuw om inlog gegevens
    if not result:
        print('Toegang afgewezen, uw email of wachtwoord zijn fout!')
    # Verwelkomt mod, geeft toegang en breakt inlog while loop
    # geeft ook aan wat de mod ID is en slaat die ook op in een variabel voor later
    else:
        print(f'Welkom in het moderatie systeem!')
        moderator_id = result[0]
        print(f'Uw moderatorID is: {moderator_id}')
        break
        cursor.close()


# keuze menu voor moderator
while True:
    print('\nMENU')
    print('1: Alle berichten van het CSV bestand tonen.')
    print('2: Bericht modereren')
    print('3: Goedgekeurde berichten naar de database versturen/uit het CSV bestand verwijderen.')
    print('4: Afgekeurde berichten verwijderen uit het CSV bestand')
    print('5: Stoppen met het moderatie programma')
    keuze = input('Wat wilt u doen: ')
# Uitvoering van keuze menu

    # laat alle berichten zien
    if keuze == '1':
        print('\nHier zijn alle berichten opgeslagen in het CSV document')
        file = open('database_opmerkingen.csv', mode='r', newline='')
        csvgelezen = csv.reader(file)
        for line in csvgelezen:
            print(line)

    # DIT IS MENU KEUZE 2!
    if keuze == '2':
        # Openen van het CSV document
        file = open('database_opmerkingen.csv', mode='r+')
        csvgelezen = csv.reader(file)
        data = list(csvgelezen)

        # elke line 1 voor 1 bekijken, in data is alles opgeslagen als een list in 1 grotere list
        for rijen in data:
            # alleen het oproepen van berichten met status 'Niet gecontroleerd'
            if rijen[4] == 'Niet gecontroleerd':


                # Tijd aan een variabel binden
                time = datetime.now()
                time = time.replace(microsecond=0)

                # vraagt mod om input van status, ook wordt het bericht dat gemod moet worden getoond
                moderatie_status = input(f'Voer een moderatie beoordeling in (Goedgekeurd of Afgekeurd, let op hoofdletters) van:\n{rijen[0]}: {rijen[1]}\n')

                # aanpassen van data in csv document
                if moderatie_status not in ['Goedgekeurd', 'Afgekeurd']:
                    print('Foutieve beoordeling, let op spelling en hoofdletters')
                else:
                    rijen[4] = moderatie_status
                    rijen[6] = str(time)
                    rijen[7] = str(moderator_id)

        # opnieuw openen van csv document, zodat er in geschreven kan worden
        with open('database_opmerkingen.csv', mode='w', newline='') as file_schrijven:
            csvschrijver = csv.writer(file_schrijven)
            csvschrijver.writerows(data)

    # DIT IS MENU KEUZE 3!
    if keuze == '3':
        with open('database_opmerkingen.csv', mode='r', newline='') as file:
            csvgelezen = csv.reader(file)
            # de goedgekeurde berichten isoleren
            for rijen in csvgelezen:
                if rijen[4] == 'Goedgekeurd':
                    # De berichten met status = 'Goedgekeurd' worden in een query verwerkt en opgestuurd naar de database
                    cursor.execute(
                        """
                        INSERT INTO bericht (naam, ingezonden_bericht, datum_en_tijd, stad, status, station_id, tijd_en_datum_moderatie, moderator_id)
                        VALUES (%s, %s, %s, %s, %s, %s, %s, %s)
                        """,
                        (rijen[0], rijen[1], rijen[2], rijen[3], rijen[4], rijen[5], rijen[6], rijen[7])
                        )
            # het committen van de query
            connection.commit()

        # Opnieuw lezen van de database, NADAT de query is uitgevoerd
        with open('database_opmerkingen.csv', mode='r', newline='') as file2:
            csvgelezen2 = csv.reader(file2)

            # maken van een lege list die gebruikt gaat worden om te schrijven in het csv document
            nieuwe_csv_zonder_opgestuurd = []

            # Het isoleren van alle berichten die niet goedgekeurd hebben als status
            for rij in csvgelezen2:
                if rij[4] != 'Goedgekeurd':
                    # deze worden in de list geschreven, zodat ze in het CSV document geschreven kunnen worden
                    nieuwe_csv_zonder_opgestuurd.append(rij)

        # Opnieuw schrijven van het CSV document, alles word er opnieuw ingeschreven, behalve goedgekeurde berichten
        with open('database_opmerkingen.csv', mode='w', newline='') as file_schrijver:
            csvschrijver2 = csv.writer(file_schrijver)
            csvschrijver2.writerows(nieuwe_csv_zonder_opgestuurd)


    # verwijdert alle rijen waar status gelijk staat aan afgekeurd
    if keuze == '4':
        # opent en leest alle lines in het CSV document
        file_read = open('database_opmerkingen.csv', mode='r', newline='')
        csvgelezen = csv.reader(file_read)
        # Lege lijst met alle lines die goedgekeurd zijn of niet gecontroleerd, om ze opnieuw in csv te schrijven
        csv_zonder_afgekeurd = []

        # gaat alle lines af en voegt aan de lijst hier boven alle lines zonder status afgekeurd toe
        for rij in csvgelezen:
            if rij[4] != 'Afgekeurd':
                csv_zonder_afgekeurd.append(rij)

        # schrijft alle nieuwe lines van rij_zonder_afgekeurd opnieuw op in het csv document
        file_write = open('database_opmerkingen.csv', mode='w', newline='')
        csvschrijver = csv.writer(file_write)
        csvschrijver.writerows(csv_zonder_afgekeurd)

    # sluit het programma af en stopt de loop
    if keuze == '5':
        print('Het moderatie programma wordt nu afgesloten! Tot ziens!')
        break
