#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: hangman.pyw
# Applikation mit Bildschirmtastatur, Implementierung des Spiels Hangman
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 5.10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import random 
from tkinter import *

words = ["PASSWORT", "VERSCHLÜSSELUNG", "SCHLÜSSEL", "PRIVAT", "ÖFFENTLICH", "COOKIE"]

def new_word():
    global word, display
    word = random.choice(words)
    display = len(word)*"-"
    word_label.config(text=len(word)*"-")

def check():
    global display                 
    display_list = list(display)
    for i in range(len(word)):
         if word[i] == key.get():
            display_list[i] = word[i]
    display = "".join(display_list)
    word_label.config(text=display)
            
# Widgets
window=Tk()
word_label = Label(master=window,
                  font=('Courier',20), width=26)
new_button = Button(master=window, text='Neues Wort',
                   command=new_word, font=("Arial", 14),
                    bg="black", fg="white")
key = StringVar(master=window)
key_rbs = [Radiobutton(master=window, command=check,
                 font=("Arial", 14), width=3,
                 variable=key, value=ch,
                 text=ch, indicatoron=False)
           for ch in "QWERTZUIOPÜASDFGHJKLÖÄYXCVBNM"]

# Layout
word_label.grid(column=0,row=0, columnspan=10)
for i in range(11):
    key_rbs[i].grid(row=1, column=i)
for i in range(11,22):
    key_rbs[i].grid(row=2, column=i-11)
for i in range(22,28):
    key_rbs[i].grid(row=3, column=i-21)
new_button.grid(column=8,row=4, columnspan=3, sticky=E)

new_word()
window.mainloop()
