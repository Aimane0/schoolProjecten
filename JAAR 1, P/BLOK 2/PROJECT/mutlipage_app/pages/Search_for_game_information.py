import streamlit as st
from PIL import Image
import requests, json, os
import matplotlib.pyplot as plt, numpy

#  Plaatjes van de platforms waar op de games gespeeld kunnen worden.
windows_img = Image.open('windows_logo.png')
windows_resize = windows_img.resize((250, 250))
mac_img = Image.open('apple_logo.png')
mac_resize = mac_img.resize((250, 250))
linux_img = Image.open('linux_logo.png')
linux_resize = linux_img.resize((250, 250))

# Titel van het dashboard met foto
image_steam_logo = Image.open('steam-logo-steam-icon-transparent-free-png.png')
newsize_steam_logo = image_steam_logo.resize((192, 192))
st.image(newsize_steam_logo)

st.title('Search information of any Steam game through this search bar!')
st.sidebar.success('Select a page above.')

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

# De games uit de dictionary in een lijst verwerken zodat die gebruikt kunnen worden
# voor de auto fill optie van de search bar
game_names = [game["name"] for game in available_games]
game_names.sort()
default_game = game_names[0]

search_bar = st.selectbox('Search for a video game by name: ', game_names, index=game_names.index(default_game))

# FUNCTIES om informatie op te halen
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
    categories = f'{selected_game["categories"]}'
    return categories

def get_genres(selected_game):
    genres = f'{selected_game["genres"]}'
    correctly_written_genres = genres.replace(";", ", ")
    return correctly_written_genres

def get_required_age(selected_game):
    if selected_game["required_age"] == 0:
        return '<b>Required age:</b> <i>None!</i>'
    else:
        if selected_game["required_age"] == 3:
            return st.markdown(f'<b>Required age:</b>', unsafe_allow_html=True), st.image('pegi3.png')

        if selected_game["required_age"] == 7:
            return st.markdown(f'<b>Required age:</b>', unsafe_allow_html=True), st.image('pegi7.png')

        if selected_game["required_age"] == 12:
            return st.markdown(f'<b>Required age:</b>', unsafe_allow_html=True), st.image('pegi12.png')

        if selected_game["required_age"] == 16:
            return st.markdown(f'<b>Required age:</b>', unsafe_allow_html=True), st.image('pegi16.png')

        if selected_game["required_age"] == 18:
            return st.markdown(f'<b>Required age:</b>', unsafe_allow_html=True), st.image('pegi18.png')

def get_english(selected_game):
    if selected_game["english"] == 1:
        return '<b>Available in English:</b> <i>Yes!</i>'
    else:
        return '<b>Available in English:<b/> <i>No!</i>'

def get_price(selected_game):
    price = f'{selected_game["price"]}'
    return f'€ {price}'

def get_game_achievements(selected_game):
    achievement_uri = 'http://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v0002/'
    params = {
        'gameid': selected_game["appid"],
        'format': 'json'
    }
    achievement_response = requests.get(achievement_uri, params)
    achievement_data = achievement_response.json()
    achievements = achievement_data.get('achievementpercentages', {}).get('achievements', [])
    result = ''
    for achievement in achievements:
        rounded_percentage = round(achievement["percent"], 2)
        result = result + (f'<b>{achievement["name"]}:</b> <i>{rounded_percentage}%</i><br>')

    empty_dic = {}
    if achievement_data == empty_dic:
        no_achievement = 'There are no achievements for this game!'
        return no_achievement
    else:
        return result

