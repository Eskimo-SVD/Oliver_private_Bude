#!/usr/bin/python3
# -*- coding: utf-8 -*-
import RPi.GPIO as GPIO
import time, sys

# Pin-Nummern verwenden (nicht GPIO-Nummern!)
GPIO.setmode(GPIO.BOARD)
ledStatus = 0

# GPIO 21 = Input, 23 = Ouptput
GPIO.setup(21, GPIO.IN)
GPIO.setup(23, GPIO.OUT)
GPIO.output(23, ledStatus)

# Funktion definieren, um bei Tastendruck den 
# LED-Zustand zu ändern
def switch_on( pin ):
  global ledStatus
  ledStatus = not ledStatus
  GPIO.output(23, ledStatus)
  return

# switch_on-Funktion aufrufen, wenn Signal 
# von HIGH auf LOW wechselt
GPIO.add_event_detect(21, GPIO.FALLING)
GPIO.add_event_callback(21, switch_on)

# mit minimaler CPU-Belastung auf das Programmende 
# durch Strg+C warten
try:
  while True:
    time.sleep(5)
except KeyboardInterrupt:
  GPIO.cleanup()
  sys.exit()
