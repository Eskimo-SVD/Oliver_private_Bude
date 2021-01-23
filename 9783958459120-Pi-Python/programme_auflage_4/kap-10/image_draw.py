#----------------------------------------------------
# Dateiname:  image_draw.py
# Auf ein Foto zeichnen.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from PIL import Image, ImageTk, ImageDraw
from tkinter import Label, Tk
img = Image.open('venedig.jpg')                      #1
draw = ImageDraw.Draw(img)                           #2
draw.ellipse((200, 120, 400, 320), outline="#FFF")   #3
window = Tk()
imgtk = ImageTk.PhotoImage(img)                      #4
label = Label(window, image=imgtk).pack()
window.mainloop()
