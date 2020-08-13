#!/usr/bin/python3
# Datei funk_sensor.py
import spidev
import os
import time
spi = spidev.SpiDev()
spi.open(0,1)

while True:
    antwort = spi.xfer([1,128,0])
    if 0 <= antwort[1] <=3:
        wert = ((antwort[1] * 256) + antwort[2]) * 0.00322
        print (wert)
                
    if wert <= 1:
        os.system("sudo /home/pi/rcswitch-pi/./send 11000 3 1") 
    elif wert >=3:
        os.system("sudo /home/pi/rcswitch-pi/./send 11000 3 0") 
    time.sleep(300) # fünf Minuten