#!/usr/bin/python3
# -*- coding: utf-8 -*-
import RPi.GPIO as GPIO
import time
# Pin-Nummern verwenden (nicht GPIO-Nummern!)
GPIO.setmode(GPIO.BOARD)
# Pin 26 (= GPIO 7) zur Datenausgabe verwenden
GPIO.setup(26, GPIO.OUT)

# Pin 26 einschalten
GPIO.output(26, GPIO.HIGH)
# Pin 26 nach fünf Sekunden wieder ausschalten
time.sleep(5)
GPIO.output(26, GPIO.LOW)

# alle vom Script benutzten GPIOs/Pins wieder freigeben
GPIO.cleanup()
