#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: black_white.py
# Umwandlung eines Farbbildes in ein Schwarzweißbild.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 5.3
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from tkinter import *

def black_white():
    average = 3*255/2                                     #1                               
    for x in range (image.width()):                       #2
        for y in range (image.height()):
            c = image.get(x, y)                           #3
            brightness = int(c[0])+ int(c[1]) + int(c[2]) #4
            if brightness < average:
                image.put("black", (x, y))
            else:
                image.put("white", (x, y))
           

window = Tk()
image = PhotoImage(file="face.gif")   
button = Button(master=window, command=black_white,
                font=("Arial", 14),
                text="Bearbeiten")        

label = Label(master=window, image=image)                                                  
label.pack()                                          
button.pack(fill=X)  
window.mainloop()           


