#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: letter_grid.pyw
# Objektorientiertes Programm mit Raster aus anklickbaren Labels, die
# mit jedem Klick ihre Beschriftung ändern.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 8.1
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import *
import random

class ClickableLabel(Label):
    letters ="AÄBCDEFGHIFKLMNOÖPQRSTUÜVWXYZ "
    def __init__(self, master):                    
        self.i = random.randint(0,len(self.letters)-1)          #1
        Label.__init__(self, master=master,        
                       font=("Arial", 30),
                       text=self.letters[self.i])   
        self.bind("<1>", self.nextLetter)
    
    def nextLetter(self, event):                            #4
        if self.i < len(self.letters)-1:
            self.i += 1
        else:
            self.i = 0
        self.config(text=self.letters[self.i])
        
class Application(Tk):
  def __init__(self):  
    Tk.__init__(self)
    for x in range(6):
      for y in range(3):
        ClickableLabel(master=self).grid(column=x, row=y)
    self.mainloop()

a = Application()  
  
