import streamlit as st
import requests
import json
import os
import serial
import psycopg2


# Vervang 'COMx' door de juiste COM-poort van de USB-naar-seriële converter op je computer
ser = serial.Serial('COM4', 115200, timeout=1)

st.set_page_config(
    page_title="Check Info Username",
    page_icon="steam_logo2.png"
)

# Titel en search bar
st.title('Check your user information with your NFC card!')
st.subheader('This feature has a one time use only!)
st.divider()

# Info van de database waarmee geconnect is
connection = psycopg2.connect(
    host='20.79.251.131',
    port='5432',
    database='steam',
    user='admin',
    password='Welkom@01'
)
cursor = connection.cursor()

def get_user_info_rfid(given_line):
    query = """SELECT steamid bigint FROM steam_gebruikers
               WHERE rfid = %s"""
    cursor.execute(query, (given_line,))
    list = cursor.fetchall()
    return list[0]

# JSON bestand oproepen
def load_games_from_json(json_file_path):
    with open(json_file_path, 'r') as file:
        games_data = json.load(file)
    return games_data

# JSON-bestandspad
project_pad = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
steam_json_pad = os.path.join(project_pad, 'steam.json')
steam_json_file = load_games_from_json(steam_json_pad)

# Functie om de username te zoeken in de database en de steamID op te vragen
def get_user_id(given_username):
    query = """SELECT steamid bigint FROM steam_gebruikers
               WHERE username = %s"""
    cursor.execute(query, (given_username,))
    return cursor.fetchall()

# Functie om de opgevraagde steam ID om te zetten in informatie
# Via de steam API
def get_user_info(user_id):
    api = (f'http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?'
               'key=F5165515610F99F856E8B2325E3F4AF7&'
               f'steamids={user_id}&'
               f'format=json')
    api_response = requests.get(api)
    api_data = api_response.json()

    player = api_data.get('response', {}).get('players', [])

    if player:
        player_info = player[0]
        username = player_info.get('personaname','Not available')
        online_status = player_info.get('personastate', 'Not available')
        profileurl = player_info.get('profileurl', 'Not available')
        avatarfull = player_info.get('avatarfull', 'Not available')

        return {
            'username': username,
            'online_status': online_status,
            'profileurl': profileurl,
            'avatarfull': avatarfull
        }
    else:
        return {}

# Functie om de games van de user op te vragen
def get_user_owned_games(user_id, steam_json_file):
    base_url = "http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/"
    params = {
        'key': 'F5165515610F99F856E8B2325E3F4AF7',
        'steamid': user_id,
        'format':'json'
    }
    response = requests.get(base_url, params=params)
    data = response.json()

    owned_games_appid = []

    if 'response' in data and 'games' in data['response']:
        games_data = data['response']['games']

        for game in games_data:
            app_id = game.get("appid")
            owned_games_appid.append(app_id)

    game_names_list = []
    for app_id in owned_games_appid:
        for game in steam_json_file:
            if game["appid"] == app_id:
                game_names_list.append(game["name"])
    game_names_list.sort()

    game_names = ''
    for games in game_names_list:
        game_names += f'{games}<br>'

    return game_names

# Functie om de games van de user te verkrijgen, maar dan in de vorm van een lijst
def get_user_owned_games_list(user_id, steam_json_file):
    base_url = "http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/"
    params = {
        'key': 'F5165515610F99F856E8B2325E3F4AF7',
        'steamid': user_id,
        'format':'json'
    }
    response = requests.get(base_url, params=params)
    data = response.json()

    owned_games_appid = []

    if 'response' in data and 'games' in data['response']:
        games_data = data['response']['games']

        for game in games_data:
            app_id = game.get("appid")
            owned_games_appid.append(app_id)

    game_names_list = []
    for app_id in owned_games_appid:
        for game in steam_json_file:
            if game["appid"] == app_id:
                game_names_list.append(game["name"])
    game_names_list.sort()

    return game_names_list

# Opvragen van vriendenlijst van de user
def get_user_friendlist(user_id):
    base_url = "http://api.steampowered.com/ISteamUser/GetFriendList/v0001/"
    params = {
        'key': 'F5165515610F99F856E8B2325E3F4AF7',
        'steamid': user_id,
        'relationship': 'friend'
    }
    response = requests.get(base_url, params=params)
    data = response.json()

    friends_steam_ids = []

    if 'friendslist' in data:
        friends_data = data['friendslist']['friends']

        for friend_id in friends_data:
            steam_id = friend_id["steamid"]
            friends_steam_ids.append(steam_id)
    return friends_steam_ids

# Opvragen van basis informatie van de vrienden uit de vriendenlijst
def get_friends_basic_summary(friends_steam_ids):
    friends_summary_data = []

    for friend_id in friends_steam_ids:
        summary = (f'http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?'
                   f'key=F5165515610F99F856E8B2325E3F4AF7&'
                   f'steamids={friend_id}&'
                   f'format=json')
        summary_response = requests.get(summary)
        summary_data = summary_response.json()

        player = summary_data.get('response', {}).get('players', [])

        if player:
            player_info = player[0]
            steamid = player_info.get('steamid', 'Not available')
            username = player_info.get('personaname', 'Not available')
            online_status = player_info.get('personastate', 'Not available')
            profileurl = player_info.get('profileurl', 'Not available')
            avatarfull = player_info.get('avatarfull', 'Not available')

            friends_summary_data.append({
                'steamid': steamid,
                'username': username,
                'online_status': online_status,
                'profileurl': profileurl,
                'avatarfull': avatarfull
            })
    return friends_summary_data

# Opvragen van laatst gespeelde games van de afgelopen 2 weken
def get_last_played_games(user_id):
    base_url = 'http://api.steampowered.com/IPlayerService/GetRecentlyPlayedGames/v0001/'
    params = {
        'key':'F5165515610F99F856E8B2325E3F4AF7',
        'steamid':user_id,
        'format':'json'
    }
    response = requests.get(base_url, params=params)
    data = response.json()

    recently_played_names = []

    if 'response' in data and 'games' in data['response']:
        games_data = data['response']['games']

        for game in games_data:
            game_name = game.get("name")
            recently_played_names.append(game_name)

    recently_played = ''
    for games in recently_played_names:
        recently_played += f'{games}<br>'
    return recently_played

# Opvragen van achievements die de speler heeft
def get_achievements(user_id, search):
    search_names = []

    for game in steam_json_file:
        if game["name"] == search:
            search_names.append(str(game["appid"]))

    base_url = 'http://api.steampowered.com/ISteamUserStats/getplayerachievements/v0001/'
    params = {
        'appid': search_names,
        'key': 'F5165515610F99F856E8B2325E3F4AF7',
        'steamid': user_id,
        'format': 'json'
    }
    response = requests.get(base_url, params=params)

    try:
        data = response.json()
        stats_data = data['playerstats']
        achievements_list = []

        for achievement in stats_data.get('achievements', []):
            if achievement.get('achieved') == 1:
                achievements_list.append(achievement.get('apiname', 'N/A'))

        if not achievements_list:
            return f"<b>- This player has not unlocked any achievements for {search}!</b><br>"


        achievements_string = f'<b>- Achievements unlocked for {search}:</b><br>'
        for i in achievements_list:
            achievements_string += f'{i}<br>'

        return achievements_string

    except KeyError:
        return "<b>This player has not unlocked any achievements for this game!</b>"

while True:
    line = ser.readline().decode().strip()

    if line:
        # De functies die gemaakt zijn oproepen om nodige info te verkrijgen
        user_id = get_user_info_rfid(line)
        user_information = get_user_info(user_id)
        owned_games = get_user_owned_games(user_id, steam_json_file)
        owned_games_list = get_user_owned_games_list(user_id, steam_json_file)
        friendlist_ids = get_user_friendlist(user_id)
        friendlist_info = get_friends_basic_summary(friendlist_ids)
        last_played_games = get_last_played_games(user_id)

        # Vormgeven van de webpage met user informatie
        st.markdown(f'<b>Username:</b> <i>{user_information["username"]}</i>', unsafe_allow_html=True)
        # If statements voor de online status
        if user_information["online_status"] == 0:
            st.markdown('<b>User is offline</b>', unsafe_allow_html=True)
        if user_information["online_status"] == 1:
            st.markdown('<b>User is online</b>', unsafe_allow_html=True)
        if user_information["online_status"] == 2:
            st.markdown('<b>User is busy</b>', unsafe_allow_html=True)
        if user_information["online_status"] == 3:
            st.markdown('<b>User is away</b>', unsafe_allow_html=True)
        if user_information["online_status"] == 4:
            st.markdown('<b>User is snoozing</b>', unsafe_allow_html=True)
        if user_information["online_status"] == 5:
            st.markdown('<b>User is looking to trade</b>', unsafe_allow_html=True)
        if user_information["online_status"] == 6:
            st.markdown('<b>User is looking to play</b>', unsafe_allow_html=True)

        # Profielfoto op de webpage krijgen
        profile_picture = user_information["avatarfull"]
        st.image(profile_picture, caption='Profile picture')

        # Profile URL tonen
        st.markdown(f'<b>Profile URL:</b> <i>{user_information["profileurl"]}</i>', unsafe_allow_html=True)

        st.divider()

        # Expander waar de laatst gespeelde games onder verscholen staan
        with st.expander(f'{user_information["username"]}\'s last played games within the last 2 weeks'):
            st.markdown(last_played_games, unsafe_allow_html=True)

        # Expander om de games die de owner heeft te tonen
        with st.expander(f'{user_information["username"]}\'s owned games'):
            st.markdown(owned_games, unsafe_allow_html=True)

        # Tonen van de vriendelijst van de gebruiker en de basis informatie van die vrienden
        with st.expander(f'{user_information["username"]}\'s friends, total amount of {len(friendlist_ids)}'):
            for friend_info in friendlist_info:
                st.markdown(f'<b>Friend\'s Username:</b> <i>{friend_info["username"]}</i>', unsafe_allow_html=True)
                st.markdown(f'<b>Steam ID:</b> <i>{friend_info["steamid"]}</i>', unsafe_allow_html=True)

                # If statement online status
                if friend_info["online_status"] == 0:
                    st.markdown('<b>User is offline</b>', unsafe_allow_html=True)
                if friend_info["online_status"] == 1:
                    st.markdown('<b>User is online</b>', unsafe_allow_html=True)
                if friend_info["online_status"] == 2:
                    st.markdown('<b>User is busy</b>', unsafe_allow_html=True)
                if friend_info["online_status"] == 3:
                    st.markdown('<b>User is away</b>', unsafe_allow_html=True)
                if friend_info["online_status"] == 4:
                    st.markdown('<b>User is snoozing</b>', unsafe_allow_html=True)
                if friend_info["online_status"] == 5:
                    st.markdown('<b>User is looking to trade</b>', unsafe_allow_html=True)
                if friend_info["online_status"] == 6:
                    st.markdown('<b>User is looking to play</b>', unsafe_allow_html=True)

                st.image(friend_info["avatarfull"], caption='Friend Profile picture')
                st.markdown(f'<b>Friend\'s Profile URL:</b> <i>{friend_info["profileurl"]}</i>', unsafe_allow_html=True)
                st.divider()

        # Tonen van de achievements van games die de user heeft
        with st.expander(f'{user_information["username"]}\'s achievements, games are in alphabetical order'):
            owned_games_list.sort()
            for i in owned_games_list:
                achievements = get_achievements(user_id, i)
                st.markdown(f'{achievements}', unsafe_allow_html=True)
