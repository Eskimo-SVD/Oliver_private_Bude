#----------------------------------------------------
# Dateiname:  zaehler_flanke.py 
# Zähler, der durch einen Schalter gesteuert wird
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from RPi import GPIO
from time import sleep
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)  #1
count=0    
while True:
    GPIO.wait_for_edge(10, GPIO.RISING)              #2
    count += 1
    print('Schalter gedrückt', count)
    sleep(0.3)                                       



