import React from "react";

function Navbar() {
  return (
    <div className="bg-gray-200 font-sans leading-normal tracking-normal">
      <nav className="bg-blue-800 text-white flex items-center h-16 px-4">
        <a href="/" className="h-full">
          <img
            src={require('../../../assets/img/Flitsmaister_Navbar.png')}
            alt="Logo"
            className="h-full"
          />
        </a>
        <ul className="list-none m-0 p-0 flex justify-center items-center flex-grow">
          <li>
            <a className="block text-white text-2xl font-arial p-5 no-underline hover:bg-blue" href="/">Leaderboard</a>
          </li>
          <li>
            <a className="block text-white text-2xl font-arial p-5 no-underline hover:bg-blue" href="/Speed">Snelheden</a>
          </li>
          <li>
            <a className="block text-white text-2xl font-arial p-5 no-underline hover:bg-blue" href="/Identification">Identificatie</a>
          </li>
          <li>
            <a className="block text-white text-2xl font-arial p-5 no-underline hover:bg-blue" href="/Login">Login</a>
          </li>
        </ul>
      </nav>
    </div>
  );
}

export default Navbar;

// Hier is het Navbar ontwerp te zien, dit is een simpele Navbar met een link naar de Leaderboard pagina.