#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.cv = tkinter.Canvas(self, width=100, height=100)
        self.cv.pack()
        
        self.font1 = ("Arial", 12, "italic")
        self.font2 = ("Courier New", 12, "bold italic")
        self.font3 = ("Comic Sans MS", 12, "bold")
        
        self.cv.create_text(55, 30, text="Python", font=self.font1) 
        self.cv.create_text(55, 50, text="Python", font=self.font2) 
        self.cv.create_text(55, 70, text="Python", font=self.font3)


if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
