#----------------------------------------------------------------
# Dateiname: lightsensor.py
# Testprogramm für den Lichtsensor TSL2561
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 9
# 22.November 2018
#----------------------------------------------------------------
from tsl2561 import TSL2561
from time import sleep

tsl = TSL2561()

while True:
    print(tsl.lux())
    sleep(1)
    
