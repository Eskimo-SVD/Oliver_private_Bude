#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: fruits.pyw
# Das RPi-Kameramodul ist angeschlossen.
# Das Programm erkennt Früchte an ihrer Farbe.
# 
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
# Kap. 10.7
# Michael Weigend 20. September 2018
#--------------------------------------------------------------

import os, time 
from tkinter import Tk, Label, Button 
from PIL import Image, ImageTk
from color import Color
WIDTH, HEIGHT = 800, 600                       #1
BBOX = (200,150,600, 450)                             #2
GRID = 10                                             #3
GREY = Color(70, 70, 70)                              #4
PATH = '/home/pi/Bilder/image.jpg'

class FruitIdentifier:
    fruits = {Color(255, 0, 0): 'Tomaten oder Kirschen',
              Color(255, 255, 0):'Bananen oder Zitronen',
              Color(0, 255, 0):'Äpfel (Granny Smith)',
              Color(0, 0, 220): 'Brombeeren',
              Color(255, 120, 10):'Orangen'}          #5

    def __init__(self):
        self.frequency = dict()                       #6

    def identify(self, photo):
        img = photo.load()                            #7
        for c in self.fruits.keys():                  #8   
            self.frequency[c] = 0
        width, height = photo.size
        for x in range(0, width, GRID):               #9
            for y in range(0, height, GRID):
                r, g, b = img[x, y]
                pixColor = Color(r, g, b)
                self.checkColor(pixColor)            #10
        for c, n in self.frequency.items():          #11
            if n == max(self.frequency.values()):
                return self.fruits[c]

    def checkColor(self, pixColor):                  #12
        for c in self.fruits.keys():
            if c - GREY < pixColor < c + GREY:
                self.frequency[c] += 1  

class App:  
    def __init__(self):                              
        self.window = Tk()
        self.labelImage = Label(master=self.window)
        self.labelImage.pack()
        self.label= Label(master=self.window,
                        text='Welche Früchte sind das?')
        self.label.pack()
        self.button = Button(master=self.window, 
                      text='Prüfen', command=self.check)
        self.button.pack()
        self.takePhotos()
        self.window.mainloop() 

    def takePhotos (self):                            #13
        command = 'raspistill -t 500 -w {} -h {} -o {} -n '
        os.system(command.format (WIDTH, HEIGHT, PATH))
        self.image = Image.open(PATH).crop(BBOX)
        self.pImage=ImageTk.PhotoImage(self.image)
        self.labelImage.config(image=self.pImage)
        self.window.after(1000, self.takePhoto)

    def check(self):                                 #14
        text = FruitIdentifier().identify(self.image)
        self.label.config(text=text)

App()                                  

        
    
                             
