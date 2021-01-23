#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: cam.pyw
# Das RPi-Kameramodul ist angeschlossen.
# Anzeige des Livebilds der Kamera mit aktueller Uhrzeit.
# 
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
# Kap. 10.4
# Michael Weigend 31. Mai 2018
#-----------------------------------------------------------------

import os, time 
from tkinter import Tk, Label
from PIL import Image, ImageTk                        #1
WIDTH = 400                                           #2
HEIGHT = 300
PATH = 'image.jpg'
COMMAND = 'raspistill -t 300 -w {} -h {} -o {} -n'

class App:
    def __init__(self):
        self.window = Tk()
        self.label = Label(master=self.window)        #3
        self.label.pack()
        self.labelTime = Label(master=self.window)    #4
        self.labelTime.pack()
        self.run()
        self.window.mainloop()
        
    def takePhoto (self):        
        os.system(COMMAND.format(WIDTH, HEIGHT, PATH))    #5
        img = Image.open('image.jpg')
        self.image=ImageTk.PhotoImage(img)
        self.label.config(image=self.image)           #6
        self.labelTime.config(text=time.asctime())

    def run(self):                                    #7
        self.takePhoto()
        self.window.after(100, self.run)
App()           
        
    
                             
