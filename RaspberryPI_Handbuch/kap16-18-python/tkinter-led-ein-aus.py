#!/usr/bin/python3
from tkinter import *
import RPi.GPIO as gpio
gpio.setmode(gpio.BOARD)
gpio.setwarnings(False)  
gpio.setup(26, gpio.OUT)   # Pin 26 
gpio.output(26, gpio.LOW)

# Reaktion auf Mausklick im Fenster
def led_change():
  if ledstatus.get():
    gpio.output(26, gpio.HIGH)  
    lbl.configure(text='Die LED leuchtet.')
  else:
    gpio.output(26, gpio.LOW)  
    lbl.configure(text='Die LED ausgeschalten.')

# Benutzeroberfläche mit Ereignisverwaltung
mywin = Tk()
mywin.wm_title('LED ein/aus')
ledstatus = IntVar()
lbl = Label(mywin, text='Die LED ist ausgeschalten.')
ledbtn = Checkbutton(mywin, text='LED ein-/ausschalten', 
                     indicatoron=0, variable=ledstatus,
                     command=led_change, padx=10, pady=10)
lbl.grid(column=0, row=0, padx=5, pady=5)
ledbtn.grid(column=0, row=1, padx=5, pady=5)
mywin.mainloop()
