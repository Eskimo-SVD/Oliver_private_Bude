#!/usr/bin/python3
# coding=utf-8
# Script-Datei pin7-low.py
import RPi.GPIO as GPIO
import time

# Pin-Nummern verwenden (nicht GPIO-Nummern)
GPIO.setmode(GPIO.BOARD)

# wir wollen Pin 7 (=GPIO 4) schalten
GPIO.setup(7, GPIO.OUT)
GPIO.output(7, GPIO.LOW)

