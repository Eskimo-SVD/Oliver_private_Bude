#! /usr/bin/python3
#----------------------------------------------------
# Dateiname:  tk_plot_co2.py
# Diskretes Absorptionsspektrum
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 9
# Michael Weigend 13.2.2018
#----------------------------------------------------
import matplotlib
matplotlib.use('TkAgg')                               
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg,
                                               NavigationToolbar2TkAgg)
from math import log10
from matplotlib.figure import Figure
from tkinter import Tk, Button, Label, LEFT, BOTH
from tsl2561_test import get_lum
 
class Plotter:                                         
    def __init__(self):     

        # data 
        self.wavelengths = [470, 530, 626]
        self.colors=["blue", "green", "red"]
        self.index = 0
        self.I0 = [100, 100, 100]
        self.absorbance = [0, 0, 0]     

        # Figure
        self.f = Figure(figsize=(5,4), dpi=100)        
        self.a = self.f.add_subplot(111)
        self.a.set_ylim(0, 1)                     
        self.a.set_xlim(400, 750)
        self.line = None

        # Widgets
        self.window = Tk()
        self.canvas = FigureCanvasTkAgg(self.f,
                             master=self.window)    
        self.canvas.show()
        self.canvas.get_tk_widget().pack(fill=BOTH,
                                        expand=True) 

        self.label = Label(master=self.window, width =20)
        self.update_label()
        self.label.pack(side=LEFT)
        self.button_cal= Button(master=self.window, text="Kalibrieren",
                             command=self.cal)

        self.button_cal.pack(side=LEFT)
        self.button_meas= Button(master=self.window, text="Messen",
                             command=self.measure)

        self.button_meas.pack(side=LEFT)
        self.window.mainloop()

    def update_label(self):
                self.label.config(bg=self.colors[self.index],
                text=str(self.wavelengths[self.index]) + " nm")
        

    def cal(self):
        self.I0[self.index] = get_lum()
        self.index +=1
        self.index %= 3
        self.update_label()


    def measure(self):
        I = get_lum()
        if I > 0:
            self.absorbance[self.index] = log10(self.I0[self.index]/I)
            self.index+=1
            self.index %= 3
            self.update_label()
            if self.line:
              self.line.remove() 
            self.line = self.a.plot(self.wavelengths,self.absorbance, "bs")[0]
            self.canvas.show()

Plotter()                                            
