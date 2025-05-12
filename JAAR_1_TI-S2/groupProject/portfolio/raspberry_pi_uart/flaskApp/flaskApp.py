from datetime import datetime
from flask import Flask, render_template
from flask_socketio import SocketIO
import json
import paho.mqtt.subscribe as subscribe

app = Flask(__name__)
socketio = SocketIO(app)

# Functie om MQTT-berichten te ontvangen en door te sturen naar de client
def mqtt_listener():
    while True:
        mqtt_tempmsg = subscribe.simple("kas/temperature", hostname="parkrangers.wifi.hu.nl")
        mqtt_presmsg = subscribe.simple("kas/pressure", hostname="parkrangers.wifi.hu.nl")
        mqtt_humimsg = subscribe.simple("kas/humidity", hostname="parkrangers.wifi.hu.nl")
        mqtt_soilmsg = subscribe.simple("kas/soil", hostname="parkrangers.wifi.hu.nl")

        tempdict = json.loads(mqtt_tempmsg.payload)
        presdict = json.loads(mqtt_presmsg.payload)
        humidict = json.loads(mqtt_humimsg.payload)
        soildict = json.loads(mqtt_soilmsg.payload)

        data = {
            'temperature': {'value': tempdict['Temperature'], 'unit': tempdict['Unit']},
            'pressure': {'value': presdict['Pressure'], 'unit': presdict['Unit']},
            'humidity': {'value': humidict['Humidity'], 'unit': humidict['Unit']},
            'soil': {'value': soildict['Soil Humidity'], 'unit': soildict['Unit']}
        }
        socketio.emit('update_data', data)
        socketio.sleep(1)  # Update elke seconde

@app.route("/")
def index():
    # Tijd maken om te tonen als klok op de app
    timeAndDayNow = datetime.now().replace(microsecond=0)

    return render_template('index.html', timeAndDayNow=timeAndDayNow)

@socketio.on('connect')
def handle_connect():
    print('Client connected')

if __name__ == "__main__":
    # Start de MQTT-berichten luisteraar in een aparte thread
    import threading
    mqtt_thread = threading.Thread(target=mqtt_listener)
    mqtt_thread.daemon = True
    mqtt_thread.start()

    # Start de Flask app met SocketIO
    socketio.run(app, host='0.0.0.0', port=5000)
