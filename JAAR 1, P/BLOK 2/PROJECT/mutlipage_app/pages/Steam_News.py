import streamlit as st
import requests, json
import os
import re

st.title('Read the latest Steam News!')
st.sidebar.success('Select a page above.')

# Functie om games uit een JSON-bestand in te laden
def load_games_from_json(json_file_path):
    with open(json_file_path, 'r') as file:
        games_data = json.load(file)
    return games_data

def replace_img_tags(contents):
    img_tag_pattern = r'\[img\](.*?)\[/img\]'
    img_replace_pattern = r'<img src="\1" alt="Steam News Image">'

    return re.sub(img_tag_pattern, img_replace_pattern, contents)

# JSON-bestandspad
project_pad = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
steam_json_pad = os.path.join(project_pad, 'steam.json')

# Tijdelijke hashmap ter testen
available_games = load_games_from_json(steam_json_pad)
game_names = []
for game in available_games:
    game_names.append(game["name"])

game_news = st.selectbox('From which game would you like to see the latest news articles?', game_names, index=None)

selected_game = next((game for game in available_games if game["name"] == game_news), None)

try:
    if selected_game is not None:
        # API aanvragen
        news_uri = 'https://api.steampowered.com/ISteamNews/GetNewsForApp/v2/'
        params = {
            'appid': selected_game["appid"]
        }

        response = requests.get(news_uri, params)
        data = response.json()

        if 'newsitems' in data.get('appnews', {}):
            news_items = data['appnews']['newsitems'][:20]

            for index, item in enumerate(news_items):

                    contents = item.get('contents', "")

                    # Overslaan van de tekst als deze bepaalde tags bevatten
                    tags_to_skip = ['[list]', '[*]', '[/list]', '[h1]', '[/h1]', '[b]', '[u]', '[i]',
                                    'url=', '[previewyoutube=']
                    if any(tag in contents for tag in tags_to_skip):
                        continue

                    st.markdown(f'<b><p style="font-size:30px;">Steam news article: </b></p>{contents}<br>', unsafe_allow_html=True)

        else:
            st.error("Please select a game.")

except Exception as e:
    st.error(f"An error occurred: {str(e)}")
