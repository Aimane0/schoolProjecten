import streamlit as st
import requests, json

st.title('Check a users information by their steamID')
st.sidebar.success('Select a page above.')

# Search functie om player info te vinden
search_bar = st.text_input('Fill in any steamID to see their info!')

# Vraagt de vrienden lijst op van de ingevulde gebruiker via een API
def get_friends_list_ids(api_key, user_steam_id):
    base_url = "http://api.steampowered.com/ISteamUser/GetFriendList/v0001/"
    params = {
        'key': api_key,
        'steamid': user_steam_id,
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

# Vraagt de basic informatie op van de user via een api
def get_basic_summary(api_key, user_steam_id):
    summary = (f'http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?'
               'key=F5165515610F99F856E8B2325E3F4AF7&'
               f'steamids={search_bar}&'
               f'format=json')
    summary_response = requests.get(summary)
    summary_data = summary_response.json()

    player = summary_data.get('response', {}).get('players',[])

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
        return{
            'There is no user information available'
        }

# Zoekt naar de relevante informatie van de ids uit de vriendenlijst
def get_friends_basic_summary(api_key, friends_steam_ids):
    friends_summary_data = []

    for friend_id in friends_steam_ids:
        summary = (f'http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?'
                   f'key={api_key}&'
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

# Wanneer de searchbar ingevuld is wordt de info getoond op het dashboard
if search_bar:
    # Algemene steam info opvragen
    summary_data = get_basic_summary('F5165515610F99F856E8B2325E3F4AF7', search_bar)
    # foto van de user in een variabel vastleggen
    profile_picture = summary_data["avatarfull"]

    st.header('Result:', divider='grey')
    # Vormgeving van het dashboard met basic user info
    st.markdown(f'<b>Username:</b> <i>{summary_data["username"]}</i>', unsafe_allow_html=True)
    if summary_data["online_status"] == 0:
        st.markdown('<b>User is offline</b>', unsafe_allow_html=True)
    if summary_data["online_status"] == 1:
        st.markdown('<b>User is online</b>', unsafe_allow_html=True)
    if summary_data["online_status"] == 2:
        st.markdown('<b>User is busy</b>', unsafe_allow_html=True)
    if summary_data["online_status"] == 3:
        st.markdown('<b>User is away</b>', unsafe_allow_html=True)
    if summary_data["online_status"] == 4:
        st.markdown('<b>User is snoozing</b>', unsafe_allow_html=True)
    if summary_data["online_status"] == 5:
        st.markdown('<b>User is looking to trade</b>', unsafe_allow_html=True)
    if summary_data["online_status"] == 6:
        st.markdown('<b>User is looking to play</b>', unsafe_allow_html=True)
    st.image(profile_picture, caption='Profile picture')
    st.markdown(f'<b>Profile URL:</b> <i>{summary_data["profileurl"]}</i>',unsafe_allow_html=True)
    st.markdown('<br>', unsafe_allow_html=True)

    # Vraagt de vrienden lijst op en vraagt vervolgens via de opgevraagde vrienden lijst alle informatie over die vrienden op via hun ids
    friends_steamid = get_friends_list_ids('F5165515610F99F856E8B2325E3F4AF7', search_bar)
    friends_summary_data = get_friends_basic_summary('F5165515610F99F856E8B2325E3F4AF7', friends_steamid)

    # Vormgeven van de vrienden lijst
    st.header(f'{summary_data["username"]}\'s friendlist', divider='grey')
    with st.expander(f'Amount of friends: {len(friends_steamid)}'):
        for friend_info in friends_summary_data:
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
