import streamlit as st
import matplotlib.pyplot as plt
import json
import pandas as pd
import os

def load_games_from_json(json_file_path):
    with open(json_file_path, 'r') as file:
        games_data = json.load(file)
    return games_data

def gradient_descent(m_now, b_now, points, L):
    m_gradient = 0
    b_gradient = 0

    n = len(points)

    for i in range(n):
        x = points["average_playtime"].iloc[i]
        y = points["positive_ratings"].iloc[i]

        m_gradient += (-2/n) * x * (y - (m_now * x + b_now))
        b_gradient += (-2/n) * (y - (m_now * x + b_now))

    m = m_now - m_gradient * L
    b = b_now - b_gradient * L

    return m, b

project_pad = os.path.dirname(os.path.abspath(__file__))
steam_json_pad = os.path.join(project_pad, 'steam.json')

# Tijdelijke hashmap ter testen
steam_json_file = load_games_from_json(steam_json_pad)

st.subheader('Linear regression of positive ratings and average playtime')
data_df = pd.DataFrame(steam_json_file)

# Filter games met minder dan 1000 positieve beoordelingen
data_df = data_df[data_df['positive_ratings'] >= 1000]

# Filter games met een gemiddelde speeltijd tussen 0 en 6000
data_df = data_df[(data_df['average_playtime'] > 0) & (data_df['average_playtime'] <= 6000)]

average_playtime = data_df["average_playtime"].tolist()
positive_ratings = data_df["positive_ratings"].tolist()

m = 0
b = 0
L = 0.0000001  # Verklein de learning rate
epochs = 1000

m_values = []
b_values = []

for i in range(epochs):
    m, b = gradient_descent(m, b, data_df, L)
    m_values.append(m)
    b_values.append(b)

plt.figure()
plt.scatter(average_playtime, positive_ratings)
plt.plot(average_playtime, [m_values[-1] * x + b_values[-1] for x in average_playtime], color='red')
plt.xlabel('Average Playtime')
plt.ylabel('Positive Ratings')
plt.title('Scatterplot: Average Playtime vs. Positive Ratings (Filtered)')
st.pyplot(plt)

st.divider()
