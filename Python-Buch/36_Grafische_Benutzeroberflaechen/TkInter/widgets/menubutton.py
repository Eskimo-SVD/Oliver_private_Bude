#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.mb = tkinter.Menubutton(self, text="Hallo Welt")
        
        self.menu = tkinter.Menu(self.mb, tearoff=False)
        self.menu.add_checkbutton(label="Donald Duck")
        self.menu.add_checkbutton(label="Onkel Dagobert")
        self.menu.add_checkbutton(label="Tick, Trick und Track")
        
        self.mb["menu"] = self.menu
        self.mb.pack()


if __name__ == "__main__":
    root = tkinter.Tk()
    root.geometry("500x300")
    app = MyApp(root)
    app.mainloop()
