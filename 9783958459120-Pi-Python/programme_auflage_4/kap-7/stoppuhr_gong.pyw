#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: stoppuhr_gong.pyw
# Stoppuhr
# Steuerung durch externen Schalter (Gong)
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 7.6
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from time import *
from tkinter import *
import _thread
from RPi import GPIO

def check_switch():
    state = "Anfang"
    while True:
        if GPIO.input(10):
            if state == "Anfang":
                state = "Uhr läuft"
                t_start = time()
            elif state == "Uhr läuft":
                state = "Uhr gestoppt"
                t = time()- t_start
                text = "Zeit: "+ str(round(t,2)) + " Sekunden" 
                label.config(text=text)
            else:
                state = "Anfang"
                label.config(text="0.00 Sekunden")               
            while GPIO.input(10):
               sleep(0.01)
        else:
            if state == "Uhr läuft":
                t = time()- t_start
                text = str(round(t)) + " Sekunden" 
                label.config(text=text)
            sleep(0.01)
                
window = Tk()
label= Label(master=window,
             font=("Arial", 16), width=20,height=3,
             text = "0.00 Sekunden")
label.pack()

GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN)
_thread.start_new_thread(check_switch, ())
window.mainloop()

