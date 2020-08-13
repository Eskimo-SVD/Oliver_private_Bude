#!/usr/bin/python3
# Datei ds18b20.py
from w1thermsensor import W1ThermSensor

# Einzelnen Sensor auslesen:
# Sensornummer zuvor mit 
# "cat /sys/devices/w1_bus_master1/w1_master_slaves" auslesen.
# Nur die Bezeichnung nach dem Bindestrich eintragen.
sensor = W1ThermSensor(W1ThermSensor.THERM_SENSOR_DS18B20, "000802ae1551")

temperature_in_celsius = sensor.get_temperature()
print("Einzelsensor:", temperature_in_celsius)

    
# Alle verfügbaren Sensoren auslesen:
for sensor in W1ThermSensor.get_available_sensors():
    print("Sensorliste:\nSensor %s hat die Temperatur %.2f" %(sensor.id, sensor.get_temperature()))