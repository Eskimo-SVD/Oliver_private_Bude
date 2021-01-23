#----------------------------------------------------------------
# Dateiname: alkohol_test.py
# Spannungsmessung
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 9
# 22.November 2018
#----------------------------------------------------------------

from RPi import GPIO
from time import sleep
from os import system
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN)

while True:
    if not GPIO.input(10):
        system('espeak -vde "Achtung! Alkoholisches Getränk!"')
        sleep(1)

