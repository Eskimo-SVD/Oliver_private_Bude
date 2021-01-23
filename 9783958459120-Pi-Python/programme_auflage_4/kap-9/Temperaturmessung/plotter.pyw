#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: plotter.py
# Darstellung von Temperatur-Zeit-Diagrammen
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 9
# Michael Weigend 20. November 2018
#--------------------------------------------------------------
import time, _thread
from temperature import TempDevices
from tkinter import *

class Plotter:
    def __init__(self):
        self.colors = ["red", "green", "blue", "black"]
        self.window = Tk()
        self.window.title("Temperatur")
        self.c = Canvas(master=self.window, width = 320,
                        height= 250, bg="white")
        self.c.create_text(20, 20, text="30 °C")
        self.c.create_text(20, 220, text="20 °C")
        self.c.pack()
        t = TempDevices()
        self.pens = []
        for i in range(len(t)):
            self.pens.append(Pen (self.c,
                t[i], self.colors[i%4]))
        _thread.start_new_thread(self.update, ())
        self.window.mainloop()
    
    def update(self):
        while True:
            for i in range(60):
                for pen in self.pens:
                    pen.draw(i*5)
                time.sleep(1)
            self.c.delete("point")

class Pen:
    def __init__ (self, canvas, tempDevice, color):
        self.canvas = canvas
        self.device = tempDevice
        self.color = color

    def draw(self, x):
        y = 400 + 220 - self.device.read() * 20
        self.canvas.create_line(x, y, x+3, y, width=3,
                                fill=self.color, tag="point")
Plotter()
