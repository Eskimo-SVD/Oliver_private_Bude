#----------------------------------------------------
# Dateiname:  blinken.py 
# Blinklicht
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#----------------------------------------------------
from RPi import GPIO
from time import sleep
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.OUT)
while True:   
    GPIO.output(10, True)
    sleep(0.5)
    GPIO.output(10, False)
    sleep(0.5)
    
    
    
