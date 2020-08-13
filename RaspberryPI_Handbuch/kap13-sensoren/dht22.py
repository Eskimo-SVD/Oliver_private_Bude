#!/usr/bin/python3
# coding=utf-8
import Adafruit_DHT

# Sensortyp
# Mögliche Eingaben: 
# Adafruit_DHT.DHT11, Adafruit_DHT.DHT22, Adafruit_DHT.AM2302
sensor = Adafruit_DHT.DHT22

# 1-Wire-Pin. BCM-Bezeichnung nutzen!
pin = 4
humidity, temperature = Adafruit_DHT.read(sensor, pin)

if humidity is not None and temperature is not None:
	print ("Temperatur: %.2f" % temperature)
	print ("Luftfeuchtigkeit: %.2f" % humidity)
else:
	print ("Lesefehler. Erneut versuchen!")