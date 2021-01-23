#--------------------------------------------------------------
# Dateiname:  cam_video_recording.py
# Das Kameramodul ist angeschlossen.
# Das Programm nimmt einen Film (20 s) auf.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

#cam_video_recording
from picamera import PiCamera
camera = PiCamera()
camera.framerate = 20                         #1
camera.resolution = (640, 480)                #2
camera.start_recording('my_video.h264')       #3
camera.wait_recording(20)                     #4
camera.stop_recording()                       #5
camera.close()


    
    
    
        
