#!/usr/bin/python3
# Datei main.py
import RPi.GPIO as GPIO
from functions import *
import time,sys

GPIO.setmode(GPIO.BOARD)
GPIO.setup(13,GPIO.OUT)
db = DB()
time_open = 5 

try:
    while True:
        print ("Warte auf Transponder...\n")
        id = read_rfid()
        check =  db.mysql_read(id)
        if check[1] != 0:
            print ("Hallo",check[1],"\n")
            print ("Tuer",time_open,"Sekunden geoeffnet ")
            db.update_timestamp(id)
            GPIO.output(13, True)
            time.sleep(time_open)
            GPIO.output(13, False)
        else:
            print ("Transpondernummer",id, "nicht gefunden!")
            print ("Kein Zutritt!")
            continue
            
except KeyboardInterrupt:    
    db.close_db()
    GPIO.cleanup()
    sys.exit()