#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.s1 = tkinter.Spinbox(self)
        self.s1["from"] = 0
        self.s1["to"] = 100
        self.s1.pack()
        
        self.s2 = tkinter.Spinbox(self)
        self.s2["values"] = (2,3,5,7,11,13,19)
        self.s2.pack()
        
        self.s3 = tkinter.Spinbox(self)
        self.s3["values"] = ("A", "B", "C")
        self.s3.pack()


if __name__ == "__main__":
    root = tkinter.Tk()
    root.geometry("500x300")
    app = MyApp(root)
    app.mainloop()
