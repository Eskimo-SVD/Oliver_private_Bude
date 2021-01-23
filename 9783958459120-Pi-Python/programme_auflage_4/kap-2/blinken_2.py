#----------------------------------------------------
# Dateiname:  binken_2.py 
# Lösung Aufgabe 5: Blicklicht, das durch einen Schalter gesteuert wird
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#----------------------------------------------------
from RPi import GPIO
from time import sleep
GPIO.setmode(GPIO.BOARD)
GPIO.setup(8, GPIO.IN, pull_up_down=GPIO.PUD_DOWN) #1
GPIO.setup(10, GPIO.OUT)                           #2
while True:
    if GPIO.input(8):                              #3 
        GPIO.output(10, False)                     #4
        sleep(0.5)
        GPIO.output(10, True)                      #5
        sleep(0.5)
