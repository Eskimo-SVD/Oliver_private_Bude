#----------------------------------------------------------------
# Dateiname: temperature.py
# Temperaturmessung - Hauptprogramm mit GUI
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 9.4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import time
from temperature import TempDevices
from tkinter import *


class App:
    def __init__(self):
        self.window = Tk()
        self.window.title("Temperatur")
        self.tempLabels = [Thermometer(self.window, t)
                           for t in TempDevices()]
        for t in self.tempLabels: t.pack()   
        self.window.mainloop()

class Thermometer(Label):
    def __init__ (self, window, tempDevice):
        Label.__init__(self, font=("Arial", 20), width=12)
        self.window = window
        self.device = tempDevice
        self.update()

    def update(self):
        text = str(round(self.device.read(), 2)) + " °C" 
        self.config(text=text)
        self.window.after(1000, self.update)
App()
