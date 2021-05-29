#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.cv = tkinter.Canvas(self, width=800, height=600)
        self.cv.pack()
        
        self.img = tkinter.PhotoImage(file="kaffee.png")
        self.cv.create_image(0, 0, image=self.img, anchor="nw")

        
if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
