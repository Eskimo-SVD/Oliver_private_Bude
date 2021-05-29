#!/usr/bin/env python

import tkinter
import tkinter.scrolledtext


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.text = tkinter.scrolledtext.ScrolledText(master)
        self.text.pack()
        self.text.insert("end", "Hallo Welt\n")


if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
