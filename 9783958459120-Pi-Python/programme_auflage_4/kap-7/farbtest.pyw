#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: farbtest.pyw
# Wahrnehmungspsychologischer Test.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 7.4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------


from tkinter import *
import _thread, random, time

def makeDarker(c):
    # Gibt eine dunklere Farbe zurück.
    colors = [int(c[1:3],16), int(c[3:5],16), int(c[5:],16)]
    newColor="#"
    for col in colors:
        col -= 1
        col = max(col, 0)
        col = hex(col)[2:]
        if len(col) == 1: col = "0" + col
        newColor += col
    return newColor

def randomColor():
    color = "#"
    for i in range(3):
        c = hex(random.randint(0, 255))[2:]
        if len(c) == 1: c = "0" + c
        color += c
    return color
            
def newTask():
    global dark, seconds, nr
    nr += 1
    window.unbind("<1>")
    color = randomColor()
    for lab in labels:
        lab.config(bg=color)
        lab.bind("<1>", check)
    dark = labels[random.randint(0,1)]
    _thread.start_new_thread(changeColor, ())

def changeColor():
    global control, seconds
    control = True
    while control:
        text="Klicke auf die dunkle Seite!\n"
        text += "Test " + str(nr) + " von 5: "
        text += str(seconds) + " Sekunden."
        labelTop.config(text=text)
        color = dark.cget("bg")
        dark.config(bg=makeDarker(color))
        seconds += 1
        time.sleep(1)

def start(event):
    global nr, seconds
    nr = seconds = 0
    newTask()   

def check(event):
    global control
    control = False
    window.unbind_all("<1>")
    if event.widget == dark:
        if nr >= 5:
          text = "Gesamtzeit: "
          text += str(seconds) + " Sekunden.\n"
          text += "Noch einmal? Klicken!"
          labelTop.config(text=text)
          window.bind("<1>", start)
        else:
            labelTop.config(text="Richtig! " + str(seconds)+" Sekunden.")
            window.after(1000, newTask)
    else:
        labelTop.config(text="Falsch!\nNoch einmal? Klicken!")
        window.bind("<1>", start)
  
window = Tk()

window.bind("<1>", start)
frame=Frame(master=window)
labels = [Label(master=frame, height=15, bg="black") for i in range(2)] 
labelTop = Label(master=window, font=("Arial", 30),
                 height=2, width=25, justify = LEFT, fg="white", bg="black",
                 text="Suche die dunkle Seite!\nKlicken!")

labelTop.pack(expand=True, fill=BOTH)
frame.pack(expand=True, fill=BOTH)
for lab in labels: lab.pack(side=LEFT, expand=True, fill=BOTH)

window.mainloop()
