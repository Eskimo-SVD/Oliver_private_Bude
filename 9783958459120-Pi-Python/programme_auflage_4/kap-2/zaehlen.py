#----------------------------------------------------
# Dateiname:  zaehlen.py 
# Einfacher Zähler
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from RPi import GPIO
from time import sleep
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN)
count=0

while True:
    if GPIO.input(10):    
        count += 1
        print(count)
        sleep(0.05)
        while GPIO.input(10):
            sleep(0.05)
    
    
    
        
