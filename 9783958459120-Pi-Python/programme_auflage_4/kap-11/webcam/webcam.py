#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname:  webcam.py 
# Webcam. Das Programm nimmt regelmäßig Fotos auf und speichert sie ab.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 11
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
#webcam.py
import os, time 
WIDTH = 400
HEIGHT = 300
PATH = 'image.jpg'
COMMAND = 'raspistill -t 500 -w {} -h {} -o {} -n'
while True:
    os.system(COMMAND.format(WIDTH, HEIGHT, PATH))
    time.sleep(2)

               
        
        
    
                             
