#! /usr/bin/python3.5
#----------------------------------------------------------------
# Dateiname: voltage.pyw
# Spannungsmessung
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 9
# 22.November 2018
#----------------------------------------------------------------
from read_mcp import readData
from tkinter import *


class Pointer:
    def __init__(self, canvas):
        self.c = canvas
        self.id = self.c.create_line(100, 100, 150, 200,
                                   width=4, fill="red")
    def read(self):
        self.c.delete(self.id)
        x =readData(0)/1023 * 3.3 * 50 + 50
        self.id = self.c.create_line(x, 100, 150, 200,
                                   width=4, fill="red")
        
class Device:      
    def __init__(self):
        self.window = Tk()
        self.window.title("Spannungsmesser")
        self.canvas = Canvas(master=self.window, width=300, height=200,
                             bg = "white")
        self.canvas.pack()
        for i in range(5):
            self.canvas.create_text(50*(i+1), 100, text=str(i))
        self.pointer = Pointer(self.canvas)
        self.run()
        self.window.mainloop()

    def run(self):
        self.pointer.read()
        self.window.after(50, self.run)

Device()
