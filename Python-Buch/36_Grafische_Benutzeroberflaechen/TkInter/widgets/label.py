#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        
        self.label = tkinter.Label(self)
        self.label["text"] = "Hallo Welt"
        self.label.pack()


if __name__ == "__main__":
    root = tkinter.Tk()
    root.geometry("500x300")
    app = MyApp(root)
    app.mainloop()