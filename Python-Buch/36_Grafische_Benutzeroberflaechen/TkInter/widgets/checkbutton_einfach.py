#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        
        self.checked = tkinter.BooleanVar()
        self.checked.set(True)
        
        self.check = tkinter.Checkbutton(self)
        self.check["text"] = "Hallo Welt"
        self.check["variable"] = self.checked
        self.check["command"] = self.handler
        self.check.pack()
        
    def handler(self):
        print(self.checked.get())


if __name__ == "__main__":
    root = tkinter.Tk()
    root.geometry("500x300")
    app = MyApp(root)
    app.mainloop()
