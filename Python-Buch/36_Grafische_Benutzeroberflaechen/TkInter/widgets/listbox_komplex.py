#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        
        self.eintraege = ["Berlin", "London", "Moskau", "Ottawa", "Paris", "Rom", "Tokio", "Washington DC"]
        
        self.lb = tkinter.Listbox(self) 
        self.lb.pack(fill="both", expand="true")
        self.lb["selectmode"] = "extended"
        self.lb.insert("end", *self.eintraege) 
        self.lb.bind("<<ListboxSelect>>", self.selectionChanged) 
        self.lb.selection_set(0)
        
        self.label = tkinter.Label(self) 
        self.label.pack()
        
        self.selectionChanged(None)

    def selectionChanged(self, event):
        self.label["text"] = "Wir fahren nach: " + ", ".join(
                (self.lb.get(i) for i in self.lb.curselection()))


if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
