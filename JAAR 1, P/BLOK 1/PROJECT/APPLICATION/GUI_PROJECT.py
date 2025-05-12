from tkinter import *
from tkinter import LEFT, RIGHT

import pygame.mixer
import requests, json
import psycopg2
from pygame import mixer
from datetime import datetime
from time import strftime

# Connecten met de database!
connection = psycopg2.connect(host='40.114.242.236', port='5432', database='project_zuil', user='admin', password='admin')
cursor = connection.cursor()

# In het console wordt er gekozen welke stad het scherm staat
gekozen_stad = input('In welke stad staat het scherm? ')

def stad_aanvragen():
    # Query om alle steden op te vragen die in de database staan
    query_steden = """SELECT stad FROM station"""
    cursor.execute(query_steden)
    steden_als_tuples = cursor.fetchall()

    # De steden uit de tuple halen en in een normale lijst verwerken
    steden = []
    for i in steden_als_tuples:
        steden.append(i[0])

    # Checked of de gekozen stad in de lijst zit van steden die in de database zit
    while True:
        global gekozen_stad
        if gekozen_stad in steden:
            print('Er is een stad gekozen')
            print(f'De gekozen stad is {gekozen_stad}')

            # Selecteert het station naam van de stad uit de database
            query_station_naam = """SELECT station_naam FROM station 
                                    WHERE stad = %s"""
            cursor.execute(query_station_naam, (gekozen_stad,))
            station_naam = cursor.fetchall()

            # We moeten het station naam uit de tuple halen en in een list verwerken
            station = []
            for i in station_naam:
                station.append(i[0])
            # Past bestaande label aan met station naam
            if station:
                label_welkom.config(text=f'Welkom op {station[0]}')
                mixer.init()
                mixer.set_num_channels(2)
                mixer.Channel(0).play(pygame.mixer.Sound('Omroepen.mp3'))
                mixer.Channel(1).play(pygame.mixer.Sound('Lopen.mp3'))
                break
        else:
            print('Deze stad doet niet mee aan de actie!')
            gekozen_stad = str(input('In welke stad staat het scherm? '))

# Maken van een dictonary met welk nummer bij welke faciliteit hoort
faciliteiten_dictonary = {
    1: 'OV fietsen',
    2: 'Lift',
    3: 'Toilet',
    4: 'P+R'
}

# Functie om het label faciliteiten aan te passen!
def faciliteiten_label_aanpassen():
    # Maken van een tekst waar we de faciliteiten aan willen toevoegen
    beschikbare_faciliteiten = 'De beschikbare faciliteiten op dit station zijn:\n'
    # Langs de faciliteiten_lijst gaan om te checken welk nummer bij welke faciliteit hoor volgens dictonary
    for faciliteit in faciliteiten_lijst:
        # Als deze in de dictonary zit, het toevoegen van bij behorende string aan de tekst beschikbare faciliteiten
        if faciliteit in faciliteiten_dictonary:
            beschikbare_faciliteiten = beschikbare_faciliteiten + faciliteiten_dictonary[faciliteit] + '\n'
    label_faciliteiten.config(text=beschikbare_faciliteiten)

def label_weerbericht_aanpassen():
    # Verkrijgen van het weer
    # Opvragen van de API
    basis_url = 'https://api.openweathermap.org/data/2.5/weather?'
    gehele_url = basis_url + 'q=' + gekozen_stad + '&units=' + 'metric' + '&appid=' + 'd492e345a95193311c2ba89d0046176f' + '&lang=' + 'nl'
    response = requests.get(gehele_url)
    data = response.json()

    # Nodige data van de openweather api koppelen aan variabel
    temperatuur = data['main']['temp']
    windsnelheid_in_ms = data['wind']['speed']
    # windsnelheid, temperatuur etc in mooie strings verwerken
    temperatuur_string = f'Het is {temperatuur} °C'
    windsnelheid_string = f'Windsnelheid: {windsnelheid_in_ms} m/s'
    vochtigheid = data['main']['humidity']
    neerslag = data['weather'][0]['description']

    # koppele van relevante weer informatie aan label
    label_weerbericht.config(text=f'{temperatuur_string}\n{windsnelheid_string}\nLuchtvochtigheid: {vochtigheid}%\nWeer conditie: {neerslag}')

