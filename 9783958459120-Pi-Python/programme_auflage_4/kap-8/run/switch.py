#----------------------------------------------------------------
# Dateiname: switch.py
# Modul zur Modellierung eines Schalters
#
# Michael Weigend: Raspberry Pi programmieren mit Python, 3. Auflage mitp 2016
# 8.3
# 29.03.2016
#----------------------------------------------------------------

from RPi import GPIO
from time import sleep

GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(8, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

STEP = 0.1
GAMETIME = 120
BWIDTH = 750

class Switch:
    def __init__ (self, nr, window=None):
        self.nr = nr
        if nr == 0:
            self.pin = 8
        else:
            self.pin = 10      

    def isPressed(self):
        return GPIO.input(self.pin)

if __name__ == "__main__":
    s0 = Switch(0)
    s1 = Switch(1)
    while True:
        sleep(1)
        print("s0: ", s0.isPressed())
        print("s1: ", s1.isPressed())
  
