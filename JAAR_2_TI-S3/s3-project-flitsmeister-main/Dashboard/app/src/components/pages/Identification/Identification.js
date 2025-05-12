import React, { useState, useEffect } from "react";
import axios from "axios";
import Navbar from "../../molecules/Navbar/Navbar";

function Identification() {
  const variables = [
    "IR Riem 1",
    "IR Riem 2",
    "IR Riem 3",
    "IR Riem 4",
    "IR Riem 5",
  ];

  // Initialize input values with localStorage data (if any) or empty strings
  const savedNames = localStorage.getItem("enteredNames");
  const initialValues = savedNames && savedNames !== "undefined" 
    ? JSON.parse(savedNames) 
    : Array(variables.length).fill("");

  const [inputValues, setInputValues] = useState(initialValues);
  const [isDisabled, setIsDisabled] = useState(true);

  // Save inputValues to localStorage whenever it changes
  useEffect(() => {
    localStorage.setItem("enteredNames", JSON.stringify(inputValues));
  }, [inputValues]);

  const handleInputChange = (index, value) => {
    const newValues = [...inputValues];
    newValues[index] = value;
    setInputValues(newValues);
  };

  const handleSend = async () => {
    setIsDisabled(true);
    const identifiers = ["ff30cf", "ff18e7", "ff7a85", "ff10ef", "ff38c7"];
    const dataToSend = identifiers.reduce((acc, id, index) => {
      acc[id] = inputValues[index];
      return acc;
    }, {});

    try {
      const response = await axios.post("https://100.69.176.84:5000/store-data", {
        data: dataToSend,
      });
      console.log(response.data.message); // Log success message
    } catch (error) {
      console.error("Error sending data:", error);
    }
  };

  const handleFocus = () => {
    setIsDisabled(false); // Unlock the fields when focused
  };

  function showNotification(message, duration = 3000) {
    const notification = document.getElementById("notification");

    // Set the message
    notification.textContent = message;

    // Show the notification with Tailwind classes
    notification.classList.remove("hidden", "opacity-0", "-translate-y-5");
    notification.classList.add("opacity-100", "translate-y-0");

    // Hide the notification after the specified duration
    setTimeout(() => {
      notification.classList.remove("opacity-100", "translate-y-0");
      notification.classList.add("opacity-0", "-translate-y-5");

      // Wait for the transition to complete before hiding the element
      setTimeout(() => {
        notification.classList.add("hidden");
      }, 500); // Match the Tailwind `duration-500`
    }, duration);
  }

  return (
    <div className="bg-white min-h-screen">
      <header>
        <Navbar />
      </header>
      <main className="p-8">
        <h2 className="text-black text-4xl text-center mb-8">
          Namen Identificatie-riemen
        </h2>
        <form className="max-w-lg mx-auto">
          {variables.map((variable, index) => (
            <div key={index} className="flex items-center mb-4">
              <label className="w-1/3 text-xl text-gray-700">{variable}</label>
              <input
                type="text"
                className={`w-2/3 p-2 border border-gray-300 rounded-lg ${
                  isDisabled ? "bg-gray-200" : ""
                }`} 
                placeholder={`Enter ${variable.toLowerCase()}`}
                value={inputValues[index]}
                onChange={(e) => handleInputChange(index, e.target.value)}
                onFocus={handleFocus}
              />
            </div>
          ))}
          <div 
              id="notification"
              className="mt-4 hidden fixed items-center justify-center p-4 bg-blue-700 text-white py-2 px-2 rounded-lg shadow-lg opacity-0 transform -translate-y-5 transition-all duration-500"
            ></div>
          <div className="flex justify-end mt-8">
            <button
              type="button"
              className="bg-blue-500 text-white px-4 py-2 rounded-lg hover:bg-blue-700"
              onClick={() => {
                handleSend();
                showNotification("Gegevens zijn opgeslagen!");
              }}
            >
              Opslaan
            </button>
          </div>
        </form>
      </main>
    </div>
  );
}

export default Identification;
