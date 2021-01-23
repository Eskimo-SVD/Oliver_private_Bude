#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: zufall.py
# Digitaler Würfel mit GUI
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 5.2 
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from tkinter import *                                      
from random import randint  


def choose():                                                        
    zufallszahl = randint(1, 6)                       
    label.config(text=zufallszahl)                     

window = Tk()                                          
button = Button(master=window,
                text="Zufallszahl",
                command=choose,
                font=("Arial",10), fg="blue" )                     

label = Label(master=window, 
              font=("Arial",50),
              text="?",
              width = 3,
              justify =LEFT)                                            
                                          
button.pack(side=LEFT)   
label.pack(side=LEFT) 

window.mainloop()                                      


