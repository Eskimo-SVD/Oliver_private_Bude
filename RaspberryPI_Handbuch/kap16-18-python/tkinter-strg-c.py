#!/usr/bin/python3
import sys, signal
from tkinter import *

mywin = Tk()

# Programmende durch Strg+C im Terminal
def strg_c(signal, frame):
  mywin.quit()

# regelmäßiger Aufruf, damit Strg+C funktioniert
def do_nothing():
  mywin.after(200, do_nothing)         

signal.signal(signal.SIGINT, strg_c)
mywin.after(200, do_nothing)

# Fenster öffnen
mywin.mainloop()

