#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: digitaluhr_simpel.pyw
# Einfacher Digitaler Bilderrahmen
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 7.4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from tkinter import *
from PIL import Image, ImageTk
from random import choice
import _thread, os, time


def showImages():
    while True:
        img=Image.open(choice(imageFiles))
        a,b = img.size
        if a/b >= 1920/1080:
            k = 1920/a
        else:
            k = 1080/b
        img = img.resize(size=(int(k*a), int(k*b)))
        imgTk = ImageTk.PhotoImage(img)
        label.config(image=imgTk)
        time.sleep(2)
        
def finish(event):
    window.destroy()


files=os.listdir(".")
imageFiles=[f for f in files
            if os.path.splitext(f)[1]in{".jpg", ".JPG"}]

window = Tk()
window.title("Bilderrahmen")
window.overrideredirect(True)
w = window.winfo_screenwidth()
h = window.winfo_screenheight()
window.geometry(str(w)+"x"+str(h)+"+0+0")
window.bind("<Button-1>", finish)
label = Label(master=window, bg="black")
label.pack(expand=True, fill=BOTH)
_thread.start_new_thread(showImages, ())

window.mainloop()

     
    
    











