#----------------------------------------------------------------
# Dateiname: read_mcp.py
# Modul mit der Funktion dataRead() zum Lesen von Spannungswerten
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 9.7
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import time
from RPi import GPIO

GPIO.setmode(GPIO.BOARD)
SCLK = 12
MOSI = 18
MISO = 16
CS = 22

GPIO.setup(SCLK, GPIO.OUT)
GPIO.setup(MOSI, GPIO.OUT)
GPIO.setup(MISO, GPIO.IN)
GPIO.setup(CS, GPIO.OUT)

out = GPIO.output

def readData(channel):
    out(CS, True)
    out(CS, False)
    out(SCLK, False)
    s = channel | 0b00011000
    for i in range(5):
        out(MOSI, bool(s & 0b00010000))   
        out(SCLK, True)
        out(SCLK, False)     # neg. Flanke, Signal, dass nächstes Bit kommt
        s <<= 1
    data = 0
    for i in range(11):
        out(SCLK, True)
        out(SCLK, False)
        data <<= 1
        if GPIO.input(MISO):
           data |= 1
    return data

if __name__ == "__main__":
    while True:
        print (readData(0))
        time.sleep(1)
