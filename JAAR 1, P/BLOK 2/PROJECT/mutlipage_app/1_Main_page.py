import streamlit as st
from PIL import Image

st.set_page_config(
    page_title="Steamvidyafinder",
    page_icon="👌🏻",
)

# Titel van het dashboard met foto
image_steam_logo = Image.open('steam-logo-steam-icon-transparent-free-png.png')
newsize_steam_logo = image_steam_logo.resize((192,192))
st.image(newsize_steam_logo)

st.title('Radical Steam Vidya Game Dashboard')
st.sidebar.success('Select a page above.')

st.markdown('Welcome to our Steam Dashboard!<br> Check out our many features by clicking on the arrow'
            ' in the top left corner!</b>', unsafe_allow_html=True)

st.markdown('<br>', unsafe_allow_html=True)
