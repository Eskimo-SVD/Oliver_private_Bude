#----------------------------------------------------
# Dateiname:  cam_brightness.py
# Das Kameramodul ist angeschlossen.
# Auf dem Bildschirm erscheint das Livebild der Kamera.
# Die Helligkeit wird in kleinen Schritten verändert.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from picamera import PiCamera
from time import sleep
camera = PiCamera()
camera.start_preview()
for i in range (100):
   camera.brightness = i                 #1
   sleep(0.1)
camera.stop_preview()
camera.close()



    
    
    
        
