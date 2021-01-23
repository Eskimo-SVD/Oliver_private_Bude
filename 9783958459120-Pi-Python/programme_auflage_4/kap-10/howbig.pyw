#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: howbig.py
# Das RPi-Kameramodul ist angeschlossen.
# Das Programm ermöglicht das Ausmessen von Objekten auf dem Display.
# 
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

import os, _thread, math, time                          #1
from tkinter import Tk, Label, Radiobutton, StringVar
from PIL import Image, ImageTk
WIDTH, HEIGHT = 800, 600
BBOX = (200,150,600, 450)                              #2
PATH = '/home/pi/photos/image.jpg'
class App:  
    def __init__(self):
        # Widgets
        self.window = Tk()
        self.state = StringVar()                       #3
        self.labelImage = Label(master=self.window)
        self.labelImage.pack()
        self.label= Label(master=self.window)
        self.label.pack()
        self.measureRB = Radiobutton(master=self.window,
                                     text='Messen',
                                     variable=self.state,
                                     value='Messen' )
        self.measureRB.select()
        self.measureRB.pack()
        self.calRB = Radiobutton(master=self.window,
                                 text='Kalibrieren',
                                 variable=self.state,
                                 value='Kalibrieren')
        self.calRB.deselect()
        self.calRB.pack()

        # Attribute
        self.p0 = ()
        self.factor = 1

        # Operationen   
        self.reset()
        self.labelImage.bind('<1>', self.click)
        _thread.start_new_thread(self.takePhotos, ())    #4
        self.window.mainloop()

    def takePhotos (self):
        while True:
          command = 'raspistill -t 500 -w {} -h {} -o {} -n'
          os.system(command.format(WIDTH, HEIGHT, PATH))
          self.image = Image.open(PATH).crop(BBOX)      #5
          self.pImage=ImageTk.PhotoImage(self.image)
          self.labelImage.config(image=self.pImage)
          time.sleep(1)

    def reset(self):
        self.p0 = ()                                    #6
        self.label.config(text='Auf den Anfang klicken') 

    def click(self, event):
        self.labelImage.unbind('<1>')                   #7
        if not self.p0:                                 #8
          self.p0 = event.x, event.y                    #9
          self.label.config(text='Auf das Ende klicken')
        else:
          x0, y0 = self.p0                             #10
          x1, y1 = event.x, event.y                    #11
          d = math.sqrt((x1 - x0)**2 + (y1 - y0)**2)   #12
          if self.state.get() == 'Kalibrieren':
            self.factor = 10/d
            text = '1 cm sind {:.1f} Pixel'
            self.label.config(text= text.format(1/self.factor))
          else:
            text = 'Länge {:.2f} cm'
            self.label.config(text=text.format(d * self.factor))
            self.window.after(5000, self.reset)
        self.labelImage.bind('<1>', self.click)                   
App()
