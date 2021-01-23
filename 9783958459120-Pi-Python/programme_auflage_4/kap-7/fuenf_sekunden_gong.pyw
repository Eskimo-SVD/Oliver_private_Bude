#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: fuens_sekunden_gong.pyw
# Fünf Sekunden stoppen und gewinnen
# Steuerung durch externen Schalter (Gong)
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 7
# Michael Weigend 20. April 2016
#--------------------------------------------------------------


from RPi import GPIO
from time import *
from tkinter import *

GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.in)

def check_switch():
    while True:   
        if GPIO.input(10):
            start()
            sleep(0.1)
            while GPIO.input(10):
               sleep(0.1)
            while not GPIO.input(10):
                sleep(0.01)
            stop()
    
def start():
    global t_start
    t_start = time()                                  
    label.config(text="Nach 5 Sekunden \nStop drücken.")
                                     

def stop():

    t = time()- t_start                               #3
    text = str(round(t,2)) + " Sekunden.\n"           #4
    if abs(t - 5) < 0.2:                              #5
        text += "Gewonnen!"
    else:
        text += "Leider verloren!"
    label.config(text=text)

window = Tk()
label = Label(master=window,
              font=("Arial", 16), width=20, height=3,
              text='5 Sekunden stoppen\n und gewinnen!')
label.pack()

running = False
window.mainloop()

