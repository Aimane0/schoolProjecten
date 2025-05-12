import React, { useEffect, useState } from "react";
import Navbar from "../../molecules/Navbar/Navbar";
import axios from 'axios';

const API_URL = 'https://100.69.176.84:5000/speeds';

const recentSpeeds = async () => {
  try {
      const response = await axios.get(API_URL);
      const data = response.data;
  
      // Parse the data using the correct field names
      const parsedData = data.map((player) => ({
        speed: player.speed_kmh,
        date: player.timestamp.split('T')[0], // Extract only the date portion
      }));

      return parsedData;

    } catch (error) {
      console.error('Error fetching leaderboard data:', error);
      return [];
    }
  };

function Speed() {
  const [latestSpeed, setLatestSpeed] = useState(null);
  const [latestDate, setLatestDate] = useState(null);
  useEffect(() => {
    const fetchData = async () => {
      try {
        const data = await recentSpeeds();
        if (data.length > 0) {
          setLatestSpeed(data[0].speed);
          setLatestDate(data[0].date);
        }
      } catch (error) {
        console.error('Error fetching data:', error);
      }
    };

    fetchData();
    const intervalID = setInterval(fetchData, 3000); // Fetch the data every 3 seconds

    return () => {clearInterval(intervalID)}; // Clear the interval when the component unmounts
  }, []);

  return (
    <div className="bg-white">
      <header>
      <Navbar/>
      </header>
      <div className="flex flex-col items-center text-center px-4 py-8">
      <div className="flex-1 flex items-center justify-center">
        <p className="text-9xl font-extrabold text-blue-600 justify-center mt-60">
          {latestSpeed !== null ? `${latestSpeed} km/h` : "Laden..."}
        </p>
        </div>
        <p className="text-2xl text-gray-500 justify-center mt-5">Datum: {latestDate}
        </p>
      </div>
    </div>
  );
}

export default Speed;
