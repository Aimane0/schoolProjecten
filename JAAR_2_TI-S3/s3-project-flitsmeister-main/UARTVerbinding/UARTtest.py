import serial
import time
from pymongo import MongoClient

# Setup UART
ser = serial.Serial("/dev/serial0", 115200, timeout=1)

# Setup MongoDB Connection
client = MongoClient("mongodb://flitsmaister:flitsmaister@flitsmaister:27017/")
db = client["flitsmaister_speeddetector"]
collection = db["SpeedAndTimes"]
identification_collection = db["Identification"]

print("Wachten op gegevens van ESP32...")

# Variabelen voor opslag
ir_id = None
speed_kmh = None

def save_to_db(name, speed_kmh):
    """Slaat ID, naam en snelheid op in de MongoDB database."""
    if name and speed_kmh:
        data = {
            "name": name,
            "speed_kmh": speed_kmh,
            "timestamp": time.strftime("%Y-%m-%d %H:%M:%S")
        }
        collection.insert_one(data)
        print(f"Gegevens opgeslagen in MongoDB: {data}")

def get_name_from_id(ir_id):
    ir_id = ir_id.lower().strip("0x")
    """Haalt de naam op die hoort bij de gegeven ir_id."""
    result = identification_collection.find_one({"_id": "identification_data"})
    if result and "data" in result and ir_id in result["data"]:
        return result["data"][ir_id]  # Geef de bijbehorende naam terug
    return None


while True:
    try:
        # Wacht op nieuwe data als de variabelen leeg zijn
        if ir_id is None and speed_kmh is None:
            data = ser.readline().decode('utf-8', errors='ignore').strip()

            if data:
                print(f"Ontvangen: {data}")

                # Parsing van ID en snelheid
                if "ID:" in data and "SPEED:" in data:
                    parts = data.split(" ")
                    ir_id = parts[0].split(":")[1]  # ID opslaan
                    speed_kmh = float(parts[1].split(":")[1])  # Snelheid opslaan

        # Alleen opslaan als beide variabelen gevuld zijn
        if ir_id and speed_kmh:
            # Naam ophalen uit de database
            name = get_name_from_id(ir_id)

            if name:
                print(f"ID {ir_id} komt overeen met naam: {name}")
                save_to_db(name, speed_kmh)
            else:
                print(f"Geen overeenkomst gevonden voor ID {ir_id}")

            # Variabelen resetten na succesvolle verwerking
            ir_id = None
            speed_kmh = None

        time.sleep(0.1)  # Voorkom overbelasting van CPU

    except Exception as e:
        print(f"Fout: {e}")

