#----------------------------------------------------------------
# Dateiname: read_mcp_adafruit.py
# Spannungsmessung
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 9
# 22.November 2018
#----------------------------------------------------------------

import time
from Adafruit_MCP3008 import MCP3008

CLK = 18
MISO = 23
MOSI = 24
CS = 25

mcp = MCP3008(clk=CLK, cs=CS, miso=MISO, mosi=MOSI)

while True:
        daten = mcp.read_adc(0)
        spannung = daten * 3.3 / 1024
        spannung_gerundet = round(spannung, 2)     
        print("{}V".format(spannung_gerundet))
       
        time.sleep(0.2)

