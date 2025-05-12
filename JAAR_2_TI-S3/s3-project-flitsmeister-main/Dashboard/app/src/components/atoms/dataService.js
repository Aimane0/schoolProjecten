// src/services/dataService.js

// Met deze file willen we data ophalen van de API. We maken gebruik van axios om een GET request te sturen naar de API.
// Het kan zijn dat we deze file omgooien, er is namelijk nog een besluit om te maken of wij een API willen maken of dat het mogelijk is om 
// rechtstreeks van de MongoDB database te lezen.

import axios from 'axios';

const API_URL = 'https://100.69.176.84:5000/leaderboard';

export const fetchLeaderboardData = async () => {
  try {
    const response = await axios.get(API_URL);
    const data = response.data;

    // Parse the data using the correct field names
    const parsedData = data.map((player) => ({
      name: player.name,
      speed: player.speed_kmh,
      date: player.timestamp,
    }));

    // Sort data by speed in descending order
    parsedData.sort((a, b) => b.speed - a.speed);

    return parsedData;
  } catch (error) {
    console.error('Error fetching leaderboard data:', error);
    return [];
  }
};