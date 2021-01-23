#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: stau.pyw
# Staumelder
#
# Michael Weigend: Raspberry Pi programmieren mit Python, mitp 2013
# Kap. 6.9.4
# 29.03.2016
#----------------------------------------------------------------#----------------------------------
 
from tkinter import *
from urllib.request import *
import re

WWW="http://www.wdr.de"
MESSAGE = """Die aktuelle Verkehrslage in NRW.
Gesamte Staulänge: {km} km. Betroffene Straßen:
{streets}."""

def findStau():
    wdrText = str(urlopen(WWW).read(), encoding="utf-8")
    finds1 = re.findall("\d+ km Stau", wdrText)
    km = int(re.findall("\d+", finds1[0])[0])
    finds2 = re.findall("#streets=[AB]\d+,", wdrText)
    streets = [re.findall("[AB]\d+", t)[0] for t in finds2]
    streetnames = ", ".join(streets)
    label.config(text=MESSAGE.format(km=km, streets=streetnames))
    if km < 10:
        image = images[0]
    elif km < 20:
        image = images[1]
    else:
        image = images[2]
    labelImage.config(image=image)
    
# Widgets
window = Tk()
images = [ PhotoImage(master = window, file= fn) 
           for fn in ["one.gif", "two.gif", "three.gif"]]
    
    
label=Label(master=window, font=("Arial", 16), bg="white")
label.pack()
labelImage = Label(master=window, bg="white")
labelImage.pack(fill=X)        
Label(master=window, font=("Arial", 8), bg="white",
      text="Datenquelle: WDR Köln").pack(fill=X)
                 
findStau()
window.mainloop()
