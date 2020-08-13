#!/usr/bin/python3
# coding=utf-8
import spidev
import time

spi = spidev.SpiDev()
spi.open(0,1)
antwort = spi.xfer([1,128,0])

if 0 <= antwort[1] <=3:
   wert = ((antwort[1] * 256) +antwort[2]) * 0.00322
   fprozent = ((wert / 2.82) * 100)
   # Substratfeuchte in Prozent ausgeben
   print (fprozent)


