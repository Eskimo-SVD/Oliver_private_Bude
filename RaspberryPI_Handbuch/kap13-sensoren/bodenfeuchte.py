#!/usr/bin/python3
# bodenfeuchte.py
import spidev
import time
max= 460.0     # Maximalwert bei voller Feuchtigkeit
spi = spidev.SpiDev()
spi.open(0,1)
antwort = spi.xfer([1,128,0])
if 0 <= antwort[1] <=3:
    wert = 1023 - ((antwort[1] * 256) + antwort[2])
    prozentwert = ((wert/max)*100)
    print("Bodenfeuchtigkeit: ", prozentwert, " %")