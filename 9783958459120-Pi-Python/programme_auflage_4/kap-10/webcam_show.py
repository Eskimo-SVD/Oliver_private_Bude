#--------------------------------------------------------------
# Dateiname: webcam_show.py
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import io
from urllib.request import urlopen
from PIL import Image, ImageTk
from tkinter import Label, Tk
URL = "http://lamp01.dortmund.de/webcams/friedensplatz/current.jpg"
f = urlopen(URL)
img_text = f.read()                                #1
img = Image.open(io.BytesIO(img_text))             #2

window = Tk()
imgtk = ImageTk.PhotoImage(img)
Label(window, image=imgtk).pack()
window.mainloop()



    
