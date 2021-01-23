#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: verschieben.pyw
# Buchstaben werden auf dem Display verschoben und zu einem Wort
# zusammengesetzt.
#
# Michael Weigend: Raspberry Pi programmieren mit Python, mitp 2013
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 8, Lösung 1
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

HEX = '0123456789abcdef'
WORDS =['FLIEGE', 'MÜCKE', 'BIENE']
from tkinter import *
from random import randint, choice

class Letter:
  def __init__(self, canvas, letter):
    self.c = canvas
    x = randint(30, int(self.c.cget('width'))-30)
    y = randint(30, int(self.c.cget('height'))-30)
    self.color = "#" + choice(HEX) + choice(HEX) + choice(HEX)
    self.iD = self.c.create_text(x, y, text=letter,
                    font=('Arial', 100, 'bold'), 
                    fill=self.color)

  def move(self, x1, y1):
      x0, y0 = self.c.coords(self.iD)
      dx, dy = x1 - x0, y1 - y0
      self.c.move(self.iD, dx, dy)            #8

class App(object):
  def __init__(self):
    self.window=Tk()
    self.c=Canvas(self.window, bg='white',
                       width='12c', height='8c')   
    self.c.pack()
    self.elements = [Letter(self.c, ch)
                     for ch in choice(WORDS)] 
    self.window.bind('<ButtonRelease-1>', self.drop)
    self.window.bind('<Double-Button-1>', self.new)
    self.c.bind('<1>', self.drag)
    self.c.bind('<Motion>', self.move)
    self.selected = None
    self.window.mainloop()

  def new(self,  event):
    for element in self.elements:
        self.c.delete(element.iD)
    self.elements = [Letter(self.c, ch)
                     for ch in choice(WORDS)] 

  def drag(self, event):
    for element in self.elements:
      if element.iD in self.c.find_closest(event.x, event.y):
        self.selected = element

  def drop(self, event):
    self.selected = None

  def move(self, event):
    if self.selected:
      self.selected.move(event.x, event.y)

App()
##EX = '0123456789abcdef'
##WORDS =['FLIEGE', 'MÜCKE', 'BIENE']
##from tkinter import *
##from random import randint, choice
##
##class Letter:
##  def __init__(self, canvas, letter):
##    self.c = canvas
##    x = randint(30, int(self.c.cget('width'))-30)
##    y = randint(30, int(self.c.cget('height'))-30)
##    self.color = "#" + choice(HEX) + choice(HEX) + choice(HEX)
##    self.iD = self.c.create_text(x, y, text=letter,
##                    font=('Arial', 100, 'bold'), 
##                    fill=self.color)
##
##  def move(self, x1, y1):
##      x0, y0 = self.c.coords(self.iD)
##      dx, dy = x1 - x0, y1 - y0
##      self.c.move(self.iD, dx, dy)            #8
##
##class Painting(object):
##  def __init__(self):
##    self.window=Tk()
##    self.c=Canvas(self.window, bg='white',
##                       width='12c', height='8c')   
##    self.c.pack()
##    self.elements = [Letter(self.c, ch)
##                     for ch in choice(WORDS)]    
##    self.window.bind('<ButtonRelease-1>', self.drop)
##    self.window.bind('<Double-Button-1>', self.new)
##    self.c.bind('<1>', self.drag)
##    self.c.bind('<Motion>', self.move)
##    
##    self.selected = []
##    self.window.mainloop()
##
##  def new(self,  event):
##    for element in self.elements:
##      self.c.delete(element.iD)
##    self.elements = [Letter(self.c, ch)
##                     for ch in choice(WORDS)] 
##
##  def drag(self, event):
##    for element in self.elements:
##      if element.iD in self.c.find_closest(event.x, event.y):
##        self.selected.append(element)
##
##  def drop(self, event):
##    self.selected = []
##
##  def move(self, event):
##    for element in self.selected:
##      element.move(event.x, event.y)
##
##Painting()
##
##
##
##
##
##                    
