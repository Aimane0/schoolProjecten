import React, { useEffect, useState, useRef } from "react";
import Navbar from "../../molecules/Navbar/Navbar";
import { fetchLeaderboardData } from "../../atoms/dataService"; // API-aanroep

function Data() {
  const [players, setPlayers] = useState([]); // Volledige spelersdata
  const [selectedPlayer, setSelectedPlayer] = useState(null); // Geselecteerde speler
  const canvasRef = useRef(null);

  // Data ophalen van de API
  useEffect(() => {
    const getData = async () => {
      try {
        const data = await fetchLeaderboardData();
        console.log("Data from API:", data); // Debug: controleer de data uit de API
        
        // Extract player names and set state
        const uniquePlayers = [...new Set(data.map((entry) => entry.Name))]; // Extract unique player names
        setPlayers(uniquePlayers);
      } catch (error) {
        console.error("Error fetching data:", error);
      }
    };

    getData();
  }, []);

  const drawChart = (playerName) => {
    const canvas = canvasRef.current;
    if (!canvas) {
      console.error("Canvas is not available.");
      return;
    }

    const ctx = canvas.getContext("2d");

    // Canvas leegmaken
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    // Filter data voor geselecteerde speler
    const playerData = players.filter((entry) => entry.Name === playerName);
    console.log("Data for selected player:", playerData); // Debug: controleer data voor speler

    if (playerData.length === 0) {
      console.error(`Geen data gevonden voor speler: ${playerName}`);
      return;
    }

    const dates = playerData.map((entry) => entry.Date); // Datums
    const speeds = playerData.map((entry) => parseFloat(entry.WalkedSpeed)); // Snelheden

    // Instellingen voor het staafdiagram
    const barWidth = 40;
    const barGap = 20;
    const chartHeight = 200;
    const chartBase = 250;

    // X- en Y-assen tekenen
    ctx.strokeStyle = "black";
    ctx.lineWidth = 2;

    // X-as
    ctx.beginPath();
    ctx.moveTo(50, chartBase);
    ctx.lineTo(450, chartBase);
    ctx.stroke();

    // Y-as
    ctx.beginPath();
    ctx.moveTo(50, chartBase);
    ctx.lineTo(50, 50);
    ctx.stroke();

    // Staafdiagram tekenen
    ctx.fillStyle = "blue";
    speeds.forEach((speed, index) => {
      const barHeight = (speed / 12) * chartHeight; // Snelheid omzetten naar hoogte
      const x = 50 + index * (barWidth + barGap);
      const y = chartBase - barHeight;

      // Staaf tekenen
      ctx.fillRect(x, y, barWidth, barHeight);

      // Snelheid label op de staaf
      ctx.fillStyle = "black";
      ctx.font = "12px Arial";
      ctx.fillText(speed.toFixed(1), x + barWidth / 4, y - 5);
    });

    // Datum labels onder de staven
    dates.forEach((date, index) => {
      const x = 50 + index * (barWidth + barGap);
      ctx.fillStyle = "black";
      ctx.font = "12px Arial";
      ctx.fillText(date, x + barWidth / 4, chartBase + 20);
    });

    // Y-as labels
    for (let i = 0; i <= 12; i += 2) {
      const y = chartBase - (i / 12) * chartHeight;
      ctx.fillText(i, 25, y + 5);
    }
  };

  useEffect(() => {
    if (selectedPlayer && canvasRef.current) {
      drawChart(selectedPlayer);
    }
  }, [selectedPlayer]);

  return (
    <div>
      <header>
        <Navbar />
      </header>
      <div className="flex h-screen">
        {/* Spelerslijst */}
        <div className="w-1/4 bg-gray-200 p-4">
          <h2 className="text-xl font-bold mb-4">Spelers</h2>
          {players.length > 0 ? (
            players.map((player, index) => (
              <button
                key={index}
                className="block w-full bg-blue-500 text-white p-2 mb-2 rounded hover:bg-blue-700"
                onClick={() => {
                  console.log(`Geselecteerde speler: ${player}`);
                  setSelectedPlayer(player);
                }}
              >
                {player} {/* Render only the player name */}
              </button>
            ))
          ) : (
            <p>Geen spelers gevonden...</p>
          )}
        </div>

        {/* Grafiek */}
        <div className="w-3/4 p-8 bg-white shadow-lg rounded">
          {selectedPlayer ? (
            <>
              <h2 className="text-2xl font-bold mb-4">
                Snelheidsgrafiek van {selectedPlayer}
              </h2>
              <canvas ref={canvasRef} width={500} height={300} />
            </>
          ) : (
            <p className="text-lg text-gray-600">
              Selecteer een speler om de grafiek te bekijken.
            </p>
          )}
        </div>
      </div>
    </div>
  );
}

export default Data;
