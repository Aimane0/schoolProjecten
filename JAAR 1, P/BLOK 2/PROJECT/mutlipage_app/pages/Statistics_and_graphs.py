import streamlit as st
import json
import os
import matplotlib.pyplot as plt
import pandas as pd
from datetime import datetime

st.title('Steam statistics and graphs')
st.sidebar.success('Select a page above.')

def load_games_from_json(json_file_path):
    with open(json_file_path, 'r') as file:
        games_data = json.load(file)
    return games_data

# ALGORITMISCH ZOEKEN
def quicksort(arr, key, secondary_key):
    if len(arr) <= 1:
        return arr

    stack = [(0, len(arr) - 1)]

    while stack:
        low, high = stack.pop()
        pivot_idx = divide(arr, low, high, key, secondary_key)

        if pivot_idx - 1 > low:
            stack.append((low, pivot_idx - 1))

        if pivot_idx + 1 < high:
            stack.append((pivot_idx + 1, high))

    return arr

# ALGORITMISCH ZOEKEN
def divide(arr, low, high, key, secondary_key):
    pivot = arr[high][key]
    i = low - 1

    for j in range(low, high):
        if key in arr[j] and pivot in arr[j][key] and arr[j][secondary_key] >= arr[high][secondary_key]:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def calculate_average_price(data, category_or_genre):
    total_price = 0
    total_games = 0

    for game in data:
        categories = game.get("categories", "").split(";")
        genres = game.get("genres", "").split(";")

         # Controleer of data niet gelijk is aan 0
        if category_or_genre in categories or category_or_genre in genres:
            data_niet_nul = game.get("price", 0)

            if data_niet_nul != 0:
                total_price += game.get("price", 0)
                total_games += 1

    if total_games == 0:
        return 0  # Om te voorkomen dat we door 0 delen

    average_price = total_price / total_games
    return average_price

# JSON-bestandspad
project_pad = os.path.dirname(os.path.abspath(__file__))
steam_json_pad = os.path.join(project_pad, 'steam.json')

# Tijdelijke hashmap ter testen
steam_json_file = load_games_from_json(steam_json_pad)

# Het verkrijgen van alle genres en steamspy tags in zoektermen
zoektermen = []

# VORM GEVEN VAN DE WEBPAGE
types_of_data = ['Median playtime', 'Average playtime', 'Owners', 'Total amount of positive ratings',
                 'Total amount of negative ratings', 'Amount of achievements', 'Price']
types_of_data.sort()
default_types_data = types_of_data[0]

for game in steam_json_file:
    if "genres" in game:
        genres = game.get("genres", "").split(';')
        for genre in genres:
            if genre not in zoektermen:
                zoektermen.append(genre)

    if "categories" in game:
        categories = game.get("categories", "").split(';')
        for tag in categories:
            if tag not in zoektermen:
                zoektermen.append(tag)

zoektermen.sort()
default_zoekterm = zoektermen[0]

st.header('Games released per year')
# Lege dict om alle games bij te houden
games_per_year = {}

# Loop door elk spel in de dataset
for game in steam_json_file:
    release_year = datetime.strptime(game['release_date'], '%Y-%m-%d').year
    games_per_year.setdefault(release_year, 0)
    games_per_year[release_year] += 1

# Sorteer de resultaten op jaar
sorted_years = sorted(games_per_year.keys())

# assen maken en gegevens opslaan van de stafen in bars
fig, ax = plt.subplots()
bars = ax.bar(sorted_years, [games_per_year[year] for year in sorted_years])

# for loop gebruiken om de gegevens te tonen per staaf.
for bar in bars:
    yval = bar.get_height()
    ax.text(bar.get_x() + bar.get_width()/2, yval, int(yval), ha='center', va='bottom')

# Maak het staafdiagram
plt.xlabel('Jaar')
plt.ylabel('Aantal Games')
plt.title('Aantal Steam Games per Jaar')
plt.show()
st.pyplot(plt)

st.divider()

st.header('Total amount of positive and negative ratings per genre or category')

search_bar4 = st.selectbox('Choose a genre or category to see statistics about! ', zoektermen,
                             index=None)

