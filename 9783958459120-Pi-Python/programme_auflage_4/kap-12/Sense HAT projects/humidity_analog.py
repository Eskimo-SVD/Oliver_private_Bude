#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: humidity_analog.py
# Der RPi trägt einen SenseHat.
# Die aktuelle Luftfeuchtigkeit wird analog (als LED-Folge) ausgegeben.
#  
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------
import sense_hat, time
sh = sense_hat.SenseHat()
sh.show_message("Humidity")
while True:
    h = int(sh.get_humidity())
    red =[255, 0, 50]
    black = [0, 0, 0]
    if h < 64:
       dots = h*[red] + (64 - h)*[black]
    else:
        dots=64*[red]
    sh.set_pixels(dots)
    time.sleep(0.5)

