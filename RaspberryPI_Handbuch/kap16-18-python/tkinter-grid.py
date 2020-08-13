#!/usr/bin/python3
from tkinter import *
mywin = Tk()
txt    = Label(mywin, text='Diverse Optionen')
optVar = IntVar()
opt1   = Radiobutton(mywin, text='Montag-Freitag', 
                     variable=optVar, value=1)
opt2   = Radiobutton(mywin, text='Samstag', 
                     variable=optVar, value=6)
opt3   = Radiobutton(mywin, text='Sonntag', 
                     variable=optVar, value=7)
check1 = Checkbutton(mywin, text='Ferrari-Rot')
check2 = Checkbutton(mywin, text='Weiß')
check3 = Checkbutton(mywin, text='Mokka-Braun')
check4 = Checkbutton(mywin, text='Vanille')
btn    = Button(mywin, text='OK')

txt.grid(column=0, row=0, columnspan=2, pady=10)
opt1.grid(column=0, row=1, sticky=W)
opt2.grid(column=0, row=2, sticky=W)
opt3.grid(column=0, row=3, sticky=W)
check1.grid(column=1, row=1, sticky=W)
check2.grid(column=1, row=2, sticky=W)
check3.grid(column=1, row=3, sticky=W)
check4.grid(column=1, row=4, sticky=W)
btn.grid(column=1, row=5, sticky=E, padx=4, pady=4)
mywin.mainloop()
