#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: stick_test.py
# Der RPi trägt einen SenseHat.
# Auf dem Bildschirm werden Stick-Aktionen ausgegeben.
#  
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------
import sense_hat
def show_event(event):
    print(event)

sh = sense_hat.SenseHat()
sh.stick.direction_any = show_event
