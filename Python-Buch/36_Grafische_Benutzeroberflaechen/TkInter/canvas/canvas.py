#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.cv = tkinter.Canvas(self, width=200, height=200)
        self.cv.pack()
        
        self.cv.create_oval(50, 50, 150, 150, fill="orange", width=3)
        self.cv.create_line(50, 150, 150, 50, width=3)
        self.cv.create_line(50, 50, 150, 150, width=3)


if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
