#!/usr/bin/env python

import tkinter


class MyApp(tkinter.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()
        
        self.text = tkinter.Text(master)
        self.text.pack()
        
        self.text.tag_config("o", foreground="orange")
        self.text.tag_config("u", underline=True)
        
        self.text.insert("end", "Hallo Welt\n")
        self.text.insert("end", "Dies ist ein langer, orangefarbener Text\n", "o")
        self.text.insert("end", "Und unterstrichen ebenfalls", "u")


if __name__ == "__main__":
    root = tkinter.Tk()
    app = MyApp(root)
    app.mainloop()
