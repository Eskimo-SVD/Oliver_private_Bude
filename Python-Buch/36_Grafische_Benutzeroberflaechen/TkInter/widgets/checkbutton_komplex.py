#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        
        self.names = ("Donald Duck", "Dagobert Duck", "Gustav Gans")
                
        self.checks = []
        self.vars = []
        
        for name in self.names:
            var = tkinter.BooleanVar()
            var.set(False)
            
            check = tkinter.Checkbutton(self)
            check["text"] = name
            check["command"] = self.handler
            check["variable"] = var
            check.pack(anchor="w")
            
            self.checks.append(check)
            self.vars.append(var)
        
    def handler(self):
        print(" und ".join([name for name, var in zip(self.names, self.vars) if var.get()]))


if __name__ == "__main__":
    root = tkinter.Tk()
    root.geometry("500x300")
    app = MyApp(root)
    app.mainloop()
