#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: options.py
# Das RPi-Kameramodul ist angeschlossen.
# Mit raspistill werden Fotos gemacht und dabei verschiedene
# Kameraoptionen verwendet.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
# Kap. 10.3
# Michael Weigend 20. September 2018
#--------------------------------------------------------------

import os
import time

BASEDIR = "/home/pi/photos/"
EX_LIST = ["off", "auto", "night"]                    #1
AWB_LIST = ["off", "auto", "sun", "cloud"]
COMMAND = "raspistill -t 300, -ex {} -awb {} -o {} -n"  
ANSWER = "Foto mit ex={} und awg={} gespeichert."

def deleteImages():
    try:
        os.remove("{}img_*.jpg".format(BASEDIR))     #2
    except: pass

def takePhoto(ex, awb):
    path = "{}img_{}_{}.jpg".format(BASEDIR, ex, awb)#3
    os.system(COMMAND.format(ex, awb, path))         #4
    time.sleep(0.2)
    print(ANSWER.format(ex, awb))

print("Lösche alte Fotos")                            #5
deleteImages()
print("Starte Fotoserie...")
for ex in EX_LIST:
    for awb in AWB_LIST:
        takePhoto(ex, awb)
print("Fertig!")
          


