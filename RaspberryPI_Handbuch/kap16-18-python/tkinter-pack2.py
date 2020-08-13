#!/usr/bin/python3
from tkinter import *
mywin = Tk()

# Container für Textfelder
upperframe = Frame(mywin)
mylabel1 = Label(upperframe, text='Text', bg="yellow")
mylabel2 = Label(upperframe, text='Noch mehr Text', fg="blue")
mytext = Text(upperframe, height=4, width=50)
mytext.insert('1.0', 'Zeile 1\nZeile 2\nZeile 3')
mylabel1.pack(anchor=W)  # Label 1 linksbündig
mylabel2.pack(anchor=E)  # Label 2 rechtsbündig
mytext.pack(anchor=W)    # Textfeld wieder linksbündig
upperframe.pack() 

# Container für Buttons
lowerframe = Frame(mywin)
mybutton1 = Button(lowerframe, text='Abbrechen')
mybutton2 = Button(lowerframe, text='OK')                          
mybutton1.pack(side=LEFT)  # Buttons nebeneinander anordnen       
mybutton2.pack(side=LEFT)  
lowerframe.pack(anchor=E)  # Button-Container rechtsbündig

mywin.mainloop()
