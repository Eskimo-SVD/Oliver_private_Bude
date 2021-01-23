#--------------------------------------------------------------
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from picamera import PiCamera
from time import sleep

camera = PiCamera()
camera.preview_fullscreen = False
camera.preview_window = (200, 200, 320, 240)

camera.start_preview()
for angle in range(360, step=60):
    camera.rotation = angle
camera.stop_preview()
camera.close()
