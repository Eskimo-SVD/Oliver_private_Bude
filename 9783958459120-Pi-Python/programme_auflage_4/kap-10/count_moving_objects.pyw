#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: count_moving.py
# Das RPi-Kameramodul ist angeschlossen.
# Das Programm zählt die Anzahl der Objekte, die von rechts und die
# Anzahl der Objekte, die von links durch das Bild gehen. Die Bewegung
# muss langsam sein (mehrere Sekunden für einen Bewegungsablauf).
# 
# Michael Weigend: Raspberry Pi programmieren mit Python, 2. Auflage mitp 2015
# Kap. 10.4
# 22. März 2016
#----------------------------------------------------------------

import os, time, io, subprocess
from tkinter import Tk, Label,PhotoImage, Canvas
from PIL import Image, ImageTk
WIDTH, HEIGHT = 80, 60
LEFT = (0, 0, 40, 60)
RIGHT = (41, 0, 80,60)
THRESHOLD = 40
MIN_SIZE = 20  
COMMAND = 'raspistill -t 10 -w {}  -h {} -o - -n' 
MESSAGE = 'Von links: {} \n Von rechts: {}' 

class Camera:
    def __init__(self):
        self.new, self.old = None, None

    def takePhoto (self):
        imageData = io.BytesIO()              #1
        self.old = self.new 
        command = COMMAND.format(WIDTH, HEIGHT)             #2
        imageData.write(subprocess.check_output(command, shell=True))                                         #3
        imageData.seek(0)                            #4
        self.new = Image.open(imageData)             #5

    def checkMotion (self):                          #6
        if self.new and self.old:                    #7
            return (self.changed(self.old.crop(LEFT),
                                 self.new.crop(LEFT)),
                    self.changed(self.old.crop(RIGHT),
                                 self.new.crop(RIGHT)))
        else: return False, False

    def changed(self, old, new):                     #8
        changedPix = 0
        o, n = old.load(), new.load()
        width, height = old.size
        for x in range(width):
            for y in range(height):
                diff = abs(o[x, y][1] - n[x, y][1])
                if diff > THRESHOLD:
                    changedPix += 1
        return changedPix > MIN_SIZE  

class Display(Label):
    def __init__(self, master):
        Label.__init__(self, master=master, width=12,
                    height=2, bg='white',
                    font=('Arial', 40), fg='blue',
                    text='Von links: 0 \nVon rechts: 0')
        self.left = 0
        self.right = 0

    def motion(self, direction):                      #9
        if direction == 'von links':
            self.left += 1
        else:
            self.right += 1
        message = MESSAGE.format(self.left, self.right)
        self.config(text=message)  

class App:
    def __init__(self):
        self.window = Tk()
        self.display = Display(self.window)
        self.display.pack()
        self.label = Label(master=self.window)
        self.label.pack() 
        self.camera = Camera()
        self.state='keine Bewegung'                  #10
        self.detect()
        self.window.mainloop() 

    def detect(self):                                #11
        self.camera.takePhoto()
        left, right = self.camera.checkMotion()
        if self.state =='keine Bewegung':            #12
            if left and not right:
                self.state = 'zuerst links'
            elif right and not left:
                self.state = 'zuerst rechts'
        elif self.state == 'zuerst links':
            if left and right:
                self.state = 'zuerst links, dann rechts'
            elif not(left or right):
                self.state = 'keine Bewegung'
        elif self.state == 'zuerst rechts':
            if left and right:
                self.state = 'zuerst rechts, dann links'
            elif not(left or right):
                self.state = 'keine Bewegung'
        elif self.state == 'zuerst links, dann rechts':
            if not (left or right):
                self.state = 'keine Bewegung'
                self.display.motion('von links')  
        elif self.state == 'zuerst rechts, dann links':
            if not (left or right):
                self.state = 'keine Bewegung'
                self.display.motion('von rechts')
        self.label.config(text=time.asctime()+ ' ' + self.state)
        self.window.after(100, self.detect)

App()                              

