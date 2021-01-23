#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: karteikarten_erweitert.pyw
# Von Karteikarten lernen
# Presenter mit Laden
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 6.6
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import *
import pickle, random

def loadCards():
    global card, cards
    f = filedialog.askopenfile("rb")
    if f:
        try:
            cards = pickle.load(f)
            card = random.choice(cards)
            text.delete(1.0, END)
            text.insert(END, card[0])
            button.config(command=turnCard)
        except:
            messagebox.showerror("", "Kartei unleserlich")
            button.config(command=None) ###
        f.close()

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
        button.config(command=nextCard)
        
    cb.deselect()
       
# Widgets
window = Tk()
learned = IntVar(master=window)
button = Button(master=window,text="Weiter",
                font = ("Arial", 16), command=turnCard)
buttonLoad = Button(master=window,text="Laden",
                font = ("Arial", 16), command=loadCards) ###
text = Text(master=window, width=30, height=6,
            font = ("Arial", 16))
cb = Checkbutton(master=window, onvalue=1, offvalue=0,
                font = ("Arial", 16),
                variable=learned, text="Gelernt!")
cb.deselect()

# Layout
text.pack()
cb.pack(side=LEFT, padx=2, pady=2)
button.pack(side=LEFT, padx=2, pady=2)
buttonLoad.pack(side=LEFT, padx=2, pady=2)  ##

text.insert(END, "Keine Kartei geladen") ### load gestrichen
window.mainloop()
