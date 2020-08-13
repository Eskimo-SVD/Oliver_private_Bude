#!/usr/bin/python3
import sys
from tkinter import *
mywin = Tk()

# Reaktion auf Mausklick im Fenster
def win_click(event):
  print("Mausklick", event.x, event.y)

# Reaktion auf Tastatureingabe
def win_key(event):
  print("Tastatureingabe", event.char)                 
  if event.char.lower() == 'q': sys.exit()
  
# Reaktion auf das Programmende
def win_close():
  # Aufräumarbeiten ..
  mywin.quit()
    
mywin.geometry("100x100")
mywin.bind('<Button-1>', win_click)
mywin.bind('<Key>', win_key)       
mywin.protocol("WM_DELETE_WINDOW", win_close)
mywin.mainloop()
