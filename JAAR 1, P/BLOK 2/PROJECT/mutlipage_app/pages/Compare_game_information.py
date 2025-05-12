import streamlit as st
import requests, json, os
import matplotlib.pyplot as plt, numpy

st.title('Compare game information!')
st.sidebar.success('Select a page above.')

# FUNCTIES OM RELEVANTE DATA OP TE VRAGEN!
def get_game_name(selected_game):
    game_name = f'{selected_game["name"]}'
    return game_name

def get_release_date(selected_game):
    release_date = f'{selected_game["release_date"]}'
    return release_date

def get_developer(selected_game):
    developer = f'{selected_game["developer"]}'
    return developer

def get_publisher(selected_game):
    publisher = f'{selected_game["publisher"]}'
    return publisher

def get_categories(selected_game):
    categories_unchanged = f'{selected_game["categories"]}'
    categories = categories_unchanged.replace(';', ', ')
    return categories

def get_genres(selected_game):
    genres = f'{selected_game["genres"]}'
    correctly_written_genres = genres.replace(";", ", ")
    return correctly_written_genres

def get_required_age(selected_game):
   required_age = selected_game["required_age"]
   return required_age

def get_english(selected_game):
    if selected_game["english"] == 1:
        return 'This game is available in English'
    else:
        return 'This game isn\'t available in English'

def get_price(selected_game):
    price = f'{selected_game["price"]}'
    return f'€ {price}'

def get_average_owners(selected_game):
    owners_range = selected_game.get("owners", "")
    if "-" in owners_range:
        start, end = map(int, owners_range.split("-"))
        return (start + end) // 2
    else:
        return int(owners_range)

def get_selected_game_numeral_data(selected_game, data_search_bar):
    if data_search_bar in selected_game:
        return selected_game[data_search_bar]
    else:
        return f'{data_search_bar} not available for {selected_game["name"]}'

def get_game_achievements(selected_game):
    achievement_uri = 'http://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v0002/'
    params = {
        'gameid': selected_game["appid"],
        'format': 'json'
    }
    achievement_response = requests.get(achievement_uri, params)
    achievement_data = achievement_response.json()
    achievements = achievement_data.get('achievementpercentages', {}).get('achievements', [])

    if len(achievements) == 0:
        return 'This game has no achievements'
    else:
        return f'Amount of achievements in this game: {len(achievements)}'

########################
# Functie om games uit een JSON-bestand in te laden
def load_games_from_json(json_file_path):
    with open(json_file_path, 'r') as file:
        games_data = json.load(file)
    return games_data

# JSON-bestandspad
project_pad = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
steam_json_pad = os.path.join(project_pad, 'steam.json')

# Tijdelijke hashmap ter testen
available_games = load_games_from_json(steam_json_pad)
####################

# Verwerken van alle games in een lijst om de selectbox mogelijk te maken
game_names = []
for game in available_games:
    game_names.append(game["name"])
default_game = game_names[0]

# Maken van 2 kolommen voor het selecteren van een game
col1, col3 = st.columns(2)

# SEARCH BARS om de games te selecteren
game1 = col1.selectbox('Select a game!', game_names, index=None)
game2 = col3.selectbox('Select a game to compare!', game_names, index=None)

if game1 and game2:
    selected_game1 = next((game for game in available_games if game["name"] == game1), None)
    selected_game2 = next((game for game in available_games if game["name"] == game2), None)

##################################
# OPVRAGEN VAN EEN HELE BOEL DATA GAME 1

    game_name1 = get_game_name(selected_game1)
    release_date1 = get_release_date(selected_game1)
    developer1 = get_developer(selected_game1)
    publisher1 = get_publisher(selected_game1)
    categories1 = get_categories(selected_game1)
    genres1 = get_genres(selected_game1)
    required_age1 = get_required_age(selected_game1)
    english_or_not1 = get_english(selected_game1)
    price1 = get_price(selected_game1)
    owners1 = get_average_owners(selected_game1)
    achievements1 = get_game_achievements(selected_game1)

    # RATINGS VAN DE GAME, OMGEZET IN PERCENTAGES
    positive_ratings1 = selected_game1["positive_ratings"]
    negative_ratings1 = selected_game1["negative_ratings"]
    totale_ratings = positive_ratings1 + negative_ratings1
    percentage_negative_ratings1 = negative_ratings1 / totale_ratings * 100
    percentage_positive_ratings1 = positive_ratings1 / totale_ratings * 100
    percentage_negative_ratings1 = round(percentage_negative_ratings1, 2)
    percentage_positive_ratings1 = round(percentage_positive_ratings1, 2)

