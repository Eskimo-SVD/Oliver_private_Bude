#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: cam_simple.py
# Das Kameramodul ist angeschlossen.
# Anzeige des Livebilds der Kamera für 10 s.
# 
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from time import sleep
from picamera import PiCamera

camera = PiCamera()

camera.start_preview()
sleep(10)
camera.stop_preview()
camera.close()
