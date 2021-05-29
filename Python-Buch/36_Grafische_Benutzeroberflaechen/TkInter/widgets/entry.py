#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        
        self.entryVar = tkinter.StringVar()
        self.entryVar.set("Hallo Welt")
        
        self.entry = tkinter.Entry(self)
        self.entry["textvariable"] = self.entryVar
        self.entry.pack()
        
        self.entry.bind("<Return>", self.handler)

    def handler(self, event):
        print(self.entryVar.get())


if __name__ == "__main__":
    root = tkinter.Tk()
    root.geometry("500x300")
    app = MyApp(root)
    app.mainloop()
