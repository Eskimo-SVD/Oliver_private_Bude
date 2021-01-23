#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: racing.pyw
# Simpler Autosimulator
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 9.7
# Michael Weigend 20. Nov 2017
#--------------------------------------------------------------
import time 
from read_mcp import readData
from tkinter import *

WIDTH = 240
HEIGHT = 200
CAR = "car.gif"
ROAD = "road.gif"

class Car:
    def __init__(self, road):
        self.img = PhotoImage(file=CAR)
        self.road = road
        self.iD = self.road.create_image(150, 170, image=self.img)
        self.x = WIDTH/2
        
    def step(self):
        if self.x <  WIDTH * readData(0)/1023:
            self.x += 1
            self.road.move(self.iD, 1, 0)
        elif self.x > WIDTH * readData(0)/1023:
            self.x -= 1
            self.road.move(self.iD, -1, 0)
        
        
class Road(Canvas):
    def __init__(self, master):
        Canvas.__init__(self, master=master, width=WIDTH, height=HEIGHT)
        self.pack()
        self.img = PhotoImage(file=ROAD)
        self.y = 0
        self.iD = self.create_image(0,HEIGHT, anchor=SW, image=self.img)

    def step(self):
        if self.y <= self.img.height() - HEIGHT:
            self.y += 3
            self.move(self.iD, 0, 3)
        else:
            self.y = 0
            self.coords(self.iD, 0, HEIGHT)
        

class Racing:
    def __init__(self):
        self.window = Tk()
        self.window.title("Autorennen")
        self.road = Road(master=self.window)
        self.car = Car(self.road)
        self.run()
        self.window.mainloop()

    def run(self):
        self.road.step()
        self.car.step()
        self.window.after(50, self.run)

Racing()
