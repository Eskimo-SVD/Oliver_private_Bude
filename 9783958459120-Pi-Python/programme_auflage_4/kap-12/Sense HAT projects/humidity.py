#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: humidity.py
# Der RPi trägt einen SenseHat.
# In einer Laufschrift wird die aktuelle Luftfeuchtigkeit ausgegeben.
#  
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------
import sense_hat, time
sh = sense_hat.SenseHat()
sh.show_message("Hello")
while True:
    sh.show_message("Humidity: ")
    h = int( sh.get_humidity())
    sh.show_message(str(h))

