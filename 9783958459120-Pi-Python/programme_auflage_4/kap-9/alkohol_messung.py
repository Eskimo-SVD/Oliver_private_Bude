#----------------------------------------------------------------
# Dateiname: alkohol_messung.py
# Spannungsmessung
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 9
# 22.November 2018
#----------------------------------------------------------------

import time
from Adafruit_MCP3008 import MCP3008
from numpy import interp

CLK = 18
MISO = 23
MOSI = 24
CS = 25

SPANNUNG = [6.8, 2.14, 2.48, 2.73, 2.96, 3.15]   # x-Achse
ALKOHOLGEHALT = [0, 2, 4, 6, 8, 10]              # y-Achse

TEXT = "In der (unverdünnten) Lösung sind {:.2f} Volumenprozent Ethanol."
FEHLER = "Messbereich überschritten!"

mcp = MCP3008(clk=CLK, cs=CS, miso=MISO, mosi=MOSI)

while True:
    daten = mcp.read_adc(0)
    spannung = daten * 3.3 / 1024
    if spannung > SPANNUNG[-1]:
        print(FEHLER)
    else:
        alkoholgehalt = interp(spannung, SPANNUNG, ALKOHOLGEHALT)     
        print(TEXT.format(alkoholgehalt))      
        time.sleep(0.2)

