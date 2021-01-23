----------------------------------------------------------------
# Dateiname: bildbearbeitung.py
# Farben bestimmter Helligkeit werden durch Zufallsfarben ersetzt.
# Das Programm, mit dem das Titelbild erstellt wurde.
#
# Michael Weigend: Raspberry Pi programmieren mit Python, 4. Aufl.  mitp 2019
# Anhang D
# 8.12. 2018
#----------------------------------------------------------------
from random import *
from tkinter import *
from tkinter import filedialog, messagebox


def newColor(event):
    global colors
    nr = int(event.widget["text"])
    digits="0123456789ABCDEF"
    newColor ="#"
    for i in range(3):
        newColor += choice(digits)
    colors[nr] = newColor
    colorLabels[nr].config(bg=colors[nr])

def process():
    global image
    image = PhotoImage(file=path)
    label.config(image=image)
    for x in range (image.width()):
        for y in range (image.height()):
            c = image.get(x, y)
            brightness = int(c[0])+ int(c[1]) + int(c[2])
            if brightness < 150:
                image.put(colors[0], (x, y))
            elif brightness < 300:
                image.put(colors[1], (x, y))
            elif brightness < 450:
                image.put(colors[2], (x, y))
            else:
                image.put(colors[3], (x, y))

def zoomImage():
    global image, label
    image=image.zoom(2)
    label.config(image=image)

def loadImage():
    global image, label, path
    p= filedialog.askopenfilename()  # Abbruch berücksichtigen
    if p:
        try:
          image = PhotoImage(file=p)
          label.config(image=image)
          path = p
        except:
           messagebox.showerror("", "Foto unleserlich")

def saveImage():
    p = filedialog.asksaveasfilename()
    if p:
       image.write(p)

# Widgets
window = Tk()
window.title("Bildbearbeitung")
frame = Frame(master=window)
label = Label(master=window, font = ("Arial", 14),
              text="Bitte ein Bild laden")


buttonImage = Button(master=frame,text="Bild bearbeiten", width=12,
                font = ("Arial", 12), command=process)
buttonLoad = Button(master=frame,text="Laden", width=12,
                font = ("Arial", 12), command=loadImage)
buttonSave = Button(master=frame,text="Speichern", width=12,
                font = ("Arial", 12), command=saveImage)
buttonZoom = Button(master=frame,text="Zoom", width=12,
                font = ("Arial", 12), command=zoomImage)

colors =["#106", "#0c7", "#DC5", "#9AF"]
colorLabels = []
for i in range(4):
    colorLabels.append(Label(master=frame, font = ("Arial", 12),
                             text=str(i), width = 5, bg=colors[i]))
    colorLabels[i].bind("<1>", newColor)


# Layout
frame.pack()
buttonImage.pack(side=LEFT, padx=2, pady=2)
buttonLoad.pack(side=LEFT, padx=2, pady=2)
buttonSave.pack(side=LEFT, padx=2, pady=2)
buttonZoom.pack(side=LEFT, padx=2, pady=2)
for cl in colorLabels:
    cl.pack(side=LEFT, padx=2, pady=2)
label.pack()

window.mainloop()