####################################
####################################
# OPVRAGEN VAN EEN HELE BOEL DATA GAME 2

    game_name2 = get_game_name(selected_game2)
    release_date2 = get_release_date(selected_game2)
    developer2 = get_developer(selected_game2)
    publisher2 = get_publisher(selected_game2)
    categories2 = get_categories(selected_game2)
    genres2 = get_genres(selected_game2)
    required_age2 = get_required_age(selected_game2)
    english_or_not2 = get_english(selected_game2)
    price2 = get_price(selected_game2)
    owners2 = get_average_owners(selected_game2)
    achievements2 = get_game_achievements(selected_game2)

    # RATINGS VAN DE GAME, OMGEZET IN PERCENTAGES
    positive_ratings2 = selected_game2["positive_ratings"]
    negative_ratings2 = selected_game2["negative_ratings"]
    totale_ratings = positive_ratings2 + negative_ratings2
    percentage_negative_ratings2 = negative_ratings2 / totale_ratings * 100
    percentage_positive_ratings2 = positive_ratings2 / totale_ratings * 100
    percentage_negative_ratings2 = round(percentage_negative_ratings2, 2)
    percentage_positive_ratings2 = round(percentage_positive_ratings2, 2)

    # Vergelijkingsresultaten voor GAME 1 en GAME 2
    st.header(f'Comparisson between {game_name1} and {game_name2}')

    # Data voor de tabel
    compare_data = [
        ["GAME NAME", game_name1, game_name2],
        ["RELEASE DATE", release_date1, release_date2],
        ["DEVELOPER", developer1, developer2],
        ["PUBLISHER", publisher1, publisher2],
        ["CATEGORIES", categories1, categories2],
        ["GENRES", genres1, genres2],
        ["REQUIRED AGE", required_age1, required_age2],
        ["ENGLISH", english_or_not1, english_or_not2],
        ["PRICE", price1, price2],
        ["ACHIEVEMENTS", achievements1, achievements2],
        ["POSITIVE RATINGS", f'{percentage_positive_ratings1}%', f'{percentage_positive_ratings2}%'],
        ["NEGATIVE RATINGS", f'{percentage_negative_ratings1}%', f'{percentage_negative_ratings2}%']
    ]
    
    # Tabel voor vergelijking
    table_comparison = st.table(compare_data)

# VORM GEVEN VAN DE WEBPAGE
types_of_data = ['Median playtime', 'Average playtime', 'Owners', 'Total amount of positive ratings',
                 'Total amount of negative ratings', 'Amount of achievements']
types_of_data.sort()

# Dictonary om de data die gezocht moet worden in search_bar2 om te zetten naar hoe het in de json file staat
translate_to_json = {
    'Amount of achievements':'achievements',
    'Average playtime':'average_playtime',
    'Median playtime':'median_playtime',
    'Owners':'owners',
    'Total amount of negative ratings':'negative_ratings',
    'Total amount of positive ratings':'positive_ratings'
}
st.divider()
data_search_bar = st.selectbox('Choose a type of data to compare!', types_of_data,
                            index=None)
# Vormen en tonen van een staafdiagram
if data_search_bar:
    # Maak een staafdiagram met het gemiddelde van het aantal owners van de games
    # Dit ivm met het feit dat owner 2 getallen geeft hiervan pakken we het gemiddelde
    if data_search_bar == 'Owners':
        selected_game1 = next((game for game in available_games if game["name"] == game1), None)
        selected_game2 = next((game for game in available_games if game["name"] == game2), None)

        game_name1 = get_game_name(selected_game1)
        game_name2 = get_game_name(selected_game2)

        owners1 = get_average_owners(selected_game1)
        owners2 = get_average_owners(selected_game2)

        # Maak een staafdiagram
        plt.bar([game_name1, game_name2], [owners1, owners2], color=['blue', 'green'])
        plt.xlabel('Games', color='white')
        plt.ylabel(data_search_bar, color='white')
        plt.title(f'Comparison between {game_name1} and {game_name2} based on {data_search_bar}', color='white')
        plt.gcf().set_facecolor('#1b2838')
        plt.tick_params(axis='x', colors='white')
        plt.tick_params(axis='y', colors='white')
        # Toon de staafdiagram
        st.pyplot(plt)

    else:
        # Maken van staafdiagram als alles behalve owner gekozen wordt
        selected_game1 = next((game for game in available_games if game["name"] == game1), None)
        selected_game2 = next((game for game in available_games if game["name"] == game2), None)

        game_name1 = get_game_name(selected_game1)
        game_name2 = get_game_name(selected_game2)

        data1 = get_selected_game_numeral_data(selected_game1, translate_to_json[data_search_bar])
        data2 = get_selected_game_numeral_data(selected_game2, translate_to_json[data_search_bar])

        # Maak een staafdiagram
        plt.bar([game_name1, game_name2], [data1, data2], color=['blue', 'green'])
        plt.xlabel('Games', color='white')
        plt.ylabel(data_search_bar, color='white')
        plt.title(f'Comparison between {game_name1} and {game_name2} based on {data_search_bar}', color='white')
        plt.gcf().set_facecolor('#1b2838')
        plt.tick_params(axis='x', colors='white')
        plt.tick_params(axis='y', colors='white')
        # Toon de staafdiagram
        st.pyplot(plt)
