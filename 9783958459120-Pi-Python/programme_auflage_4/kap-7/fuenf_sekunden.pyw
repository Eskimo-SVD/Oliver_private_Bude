#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: fuenf_sekunden.pyw
# Spiel: Fünf Sekunden stoppen und gewinnen
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 7.1
# Michael Weigend 20. April 2016
#--------------------------------------------------------------


from time import *
from tkinter import *

def start():
    global t_start
    t_start = time()
    label.config(text="Nach 5 Sekunden \nStop drücken")
    button.config(text="Stop", command=stop)

           
def stop():
    t = time()- t_start
    text = str(round(t,2)) + " Sekunden.\n"
    if abs(t - 5) <0.2:
        text += "Gewonnen!"
    else:
        text += "Leider verloren!"
    label.config(text=text)
    button.config(text="Start", command=start)

        
        
    

window = Tk()

label = Label(master=window,
              font=("Arial", 16), width=20, height=3,
              text='5 Sekunden stoppen\n und gewinnen!')
label.pack()

button=Button(master=window,command=start,
                    font=("Arial", 16), text='Start')
button.pack(fill=X)
window.mainloop()
                                                
