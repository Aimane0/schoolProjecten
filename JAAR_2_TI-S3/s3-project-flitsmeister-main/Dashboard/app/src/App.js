import React from 'react';
import { Routes, Route } from "react-router-dom";
import { BaseLayout } from "./components/templates/BaseTemplate";
import { Home } from "./components/pages/Home";
import { Identification } from "./components/pages/Identification";
import { Login } from "./components/pages/Login"
import { Data } from "./components/pages/Data";
import { Speed } from "./components/pages/Speed";
import "./App.css";

function App() {
  return (
    <Routes>
      <Route path="/" element={<BaseLayout />}>
        <Route index element={<Home />} />
      </Route>
      <Route path="/Identification" element={<BaseLayout />}>
        <Route index element={<Identification />} />
      </Route>
      <Route path="/Login" element={<BaseLayout />}>
        <Route index element={<Login />} />
      </Route>
      <Route path="/Data" element={<BaseLayout />}>
        <Route index element={<Data />} />
      </Route>
      <Route path="/Speed" element={<BaseLayout />}>
        <Route index element={<Speed />} />
      </Route>
    </Routes>
  );
}

export default App;

// In dit bestand is de App component te zien. Hier wordt de routing van de applicatie geregeld. De Home pagina wordt weergegeven in de BaseLayout template.