def berichten_displayen():
    # Query die de laatste 5 berichten die opgestuurd zijn naar de database opvraagt
    query_berichten_kiezen = """SELECT naam, ingezonden_bericht, stad FROM bericht 
                                    ORDER BY datum_en_tijd DESC LIMIT 5"""
    cursor.execute(query_berichten_kiezen)
    resultaten = cursor.fetchall()

    # Deelt de namen berichten en steden via een for loop in lijsten
    namen = []
    berichten = []
    steden = []
    for i in resultaten:
        namen.append(i[0])
        berichten.append(i[1])
        steden.append(i[2])

    # Maakt mooie berichten door de index van lijsten in een f string te verwerken
    bericht1 = (f'{namen[0]} heeft vanuit {steden[0]} verstuurd: "{berichten[0]}"')
    bericht2 = (f'{namen[1]} heeft vanuit {steden[1]} verstuurd: "{berichten[1]}"')
    bericht3 = (f'{namen[2]} heeft vanuit {steden[2]} verstuurd: "{berichten[2]}"')
    bericht4 = (f'{namen[3]} heeft vanuit {steden[3]} verstuurd: "{berichten[3]}"')
    bericht5 = (f'{namen[4]} heeft vanuit {steden[4]} verstuurd: "{berichten[4]}"')
    # Voegt de berichten toe als text aan de labels gemaakt om de berichten te tonen
    label_berichten1.config(text=bericht1)
    label_berichten2.config(text=bericht2)
    label_berichten3.config(text=bericht3)
    label_berichten4.config(text=bericht4)
    label_berichten5.config(text=bericht5)

def live_tijd():
    tijd = strftime('%d/%m/%y %H:%M:%S')
    label_tijd.config(text=tijd)
    label_tijd.after(100, live_tijd)


# Root van de GUI
root = Tk()
root.title('Stationscherm')
root.geometry('1800x700')


# label met het NS logo
station_logo = PhotoImage(file='Nederlandse_Spoorwegen_logo.svg.png')
aangepast_station_logo = station_logo.subsample(4, 4)
label_NS_foto = Label(master=root, image=aangepast_station_logo, bg="#FFC917")
label_NS_foto.pack(fill='x')

# Tonen welk station er in de stad is
label_welkom = Label(master=root, text='', bg="#FFC917", fg="#003082", font=('arial', 40), pady=30)
label_welkom.pack(fill='x',)
stad_aanvragen()

# Tonen van faciliteiten op het station
label_faciliteiten = Label(master=root, text='', font=('arial', 12), padx=50, pady=50)
label_faciliteiten.pack(side=LEFT)

# Via SQL aanvragen welk station ID bij welke stad hoort
query_station_id_aanvragen = """SELECT station_id FROM station 
                                WHERE stad = %s"""
cursor.execute(query_station_id_aanvragen, (gekozen_stad,))
station_id_tuple = cursor.fetchone()
station_id = station_id_tuple[0]

# Via SQL aanvragen welke faciliteiten bij het station ID hoort
query_faciliteiten_aanvragen = """SELECT faciliteit_id FROM stationfaciliteit
                                  WHERE station_id = %s"""
cursor.execute(query_faciliteiten_aanvragen, (station_id,))
faciliteiten_tuple = cursor.fetchall()
# Van tuple een list maken
faciliteiten_lijst = [faciliteiten_tuple[0][0], faciliteiten_tuple[1][0]]

# Uitvoeren van de functie die faciliteit label aanpast
faciliteiten_label_aanpassen()

# Tonen van het weer, gebaseerd op waar het scherm zich plaats vindt
label_weerbericht = Label(master=root, text='', font=('arial', 12), padx=50, pady=30)
label_weerbericht.pack(side=RIGHT)
label_weerbericht_aanpassen()

# Tonen van de berichten, chronologische volgorde, de laatste 5!
label_berichten1 = Label(master=root, text='', font=('arial', 15))
label_berichten1.pack()

label_berichten2 = Label(master=root, text='', font=('arial', 15))
label_berichten2.pack()

label_berichten3 = Label(master=root, text='', font=('arial', 15))
label_berichten3.pack()

label_berichten4 = Label(master=root, text='', font=('arial', 15))
label_berichten4.pack()

label_berichten5 = Label(master=root, text='', font=('arial', 15))
label_berichten5.pack()

label_tijd = Label(master=root, text='', font=('arial', 40), padx=50, pady=50)
label_tijd.pack(anchor='center')
live_tijd()

berichten_displayen()

root.mainloop()