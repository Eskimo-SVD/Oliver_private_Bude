#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: schloss_einfach_relais.pyw
# 
# Zahlenschloss, das ein Relais ansteuert.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 7, Aufgabe 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------


import time, _thread
from tkinter import *
from RPi import GPIO


KEYS = ["1204", "8897", "1805"]


def close():
    frame.destroy()
    label.config(text="")
    label.bind("<1>", createKeyboard)

def insert():
    global keyId
    label.after_cancel(keyId)
    num = label.cget("text") + key.get()
    label.config(text=num)
    _thread.start_new_thread(check, (num,))

def check(num):
    global keyId
    if num in KEYS:
        label.config(text="Tür auf!")
        GPIO.output(10, False)
        time.sleep(3)
        GPIO.output(10, True)
        label.config(text="")
    keyId = label.after(10000, close)
     

def createKeyboard(event):
    global frame,keyId
    keyId = label.after(10000, close)
    label.unbind("<1>")
    frame = Frame(master=window)
    frame.pack()
    numButtons = [Radiobutton(master=frame, command=insert,
                            font=("Arial", 14), width=3,
                            variable=key, value=n,
                            text=n, indicatoron=False)
                  for n in "1234567890"]
    for i in range(3):
       numButtons[i].grid(row=0, column=i)
    for i in range(3,6):
       numButtons[i].grid(row=1, column=i-3)
    for i in range(6,9):
       numButtons[i].grid(row=2, column=i-6)
    numButtons[9].grid(row=3, column=0)



GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.OUT)
GPIO.output(10, True)

window=Tk()
key = StringVar(master=window)
label = Label(master=window, bd=4, relief=SUNKEN,
            font=("Arial",14), width=14)
label.pack(padx=30, pady=2)
label.bind("<1>", createKeyboard)
window.mainloop()
