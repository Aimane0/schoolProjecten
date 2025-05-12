# **Testplan voor main.cpp van Wifi-Mesh**

## **Doel**
Het doel van dit testplan is om de functionaliteit van de mesh-netwerkcommunicatie, taakbeheer en berichtverwerking te valideren met behulp van de **painlessMesh**, **CleanRTOS**, en andere gebruikte bibliotheken.

---

## **Testomgeving**
- **Hardware**: Minimaal twee ESP32 microcontrollers.
- **Software**:
  - Arduino IDE met geconfigureerde ESP32 boardmanager of in PlatformIO.
  - Bibliotheken:
    - painlessMesh
    - CleanRTOS
    - AsyncTCP (voor ESP32) of ESPAsyncTCP (voor ESP8266)
    - Arduino-ESP32 core.

---

## **Testscenario's**

### **1. Mesh-netwerk initialisatie**
- **Testdoel**: Verifiëren dat nodes succesvol verbinding maken met het mesh-netwerk.
- **Stappen**:
  1. Upload de code naar twee of meer ESP-nodes.
  2. Monitor de seriële monitor (115200 baud).
- **Verwachte resultaten**:
  - Logs zoals:
    ```
    New Connection, nodeId = <NodeID>
    Changed connections
    ```

---

### **2. Verzenden van broadcast-berichten**
- **Testdoel**: Controleren of de nodes correct broadcast-berichten verzenden.
- **Stappen**:
  1. Start nodes.
  2. Bekijk seriële output op elk apparaat.
- **Verwachte resultaten**:
  - Elk apparaat verzendt berichten zoals:
    ```
    Broadcasted message: Hi from node 1 with ID: <NodeID>
    ```

---

### **3. Ontvangen van berichten**
- **Testdoel**: Controleren of ontvangen berichten worden verwerkt en gelogd.
- **Stappen**:
  1. Start alle nodes.
  2. Controleer de seriële output voor ontvangen berichten.
- **Verwachte resultaten**:
  - Een node logt een ontvangen bericht zoals:
    ```
    Received message: <SenderID>: Hi from node 1 with ID: <NodeID>
    ```

---

### **4. Queue-functionaliteit**
- **Testdoel**: Verifiëren dat de message queue correct berichten buffert en doorstuurt naar de verwerkingslogica.
- **Stappen**:
  1. Stress-test het systeem door meerdere berichten snel te verzenden.
  2. Controleer de seriële output.
- **Verwachte resultaten**:
  - Geen berichten verloren.
  - Berichten worden in de volgorde van ontvangst verwerkt.

---

### **5. Mesh-updates**
- **Testdoel**: Controleren of de mesh regelmatig wordt bijgewerkt.
- **Stappen**:
  1. Voeg nieuwe nodes toe aan het netwerk.
  2. Observeer of `Changed connections` en `New Connection` worden gelogd.
- **Verwachte resultaten**:
  - Nieuwe nodes worden herkend en logs worden gegenereerd.

---

## **Resultatenregistratie**

| **Testscenario**            | **Resultaat**       |
|-----------------------------|---------------------|
| Mesh-netwerk initialisatie  | Geslaagd            |
| Verzenden van berichten     | Geslaagd            |
| Ontvangen van berichten     | Geslaagd            |
| Queue-functionaliteit       | Geslaagd            |
| Mesh-updates                | Geslaagd            |

---

## **Extra Documentatie**

1. **Initialisatie**: Gecontroleerd of nodes correct starten en verbinding maken met het mesh-netwerk. Noteer eventuele foutmeldingen.
2. **Debugging**: Gebruik gemaakt van seriële logging om de communicatie te checken.
3. **Tuning**: `vTaskDelay` aangepast in taken om de prestaties te optimaliseren.
4. **Stress-test**: Meerdere nodes toegevoegd (>3) om te testen of het systeem schaalbaar is.

---

## **Conclusie**
De tests bevestigden dat het systeem stabiel, efficiënt en flexibel werkt in een mesh-netwerk van meerdere nodes. Berichten werden zonder verlies verzonden, ontvangen en verwerkt. Het gebruik van CleanRTOS zorgde voor juiste taakbeheer, en logging hielp bij het monitoren van netwerkactiviteiten. Het netwerk bleef stabiel bij 4 nodes. Optimalisaties in geheugenbeheer en het toevoegen van uitgebreide berichtinformatie, zoals timestamps, kunnen de functionaliteit eventueel nog verder verbeteren. 

WAARSCHUWING: De ESP IDF moet ge-downgrade worden naar een versie tussen 5.1 en 5.19, anders werken de gebruikte functionaliteiten NIET.
