#!/usr/bin/python3
# Datei rpicam.py
import picamera, sys, time
import RPi.GPIO as GPIO
cam = picamera.PiCamera()
cam.resolution = (1920,1080)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(7, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

def motion(pin):
    t = time.strftime("%Y_%m_%d-%H:%M:%S")
    print("Erzeuge Foto")
    cam.capture('/Ordner/Bild_%s.jpg' %t)
    print("Foto gespeichert")
    return
    
GPIO.add_event_detect(7, GPIO.RISING)
GPIO.add_event_callback(7, motion)

# mit minimaler CPU-Belastung auf das Programmende 
# durch Strg+C warten
try:
  while True:
    time.sleep(5)
except KeyboardInterrupt:
  GPIO.cleanup()
  sys.exit()
  cam.close()