#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: digitaluhr_simpel.pyw
# Einfache Digitaluhr mit Thread
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 7.3
# Michael Weigend 20. April 2016
#--------------------------------------------------------------


from time import *
from tkinter import *
from _thread import *

def checkTime():
        while True:
           t = localtime()
           timeText = str(t.tm_hour) + " Uhr\n"
           timeText += str(t.tm_min) + " Minuten und\n"
           timeText += str(t.tm_sec) + " Sekunden."
           sleep(1)
           timeLabel.config(text=timeText)
           
window = Tk()

timeLabel=Label(master=window,bg="black", justify=LEFT,
                 font=("Courier", 30), fg="white")

timeLabel.pack(fill=Y)
start_new_thread(checkTime,())

window.mainloop()
