#!/usr/bin/python3
#--------------------------------------------------------------
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import time, tkinter
window = tkinter.Tk()
label=tkinter.Label(master=window,
                    text="Uhrzeit: " + time.asctime())
label.pack()
window.mainloop()