if search_bar4:

    genre_games = [game for game in steam_json_file if search_bar4 in game['genres']]
    category_games = [game for game in steam_json_file if search_bar4 in game['categories']]

    positive_more_than_negative = 0
    negative_more_than_positive = 0

    for game in genre_games or category_games:
        if game['positive_ratings'] > game['negative_ratings']:
            positive_more_than_negative += 1
        elif game['positive_ratings'] < game['negative_ratings']:
            negative_more_than_positive += 1

    labels = ['Positive ratings', 'Negative ratings']
    counts = [positive_more_than_negative, negative_more_than_positive]

    plt.figure()
    plt.bar(labels, counts, color=['green', 'red'])
    plt.title(f'Ratings for the genre or categorie {search_bar4}')
    plt.xlabel('Ratings')
    plt.ylabel('Amount of games')
    st.pyplot(plt)

st.divider()

st.header('Check out the top 5 to top 200 stats of certain genres and categories', divider='grey')

# Vormen van 2 columns ter vergelijking van video games
col1, col2 = st.columns(2)

# Maken van search bars
amount_of_games_to_display = [5,10,15,20,25,50,75,100,125,150,200]

search_bar1 = col1.selectbox('Choose a genre or category to see statistics about!', zoektermen,
                             index=None)
search_bar2 = col2.selectbox('Choose a type data to see', types_of_data,
                             index=None)
search_bar3 = st.selectbox('Choose an amount of games you want to display', amount_of_games_to_display,
                             index=None)

# Dictonary om de data die gezocht moet worden in search_bar2 om te zetten naar hoe het in de json file staat
translate_to_json = {
    'Amount of achievements':'achievements',
    'Average playtime':'average_playtime',
    'Median playtime':'median_playtime',
    'Owners':'owners',
    'Total amount of negative ratings':'negative_ratings',
    'Total amount of positive ratings':'positive_ratings',
    'Price':'price'
}

if search_bar1 and search_bar2 and search_bar3:

    # Uitvoeren van functies en zoeken naar data via algorithme
    games_sorted_genre = quicksort(steam_json_file.copy(), key="genres", secondary_key=translate_to_json[search_bar2])
    games_sorted_categories = quicksort(steam_json_file.copy(), key="categories", secondary_key=translate_to_json[search_bar2])

    result_genres = [game for game in games_sorted_genre if search_bar1 in game["genres"]]
    result_category = [game for game in games_sorted_categories if search_bar1 in game["categories"]]

    result_genres_sorted = sorted(result_genres, key=lambda x: x[translate_to_json[search_bar2]], reverse=True)
    result_category_sorted = sorted(result_category, key=lambda x: x[translate_to_json[search_bar2]], reverse=True)

    with st.expander('See the results down here!'):
        # Print de resultaten
        for game in result_genres_sorted[:search_bar3]:
            genres = game.get('genres', '').replace(';', ', ').strip()
            st.markdown(
                f"Name: {game['name']}<br>Genres: {genres}<br>{search_bar2}: {game[translate_to_json[search_bar2]]}",
                unsafe_allow_html=True)
            st.divider()

        for game in result_category_sorted[:search_bar3]:
            categories = game.get('categories', '').replace(';', ' ').strip()
            st.markdown(
                f"<b>Name:</b> <i>{game['name']}</i><br><b>Genres: </b><i>{game['genres']}</i><br>"
                f"<b>Category:</b> <i>{categories}</i><br>"
                f"<b>{search_bar2}:</b> <i>{game[translate_to_json[search_bar2]]}</i>",
                unsafe_allow_html=True)
            st.divider()

st.divider()

st.header('Average price per genre or category')
# Vraag de gebruiker om input voor het gewenste genre of categorie
search_bar8 = st.selectbox(' Choose a genre or category to see statistics about! ', zoektermen,
                             index=None)

if search_bar8:
    # Bereken het gemiddelde van de prijzen voor het opgegeven genre of categorie
    genre_average_price = calculate_average_price(steam_json_file, search_bar8)
    st.markdown(f"The average price of '{search_bar8}': {genre_average_price:.2f}")

st.divider()
