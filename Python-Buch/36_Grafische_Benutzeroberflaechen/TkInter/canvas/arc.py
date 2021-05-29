#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.cv = tkinter.Canvas(self, width=600, height=200)
        self.cv.pack()
        
        self.cv.create_arc(20, 20, 180, 180, fill="orange", width=3, style="pieslice")
        self.cv.create_arc(220, 20, 380, 180, fill="orange", width=3, style="chord")
        self.cv.create_arc(420, 20, 580, 180, fill="orange", width=3, style="arc")


if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
