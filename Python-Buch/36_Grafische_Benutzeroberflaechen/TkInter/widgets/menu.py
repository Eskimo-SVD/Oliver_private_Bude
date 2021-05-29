#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
       
        self.menuBar = tkinter.Menu(master)
        master.config(menu=self.menuBar)
        
        self.fillMenuBar()

    def fillMenuBar(self):
        self.menuFile = tkinter.Menu(self.menuBar, tearoff=False)
        
        self.menuFile.add_command(label="Öffnen", command=self.handler)
        self.menuFile.add_command(label="Speichern", command=self.handler)
        self.menuFile.add_command(label="Speichern unter", command=self.handler)
        
        self.menuFile.add_separator()
        self.menuFile.add_command(label="Beenden", command=self.quit)
        self.menuBar.add_cascade(label="Datei", menu=self.menuFile)

    def handler(self):
        print("Hallo Welt!")


if __name__ == "__main__":
    root = tkinter.Tk()
    root.geometry("500x300")
    app = MyApp(root)
    app.mainloop()
