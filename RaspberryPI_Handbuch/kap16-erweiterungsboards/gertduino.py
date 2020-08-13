#!/usr/bin/python3
# Datei gertduino.py
import serial, import time, RPi.GPIO as GPIO

# Reset-Modus des Arduino abschalten
GPIO.setmode(GPIO.BCM)
reset = 8
GPIO.setup(reset, GPIO.OUT)
GPIO.output(reset, GPIO.HIGH)
ser = serial.Serial("/dev/ttyAMA0", timeout = 10)
ser.baudrate = 9600
while True:
	daten = ser.readline()
	print("Spannung am Arduino: ", daten.decode('utf-8'))
	time.sleep(.5)
ser.close()