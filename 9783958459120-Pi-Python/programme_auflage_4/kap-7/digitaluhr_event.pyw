#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: digitaluhr_event.pyw
# Digitaluhr. Das Anwendungsfenster wird durch Doppelklick
# geschlossen.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 7
# Michael Weigend 20. April 2016
#--------------------------------------------------------------


from time import *
from tkinter import *
import _thread
BGCOLOR="#933"                                        #1

month=["Januar", "Februar", "März", "April", "Mai",
       "Juni", "Juli", "August", "September",
       "Oktober", "November", "Dezember"]             #2

def checkTime():
    while True:
        t = localtime()                               #3
        timeText = "Heute ist der "+str(t.tm_mday)+". "
        timeText += month[t.tm_mon - 1] + " "
        timeText += str(t.tm_year)+".\n"
        timeText += "Es ist " + str(t.tm_hour) + " Uhr\n"
        timeText += str(t.tm_min) + " Minuten und\n"
        timeText += str(t.tm_sec) + " Sekunden."
        label.config(text=timeText)                   #4                 
        sleep(1)                                      #5

def finish(event):
    window.destroy()

window = Tk()
window.bind("<Double-1>", finish)
#window.overrideredirect(True)                        #6
w = window.winfo_screenwidth()
h = window.winfo_screenheight()
window.geometry(str(w)+ "x" + str(h) + "+0+0")        #7 

frame=Frame(master=window, bg=BGCOLOR)
label=Label(master=frame,bg=BGCOLOR,
            font=("Courier", 30), fg="white")
frame.pack(expand=True, fill=BOTH)                    #9
label.pack(expand=True, fill=BOTH)

_thread.start_new_thread(checkTime, ())              #10

window.mainloop()
