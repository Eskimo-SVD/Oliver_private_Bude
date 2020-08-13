#!/usr/bin/python3
from tkinter import *
import tkinter.font as tkf
mywin = Tk()
mywin.wm_title('Hello World')
myfont = tkf.Font(family='DejaVuSans', size=20)
mylabel = Label(mywin, text='Hello World!', font=myfont)
mylabel.pack()
mywin.mainloop()

