#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: weckzeit.pyw
# Simuliert das Einstellen eines Weckers durch Klicken.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 7
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import *
import _thread, time

def start(event):
    _thread.start_new_thread(changeNumber, ())
    label.unbind("<1>")
    

def changeNumber():
    global control
    control = True
    while control:
        hour.set(hour.get() + 1)
        if hour.get() > 23:
            hour.set(0)
        time.sleep(0.2)       

def stop(event):
    global control
    control = False
    label.bind("<1>", start)

window = Tk()
hour = IntVar(master=window, value=0)
label=Label(master=window, height=1, width=2,
            font=("Arial", 40), textvariable=hour)
label.bind("<1>", start)
label.bind("<ButtonRelease-1>", stop)
label.pack()

window.mainloop()
