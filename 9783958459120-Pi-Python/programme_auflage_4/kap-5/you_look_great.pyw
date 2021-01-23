#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: you_look_grat.py
# Aufmunterungen in zwei Sprachen.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 5.3 
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from tkinter import *
from random import randint

sayings =[("Du siehst heute gut aus.",
           "You look phantastic today."),
          ("Kopf hoch!",
           "Chins up!"),
          ("Du schaffst es!",
           "You will make it!")]
 
def pick():
    nr = randint(0, len(sayings)-1)
    t = sayings[nr]       
    label.config(text = t[language.get()])

# Widgets
window = Tk()
language = IntVar(window)
button = Button(master=window, text="Neu",
                command=pick)
label = Label(master=window, width = 30, font=("Arial", 12))
german_rb = Radiobutton(master=window, value=0,
                             text="Deutsch",  variable=language)
english_rb = Radiobutton(master=window, value=1,
                             text="Englisch",  variable=language)                

# Layout
label.pack()
german_rb.pack(anchor=W)
english_rb.pack(anchor=W)
german_rb.select()
button.pack(anchor=W)

window.mainloop()
