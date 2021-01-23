#----------------------------------------------------------------
# Dateiname: read_mcp.py
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

def readData(n)
        data = mcp.read_adc(n)
        return data


