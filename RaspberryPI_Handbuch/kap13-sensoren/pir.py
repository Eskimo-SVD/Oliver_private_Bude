#!/usr/bin/python3
# Datei pir.py
import sys
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setup(7, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

def motion(pin):
    print("Achtung! Bewegung erkannt!")
    return

GPIO.add_event_detect(7, GPIO.RISING)
GPIO.add_event_callback(7, motion)

# mit minimaler CPU-Auslastung auf das Programmende durch 
# Strg+C warten
try:
  while True:
    time.sleep(0.5)
except KeyboardInterrupt:
  GPIO.cleanup()
  sys.exit()