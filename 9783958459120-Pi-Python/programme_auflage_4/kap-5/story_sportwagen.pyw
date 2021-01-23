#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: story_sportwagen.py
# Krimiautomat.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 5.9 
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from tkinter import *
 
def tell_story():
    text = "Es geschah an einem Montagmorgen im "
    text += month_entry.get() + ". "
    text += name_entry.get()
    text += " war auf dem Weg zum Bahnhof. Da fuhr ein "
    text += color_entry.get() 
    text += "er Sportwagen an ihm vorbei..."
    story.delete(1.0, END)
    story.insert(END, text)

window = Tk() 

button = Button(master=window,
                text="Neue Geschichte",
                command=tell_story)                    

story = Text(master=window, width = 30, height = 5, wrap=WORD)
name_label = Label(master=window,
                   text="Männlicher Vorname: ")
month_label = Label(master=window,text="Monat: ")
color_label = Label(master=window,text="Farbe: ")
name_entry = Entry(master=window)
month_entry = Entry(master=window)
color_entry = Entry(master=window)
story.pack()
name_label.pack()
name_entry.pack()
month_label.pack()
month_entry.pack()
color_label.pack()
color_entry.pack()
button.pack()
window.mainloop()
