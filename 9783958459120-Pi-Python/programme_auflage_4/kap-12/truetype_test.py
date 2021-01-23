#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: truetype_test.py
# Gefundene TrueType-Fonts werden ausgegeben.
#  
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------
from PIL import Image, ImageDraw, ImageFont, ImageTk
from os import popen
from tkinter import Tk, Label
SIZE=20


fonts = popen("fc-list").readlines()
paths = [line.split(":")[0] for line in fonts]

w = SIZE * 25
h = SIZE * len(fonts) + 10

image = Image.new('1', (w, h))
draw = ImageDraw.Draw(image)
draw.rectangle((0,0,w, h), outline=0, fill=0)

y = 0
for path in paths:
    font = ImageFont.truetype(font=path, size=SIZE)
    name=path.split("/")[-1]
    draw.text((0, y), text=name, fill=255, font=font)
    y += SIZE

window = Tk()
img = ImageTk.PhotoImage(image)
label = Label(master=window, image=img )
label.pack()
window.mainloop()
    
 
