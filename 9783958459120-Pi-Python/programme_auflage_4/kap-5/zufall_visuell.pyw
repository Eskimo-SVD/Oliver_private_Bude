#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: zufall_visuell.py
# Rein visuelles Programm mit GUI zur Generierung von Zufallszahlen.
# Anders als im Buch werden hier einfache Zeichnungen (gif-Dateien
# verwandt.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 5.3 
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import *
from random import randint  

def choose():                                                        
    zufallszahl = randint(0, 5)                        
    label.config(image=items[zufallszahl])                      #1


window = Tk()                                                   #2
items = [PhotoImage(file="1.gif"),
         PhotoImage(file="2.gif"),
         PhotoImage(file="3.gif"),
         PhotoImage(file="4.gif"),
         PhotoImage(file="5.gif"),
         PhotoImage(file="6.gif")]                              #3
new_image = PhotoImage(file="new_image.gif")
button = Button(master=window, command=choose,
                image=new_image)                                #4
label = Label(master=window, image=items[0])                    #5
label.pack()
button.pack()
window.mainloop()       


