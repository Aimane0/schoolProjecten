import axios from "axios";
import Navbar from "../../molecules/Navbar/Navbar";
import React, { useState, useEffect } from "react";
import { useNavigate } from "react-router-dom";

const Login = (props) => {
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');
    const [usernameError, setUsernameError] = useState('');
    const [passwordError, setPasswordError] = useState('');
  
    const navigate = useNavigate();

    const onButtonClick = async () => {
      setUsernameError('');
      setPasswordError('');
  
      if (!username) {
          setUsernameError('Please enter your username');
          return;
      }
  
      if (!password) {
          setPasswordError('Please enter a password');
          return;
      }
  
      try {
          // Stuur POST-verzoek naar Flask API
          const response = await axios.post('https://100.69.176.84:5000/login', {
              username,
              password,
          });
  
          // Controleer responsstatus
          if (response.status === 200) {
              // Login succesvol: navigeer naar een nieuwe pagina
              navigate('/Data'); // Zorg voor een nieuwe route voor '/dashboard'
          }
      } catch (error) {
          // Behandel foutmeldingen
          if (error.response?.status === 401) {
              setUsernameError('Invalid username or password');
          } else {
              console.error('Login error:', error);
          }
      }
  };
  
    return (
        <div className="min-h-screen bg-gray-100">
          <header>
            <Navbar />
          </header>
          <div className="flex flex-col items-center mt-60">
            <div className={'mainContainer'}>
              <div className={'titleContainer'}>
                <h2 className="text-black text-4xl text-center mb-8">Login</h2>
              </div>
              <div className="flex flex-col items-center">
                <div className="inputContainer mb-4 w-full max-w-sm flex flex-col">
                  <input
                    value={username}
                    placeholder="Vul hier je gebruikersnaam in"
                    onChange={(ev) => setUsername(ev.target.value)}
                    className="px-4 py-2 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-blue-500 w-full"
                  />
                  {usernameError && (
                    <span className="text-red-500 text-sm mt-1">{usernameError}</span>
                  )}
                </div>
                <div className="inputContainer mb-4 w-full max-w-sm flex flex-col">
                  <input
                    type="password"
                    value={password}
                    placeholder="Enter your password here"
                    onChange={(ev) => setPassword(ev.target.value)}
                    className="px-4 py-2 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-blue-500 w-full"
                  />
                  {passwordError && (
                    <span className="text-red-500 text-sm mt-1">{passwordError}</span>
                  )}
                </div>
                <div className={'inputContainer'}>
                  <input
                    type="button"
                    onClick={onButtonClick}
                    value="Log in"
                    className="bg-blue-500 text-white px-4 py-2 rounded-lg hover:bg-blue-700 cursor-pointer"
                  />
                </div>
              </div>
            </div>
          </div>
        </div>
      );            
      
  };
  
  export default Login