#!/usr/bin/python3
# browserstream.py
import time, sys
import picamera
cam = picamera.PiCamera()

try:
    while True:        
        cam.capture('bild.jpg')
        time.sleep(3)  
        
except KeyboardInterrupt:
  cam.close()
  sys.exit()