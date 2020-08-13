#!/usr/bin/python3
# Datei wassermelder.py
import time, sys
import RPi.GPIO as GPIO
from pushbullet.pushbullet import PushBullet

GPIO.setmode(GPIO.BOARD)
GPIO.setup(16, GPIO.IN, pull_up_down=GPIO.PUD_UP)

api_key = "Ihr API-Key"
pb = PushBullet(api_key)

def melder(pin):
    zeit= time.strftime("%d.%m.%Y %H:%M:%S")
    devices = pb.getDevices()
    pb.pushNote(devices[0]["iden"], 'Wasser im Keller!', zeit)
    return

GPIO.add_event_detect(16, GPIO.FALLING, bouncetime=1000)
GPIO.add_event_callback(16, melder)
 
# mit minimaler CPU-Auslastung auf das Programmende durch 
# Strg+C warten
try:
  while True:
    time.sleep(0.5)
except KeyboardInterrupt:
  GPIO.cleanup()
  sys.exit()