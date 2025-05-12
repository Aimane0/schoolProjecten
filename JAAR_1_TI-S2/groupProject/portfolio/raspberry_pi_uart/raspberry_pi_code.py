import psycopg2
import serial
import time
import paho.mqtt.client as mqtt
import json
from datetime import datetime

password_file = open("password.txt", "r")

"""Sets connection to database"""
connection = psycopg2.connect(host="parkrangers.wifi.hu.nl", port="5432", database="postgres", user="postgres", password=password_file)
cursor = connection.cursor()

"""MQTT connectie"""
client = mqtt.Client("Test123Test")
client.connect("parkrangers.wifi.hu.nl", port=1883)

"""UART"""
def listen_to_serial(port_name, baudrate=9600):
    # Maak een verbinding met de seriële poort
    ser = serial.Serial(port_name, baudrate, timeout=1)

    try:
        print(f"Luisteren naar gegevens op {port_name} ...")
        while True:
            data = ser.readline()  # Lees een regel van de seriële poort
            if data:
                """Sets time"""
                timeAndDayNow = datetime.now()
                timeAndDayNow = timeAndDayNow.replace(microsecond=0)
                print(f"Ontvangen: {data.decode().strip()}")
                cursor.execute(
                        """
                        INSERT INTO temperature (tempcelcius, postedtime)
                        VALUES (%s, %s)
                        """,
                        (data.decode().strip(), timeAndDayNow)
                        )

                """MQTT data publishing"""
                mqtt_msg = json.dumps({"Time": str(timeAndDayNow),"Unit":"Celcius","Temperature":data.decode().strip()})
                client.publish("kas/temperature/outsideTemp", mqtt_msg)
                connection.commit()

                time.sleep(5)

    except KeyboardInterrupt:
        print("\nProgramma gestopt.")
    finally:
        ser.close()

if __name__ == "__main__":
    PORT_NAME = '/dev/ttyUSB0'  # Voor de Raspberry Pi
    listen_to_serial(PORT_NAME)
