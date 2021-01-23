#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: schloss_einfach_fenster.pyw
# Zahlenschloss mit separatem Eingabefenster
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 7
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from tkinter import *

KEYS = ["1200", "8897", "180"]

def close():
    global keyboard
    keyboard.destroy()
    label.config(text="")
    label.bind("<1>", createKeyboard)

def insert():
    label.after_cancel(keyId)
    num = label.cget("text") + key.get()
    label.config(text=num)
    _thread.start_new_thread(check, (num,))

def check(num):
    global keyId
    if num in KEYS:
        label.config(text="Tür auf!")
        time.sleep(1)
        label.config(text="")
    keyId = label.after(3000, close)
     

def createKeyboard(event):
    global keyId, keyboard
    keyId = label.after(3000, close)
    label.unbind("<1>")
    keyboard = Tk()
    keyboard.geometry("120x140+100+120")
    numButtons = [Radiobutton(master=keyboard, command=insert,
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

window=Tk()
key = StringVar(master=window)
label = Label(master=window, bd=4, relief=SUNKEN,
            font=("Arial",14), width=14)
label.pack(padx=30, pady=2)
label.bind("<1>", createKeyboard)
window.mainloop()
