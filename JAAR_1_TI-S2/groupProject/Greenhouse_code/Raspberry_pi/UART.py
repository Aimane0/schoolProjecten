import psycopg2
import serial
import time
import paho.mqtt.client as mqtt
import json
from datetime import datetime

password_file = open("password.txt","r")

#Sets connection to database
connection = psycopg2.connect(host="parkrangers.wifi.hu.nl", port="5432", database="postgres", user="postgres", password=password_file)
cursor = connection.cursor()

#MQTT connectie
client = mqtt.Client("Test123Test")
client.connect("parkrangers.wifi.hu.nl", port=1883)

def listen_to_serial(port_name, baudrate=9600):

    # Maak een verbinding met de seriële poort
    ser = serial.Serial(port_name, baudrate, timeout=1)
    serSend = serial.Serial('/dev/ttyUSB1', baudrate, timeout=1)

    try:
        print(f"Luisteren naar gegevens op {port_name} ...")
        while True:
            temp = ser.readline()  # Lees een regel van de seriële poort
            pres = ser.readline()
            humi = ser.readline()
            soil = ser.readline()

            # write to USB1
            serSend.write(temp)
            serSend.write(b'\n')
            serSend.write(pres)
            serSend.write(b'\n')
            serSend.write(humi)
            serSend.write(b'\n')
            serSend.write(soil)
            serSend.write(b'\n')
            if temp and pres and humi and soil:
                # Sets time
                timeAndDayNow = datetime.now()
                timeAndDayNow = timeAndDayNow.replace(microsecond=0)
                cursor.execute(
                        """
                        INSERT INTO temperature (tempcelcius, postedtime)
                        VALUES (%s, %s)
                        """,
                        (temp.decode().strip(), timeAndDayNow)
                        )
                connection.commit()
                cursor.execute(
                        """
                        INSERT INTO pressure (pressurehpa, postedtime)
                        VALUES (%s, %s)
                        """,
                        (pres.decode().strip(), timeAndDayNow)
                        )
                connection.commit()
                cursor.execute(
                        """
                        INSERT INTO humidity (humidityrh, postedtime)
                        VALUES (%s, %s)
                        """,
                        (humi.decode().strip(), timeAndDayNow)
                        )
                connection.commit()

                cursor.execute(
                        """
                        INSERT INTO soil (soilhumidity, postedtime)
                        VALUES (%s, %s)
                        """,
                        (soil.decode().strip(), timeAndDayNow)
                        )
                connection.commit()
                
                #MQTT data publishing
                mqtt_tempmsg = json.dumps({"Time": str(timeAndDayNow),"Unit":"Celcius","Temperature":temp.decode().strip()})
                mqtt_presmsg = json.dumps({"Time": str(timeAndDayNow),"Unit":"hPa","Pressure":pres.decode().strip()})
                mqtt_humimsg = json.dumps({"Time": str(timeAndDayNow),"Unit":"RH%","Humidity":humi.decode().strip()})
                mqtt_soilmsg = json.dumps({"Time": str(timeAndDayNow),"Unit":"%","Soil Humidity":soil.decode().strip()})
                
                client.publish("kas/temperature", mqtt_tempmsg)
                client.publish("kas/pressure", mqtt_presmsg)
                client.publish("kas/humidity", mqtt_humimsg)
                client.publish("kas/soil", mqtt_soilmsg)
                time.sleep(5)
    except KeyboardInterrupt:
        print("\nProgramma gestopt.")
    finally:
        ser.close()

if __name__ == "__main__":
    PORT_NAME = '/dev/ttyUSB0'  # Voor de Raspberry Pi
    listen_to_serial(PORT_NAME)