# Maak van het dashboard
if search_bar:
    # ChatGPT heeft hiermee geholpen
    selected_game = next((game for game in available_games if game["name"] == search_bar), None)

    # Opvragen van alle data en linken aan variabel via de geschreven functies
    game_name = get_game_name(selected_game)
    release_date = get_release_date(selected_game)
    developer = get_developer(selected_game)
    publisher = get_publisher(selected_game)
    categories_unchanged = get_categories(selected_game)
    categories = categories_unchanged.replace(';', ', ').strip()
    uncorrectly_written_genres = get_genres(selected_game)
    genres = uncorrectly_written_genres.replace(";", ", ")
    english_or_not = get_english(selected_game)
    price = get_price(selected_game)
    achievements = get_game_achievements(selected_game)
    positive_ratings = selected_game["positive_ratings"]
    negative_ratings = selected_game["negative_ratings"]
    totale_ratings = positive_ratings + negative_ratings
    percentage_negative_ratings = negative_ratings / totale_ratings * 100
    percentage_positive_ratings = positive_ratings / totale_ratings * 100
    percentage_negative_ratings = round(percentage_negative_ratings, 2)
    percentage_positive_ratings = round(percentage_positive_ratings, 2)

    # Vorm geven aan het dashboard
    st.header('Game description:', divider='grey')
    st.markdown(f'<b>Game name:</b> <i>{game_name}</i><br>'
                f'<b>Release date:</b> <i>{release_date}</i><br>'
                f'<b>Developer:</b> <i>{developer}</i><br>'
                f'<b>Publisher:</b> <i>{publisher}</i><br>'
                f'<b>Categories:</b> <i>{categories}</i><br>'
                f'<b>Genres:</b> <i>{genres}</i><br>'
                f'<b>Price:</b> <i>{price}<br>'
                f'{english_or_not}', unsafe_allow_html=True)
    #opvragen van de required age hier, zodat het in de game description staat
    required_age = get_required_age(selected_game)
    if required_age == '<b>Required age:</b> <i>None!</i>':
        st.markdown(required_age, unsafe_allow_html=True)

    st.header('Available platforms:', divider='grey')
    platform_images = []
    if 'windows' in selected_game["platforms"]:
        platform_images.append(windows_resize)
    if 'mac' in selected_game["platforms"]:
        platform_images.append(mac_resize)
    if 'linux' in selected_game["platforms"]:
        platform_images.append(linux_resize)

    # Hier maken we kolommen aan, zodat de plaatjes van links naar rechts getoond kunnen worden
    columns = st.columns(len(platform_images))
    # Gewenste breedte van de kolommen
    image_width = 250

    for column, image in zip(columns, platform_images):
        column.image(image, caption='', width=image_width)

    # Voeg een lege ruimte toe tussen de kolommen
    st.markdown('<br>', unsafe_allow_html=True)

    st.header('Player ratings:', divider='grey')
    # Tonen van pie chart die positieve en negatieve ratings toont
    labels = 'Positive ratings', 'Negative ratings'
    # Vraagt om de positieve en negatieve ratings van selected game
    # Maakt een pie chart van de ratings
    sizes = [positive_ratings, negative_ratings]
    fig1, ax1 = plt.subplots()
    fig1.set_facecolor('#1b2838')
    ax1.pie(sizes, labels=labels, textprops={'color': 'white'})
    ax1.axis('equal')
    st.pyplot(fig1)
    # Toont onder de pie chart hoeveel positieve en negatieve ratings er zijn
    ratings = f'Total amount of ratings: {totale_ratings}<br>Amount of positive ratings: {positive_ratings} ({percentage_positive_ratings}%)<br>Amount of negative ratings: {negative_ratings} ({percentage_negative_ratings}%)'
    st.markdown(ratings, unsafe_allow_html=True)
    # Tonen van average playtime en median playtime

    st.header('Player statistics:', divider='grey')
    st.markdown(f'<b>Average playtime:</b><i> {selected_game["average_playtime"]}</i><br>'
                f'<b>Median playtime:</b><i> {selected_game["median_playtime"]}</i><br>'
                f'<b>Estimated amount of owners:</b><i> {selected_game["owners"]}</i>',
                unsafe_allow_html=True)

    with st.expander('See game achievements and how many players have unlocked them!'):
        st.markdown(achievements, unsafe_allow_html=True)
