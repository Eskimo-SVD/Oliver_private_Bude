#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        
        self.auswahl = ["Berlin", "London", "Moskau", "Ottawa", 
                        "Paris", "Rom", "Tokio", "Washington DC"]
        
        self.stadt = tkinter.StringVar()
        self.stadt.set("Moskau")
        
        for a in self.auswahl:
            b = tkinter.Radiobutton(self)
            b["text"] = a
            b["value"] = a
            b["variable"] = self.stadt
            b["command"] = self.handler
            b.pack(anchor="w")
        
    def handler(self):
        print(self.stadt.get())


if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
