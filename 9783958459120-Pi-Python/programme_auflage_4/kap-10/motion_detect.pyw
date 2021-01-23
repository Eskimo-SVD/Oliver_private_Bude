#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: motion_detect.pyw
# Das RPi-Kameramodul ist angeschlossen.
# Anzeige des Livebilds der Kamera mit aktueller Uhrzeit.
# Bewegungen (z.B. vorbeifahrende Autos) werden erkannt.
# 
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10.4
# Michael Weigend 20. April 2016
#-----------------------------------------------------------------
#! /usr/bin/python3
# motion_detect.pyw
import os, time 
from tkinter import Tk, Label,N,LEFT
from PIL import Image, ImageTk
WIDTH = 400
HEIGHT = 300
BBOX= (50, 100, 350, 200)    
COMMAND = 'raspistill -t 300 -w {} -h {} -o {} -n '   #1
BASEDIR = '/home/pi/Bilder/'
PATH = BASEDIR + 'image.jpg'
THRESHOLD = 50                                        #2
MIN_SIZE = 400

class App:
    def __init__(self):
        self.window = Tk()
        self.label = Label(master=self.window)
        self.label.pack()
        self.labelTime = Label(master=self.window)
        self.labelTime.pack()
        self.image=None                               #3        
        self.oldImage=None 
        self.pImage=None                              #4
        self.movingObject = False
        self.run()
        self.window.mainloop() 

    def takePhoto (self):
        self.oldImage = self.image                    #5
        os.system(COMMAND.format(WIDTH, HEIGHT, PATH))    #6
        self.image = Image.open(PATH)
        self.pImage=ImageTk.PhotoImage(self.image)   
        self.label.config(image=self.pImage)   

    def checkMotion (self):                           #7
        if self.image and self.oldImage:
          old = self.oldImage.crop(BBOX)              #8
          new = self.image.crop(BBOX)
          if self.changed(old, new):
            if not self.movingObject:                 #9
              self.image.save(BASEDIR + time.asctime() +'.jpg')
              self.labelTime.config(text=time.asctime() + " Objekt erkannt")
              self.movingObject=True                 #10
          else:                                      #11
            self.movingObject = False
            self.labelTime.config(text=time.asctime() + " Keine Bewegung")

    def changed(self, old, new):                     #12
        changedPix = 0
        o, n = old.load(), new.load()                #13
        width, height = old.size
        for x in range(width):
            for y in range(height):
                diff = abs(o[x, y][1] - n[x, y][1])  #14
                if diff > THRESHOLD:
                    changedPix += 1
        return changedPix > MIN_SIZE 

    def run(self):
        self.takePhoto()
        self.checkMotion()
        self.window.after(100, self.run)
App()           

        
    
                             
