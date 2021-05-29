#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        
        self.eintraege = ["Berlin", "London", "Moskau", "Ottawa", "Paris", "Rom", "Tokio", "Washington DC"]
        self.lb = tkinter.Listbox(master)
        self.lb.insert("end", *self.eintraege)
        self.lb.pack()


if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
