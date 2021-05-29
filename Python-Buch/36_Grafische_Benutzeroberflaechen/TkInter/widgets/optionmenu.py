#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.lst = ["Linux", "MacOS X", "Windows"]
        
        self.var = tkinter.StringVar()
        self.var.set("Linux")
        
        self.op = tkinter.OptionMenu(self, self.var, *self.lst, command=self.handler)
        self.op.pack()

    def handler(self, text):
        print(text, self.var.get())


if __name__ == "__main__":
    root = tkinter.Tk()
    root.geometry("500x300")
    app = MyApp(root)
    app.mainloop()
