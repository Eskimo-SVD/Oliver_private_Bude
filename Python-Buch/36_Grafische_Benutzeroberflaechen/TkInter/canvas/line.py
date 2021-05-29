#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.cv = tkinter.Canvas(self, width=100, height=150)
        self.cv.pack()
        
        punkte = (10, 140,    90, 60,    10, 60,
                  50, 10,     90, 60,    90, 140,
                  10, 140,    10, 60,    90, 140)
        self.cv.create_line(*punkte, width=3)


if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
