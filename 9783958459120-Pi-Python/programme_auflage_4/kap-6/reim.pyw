#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: reim.pyw
# Reimende Wörter suchen
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 6.11
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import *
from re import *

def search():
    postfix = entry.get()
    wordlist = findall("\w*" + postfix + "[.,!? ]", faust)
    wordlist2 = [w[:-1] for w in wordlist]
    words = set(wordlist2)
    result = ", ".join(words)
    text.delete(1.0, END)
    text.insert(END, result)
    
# Widgets
window = Tk()  
entry=Entry(master=window, font=("Arial", 14))
button = Button(master=window, font=("Arial", 14),
        text = "Suche Reime!", command=search)
text=Text(master=window, font=("Arial", 14),
          width=40, height=7, wrap=WORD)
text.pack()
entry.pack(side=LEFT)
button.pack(side=LEFT)

faust = open("faust.txt", mode="r", encoding="utf-8").read()
window.mainloop()
