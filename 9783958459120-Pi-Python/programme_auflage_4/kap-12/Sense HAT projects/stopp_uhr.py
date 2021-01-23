#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: stopp_uhr.py
# Der RPi trägt einen SenseHat.
# Mit dem Stick wird ein Sekundenzähler gestartet und gestoppt.
#  
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------
import sense_hat
from time import sleep

sh = sense_hat.SenseHat()
sh.clear()
while True:
    sh.stick.wait_for_event()
    count = 0
    sh.show_letter(str(count))
    actions = []
    while "pressed" not in actions:
        sleep(1)
        count = (count + 1) % 10
        sh.show_letter(str(count))
        events = sh.stick.get_events()
        actions = [e.action for e in events]
        print(count, actions)
    sh.stick.wait_for_event()
    sleep(0.5)
