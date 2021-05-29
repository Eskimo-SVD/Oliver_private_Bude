#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.cv = tkinter.Canvas(self, width=200, height=100)
        self.cv.pack()
        
        self.cv.create_oval(10, 10, 190, 90, fill="red", width=3)
        self.b = tkinter.Button(None, text="Selbstzerstörung",      
                                background="red", activebackground="red",  
                                foreground="white", activeforeground="white")
        self.cv.create_window(100, 50, window=self.b)


if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
