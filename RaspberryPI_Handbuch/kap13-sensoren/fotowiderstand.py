#!/usr/bin/python3
# Datei fotowiderstand.py
import spidev
import time
spi = spidev.SpiDev()
spi.open(0,1)
spi.max_speed_hz = 5000
while True:
    antwort = spi.xfer([1,128,0])
    if 0 <= antwort[1] <=3:
        wert = ((antwort[1] * 256) + antwort[2]) * 0.00322
        print(wert, " V")
        time.sleep(1)
