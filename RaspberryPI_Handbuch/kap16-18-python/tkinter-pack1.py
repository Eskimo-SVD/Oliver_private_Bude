#!/usr/bin/python3
from tkinter import *
mywin = Tk()
mylabel1 = Label(mywin, text='Text', bg="yellow")        
mylabel2 = Label(mywin, text='Noch mehr Text', fg="blue")
mybutton1 = Button(mywin, text='Button 1')
mybutton2 = Button(mywin, 
                   text='Button 2 mit einem längeren Text')
mylabel1.pack()
mylabel2.pack()
mybutton1.pack()
mybutton2.pack()
mywin.mainloop()
