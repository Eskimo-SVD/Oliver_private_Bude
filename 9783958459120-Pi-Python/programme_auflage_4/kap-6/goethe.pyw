#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: goethe.pyw
# Aus Texten von Goethe und Schiller werden Zitate generiert
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 6.8
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import *
import random, time

def createBook(filename):
    f = open(filename, "r", encoding="utf-8")         #1
    text = f.read()
    f.close()
    text = text.replace("\n", " ")                    #2
    raw = text.split(". ")                            #3
    sentences=[s.strip() for s in raw
               if (len(s) > 100) and ("(" not in s)\
               and("_" not in s)]                     #4
    return sentences

def newQuote():
    global author
    if answer.get():                                  #5
        author = random.choice(["Goethe", "Schiller"])
        if author == "Goethe":
            quote = random.choice(bookGoethe) + "."   #6
        else:
            quote = random.choice(bookSchiller) + "." 
        text.delete(1.0, END)
        text.insert(1.0, quote)
        label.config(text="Von wem stammt dieser Text?")
        for rb in radiobuttons: rb.deselect()
        answer.set("")                                #7

def check():
    if author == answer.get():                        #8
        response = "Richtig! "
    else:
        response = "Falsch! "
    label.config(text=response+"Das stammt von " + author)

# Widgets
window = Tk()
answer=StringVar(master=window, value="x")
label=Label(master=window, font=("Arial", 16))
radiobuttons=[Radiobutton(master=window,text=a, value=a, 
                          font=("Arial", 16),
                          variable=answer,
                          command=check,
                          indicatoron=False)
              for a in ("Goethe", "Schiller")]        #9
button = Button(master=window, font=("Arial", 16),
                text="Nächstes Zitat", command=newQuote)
text = Text(master=window, font=("Arial", 14), width=50,
            height=8, wrap=WORD)

# Layout
label.pack()
text.pack()
for rb in radiobuttons: rb.pack(side=LEFT)           #10        
button.pack(side=LEFT)

bookGoethe = createBook("faust.txt")
bookSchiller = createBook("raeuber.txt")
newQuote()
window.mainloop()
