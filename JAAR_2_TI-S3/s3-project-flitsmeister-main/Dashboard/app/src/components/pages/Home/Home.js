import React, { useEffect, useState } from 'react';
import Navbar from '../../molecules/Navbar/Navbar';
import { fetchLeaderboardData } from '../../atoms/dataService';

function Home() {
  const [leaderboardData, setLeaderboardData] = useState([]); // Initialize the leaderboardData state with an empty array

  useEffect(() => {
    const getData = async () => {
      const data = await fetchLeaderboardData(); // Fetch the leaderboard data from the API called in dataService.js
      setLeaderboardData(data); // Update the leaderboardData state with the fetched data
    };

    getData();
    const intervalID = setInterval(getData, 5000); // Fetch the data every 5 seconds

    return () => {clearInterval(intervalID)}; // Clear the interval when the component unmounts
  }, []);

  return (
    <div className="bg-white">
      <header>
        <Navbar />
      </header>
      <main className="bg-white shadow-md text-center">
        <div className="overflow-x-auto"> {/* Add a horizontal scrollbar when the table is too wide */}
        <table className="min-w-full border-collapse">
            <thead>
              <tr>
                <th className="bg-blue-700 text-white text-6xl text-center pr-20">Rang</th>
                <th className="bg-blue-700 text-white text-6xl text-center pl-2">Speler</th>
                <th className="bg-blue-700 text-white text-6xl text-center">Snelheid</th>
              </tr>
            </thead>
            <tbody id="leaderboard-body">
              {leaderboardData.map((player, index) => (
                <tr key={player.id} className="bg-white text-6xl border-b-2 border-black">
                  <td className="text-center pr-20">{index + 1}</td>
                  <td className="text-center pl-20">{player.name}</td>
                  <td className="text-center pl-10">{player.speed} km/u</td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </main>
    </div>
  );
}

export default Home; // Don't forget to export the component so it can be used in other files

// In dit bestand is de Home pagina te zien. Hier wordt de data van de API opgehaald en weergegeven in een tabel.