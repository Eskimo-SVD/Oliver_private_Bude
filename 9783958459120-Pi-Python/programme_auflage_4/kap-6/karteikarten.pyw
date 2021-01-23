#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: karteikarten_edit.pyw
# Von Karteikarten lernen - Presenter
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 6.5
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import *
import pickle, random
PATH = "cards.dat"

def loadCards():
    global card, cards
    try:
        f = open(PATH, "rb")
        cards = pickle.load(f)
        f.close()
        card = random.choice(cards)
        text.insert(END, card[0])
    except:
        cb.destroy()
        button.destroy()
        text.insert(END,"Sorry, keine Karteikarten vorhanden...")
        

def turnCard():
    text.insert(END, "\n"+card[1])
    button.config(command=nextCard)
    
def nextCard():
    global card, cards
    text.delete(0.0, END)
    if learned.get() == 1:
        cards.remove(card)
    if cards:
        card = random.choice(cards)
        text.insert(END, card[0])
        button.config(command=turnCard)
    else:
        text.insert(END, "Alles gelernt!")
    cb.deselect()
       
# Widgets
window = Tk()
learned = IntVar(master=window)
button = Button(master=window,text="Weiter",
                font = ("Arial", 16), command=turnCard)
text = Text(master=window, width=30, height=6,
            font = ("Arial", 16))
cb = Checkbutton(master=window, onvalue=1, offvalue=0,
                font = ("Arial", 16),
                variable=learned, text="Gelernt!")
cb.deselect()
# Layout
text.pack()
cb.pack(side=LEFT)
button.pack(side=LEFT)

loadCards()
window.mainloop()
