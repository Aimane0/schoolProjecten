Dit zijn screenshots als bewijs dat wij MQTT, Flask en Postgres draaiende hebben gekregen via DOCKER.

Onze one wire warmte sensor, aangestuurd door een Arduino, verstuurt de opgemeten temperatuur naar de Raspberry Pi 4.
Deze verstuurt in JSON format de tijd en datum, temperatuur en eenheid van de temperatuur op naar MQTT.
Ook wordt deze data verstuurd naar onze PostgreSQL database.

De FlaskApp vraagt MQTT de verkregen JSON data en leest de JSON file uit om te printen op een webpage.

Dit is allemaal terug te zien in de fotos van deze map.

![](https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/portfolio/raspberry_pi_uart/bewijslast_werking/bewijslast_flaskapp.jpg)

![](https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/portfolio/raspberry_pi_uart/bewijslast_werking/bewijslast_werking_mqtt.jpg)

![](https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/portfolio/raspberry_pi_uart/bewijslast_werking/bewijstlast_mqtt_json.jpg)

![](https://github.com/TICT-TV1SE2-2324/kas-project-parkrangers/blob/main/portfolio/raspberry_pi_uart/bewijslast_werking/bewijstlast_werking_postgres.jpg)
