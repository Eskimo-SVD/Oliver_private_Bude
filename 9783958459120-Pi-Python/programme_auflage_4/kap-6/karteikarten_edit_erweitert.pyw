#!/usr/bin/python3.2
#----------------------------------------------------------------
# Dateiname: karteikarten_edit_erweitert.pyw
# Von Karteikarten lernen
# Editor mit Laden und Speichern
#
# Michael Weigend: Raspberry Pi programmieren mit Python, mitp 2013
# 6.6.2
# 29.10.2013
#----------------------------------------------------------------

from tkinter import *
import pickle, random



def loadCards():
    global cards, num, path
    p = filedialog.askopenfilename()  # Abbruch berücksichtigen
    if p:
        try:
           f = open(p, "rb")  
           cards = pickle.load(f)
           path = p
           f.close()
           num=0
           showCard(num)
        except:
           messagebox.showerror("", "Kartei unleserlich")           

def newCards():
    global cards, path, num
    p = filedialog.asksaveasfilename()
    if p:
        path = p
        num=0
        cards = [("", "")]
        showCard(num)
        saveCards()


def saveCards():
    f = open(path, "wb")    # keine Konstante
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
label = Label(master=window, width=20,font = ("Arial", 14),
              text="Keine Karten geladen")  
buttonNext = Button(master=window,text="Weiter und speichern",
                font = ("Arial", 12), command=nextCard)
buttonNew = Button(master=window,text="Neue Karte", width=12,
                font = ("Arial", 12), command=newCard)
buttonLoad = Button(master=window,text="Laden", width=12,
                font = ("Arial", 12), command=loadCards)   #####
buttonNewCards = Button(master=window,text="Neue Kartei", width=12,
                font = ("Arial", 12), command=newCards)   ##

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
buttonLoad.pack(side=LEFT, padx=2, pady=2) ##
buttonNewCards.pack(side=LEFT, padx=2, pady=2) ##



num = 0
window.mainloop()
