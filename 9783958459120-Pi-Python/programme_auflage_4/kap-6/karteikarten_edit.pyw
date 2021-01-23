#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: karteikarten_edit.pyw
# Von Karteikarten lernen - Editor 
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
    global cards, num
    try:
        f = open(PATH, "rb")
        cards = pickle.load(f)
        f.close()     
    except:
        cards = [("", "")]
        saveCards()
    showCard(0)

def saveCards():
    f = open(PATH, "wb")
    pickle.dump(cards, f)
    f.close()

def showCard(n):
    label.config(text="Karte "+str(n+1))
    text1.delete(1.0, END)
    text1.insert(1.0, cards[n][0])
    text2.delete(1.0, END)
    text2.insert(1.0, cards[n][1])      
    
def newCard():
    global num, cards
    cards.append(("",""))
    num = len(cards) - 1
    showCard(num)
    
def nextCard():
    global num, cards
    cards[num] = (text1.get(1.0, END)[:-1],
                  text2.get(1.0, END)[:-1])
    saveCards()
    num += 1
    if num >= len(cards):
        num = 0
    showCard(num)
           
# Widgets
window = Tk()
window.title("Karteikarten-Editor")
label = Label(master=window, width=20,font = ("Arial", 16))  
buttonNext = Button(master=window,text="Speichern und weiter",width=20,
                font = ("Arial", 14), command=nextCard)
buttonNew = Button(master=window,text="Neue Karte", width=20,
                font = ("Arial", 14), command=newCard)
text1 = Text(master=window, width=40, height=4,
            font = ("Arial", 14), wrap=WORD)
text2 = Text(master=window, width=40, height=4, fg="blue",
            font = ("Arial", 14), wrap=WORD)
                         
# Layout
label.pack()
text1.pack(pady=2)
text2.pack(pady=2)
buttonNew.pack(side=LEFT, padx=2, pady=2)
buttonNext.pack(side=LEFT, padx=2, pady=2)

loadCards()
num = 0
window.mainloop()
