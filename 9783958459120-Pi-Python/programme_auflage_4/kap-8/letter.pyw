#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: letter.pyw
# Objektorientiertes Programm mit anklickbarem Label, das
# mit jedem Klick seine Beschriftung ändert.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 8.1
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import *
import random

class ClickableLabel:
    letters ="AÄBCDEFGHIFKLMNOÖPQRSTUÜVWXYZ"
    def __init__(self, master):                    #1
        self.master = master
        self.i = random.randint(0,len(self.letters)-1)          #2
        self.label=Label(master=self.master,
                         font=("Arial", 20),
                         text=self.letters[self.i])    #3
        self.label.bind("<1>", self.nextLetter)
    
    def nextLetter(self, event):                            #4
        if self.i < len(self.letters)-1:
            self.i += 1
        else:
            self.i = 0
        self.label.config(text=self.letters[self.i])

    def pack(self):                                #5
        self.label.pack()

class Application:
    def __init__(self):  
        self.window = Tk()
        self.c = ClickableLabel(master=self.window)
        self.c.pack()
        self.window.mainloop()

a = Application()  
  
