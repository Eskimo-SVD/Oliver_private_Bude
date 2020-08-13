#!/usr/bin/python3
# coding=utf-8
# Script-Datei pin7-high.py

import RPi.GPIO as GPIO
import time

# Warnung, dass der GPIO-Kanal noch offen ist, unterdruecken
GPIO.setwarnings(False)

# Pin-Nummern verwenden (nicht GPIO-Nummern)
GPIO.setmode(GPIO.BOARD)

# Wir wollen Pin 7 (=GPIO 4) schalten
GPIO.setup(7, GPIO.OUT)
GPIO.output(7, GPIO.HIGH)

GPIO.cleanup()

