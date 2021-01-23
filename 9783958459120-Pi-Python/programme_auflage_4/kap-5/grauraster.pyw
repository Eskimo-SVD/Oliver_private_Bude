#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: grauraster.pyw
# Darstllung eines Bildes als Rasterbild nach Meisenbach
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 5.9 
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import *

greys = ["{black black} {black black}",
         "{black black} {white black}",
         "{black white} {white black}",
         "{black white} {white white}",
         "{white white} {white white}"]
         
def get_brightness(image, x_, y_):
    """Liefert die mittlere Helligkeit des Bildausschnitts x_,y_
    bis x_+1, y_+1 als ganze Zahl zwischen 0 (schwarz) und 4 (weiß)"""
    brightness = 0
    for x in [x_, x_ + 1]:
        for y in [y_, y_ + 1]:
            c = image.get(x, y)                       
            brightness += int(c[0])+ int(c[1]) + int(c[2])
    return round(4* brightness /(4*255*3) )
        

def grey():
    global image, image_zoom
    for x in range (image.width()//2):                       
        for y in range (image.height()//2):
            brightness = get_brightness(image, 2*x, 2*y)
            image.put(greys[brightness], (2*x, 2*y))
    image_zoom = image.zoom(2)
    label.config(image=image_zoom)

    
window = Tk()
image = PhotoImage(master=window, file="face.gif")
image_zoom = image.zoom(2)

button = Button(master=window, command=grey,
                font=("Arial", 14),
                text="Bearbeiten")


label = Label(master=window, image=image_zoom)                                                  
label.pack()                                          
button.pack(fill=X)
window.mainloop()           


